// Copyright 2024 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <WiFi.h>
#include <ESPmDNS.h>
#include <NetworkUdp.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>

//Conectando-se à rede wi-fi
const char *ssid = "ANDRE_5907";
const char *password = "99634M{m";

// Configuração do UDP (logs via rede)
WiFiUDP udp;
const char* remoteHost = "192.168.15.9"; // coloque aqui o IP do PC
const int remotePort   = 8888;           // porta UDP

// =========================
// Fila para logs (FreeRTOS Queue)
// =========================
QueueHandle_t logQueue;

// =========================
// Função auxiliar: envia log
// =========================
void logMessage(const char* msg) {
  if (logQueue != NULL) {
    xQueueSend(logQueue, &msg, 0); // envia ponteiro para string
  }
}

// =========================
// Task: OTA (Core 0)
// =========================
void taskOTA(void *pvParameters) {
  for (;;) {
    ArduinoOTA.handle();           // Mantém OTA ativo
    vTaskDelay(pdMS_TO_TICKS(50)); // Chamada a cada 50ms
  }
}

// =========================
// Task: Blink (Core 1)
// =========================
void taskBlink(void *pvParameters) {
  pinMode(2, OUTPUT);

  for (;;) {
    digitalWrite(2, HIGH);
    logMessage("LED ON");
    vTaskDelay(pdMS_TO_TICKS(1200));
    digitalWrite(2, LOW);
    logMessage("LED OFF");
    vTaskDelay(pdMS_TO_TICKS(1200));
  }
}

// =========================
// Task: Logger (Core 1)
// =========================
void taskLogger(void *pvParameters) {
  const char* msg;
  for (;;) {
    if (xQueueReceive(logQueue, &msg, portMAX_DELAY)) {
      // Envia para Serial
      Serial.println(msg);

      // Envia para UDP
      udp.beginPacket(remoteHost, remotePort);
      udp.print(msg);
      udp.endPacket();
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  // ArduinoOTA.setHostname("myesp32");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA.onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH) {
        type = "sketch";
      } else {  // U_SPIFFS
        type = "filesystem";
      }

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) {
        Serial.println("Auth Failed");
      } else if (error == OTA_BEGIN_ERROR) {
        Serial.println("Begin Failed");
      } else if (error == OTA_CONNECT_ERROR) {
        Serial.println("Connect Failed");
      } else if (error == OTA_RECEIVE_ERROR) {
        Serial.println("Receive Failed");
      } else if (error == OTA_END_ERROR) {
        Serial.println("End Failed");
      }
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(WiFi.localIP(), remotePort);
  // Cria fila para até 20 mensagens (ponteiros para const char*)
  logQueue = xQueueCreate(20, sizeof(const char*));

  // função               nome, stack, parâmetros, prioridade handle core 
  // Cria a task OTA no Core 0
  xTaskCreatePinnedToCore(taskOTA, "OTA Task", 4096, NULL, 1, NULL, 0);

  // Cria a task Blink no Core 1
  xTaskCreatePinnedToCore(taskBlink, "Blink Task", 2048, NULL, 1, NULL, 1);
  // Cria a task Logger no core 1
  xTaskCreatePinnedToCore(taskLogger, "Logger Task", 4096, NULL, 1, NULL, 1);
}

void loop() {
  //Nada aqui pois o freeRTOS controla as tasks
}

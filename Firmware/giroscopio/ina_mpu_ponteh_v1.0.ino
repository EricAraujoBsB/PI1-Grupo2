#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_INA219.h>
#include <math.h>

// === Sensores ===
Adafruit_MPU6050 mpu;
Adafruit_INA219 ina219;

// === Classe Motor DC ===
class DCMotor {
  int pin1, pin2;

public:
  void Pinout(int in1, int in2) {
    pin1 = in1;
    pin2 = in2;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }

  void Forward() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }

  void Backward() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }

  void Stop() {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
  }
};

// === Classe AGV ===
class AGV {
public:
  DCMotor Motor1, Motor2;

  void Create(int in1, int in2, int in3, int in4) {
    Motor1.Pinout(in1, in2);
    Motor2.Pinout(in3, in4);
  }

  void ForwardAGV() {
    Motor1.Forward();
    Motor2.Forward();
  }

  void BackwardAGV() {
    Motor1.Backward();
    Motor2.Backward();
  }

  void LeftAGV() {
    Motor1.Backward();
    Motor2.Forward();
  }

  void RightAGV() {
    Motor1.Forward();
    Motor2.Backward();
  }

  void StopAGV() {
    Motor1.Stop();
    Motor2.Stop();
  }
};

// === Variáveis globais ===
AGV agv;
float yaw = 0.0;
float gyroBiasZ = 0.0;
unsigned long lastTime = 0;

// === Calibração do giroscópio ===
void calibrarGyroZ(int samples = 2000) {
  Serial.println("Calibrando giroscópio... mantenha o sensor parado.");
  delay(1000);

  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sensors_event_t a, g, t;
    mpu.getEvent(&a, &g, &t);
    sum += g.gyro.z;
    delay(2);
  }
  gyroBiasZ = (float)sum / samples;
  Serial.print("Bias Z calibrado: ");
  Serial.println(gyroBiasZ, 6);
}

// === Atualiza o yaw ===
float atualizarYaw() {
  unsigned long now = micros();
  float dt = (now - lastTime) / 1e6;
  lastTime = now;

  sensors_event_t a, g, t;
  mpu.getEvent(&a, &g, &t);

  float gz = g.gyro.z - gyroBiasZ;
  yaw += gz * dt * 180.0 / PI;

  // Mantém yaw entre [-180, 180]
  if (yaw > 180) yaw -= 360;
  if (yaw < -180) yaw += 360;

  return yaw;
}

// === Gira até atingir o ângulo especificado ===
void girarAte(float anguloAlvo) {
  float yawInicial = yaw;
  float yawFinal = yawInicial + anguloAlvo;

  if (yawFinal > 180) yawFinal -= 360;
  if (yawFinal < -180) yawFinal += 360;

  Serial.print("Girando até "); Serial.print(anguloAlvo); Serial.println(" graus...");

  // Define direção
  if (anguloAlvo > 0)
    agv.RightAGV();
  else
    agv.LeftAGV();

  while (true) {
    float atual = atualizarYaw();
    float delta = atual - yawInicial;

    if (anguloAlvo > 0 && delta >= anguloAlvo) break;
    if (anguloAlvo < 0 && delta <= anguloAlvo) break;

    // === Leitura da bateria durante a rotação ===
    float shuntVoltage = ina219.getShuntVoltage_mV();
    float busVoltage = ina219.getBusVoltage_V();
    float current_mA = ina219.getCurrent_mA();
    float loadVoltage = busVoltage + (shuntVoltage / 1000.0);
    float power_mW = ina219.getPower_mW();

    Serial.print("Yaw: "); Serial.print(atual, 2);
    Serial.print("° | Vbat: "); Serial.print(loadVoltage, 2);
    Serial.print(" V | Corrente: "); Serial.print(current_mA, 1);
    Serial.print(" mA | Potência: "); Serial.print(power_mW, 1);
    Serial.println(" mW");

    delay(100);
  }

  agv.StopAGV();
  Serial.println("Alvo atingido!");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL

  // Pinos para ESP32
  agv.Create(25, 26, 27, 14);

  // Inicializa MPU6050
  if (!mpu.begin()) {
    Serial.println("Falha ao inicializar MPU6050!");
    while (1);
  }
  Serial.println("MPU6050 pronto!");

  // Inicializa INA219
  if (!ina219.begin()) {
    Serial.println("Falha ao inicializar INA219!");
    while (1);
  }
  ina219.setCalibration_32V_2A(); // Ajuste comum p/ medições gerais

  calibrarGyroZ();
  lastTime = micros();
}

void loop() {
  if (Serial.available() > 0) {
    float angulo = Serial.parseFloat();
    if (angulo != 0) {
      girarAte(angulo);
      Serial.println("Pronto para novo comando.");
    }
  }
}

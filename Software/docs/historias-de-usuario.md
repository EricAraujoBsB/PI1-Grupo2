# Histórias de Usuário (US's)

## Introdução

<div align="justify">&emsp;&emsp;
As histórias de usuário são utilizadas para descrever de forma simples e objetiva as necessidades dos usuários dentro do sistema. Elas têm como foco apresentar o ponto de vista do usuário final, permitindo que a equipe de desenvolvimento compreenda claramente quais funcionalidades devem ser implementadas e qual valor será entregue. Esse método facilita a comunicação entre os envolvidos no projeto e garante que os requisitos estejam alinhados com as expectativas reais.
</div>

## Objetivo

<div align="justify">&emsp;&emsp;
O objetivo principal das histórias de usuário é registrar e organizar as funcionalidades do sistema a partir da perspectiva do usuário, promovendo clareza e priorização das entregas. Dessa forma, é possível assegurar que cada funcionalidade agregue valor, mantenha o foco no usuário final e apoie o desenvolvimento incremental e iterativo do software.
</div>

## Metodologia

<div align="justify">&emsp;&emsp;
A metodologia adotada segue o padrão ágil, onde as histórias de usuário são escritas no formato: "Como [tipo de usuário], eu quero [funcionalidade] para [benefício esperado]". Cada história é complementada por critérios de aceitação, que especificam as condições necessárias para que a entrega seja considerada concluída. Além disso, as histórias são priorizadas em backlog e refinadas em reuniões de planejamento, permitindo uma evolução contínua do sistema de acordo com o feedback dos usuários e stakeholders.
</div>

---

## Histórias

### US1 - Listar trajetórias antigas

**Como** usuário, **quero** visualizar a lista de trajetórias antigas **para** analisar execuções passadas e escolher qual detalhar.

#### Critérios de Aceitação
- [ ] O sistema deve exibir todas as trajetórias armazenadas.  
- [ ] Cada trajetória deve conter informações resumidas (data, duração, status).
- [ ] Se não houver trajetórias, o sistema deve informar "Nenhuma trajetória encontrada". 

---

### US2 - Detalhar trajetória antiga

**Como** usuário, **quero** visualizar os detalhes de uma trajetória antiga **para** entender sua execução de forma mais completa tendo acesso a seus dados, gráficos e estatísticas.

#### Critérios de Aceitação
- [ ] O sistema deve exibir os comandos executados e suas sequências.  
- [ ] O sistema deve exibir parâmetros como distância percorrida, desenho de trajetória e tempo.
- [ ] A trajetória deve mostrar onde o objeto foi depositado.   
- [ ] Se a trajetória não existir, o sistema deve mostrar uma mensagem de erro.  

---

### US3 - Conectar com carrinho

**Como** usuário, **quero** conectar a interface web ao carrinho (ESP32) **para** controlar e monitorar suas trajetórias em tempo real.

#### Critérios de Aceitação
- [ ] O usuário deve poder clicar em um botão "Conectar" para iniciar conexão com o carrinho.  
- [ ] Caso o usuário tente iniciar uma trajetória sem estar conectado, uma mensagem de erro deve aparecer.
- [ ] O sistema deve exibir claramente o status da conexão (conectado/desconectado) a todo momento, em qualquer página.
- [ ] Se a conexão falhar, o sistema deve mostrar uma mensagem de erro.  

---

### US4 - Planejar nova trajetória

**Como** usuário, **quero** montar uma sequência de comandos para o carrinho **para** que ele execute um percurso definido.

#### Critérios de Aceitação
- [ ] O sistema deve permitir inserir comandos: avançar (com distância), virar à esquerda (90°), virar à direita (90°).  
- [ ] O usuário deve poder salvar ou enviar a sequência para o carrinho.  
- [ ] Em caso de parâmetro inválido, o sistema deve exibir mensagem de erro.  

---

### US5 - Iniciar trajetória

**Como** usuário, **quero** iniciar a execução de uma trajetória planejada **para** que o carrinho comece a percorrer o trajeto.

#### Critérios de Aceitação
- [ ] O sistema deve confirmar a sequência de comandos antes do envio.  
- [ ] O carrinho deve receber os comandos validados para execução.  
- [ ] Em caso de falha no envio, o sistema deve notificar o usuário.  

---

### US6 - Parar carrinho

**Como** usuário, **quero** parar a execução de uma trajetória em andamento **para** interromper imediatamente o movimento do carrinho.

#### Critérios de Aceitação
- [ ] O sistema deve enviar um comando de parada imediata ao carrinho.  
- [ ] O carrinho deve interromper todos os movimentos em execução.  
- [ ] O sistema deve confirmar visualmente que o carrinho foi parado.
- [ ] O sistema deve processar a trajetória encerrada, salvá-la e gerar suas análises normalmente.

---

### US7 - Detalhar trajetória atual

**Como** usuário, **quero** visualizar detalhes da trajetória em execução **para** acompanhar em tempo real o andamento do carrinho.

#### Critérios de Aceitação
- [ ] O sistema deve ser capaz de receber e processar dados da ESP32.
- [ ] O sistema deve exibir em tempo real os comandos que estão sendo executados por meio de desenho.  
- [ ] O sistema deve mostrar informações de status como posição atual e etapa em andamento através de gráficos.  
- [ ] Caso ocorra falha na transmissão, o sistema deve exibir uma mensagem de erro.


### USX - Nome da História de Usuário

**Como** [tipo de usuário], **quero** [funcionalidade desejada] **para** [benefício ou objetivo alcançado]

#### Critérios de Aceitação
- [ ] Critério 1  
- [ ] Critério 2  
- [ ] Critério 3 

---
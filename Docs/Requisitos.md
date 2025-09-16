# **Requisitos do Sistema - Carrinho Autônomo para Depósito de Objetos**

## Requisitos

### 1. **Trajetórias e Navegação**
- O carrinho deverá percorrer as três trajetórias de forma autônoma, seguindo as instruções programadas na interface gráfica.
- As marcações nas trajetórias servem apenas como **referência visual** para o desenvolvimento e ajuste do carrinho, mas o carrinho deverá ser capaz de executar as trajetórias sem intervenção humana.

### 2. **Objeto e Armazenamento**
- O objeto a ser transportado terá as dimensões e a fragilidade de um **ovo médio** (38g a 47,99g).
- O objeto será posicionado manualmente no carrinho no início da trajetória e deverá ser **depositado automaticamente** em uma caixa acolchoada ao final.

### 3. **Interface Gráfica**
- O sistema deverá permitir que as trajetórias sejam **programadas em ambiente gráfico**, utilizando comandos como "andar X cm", "girar 90º", etc.
- O carrinho deverá seguir as trajetórias automaticamente, sem intervenção humana durante a execução.

### 4. **Comunicação e Dados**
- O carrinho deverá se comunicar sem fio (ex: Wi-Fi, Bluetooth) para receber as instruções de trajeto e enviar dados sobre o progresso da execução.
- O sistema de medição e registro de dados irá armazenar informações como:
  - **Trajetória percorrida**.
  - **Tempo de execução**.
- Os dados coletados serão agrupados e persistidos em um banco de dados para análise posterior.

### 5. **Sistema de Registro de Dados**
- O carrinho contará com sensores para medir dados em tempo real, como a trajetória percorrida e o tempo gasto para completar cada parte da trajetória.
- As informações coletadas serão apresentadas e analisadas através de software dedicado, com a persistência dos dados em banco de dados.

### 6. **Desenvolvimento do Sistema**
- **Desenvolvimento Exclusivo**: O sistema deve ser desenvolvido do zero pelos integrantes do grupo, sem o uso de soluções prontas do mercado.
- **Integração Multidisciplinar**: O projeto exigirá conhecimentos de diferentes áreas da engenharia (energia, computação, eletrônica, software, etc.) para a construção do carrinho.

## Brainstorming

### Requisitos de Software

O sistema de software do carrinho autônomo deverá ser programado para seguir as instruções de trajetória de forma automática, sem intervenção humana.

- Interface e comunicação:
    - Desenvolver uma **interface gráfica** para programação e monitoramento.
    - A interface deve ser **responsiva** e, de preferência, uma **interface web**.
    - Habilitar a **comunicação contínua** e sem fio com o hardware do carrinho.
    - A interface deve ser capaz de ler e escrever comandos no **módulo embarcado**.

- Dados e funcionalidade:
    - Implementar um **banco de dados** para persistir e agrupar as variáveis.
    - Receber e processar dados do carrinho em tempo real.
    - **Analisar os resultados** recebidos e exibir a trajetória percorrida em um **gráfico de trajetória**.


### Requisitos de Hardware

O hardware do projeto deve ser um sistema autônomo, projetado para receber e executar comandos de navegação de forma precisa e eficiente.

- Navegação e movimentação:
    - O carrinho deve ser **autônomo**, capaz de armazenar e seguir uma **lista de comandos** para completar a trajetória.
    - Deve se movimentar com a força mínima necessária e ser capaz de girar em torno do próprio eixo.
    - A comunicação com o software deve ser **sem fio** para evitar obstruções.

- Armazenamento e medição:
    - Ter um sistema para **registrar dados** em tempo real, como a trajetória percorrida e o tempo.
    - Calcular e medir a **trajetória**, o tempo e os demais dados necessários para o registro.

- Carga e energia:
    - Depositar o objeto automaticamente em uma caixa acolchoada no final da trajetória.
    - Garantir a **permanência energética** do veículo durante o percurso.

### Requisitos de Estrutura
A estrutura física do carrinho precisa ser robusta e funcional para atender aos objetivos do projeto.

- Design e funcionalidade:
    - A estrutura deve ser capaz de **comportar todos os componentes** de forma segura e organizada.
    - Garantir o **equilíbrio de peso** para um transporte estável.
    - A estrutura deve ser capaz de **transportar e depositar o objeto** de forma segura.

- Especificações:
    - Massa mínima de 200g e massa máxima de 2kg.
    - O projeto da estrutura deve incluir um documento de modelagem 3D.


### Requisitos Funcionais (RF)

Os requisitos funcionais descrevem as funcionalidades que o sistema deve oferecer.

| Código | Requisito                                                                                                               |
| ------ | ----------------------------------------------------------------------------------------------------------------------- |
| RF01   | Fornecer uma interface gráfica para o usuário.                                                                          |
| RF02   | Estabelecer e manter comunicação sem fio com o hardware do carrinho (ESP32).                                            |
| RF03   | Permitir que o usuário inicie conexão com um carrinho específico na rede.                                               |
| RF04   | Criar novas trajetórias combinando comandos pré-definidos (ex.: "Avançar x cm", "Virar à esquerda", "Virar à direita"). |
| RF07   | Enviar a sequência de comandos planejada para o carrinho e iniciar a execução da trajetória.                            |
| RF08   | Disponibilizar comando de parada de emergência para interromper a trajetória em execução.                               |
| RF09   | Receber e processar dados do carrinho em tempo real durante a execução da trajetória.                                   |
| RF10   | Exibir graficamente a trajetória atual do carrinho em tempo real.                                                       |
| RF11   | Persistir dados das trajetórias concluídas em um banco de dados.                                                        |
| RF12   | Listar todas as trajetórias salvas anteriormente.                                                                       |
| RF13   | Visualizar detalhadamente uma trajetória antiga, incluindo a exibição do percurso em gráfico.                           |
| RF14   | Executar trajetórias de forma autônoma após o envio dos comandos, sem intervenção humana.                               |
| RF15   | Exibir informações básicas do carrinho conectado, como nível da bateria e estado atual.                                 |

### Requisitos Não Funcionais (RNF)

Os requisitos não funcionais definem as restrições ou qualidades do sistema, como desempenho, usabilidade, confiabilidade e tecnologia utilizada.

| Código | Requisito                                                                                                      |
| ------ | -------------------------------------------------------------------------------------------------------------- |
| RNF01  | Fornecer a interface como uma aplicação web.                                                                   |
| RNF02  | Tornar a interface web responsiva, adaptando-se a diferentes tamanhos de tela.                                 |
| RNF03  | Exibir mensagens de erro claras caso a comunicação com o carrinho falhe ou comandos inválidos sejam inseridos. |
| RNF04  | Manter comunicação contínua e estável entre a interface e o carrinho durante a operação.                       |

## MoSCoW

MoSCoW é uma técnica de priorização de requisitos que os classifica em quatro categorias:

- **Must Have (Deve ter):** requisitos essenciais que o sistema precisa implementar obrigatoriamente.
- **Should Have (Deveria ter):** requisitos importantes que melhoram a experiência ou a confiabilidade, mas não são críticos para o funcionamento inicial.
- **Could Have (Poderia ter):** requisitos opcionais que podem ser implementados se houver tempo ou recursos disponíveis.
- **Won’t Have (Não terá):** requisitos que não serão implementados nesta versão do projeto, mas podem ser considerados futuramente.

### M - Must Have (Deve Ter)

| Código | Requisito                                                                                     |
| ------ | --------------------------------------------------------------------------------------------- |
| RF01   | Fornecer uma interface gráfica para o usuário.                                                |
| RF02   | Estabelecer e manter comunicação sem fio com o hardware do carrinho (ESP32).                  |
| RF03   | Permitir que o usuário inicie conexão com um carrinho específico na rede.                     |
| RF04   | Criar novas trajetórias combinando comandos pré-definidos.                                    |
| RF07   | Enviar a sequência de comandos planejada para o carrinho e iniciar a execução da trajetória.  |
| RF08   | Disponibilizar comando de parada de emergência para interromper a trajetória em execução.     |
| RF09   | Receber e processar dados do carrinho em tempo real durante a execução da trajetória.         |
| RF11   | Persistir dados das trajetórias concluídas em um banco de dados.                              |
| RF12   | Listar todas as trajetórias salvas anteriormente.                                             |
| RF13   | Visualizar detalhadamente uma trajetória antiga, incluindo a exibição do percurso em gráfico. |
| RF14   | Executar trajetórias de forma autônoma após o envio dos comandos, sem intervenção humana.     |

### S - Should Have (Deveria Ter)

| Código | Requisito                                                                                |
| ------ | ---------------------------------------------------------------------------------------- |
| RF10   | Exibir graficamente a trajetória atual do carrinho em tempo real.                        |
| RNF02  | Tornar a interface web responsiva, adaptando-se a diferentes tamanhos de tela.           |
| RNF04  | Manter comunicação contínua e estável entre a interface e o carrinho durante a operação. |

### C - Could Have (Poderia ter)

| Código | Requisito                                                                               |
| ------ | --------------------------------------------------------------------------------------- |
| RF15   | Exibir informações básicas do carrinho conectado, como nível da bateria e estado atual. |

### W - Won't Have (Não Terá)

| Funcionalidade                              |
| ------------------------------------------- |
| Autenticação de usuários / Sistema de login |

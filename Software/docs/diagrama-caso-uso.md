# Diagrama de Caso de Uso

## Introdução

<div align="justify">&emsp;&emsp; O presente documento apresenta o diagrama de casos de uso referente ao <b>Sistema Web</b>, cujo objetivo é permitir a interação entre o usuário e um carrinho controlado por meio de uma interface, além da comunicação com o microcontrolador <b>ESP32</b>. O diagrama ilustra os atores envolvidos e as principais funcionalidades disponibilizadas pelo sistema, evidenciando como o usuário pode planejar, iniciar, detalhar e controlar trajetórias, enquanto o ESP32 é responsável pela execução e transmissão de dados relacionados. </div>

## Objetivo

<div align="justify">&emsp;&emsp; O objetivo do diagrama é representar de forma clara e organizada as funcionalidades oferecidas pelo sistema, destacando a relação entre o <b>usuário</b>, o <b>ESP32</b> e o <b>Sistema Web</b>. Dessa forma, busca-se facilitar a compreensão do fluxo de atividades, como o planejamento e execução de trajetórias, a conexão com o carrinho, a listagem de trajetórias antigas e o envio de dados durante a execução. </div>

## Metodologia

<div align="justify">&emsp;&emsp; Para a elaboração do diagrama, foi utilizada a notação UML de casos de uso. Foram identificados dois atores principais: o <b>Usuário</b>, que interage diretamente com o sistema web, e o <b>ESP32</b>, que executa as instruções e transmite informações. Em seguida, foram modelados os casos de uso, organizando-os em funcionalidades principais e relacionamentos do tipo <b>&lt;&lt;extend&gt;&gt;</b>, como no caso de "Detalhar trajetória antiga" e "Parar carrinho". O resultado é um modelo visual que sintetiza a comunicação entre os atores e o sistema. </div>

## Resultados

<div align="justify">&emsp;&emsp; O diagrama de casos de uso produzido apresenta as seguintes funcionalidades principais: - Conectar com o carrinho; - Planejar nova trajetória; - Listar trajetórias antigas e detalhar uma trajetória selecionada; - Iniciar e detalhar a trajetória atual; - Parar ou cancelar a trajetória; - Executar a trajetória; - Enviar dados pelo ESP32.

Assim, o modelo demonstra como o sistema possibilita tanto a análise de trajetórias passadas quanto o controle em tempo real do carrinho.

</div>

![Desc](link)

<center><b>Autor(es):</b> Márcio Henrique, Cássio Reis, Eduardo Matheus.</center>

</details>

## Conclusão

<div align="justify">&emsp;&emsp; Conclui-se que o diagrama de casos de uso desenvolvido permite uma visão clara e simplificada das funcionalidades essenciais do sistema web e de como os atores se relacionam. A modelagem favorece o entendimento inicial dos requisitos do sistema, servindo de base para etapas posteriores de análise, projeto e implementação. </div>


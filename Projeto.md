# Visão Geral Do Projeto

## Objetivo

O Zangão Avarento foi desenvolvido como um TCC na área de automação industrial com a proposta de construir um drone experimental de baixo custo controlado por smartphone. A ideia central era integrar mecânica, eletrônica, programação embarcada e comunicação sem fio em uma única plataforma.

## Proposta técnica

O projeto foi organizado em quatro frentes principais:

- `Estrutura mecânica`: carcaça, suporte dos motores e adaptação das hélices.
- `Eletrônica`: esquema elétrico, condicionamento de alimentação e placa de circuito impresso.
- `Controle embarcado`: código em Arduino para acionar os motores e receber comandos.
- `Aplicativo`: interface mobile criada no MIT App Inventor para enviar comandos via Bluetooth.

## Linha do tempo

### Etapa inicial - 2022

Em 2022 o grupo desenvolveu uma prova de conceito para validar o controle dos motores por smartphone. Nessa fase, o sistema ainda não era um drone completo: tratava-se de uma estrutura simples com quatro motores, controlados por um Arduino Nano e por um aplicativo Android via Bluetooth.

<p align="center">
  <img width="650" alt="Protótipo de 2022" src="Images/Projeto - 2022.jpg"><br/>
  Protótipo inicial utilizado para demonstrar o acionamento dos motores.
</p>

Ainda nesse período foi criada uma planilha de custos para levantar os componentes necessários:

- [Planilha com os preços 2022.xlsx](Planilha%20com%20os%20pre%C3%A7os%202022.xlsx)

## Evolução em 2023

Com a base validada em 2022, o trabalho passou a focar na construção de uma versão mais completa e melhor documentada. As decisões principais dessa fase foram:

- Produzir uma carcaça compatível com os conjuntos de motor e hélice disponíveis.
- Refazer o esquema elétrico para acomodar potência e lógica no mesmo projeto.
- Projetar uma PCI própria para organizar os componentes.
- Manter o controle via smartphone para preservar a proposta de baixo custo.
- Preparar o sistema para uso de sensores como giroscópio/acelerômetro.

## O que foi desenvolvido

### Estrutura e prototipagem

A construção mecânica passou por ajustes porque os primeiros motores e hélices comprados separadamente não se encaixavam de forma adequada. A solução foi utilizar conjuntos prontos de hélices, motores e suportes, reduzindo o esforço de adaptação mecânica e acelerando os testes.

Veja mais em [Construção mecânica e estrutura](Construcao_Mecanica.md).

### Eletrônica e PCB

O esquema elétrico e a placa foram desenvolvidos no KiCad 6.0. A eletrônica reúne:

- Arduino Nano como controlador principal.
- Módulo Bluetooth HC-06 para comunicação com o aplicativo.
- Módulo giroscópio MPU-6050/GY-521 para sensoriamento.
- Conversor step-up MT3608 para alimentação em 5 V.
- Quatro MOSFETs IRF640 para acionamento dos motores.

<p align="center">
  <img width="650" alt="Esquema elétrico" src="Images/Esquema_Eletrico.png"><br/>
  Esquema elétrico desenvolvido no KiCad.
</p>

Detalhes completos em [Esquema elétrico e PCB no KiCad](KicadSchemePCB_Reference.md).

### Firmware

O firmware disponível no repositório mostra a lógica base de acionamento dos quatro motores por PWM e a separação das funções de comando, como subir, descer, deslocar e girar.

Detalhes em [Firmware e lógica de controle no Arduino](Arduino_Reference.md).

### Aplicativo

O aplicativo foi desenvolvido no MIT App Inventor e é responsável pelo envio dos comandos ao sistema via Bluetooth. O repositório inclui tanto o projeto editável quanto o APK gerado.

Detalhes em [Aplicativo Android](App_Reference.md).

## Resultado do repositório

Este repositório preserva os principais artefatos do TCC como uma base de consulta pública. O objetivo não é apenas guardar os arquivos finais, mas também permitir que outras pessoas entendam como o projeto foi estruturado e possam estudar ou reaproveitar partes dele.

Para uma visão consolidada dos arquivos, consulte [Arquivos e recursos do repositório](Arquivos_e_Recursos.md).

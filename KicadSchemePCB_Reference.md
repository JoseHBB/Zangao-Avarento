# Esquema Elétrico E PCB No KiCad

## Visão geral

O projeto eletrônico do Zangão Avarento foi desenvolvido no KiCad 6.0 e reúne a parte de alimentação, controle, comunicação e acionamento dos motores. O repositório guarda tanto os arquivos editáveis do projeto quanto imagens exportadas do esquema e da placa.

## Arquivos disponíveis

Na pasta `Kicad Scheme-PCB/` estão os arquivos principais:

- `drone_pcb_V1.4.kicad_sch`: esquema elétrico.
- `drone_pcb_V1.4.kicad_pcb`: layout da placa.
- `drone_pcb_V1.4.kicad_pro`: projeto KiCad.
- `drone_pcb_V1.4.kicad_prl`: preferências locais do projeto.

## Arquitetura eletrônica identificada

Pelos arquivos do KiCad, a placa foi estruturada em torno dos seguintes blocos:

- `Arduino Nano`: controlador principal.
- `HC-06`: comunicação Bluetooth com o smartphone.
- `MPU-6050 / GY-521`: módulo de giroscópio e acelerômetro.
- `MT3608`: conversor step-up para elevação da tensão.
- `4 x IRF640`: MOSFETs para acionamento dos motores.
- `Switch`: chave para comutação da alimentação.

## Componentes principais

### Arduino Nano

O esquema identifica o microcontrolador como `A1`, usando o módulo `Arduino Nano v3.x`. Ele centraliza a leitura dos comandos e a geração dos sinais PWM.

### Bluetooth HC-06

O módulo `U3` é um `HC-06`, responsável pela comunicação serial Bluetooth entre o app e o Arduino.

### Giroscópio / acelerômetro

O módulo `U2` aparece como `Gyroscope`, com texto interno identificando `Mpu-6050 Gy-521`. Isso indica a intenção de usar dados de orientação e aceleração como apoio ao controle do voo.

### Alimentação

O módulo `U1` é um `MT3608`, com indicação de entrada em `3,7 V` e saída em `5,0 V`. Isso mostra a estratégia de elevar a tensão para alimentar a lógica do sistema.

### Estágio de potência

Os transistores `Q1`, `Q2`, `Q3` e `Q4` são `IRF640`. No contexto do projeto, esses MOSFETs atuam como chaveamento dos motores a partir dos sinais PWM do Arduino.

## Conexões relevantes observadas

No arquivo da placa aparecem as seguintes redes de controle:

- `PWM_D6`
- `PWM_D9`
- `PWM_D10`
- `PWM_D11`
- `SCL`
- `SDA`
- `RXD`
- `TXD`

Isso está alinhado com a lógica documentada no firmware:

- quatro saídas PWM para os motores;
- linhas de comunicação serial para o Bluetooth;
- barramento I2C para o módulo sensor.

## Imagens da eletrônica

<p align="center">
  <img width="700" alt="Esquema elétrico" src="Images/Esquema_Eletrico.png"><br/>
  Esquema elétrico do projeto.
</p>

<p align="center">
  <img width="700" alt="Blueprint da PCB" src="Images/PCB_Blueprint.png"><br/>
  Blueprint da placa desenvolvido no KiCad.
</p>

<p align="center">
  <img width="700" alt="Face frontal da PCB" src="Images/PCB_Front.jpg"><br/>
  Face frontal da placa.
</p>

<p align="center">
  <img width="700" alt="Face traseira da PCB" src="Images/PCB_Back.jpg"><br/>
  Face traseira da placa.
</p>

<p align="center">
  <img width="700" alt="PCB isolada" src="Images/PCB_Only.jpg"><br/>
  Vista da placa fora do conjunto.
</p>

## Papel da PCB no projeto

A placa organiza em um único conjunto:

- o controlador principal;
- os módulos auxiliares;
- a distribuição da alimentação;
- o estágio de chaveamento dos motores.

Isso melhora a montagem, reduz ligações soltas e deixa o protótipo mais próximo de um sistema embarcado completo.

## Leitura recomendada

- [Visão geral do projeto](Projeto.md)
- [Firmware e lógica de controle no Arduino](Arduino_Reference.md)
- [Aplicativo Android](App_Reference.md)

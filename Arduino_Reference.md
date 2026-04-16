# Firmware E Lógica De Controle No Arduino

## Visão geral

Os arquivos da pasta `Arduino/` registram a base do firmware utilizado para o controle dos motores do drone. O código está organizado como um conjunto de trechos que mostram a estrutura do projeto, a definição dos pinos, a comunicação Bluetooth e as funções de movimento.

## Arquivos disponíveis

- `Arduino/Drone_codigo.ino`: definições principais, variáveis e comunicação serial por software.
- `Arduino/Drone_codigo_functions.ino`: funções de acionamento dos motores.
- `Arduino/Drone_codigo_comments.ino`: descrição textual dos comandos previstos.
- `Arduino/Drone_codigo_base.ino`: estrutura vazia de `setup()` e `loop()`.

## Base eletrônica controlada pelo firmware

Pelos arquivos do projeto, o Arduino Nano atua como controlador principal do sistema. O firmware foi pensado para:

- receber comandos de um smartphone;
- interpretar esses comandos por Bluetooth;
- gerar sinais PWM para quatro motores;
- preparar a lógica para controle de movimentação básica.

## Mapeamento dos motores

No arquivo `Drone_codigo.ino`, os motores são associados aos seguintes pinos PWM:

- `motor_frente_dir`: pino `6`
- `motor_traz_dir`: pino `9`
- `motor_frente_esq`: pino `10`
- `motor_traz_esq`: pino `11`

Também foi declarada a interface Bluetooth com:

- `SoftwareSerial HC_06(2,3);`

Isso indica a intenção de usar o módulo HC-06 nos pinos digitais `2` e `3`.

## Variáveis de velocidade

O código separa a intensidade dos movimentos por tipo de ação:

- `vel_subir`
- `vel_descer`
- `vel_xy`
- `vel_giro`

Essa divisão simplifica o ajuste da potência aplicada aos motores em cada situação.

## Funções implementadas

As funções presentes em `Drone_codigo_functions.ino` representam os movimentos básicos do drone:

- `start()`: liga todos os motores com potência fixa inicial.
- `stop()`: desliga todos os motores.
- `subir()`: aplica a mesma potência de subida aos quatro motores.
- `descer()`: aplica a mesma potência de descida aos quatro motores.
- `frente()`: aumenta a potência dos motores traseiros.
- `traz()`: aumenta a potência dos motores dianteiros.
- `direita()`: aumenta a potência dos motores da esquerda.
- `esquerda()`: aumenta a potência dos motores da direita.
- `girar_horario()`: altera dois motores para rotação no sentido horário.
- `girar_anti_horario()`: altera dois motores para rotação no sentido anti-horário.

## Lógica documentada nos comentários

O arquivo `Drone_codigo_comments.ino` resume os seis blocos de comportamento previstos:

1. ligar todos os motores em velocidade pré-definida;
2. desligar todos os motores;
3. subir;
4. descer;
5. movimentação horizontal nos eixos `X` e `Y`;
6. movimentação rotativa.

## Escopo do que está no repositório

Os arquivos disponíveis representam a base do algoritmo e a divisão das funções principais. O repositório não contém, de forma completa nesse diretório, uma versão final consolidada com toda a lógica de leitura Bluetooth, estabilização por sensor e integração final em `setup()` e `loop()`.

Ainda assim, a documentação é útil para entender a arquitetura pensada:

- um comando vindo do app;
- a interpretação desse comando no Arduino;
- a seleção da função de movimento;
- o ajuste da potência dos motores via PWM.

## Relação com o hardware

O firmware conversa diretamente com a eletrônica descrita em [KicadSchemePCB_Reference.md](KicadSchemePCB_Reference.md):

- os sinais PWM saem do Arduino Nano;
- esses sinais acionam os MOSFETs da placa;
- os MOSFETs controlam a alimentação dos motores;
- o HC-06 recebe os comandos do aplicativo;
- o giroscópio foi previsto como fonte de dados para evolução do controle.

## Leitura recomendada

- [Visão geral do projeto](Projeto.md)
- [Esquema elétrico e PCB no KiCad](KicadSchemePCB_Reference.md)
- [Aplicativo Android](App_Reference.md)

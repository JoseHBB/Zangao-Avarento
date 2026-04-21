# Firmware E Lógica De Controle No Arduino

## Visão geral

Os arquivos da pasta `Arduino/` registram a base do firmware utilizado para o controle dos motores do drone. O código está organizado como um conjunto de trechos que mostram a estrutura do projeto, a definição dos pinos, a comunicação Bluetooth e as funções de movimento.

## Arquivos disponíveis

- `Arduino/Drone_codigo.ino`: definições principais, variáveis e comunicação serial por software.
- `Arduino/Drone_codigo_functions.ino`: funções de acionamento dos motores.
- `Arduino/Drone_codigo_comments.ino`: descrição textual dos comandos previstos.
- `Arduino/Drone_codigo_base.ino`: `setup()` e `loop()` com leitura Bluetooth e despacho de comandos.

Com a atualização mais recente do repositório, os quatro arquivos acima agora representam o fluxo completo da lógica de controle usada nos testes do projeto.

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

Também aparecem variáveis de estado para controlar o comportamento geral:

- `stoped`: flag de estado para indicar se o sistema está parado.
- `vel_atual`: referência da velocidade atual aplicada ao conjunto.
- `vel_parado` e `vel_start`: base para manter rotação mínima e partida.

## Fluxo de execução do firmware

O funcionamento foi dividido em um fluxo simples e direto:

1. `setup()`
2. inicializa serial USB (`Serial.begin(9600)`)
3. inicializa serial Bluetooth (`HC_06.begin(9600)`)
4. inicializa MPU-6050 (`start_gyro()`)

No `loop()` o código repete o ciclo:

1. faz leitura do sensor (`read_gyro()`)
2. espera um comando Bluetooth chegar (`HC_06.available()`)
3. converte o comando recebido para inteiro (`parseInt()`)
4. usa `switch` para disparar a ação correspondente
5. se o comando não estiver mapeado, executa `parado_no_ar()`

Esse formato deixa o firmware orientado a comando remoto: cada número recebido representa uma função de controle de atitude/movimento.

## Mapeamento de comandos Bluetooth

No `switch` de `Drone_codigo_base.ino`, os códigos são:

- `100`: `start()`
- `101`: `stop()`
- `102`: `subir()`
- `103`: `descer()`
- `104`: `frente()`
- `105`: `traz()`
- `106`: `direita()`
- `107`: `esquerda()`
- `108`: `girar_horario()`
- `109`: `girar_anti_horario()`

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

Na prática, os movimentos são obtidos por diferença de PWM entre pares de motores:

- subida/descida: alteração conjunta dos quatro motores;
- translação horizontal: aumenta dois motores e reduz os opostos;
- guinada (yaw): aumenta motores de uma diagonal e reduz os da diagonal contrária.

Esse método é consistente com o comportamento esperado de um quadricóptero em configuração de quatro rotores com controle diferencial de empuxo.

## Leitura do giroscópio/acelerômetro

As funções de sensor já estão presentes no código:

- `start_gyro()`: inicia o MPU-6050 e define faixas de medição/filtro.
- `read_gyro()`: captura aceleração (`a`), rotação (`g`) e temperatura (`temp`).

Mesmo sem malha de controle fechada implementada nesta versão, essa base já prepara o firmware para evolução com estabilização automática e correção por realimentação.

## Lógica documentada nos comentários

O arquivo `Drone_codigo_comments.ino` resume os seis blocos de comportamento previstos:

1. ligar todos os motores em velocidade pré-definida;
2. desligar todos os motores;
3. subir;
4. descer;
5. movimentação horizontal nos eixos `X` e `Y`;
6. movimentação rotativa.

## Escopo do que está no repositório

Os arquivos disponíveis representam a implementação funcional de controle por comandos Bluetooth e organização da lógica por funções de voo/movimento. A parte de estabilização por sensor ainda aparece como base de leitura e preparação da arquitetura.

A documentação é útil para entender a arquitetura adotada:

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

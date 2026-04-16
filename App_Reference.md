# Aplicativo Android

## Visão geral

O controle do Zangão Avarento foi pensado para ser feito por smartphone, mantendo o projeto alinhado com a proposta de baixo custo. Em vez de um rádio controle dedicado, o grupo utilizou comunicação Bluetooth entre o celular e o sistema embarcado.

## Arquivos disponíveis

Na pasta `App/` existem dois artefatos:

- `App/Controlador_de_motor_via_BT.aia`: projeto editável do MIT App Inventor.
- `App/Controlador_de_motor_via_BT.apk`: aplicativo Android compilado para instalação.

## Função do aplicativo no projeto

O aplicativo atua como interface do usuário para enviar comandos ao Arduino por meio do módulo HC-06. Dentro da arquitetura do projeto, ele cumpre três papéis:

- oferecer um meio simples de controle;
- substituir um controle remoto dedicado;
- demonstrar integração entre software mobile e sistema embarcado.

## Tecnologia utilizada

O desenvolvimento foi feito no MIT App Inventor, uma plataforma visual bastante adequada para protótipos educacionais e experimentais. Isso combina com a proposta do TCC porque reduz a barreira de desenvolvimento do lado mobile e acelera a criação da interface.

## Relação com o firmware

O app depende da lógica descrita em [Arduino_Reference.md](Arduino_Reference.md):

- o celular envia comandos;
- o módulo Bluetooth HC-06 recebe esses dados;
- o Arduino interpreta a informação recebida;
- o firmware ajusta os motores conforme a ação desejada.

## Relação com a eletrônica

No projeto eletrônico documentado em [KicadSchemePCB_Reference.md](KicadSchemePCB_Reference.md), o módulo Bluetooth identificado é o `HC-06`. Isso confirma que a aplicação Android foi pensada especificamente para controle sem fio via Bluetooth serial.

## Observação sobre edição

O arquivo `.aia` é o ponto de partida para estudar ou alterar o aplicativo. O `.apk` é útil para instalação e demonstração, mas não substitui o arquivo-fonte do App Inventor.

## Leitura recomendada

- [Visão geral do projeto](Projeto.md)
- [Firmware e lógica de controle no Arduino](Arduino_Reference.md)
- [Arquivos e recursos do repositório](Arquivos_e_Recursos.md)

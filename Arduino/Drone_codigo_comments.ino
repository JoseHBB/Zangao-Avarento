/*
1. Liga todos os motores em uma velocidade pré definida.
2. Desliga todos os motores.
3. Faz o drone subir colocando os motores em uma velocidade fixa.
4. Faz o drone descer colocando os motores em uma velocidade fixa.
5. Movimentação horizontal do drone, aumentando a potência de dois motores fazemos com que o drone se movimente horizontalmente em 4 direções diferentes(eixo X e Y).
6. Movimentação rotativa do drone, aumentando a potência dos dois motores que giram em sentido horário fazemos o drone girar em sentido horário e a mesma coisa acontece com os motores que giram em sentido anti-horário.
7. Inicia o serial bluetooth.
8. Escreve o serial do HC_06 no monitor serial.
9. Inicia e configura o gyroscópio.
10. Faz a leitura dos valores do gyroscópio e armazena os valores em suas variáveis.
    Os valores ficam nas váriaveis: a.acceleration.x - a.acceleration.y - a.acceleration.z - g.gyro.x - g.gyro.y - g.gyro.z - temp.temperature | m/s^2 - rad/s - degC
11. Altera a velocidade do drone para mante-lo estavel.
12.
13.
*/ 
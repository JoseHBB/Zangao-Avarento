void setup() {
  Serial.begin(9600);
  HC_06.begin(9600); //comm. 7
  start_gyro();
}

void loop() {
  read_gyro();
  /*
  if (HC_06.available() > 0) { //comm. 8
    Serial.write(HC_06.read());
  }
  */  
  while (HC_06.available()==0){}
  read = HC_06.parseInt();
  switch (read){
    case 100:
    start();
    break;
    case 101:
    stop();
    break;
    case 102:
    subir();
    break;
    case 103:
    descer();
    break;
    case 104:
    frente();
    break;
    case 105:
    traz();
    break;
    case 106:
    direita();
    break;
    case 107:
    esquerda();
    break;
    case 108:
    girar_horario();
    break;
    case 109:
    girar_anti_horario();
    break;
    default:
    parado_no_ar(); 
    break;
  }  

}
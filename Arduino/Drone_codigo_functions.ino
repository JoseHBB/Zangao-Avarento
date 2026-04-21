void parado_no_ar(){ //comm. 11
  for (vel_atual; vel_atual > vel_parado; vel_atual--) {
    analogWrite(motor_frente_dir, vel_atual); 
    analogWrite(motor_frente_esq, vel_atual);
    analogWrite(motor_traz_dir, vel_atual);
    analogWrite(motor_traz_esq, vel_atual);
    }
  for (vel_atual; vel_atual < vel_parado; vel_atual++) {
    analogWrite(motor_frente_dir, vel_atual); 
    analogWrite(motor_frente_esq, vel_atual);
    analogWrite(motor_traz_dir, vel_atual);
    analogWrite(motor_traz_esq, vel_atual);
    }
}

void start(){ //comm. 1
    if (stoped = 1) {
      for (vel_start; vel_start < 100; vel_start++){
      analogWrite(motor_frente_dir, vel_start); 
      analogWrite(motor_frente_esq, vel_start);
      analogWrite(motor_traz_dir, vel_start);
      analogWrite(motor_traz_esq, vel_start);
      }
    stoped = 0;
    vel_atual = vel_start;
    }
}

void stop(){ //comm. 2
    analogWrite(motor_frente_dir, 0); 
    analogWrite(motor_frente_esq, 0);
    analogWrite(motor_traz_dir, 0);
    analogWrite(motor_traz_esq, 0);
    stoped = 1;
}

void subir(){ //comm. 3
    for (vel_subir; vel_subir < 220; vel_subir++){
    analogWrite(motor_frente_dir, vel_subir); 
    analogWrite(motor_frente_esq, vel_subir);
    analogWrite(motor_traz_dir, vel_subir);
    analogWrite(motor_traz_esq, vel_subir);
    }
  vel_atual = vel_subir;
}

void descer(){ //comm. 4
    for (vel_descer; vel_descer < 220; vel_descer--){
    analogWrite(motor_frente_dir, vel_descer);
    analogWrite(motor_frente_esq, vel_descer);
    analogWrite(motor_traz_dir, vel_descer);
    analogWrite(motor_traz_esq, vel_descer);
    }
  vel_atual = vel_descer;
}

void frente(){ //comm. 5
    for (vel_xy; vel_xy < 25; vel_xy++){
    analogWrite(motor_traz_dir, vel_parado+vel_xy);
    analogWrite(motor_traz_esq, vel_parado+vel_xy);
    analogWrite(motor_frente_dir, vel_parado-vel_xy);
    analogWrite(motor_frente_esq, vel_parado-vel_xy);
    }
  vel_atual = vel_xy;
}

void traz(){ //comm. 5
    for (vel_xy; vel_xy < 25; vel_xy++){
    analogWrite(motor_frente_dir, vel_parado+vel_xy);
    analogWrite(motor_frente_esq, vel_parado+vel_xy);
    analogWrite(motor_traz_dir, vel_parado-vel_xy);
    analogWrite(motor_traz_esq, vel_parado-vel_xy);
    }
  vel_atual = vel_xy;
}

void direita(){ //comm. 5
    for (vel_xy; vel_xy < 25; vel_xy++){
    analogWrite(motor_frente_esq, vel_parado+vel_xy);
    analogWrite(motor_traz_esq, vel_parado+vel_xy);
    analogWrite(motor_frente_dir, vel_parado-vel_xy);
    analogWrite(motor_traz_dir, vel_parado-vel_xy);
    }
  vel_atual = vel_xy;
}

void esquerda(){ //comm. 5
    for (vel_xy; vel_xy < 25; vel_xy++){
    analogWrite(motor_frente_dir, vel_parado+vel_xy);
    analogWrite(motor_traz_dir, vel_parado+vel_xy);
    analogWrite(motor_frente_esq, vel_parado-vel_xy);
    analogWrite(motor_traz_esq, vel_parado-vel_xy);
    }
  vel_atual = vel_xy;
}

void girar_horario(){ //comm. 6
    for (vel_giro; vel_giro < 25; vel_giro++){
    analogWrite(motor_frente_esq, vel_parado+vel_giro);
    analogWrite(motor_traz_dir, vel_parado+vel_giro);
    analogWrite(motor_frente_dir, vel_parado-vel_giro);
    analogWrite(motor_traz_esq, vel_parado-vel_giro);
    }
  vel_atual = vel_giro;
}

void girar_anti_horario(){ //comm. 6
    for (vel_giro; vel_giro < 25; vel_giro++){
    analogWrite(motor_frente_dir, vel_parado+vel_giro);
    analogWrite(motor_traz_esq, vel_parado+vel_giro);
    analogWrite(motor_frente_esq, vel_parado-vel_giro);
    analogWrite(motor_traz_dir, vel_parado-vel_giro);
    }
  vel_atual = vel_giro;
}

void start_gyro(){ //comm. 9
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void read_gyro(){ //comm. 10
  sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);
}
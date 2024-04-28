void start(){ //comm. 1
    analogWrite(motor_frente_dir, 100); 
    analogWrite(motor_frente_esq, 100);
    analogWrite(motor_traz_dir, 100);
    analogWrite(motor_traz_esq, 100);
}

void stop(){ //comm. 2
    analogWrite(motor_frente_dir, 0); 
    analogWrite(motor_frente_esq, 0);
    analogWrite(motor_traz_dir, 0);
    analogWrite(motor_traz_esq, 0);
}

void subir(){ //comm. 3
    analogWrite(motor_frente_dir, vel_subir);
    analogWrite(motor_frente_esq, vel_subir);
    analogWrite(motor_traz_dir, vel_subir);
    analogWrite(motor_traz_esq, vel_subir);
}

void descer(){ //comm. 4
    analogWrite(motor_frente_dir, vel_descer);
    analogWrite(motor_frente_esq, vel_descer);
    analogWrite(motor_traz_dir, vel_descer);
    analogWrite(motor_traz_esq, vel_descer);
}

void frente(){ //comm. 5
    analogWrite(motor_traz_dir, vel_xy);
    analogWrite(motor_traz_esq, vel_xy);
}

void traz(){ //comm. 5
    analogWrite(motor_frente_dir, vel_xy);
    analogWrite(motor_frente_esq, vel_xy);
}

void direita(){ //comm. 5
    analogWrite(motor_frente_esq, vel_xy);
    analogWrite(motor_traz_esq, vel_xy);
}

void esquerda(){ //comm. 5
    analogWrite(motor_frente_dir, vel_xy);
    analogWrite(motor_traz_dir, vel_xy);
}

void girar_horario(){ //comm. 6
    analogWrite(motor_frente_esq, vel_giro);
    analogWrite(motor_traz_dir, vel_giro);
}

void girar_anti_horario(){ //comm. 6
    analogWrite(motor_frente_dir, vel_giro);
    analogWrite(motor_traz_esq, vel_giro);
}
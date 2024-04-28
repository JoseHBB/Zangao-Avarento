#include <SoftwareSerial.h>

#define motor_frente_dir 6
#define motor_traz_dir 9
#define motor_frente_esq 10
#define motor_traz_esq 11

SoftwareSerial HC_06(2,3);

int read;
int vel_subir;
int vel_descer; 
int vel_xy;
int vel_giro;
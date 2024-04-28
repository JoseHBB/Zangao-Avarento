#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

SoftwareSerial HC_06(3,2);

Adafruit_MPU6050 mpu;

#define motor_frente_dir 6
#define motor_traz_dir 9
#define motor_frente_esq 10
#define motor_traz_esq 11

int read;
int stoped = 1;
int vel_atual;
int vel_parado;
int vel_start;
int vel_subir;
int vel_descer; 
int vel_xy;
int vel_giro;
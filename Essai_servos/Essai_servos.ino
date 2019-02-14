//Bibliothèques :
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Driver :
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//Servos :
#define SERVOMIN 105 //Longueur minimum d'impulsion
#define SERVOMAX 460 //Longueur maximum d'impulsion
#define NBSERVO 1    //Nombre de servos-1
#define PAUSE 10
uint8_t servonum = 0;
int pos = 0;
int consigne = 0;

void commandeServoMoteur(int numeroServo, int angle) {
  if(numeroServo == 0) {
    pwm.setPWM(0, 0, 2 * angle + 286);
  }
  else {
    pwm.setPWM(1, 0, 1.917 * angle + 302.5);
  }
}

void setup() 
{
  Serial.begin(9600);
  pwm.begin();

  pwm.setPWMFreq(50); //Fréquence utilisée par les servos analogiques

  yield();
}

void loop() 
{
  /*
  for (pos = SERVOMIN; pos <= SERVOMAX; pos++)
  //Rejoins un angle de 180° depuis 0° par pas de 1°
  {
    pwm.setPWM(servonum,0,pos);
    delay(PAUSE);
  }
  delay(2000);
  for (pos = SERVOMAX; pos >= SERVOMIN; pos--)
  //Rejoins un angle de 0° depuis 180° par pas de 1°
  {
    pwm.setPWM(servonum,0,pos);
    delay(PAUSE);
  }
  delay(2000);
  servonum++;
  if (servonum > NBSERVO) servonum = 0; 
  */

  // Servo 0
  // Coté gauche à -90° : 106
  // Coté droite à 90° : 466
  // Résolution : 0.5°

  // Servo 1
  // Coté gauche à -90° : 130
  // Coté droite à 90° : 475
  // Résolution : 0.5°
  /*
  for(int consigne=400 ; consigne <= 475 ; consigne += 5) {
    delay(500);
    pwm.setPWM(1, 0, consigne);
    Serial.println(consigne);
  }
  */
   
  
  for(int angle = -90 ; angle <= 90 ; angle += 5) {
    delay(500);
    commandeServoMoteur(1, angle);
  }
  
}



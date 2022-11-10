#include <PS4Controller.h>
#include "ESC.h"          

#define leftMotorPin 27
#define rightMotorPin 32
#define ledVermelho 13
#define ledAmarelo 12
//#define weaponMotorPin 34

#define SPEED_MIN (1000)  // Set the Minimum Speed in microseconds
#define SPEED_MAX (2000)  
#define SPEED_MED (1500)

ESC motorEsquerdo (leftMotorPin, SPEED_MIN, SPEED_MAX, 500); 
ESC motorDireito (rightMotorPin, SPEED_MIN, SPEED_MAX, 500);  
//ESC motorArma (weaponMotorPin, SPEED_MIN, SPEED_MAX, 500);  

int angle;
int lastState = 0;
int velocidade = 0;
int ve, vd, va;

void setup() {
  //PS4.begin("58:a0:23:33:d9:b0");
  PS4.begin("40:99:22:ce:af:c4");
  Serial.begin(115200);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);

  while(!PS4.isConnected()){
    Serial.println("Esperando Conexão");
    delay(250);
  }

  PS4.setLed(0,100,0); 
  PS4.sendToController();

  Serial.println ("Conexão Estabelecida");

  motorEsquerdo.arm();
  motorDireito.arm();
  //motorArma.arm();

}

void loop() {
  if(PS4.isConnected() == true){
    while(PS4.isConnected()){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, HIGH);
      int LStickY= PS4.LStickY();
      int LStickX= PS4.LStickX();
      
      //Serial.print("X: ");
      //Serial.print(LStickX);
      //Serial.print("       Y: ");
      //Serial.println (LStickY);
  
      if(abs(LStickY) > abs(LStickX)){
        //anda frente e tras
        if (LStickY>=30){
          ve = map(LStickY, 30, 127, SPEED_MED, SPEED_MAX);
          vd = map(LStickY, 30, 127, SPEED_MED, SPEED_MIN);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
        else if(LStickY<=-30){
          ve = map(LStickY, -30, -127, SPEED_MED, SPEED_MIN);
          vd = map(LStickY, -30, -127, SPEED_MED, SPEED_MAX);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
        
        else{
          motorEsquerdo.stop();
          motorDireito.stop();
        }
      
      }
  
      else if(abs(LStickY) < abs(LStickX)){
        //vira esquerda e direita
        if (LStickX>=30){
          ve = map(LStickX, 30, 127, SPEED_MED, SPEED_MAX);
          vd = map(LStickX, 30, 127, SPEED_MED, SPEED_MAX);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
        else if(LStickX<=-30){
          ve = map(LStickX, -30, -127, SPEED_MED, SPEED_MIN);
          vd = map(LStickX, -30, -127, SPEED_MED, SPEED_MIN);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
        
        else{
          motorEsquerdo.stop();
          motorDireito.stop();
        }
      
      }

      else if(PS4.Square()){
        motorDireito.speed(1600);
      }

      else if (PS4.Circle()){
        motorDireito.stop();
      }
  
      else{
        motorEsquerdo.stop();
        motorDireito.stop();
      }

      
  
    }
  }
    //Fail safe
  if(PS4.isConnected() == false){
    digitalWrite(ledVermelho, LOW);
    motorEsquerdo.speed(1500);
    motorDireito.speed(1500);
    motorEsquerdo.stop();
    motorDireito.stop();
    digitalWrite(ledAmarelo, LOW);
    //motorArma.stop();
    //Serial.println("Restart");
    setup();
    //delay(20);
  }
  


}

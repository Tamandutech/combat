#include <PS4Controller.h>
#include "ESC.h"          

#define leftMotorPin 27
#define rightMotorPin 33
#define ledVermelho 13
#define ledAmarelo 12
#define weaponMotorPin 32

int SPEED_MIN = 1300;  // Set the Minimum Speed in microseconds
int SPEED_MAX = 1700;
int SPEED_MED = 1500;

ESC motorEsquerdo (leftMotorPin, SPEED_MIN, SPEED_MAX, 500); 
ESC motorDireito (rightMotorPin, SPEED_MIN, SPEED_MAX, 500);  
ESC motorArma (weaponMotorPin, SPEED_MIN, SPEED_MAX, 500);  

int angle;
int lastState = 0;
int velocidade = 0;
int ve, vd, va;
int locMaxSpeed = 300;
int compensation = 0;

void setup() {
  //PS4.begin("58:a0:23:33:d9:b0");
  PS4.begin("40:99:22:ce:af:c4");
  Serial.begin(115200);

  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);

  motorDireito.stop();
  motorEsquerdo.stop();
  motorArma.stop();


  while(!PS4.isConnected()){
  //  Serial.println("Esperando Conexão");
    delay(250);
  }

  PS4.setLed(0,100,0); 
  PS4.sendToController();

  //Serial.println ("Conexão Estabelecida");
  
  motorEsquerdo.arm();
  motorDireito.arm();
  motorArma.arm();

}

void loop() {
  if(PS4.isConnected()){
      int LStickY= PS4.LStickY();
      int LStickX= PS4.LStickX();

      //Ajusta compensacao para andar reto
      if(PS4.L1()){
        if(compensation > -30){
          compensation -= 1;
          delay(500);
        }
      }
  
      if(PS4.R1()){
        if(compensation < 30){
          compensation += 1;
          delay(500);
        }
      }

      //Ajusta velocidade maxima
      if(PS4.R2()){
        if(SPEED_MAX < 2000 && SPEED_MIN > 1000){
          SPEED_MAX += 25;
          SPEED_MIN -= 25;
          delay(500);
        }
      }
  
      if(PS4.L2()){
        if(SPEED_MAX > 1525 && SPEED_MIN < 1475){
          SPEED_MAX -= 25;
          SPEED_MIN += 25;
          delay(500);
        }
      }

      //Teste inicio

      if (PS4.Up()){ //frente
          vd = SPEED_MAX+(compensation * 10);
          ve = SPEED_MIN;
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
        else if(PS4.Down()){ //re
          //vd = map(LStickY-compensation, -30, -127, SPEED_MED, SPEED_MIN);
          //ve = map(LStickY+compensation, -30, -127, SPEED_MED, SPEED_MAX);
          vd = SPEED_MIN;
          ve = SPEED_MAX+(compensation * 10);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
      
  
      else if(PS4.Right()){
          vd = SPEED_MAX;
          ve = SPEED_MAX;
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
      else if(PS4.Left()){
        vd = SPEED_MIN;
        ve = SPEED_MIN;

        motorEsquerdo.speed(ve);
        motorDireito.speed(vd);
      }
      //Fim Teste
  
      /*if(abs(LStickY) > abs(LStickX)){
        //anda frente e tras
        if (LStickY>=30){ //frente
          //vd = map(LStickY+compensation, 30, 127, SPEED_MED, SPEED_MAX);
          //ve = map(LStickY-compensation, 30, 127, SPEED_MED, SPEED_MIN);
          vd = map(LStickY, 30, 127, SPEED_MED, SPEED_MAX+(compensation * 10));
          ve = map(LStickY, 30, 127, SPEED_MED, SPEED_MIN);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
        else if(LStickY<=-30){ //re
          //vd = map(LStickY-compensation, -30, -127, SPEED_MED, SPEED_MIN);
          //ve = map(LStickY+compensation, -30, -127, SPEED_MED, SPEED_MAX);
          vd = map(LStickY-compensation, -30, -127, SPEED_MED, SPEED_MIN);
          ve = map(LStickY+compensation, -30, -127, SPEED_MED, SPEED_MAX+(compensation * 10));
  
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
          vd = map(LStickX, 30, 127, SPEED_MED, SPEED_MAX);
          ve = map(LStickX, 30, 127, SPEED_MED, SPEED_MAX);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
  
        else if(LStickX<=-30){
          vd = map(LStickX, -30, -127, SPEED_MED, SPEED_MIN);
          ve = map(LStickX, -30, -127, SPEED_MED, SPEED_MIN);
  
          motorEsquerdo.speed(ve);
          motorDireito.speed(vd);
        }
        
        else{
          motorEsquerdo.stop();
          motorDireito.stop();
        }
      
      }*/
  
      else{
        motorEsquerdo.stop();
        motorDireito.stop();
      }

      if(PS4.Square()){
        motorArma.speed(1400);
      }

      else if (PS4.Triangle()){
        motorArma.speed(1200);
      }

       else if (PS4.Circle()){
        motorArma.speed(1000);
      }

      else if (PS4.Cross()){
        motorArma.stop();
      }

  }
    //Fail safe
  else{
    motorEsquerdo.speed(1500);
    motorDireito.speed(1500);
    motorArma.speed(1500);
    delay(500);
    motorEsquerdo.stop();
    motorDireito.stop();
    motorArma.stop();
    delay(500);
    //Serial.println("Restart");
    setup();
  }
  


}

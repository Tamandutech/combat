#include <PS4Controller.h>
#include "ESC.h"          

//Definindo as portas:
//Definindo as portas:
# define A1 12
# define A2 13
# define B1 25
# define B2 33
# define C1 02
# define C2 04
# define D1 18
# define D2 19


int angle;
int lastState = 0;
int velocidade = 0;
int VA, VB, VC;
int locMaxSpeed = 300;

void setup() {
  PS4.begin("08:a6:f7:0d:f0:ec"); //endereço controle verde
  
  Serial.begin(115200);

    pinMode(A1,OUTPUT);//motor locomoção
    pinMode(A2,OUTPUT);
    pinMode(B1,OUTPUT);//motor locomoção
    pinMode(B2,OUTPUT);
    pinMode(C1,OUTPUT);//motor arma
    pinMode(C2,OUTPUT);
    pinMode(D1,OUTPUT);//motor arma
    pinMode(D2,OUTPUT);
    digitalWrite(A1,0);
    digitalWrite(A2,0);
    digitalWrite(B1,0);
    digitalWrite(B2,0);
    digitalWrite(C1,0);
    digitalWrite(C2,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);


  while(!PS4.isConnected()){
   Serial.println("Esperando Conexão");
    delay(250);
  }

  PS4.setLed(0,100,0); // deixa o led verd
  PS4.sendToController();

  Serial.println ("Conexão Estabelecida");
  
   digitalWrite(A1,0);
    digitalWrite(A2,0);
    digitalWrite(B1,0);
    digitalWrite(B2,0);
    digitalWrite(C1,0);
    digitalWrite(C2,0);
    digitalWrite(C1,0);
    digitalWrite(C2,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);

}

void loop() {
  if(PS4.isConnected()){
      int LStickY= PS4.LStickY();
      int LStickX= PS4.LStickX();

     if(abs(LStickY) > abs(LStickX)){
        //anda frente e tras
        if (LStickY>=30){ //frente
         
          VA = map(LStickY, 30, 127, 0, 255);
          VB = map(LStickY, 30, 127, 0, 255);
        
         digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);

         digitalWrite(A1,0);
         digitalWrite(A2,VA);
         digitalWrite(B1,VB);
         digitalWrite(B2,0);
         digitalWrite(C1,0);
         digitalWrite(C2,0);
         Serial.println(VA);
         Serial.println(VB);

         Serial.println(LStickY);
         
         
        }
  
        else if(LStickY<=-30){ //trás
          VA = map(LStickY, 30, 127, 0, 255);
          VB = map(LStickY, 30, 127, 0, 255);
          
         digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);


         digitalWrite(A1,VA);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,VB);
       

          Serial.println(VA);
         Serial.println(VB);
         Serial.println(LStickY);
        }
        
        else{
          digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);
         
        }
      
      }
  
      else if(abs(LStickY) < abs(LStickX)){
        //vira esquerda e direita
        if (LStickX>=30){
        VA = map(LStickX, 30, 127, 0, 255);
          VB = map(LStickX, 30, 127, 0, 255);
        
         digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);

         digitalWrite(A1,0);
         digitalWrite(A2,VA);
         digitalWrite(B1,0);
         digitalWrite(B2,VB);
         
          Serial.println(VA);
         Serial.println(VB);
         Serial.println(LStickY);
        }
  
        else if(LStickX<=-30){
           VA = map(LStickX, 30, 127, 0, 255);
          VB = map(LStickX, 30, 127, 0, 255);
                 
         digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);

         digitalWrite(A1,VA);
         digitalWrite(A2,0);
         digitalWrite(B1,VB);
         digitalWrite(B2,0);

          Serial.println(VA);
         Serial.println(VB);
        }
        
        else{
          digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);
        }
      
      }
      
      if(PS4.Square()){//liga o motor arma e um sentido
        digitalWrite(C1,0);
         digitalWrite(C2,150);
         digitalWrite(D1,0);
         digitalWrite(D2,150);
      }

      else if (PS4.Triangle()){//liga o motor arma no outro sentido
       digitalWrite(C1,150);
         digitalWrite(C2,0);
         digitalWrite(D1,150);
         digitalWrite(D2,0);
      }

       else if (PS4.Circle()){//liga o motor arma mais rapido)
        digitalWrite(C1,255);
         digitalWrite(C2,0);
         digitalWrite(D1,255);
         digitalWrite(D2,0);
      }

      else if (PS4.Cross()){// para o motor arma
        digitalWrite(C1,0);
         digitalWrite(C2,0);
         digitalWrite(D1,0);
         digitalWrite(D2,0);
      }

  
      else{
        digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);
         digitalWrite(C1,0);
         digitalWrite(C2,0);
        
      }

  }
    //Fail safe
  else{
    digitalWrite(A1,0);
         digitalWrite(A2,0);
         digitalWrite(B1,0);
         digitalWrite(B2,0);
         digitalWrite(C1,0);
         digitalWrite(C2,0);
         digitalWrite(C1,0);
    digitalWrite(C2,0);
    digitalWrite(D1,0);
    digitalWrite(D2,0);
  
    delay(500);
    Serial.println("Restart");
    setup();
  }
  


}

#include <PS4Controller.h>        

//Definindo as portas:
# define A1 12
# define A2 13
# define B1 25
# define B2 33
# define C1 02
# define C2 04
# define D1 18
# define D2 19

void setup() {
  
  PS4.begin("0c:b8:15:f5:fe:2c");
  
  Serial.begin(115200);

    pinMode(A1,OUTPUT);//motor locomoção
    pinMode(A2,OUTPUT);
    pinMode(B1,OUTPUT);//motor locomoção
    pinMode(B2,OUTPUT);
    pinMode(C1,OUTPUT);//motor arma
    pinMode(C2,OUTPUT);
    pinMode(D1,OUTPUT);//motor arma
    pinMode(D2,OUTPUT);
    analogWrite(A1,0);
    analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

  while(!PS4.isConnected()){
   Serial.println("Esperando Conexão");
    delay(250);
  }

  PS4.setLed(0,100,0); // deixa o led verd
  PS4.sendToController();

  Serial.println ("Conexão Estabelecida");
  
       analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
}

void loop() {
  if(PS4.isConnected()){
      int LStickY= PS4.LStickY();
      int LStickX= PS4.LStickX();
      int RStickY= PS4.RStickY();
      int RStickX= PS4.RStickX();


     if(abs(LStickY) > abs(LStickX)){
        //anda frente e tras
        if (LStickY>=30){ //frente
         
          VA = map(LStickY, 30, 127, 0, 230);
          VB = map(LStickY, 30, 127, 0, 230);
        
             analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

        analogWrite(A1,0);
         analogWrite(A2,VA);
    analogWrite(B1,VB);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
         
         Serial.println(VA);
         Serial.println(VB);

         Serial.println(LStickY);
         
         
        }
  
        else if(LStickY<=-30){ //trás
          VA = map(LStickY, 30, 127, 0, 230);
          VB = map(LStickY, 30, 127, 0, 230);
          
            analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

        analogWrite(A1,VA);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,VB);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);


  

          Serial.println(VA);
         Serial.println(VB);
         Serial.println(LStickY);
        }
        
        else{
           analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
         
        }
      
      }
  
      else if(abs(LStickY) < abs(LStickX)){
        //vira esquerda e direita
        if (LStickX>=30){
        VA = map(LStickX, 30, 127, 0, 230);
          VB = map(LStickX, 30, 127, 0, 230);
        
             analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

    analogWrite(A1,0);
         analogWrite(A2,VA);
    analogWrite(B1,0);
    analogWrite(B2,VB);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
        
          Serial.println(VA);
         Serial.println(VB);
         Serial.println(LStickY);
        }
  
        else if(LStickX<=-30){
           VA = map(LStickX, 30, 127, 0, 230);
          VB = map(LStickX, 30, 127, 0, 230);
                 
             analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

        analogWrite(A1,VA);
         analogWrite(A2,0);
    analogWrite(B1,VB);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
        
          Serial.println(VA);
         Serial.println(VB);
        }
        
        else{
              analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
        }
      
      }
      
      if(abs(RStickY) > abs(RStickX)){
        //sobe ou desce a rampa
        if (RStickY>=30){ //sobe rampa
         
          VA3 = map(RStickY, 30, 127, 0, 50);
          VB4 = map(RStickY, 30, 127, 0, 50);
        
             analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

        analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,VA3);
    analogWrite(C2,0);
    analogWrite(D1,VB4);
    analogWrite(D2,0);

       
         Serial.println(VA3);
         Serial.println(VB4);

         Serial.println(RStickY);
         
         
        }
  
        else if(RStickY<=-30){ //desce rampa
          VA3 = map(RStickY, 30, 127, 0, 50);
          VB4 = map(RStickY, 30, 127, 0, 50);
          
             analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);

        analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,VA3);
    analogWrite(D1,VB4);
    analogWrite(D2,0);       

          Serial.println(VA3);
         Serial.println(VB4);
         Serial.println(RStickY);
        }
        
        else{
              analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
         
        }
      
      }
  
      else{
            analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
        
      }

      if(PS4.Square()){//liga o motor arma e um sentido(descer rampa)
        analogWrite(C1,0);
    analogWrite(C2,120);
    analogWrite(D1,120);
    analogWrite(D2,0);
       
      }

      else if (PS4.Triangle()){//liga o motor arma no outro sentido (subir rampa)
        analogWrite(C1,120);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,120);
       
      }

       else if (PS4.Circle()){//liga o motor arma mais rapido)

        analogWrite(C1,180);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,180);
 
      }

      else if (PS4.Cross()){// para o motor arma
       
        analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
    
      }

  }
    //Fail safe
  else{
           analogWrite(A1,0);
         analogWrite(A2,0);
    analogWrite(B1,0);
    analogWrite(B2,0);
    analogWrite(C1,0);
    analogWrite(C2,0);
    analogWrite(D1,0);
    analogWrite(D2,0);
    
    delay(500);
    Serial.println("Restart");
    setup();
  }
  


}

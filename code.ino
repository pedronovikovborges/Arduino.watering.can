/*
Desenvolvedor: Pedro José Duarte Novikov Borges
Projeto: Regador automático
O projeto simula uma detecção de umidade do solo.

-Se o percentual de umidade do solo é detectado igual ou
abaixo de 40%, a umidade é considerada baixa, acende o
led vermelho e o regador é acionado por 5 segundos.

-Se o percentual de umidade do solo é detectado igual ou
acima de 75%, a umidade é considerada alta, acende o
led verde e o regador não é acionado. Sistema aguarda
10 segundos para nova leitura.

-Caso nenhum dos casos acima aconteça, a umidade é
considerada média, acende o led amarelo e o regador é
acionado por apenas 3 segundos.
*/
#include <LiquidCrystal.h>
int i =0;
int j = 0;
int k = 0;
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7 ,OUTPUT);
  pinMode(6, OUTPUT);
  
  lcd.begin(16, 2);
 
}

void loop() {
  
  
float saida = analogRead(A1);
  
saida  = (saida/1023);
saida = saida* 100.;
 
  
  
     if ( saida <= 40) { 
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Umidade do Solo");  
     lcd.setCursor(0,1);
     lcd.print(saida);
     lcd.print("% Baixa  ");
     digitalWrite(10,HIGH);
     digitalWrite(9,LOW);
     digitalWrite(8,LOW);
     delay (3000);
  
// ligar agua 
    
         for (i = 3; i >= 1; i -= 1) {
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("Ativando regador");
           lcd.setCursor(0,1);
           lcd.println(i);
           delay(1000);
         }
       
// regar 
       
         for (i = 5; i >= 0; i -= 1) {
   
           digitalWrite(7,HIGH);
           lcd.setCursor(0,0);
           lcd.print("Regando as Plantas");
           lcd.setCursor(0,1);
           lcd.println(i);
           delay(1000);
         }
       
         
         digitalWrite(7,LOW); 
    
  
        for (k = 3; k >= 0; k -= 1) {
          
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Nova Leitura");
          lcd.setCursor(0,1);
          lcd.println(k);
          digitalWrite(10, HIGH);
          delay(700); 
          digitalWrite(10, LOW);
          delay(300); 
           
        }
       
     }

  
     if ( saida > 40 && saida <= 75) { 
       
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Umidade do Solo");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% Media  ");
       digitalWrite(10,LOW);
       digitalWrite(9,HIGH);
       digitalWrite(8,LOW);
       delay (3000);
       
// ligar agua
       
       lcd.clear();
    
       for (i = 3; i >= 1; i -= 1) {
    
         lcd.setCursor(0,0);
         lcd.print("Ativando regador");
         lcd.setCursor(0,1);
         lcd.println(i);
         delay(1000); 
      }
       
// regar 
       
       for (i = 3; i >= 0; i -= 1) {
   
         digitalWrite(7,HIGH);
         lcd.setCursor(0,0);
         lcd.print("Regando as Plantas");
         lcd.setCursor(0,1);
         lcd.println(i);
         delay(1000); 
       }
       
       
       digitalWrite(7,LOW); 
    
       for (k = 3; k >= 0; k -= 1) {
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("Nova Leitura");
         lcd.setCursor(0,1);
         lcd.println(k);
         digitalWrite(9, HIGH);
         delay(700); 
         digitalWrite(9, LOW);
         delay(300); 
         
       }  
    
    
     }
  
     if ( saida > 75) { 
       
       lcd.clear();  
       lcd.setCursor(0,0);
       lcd.print("Umidade do Solo");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% Alta  ");
       digitalWrite(8,HIGH);
       digitalWrite(9,LOW);
       digitalWrite(10,LOW);
       delay(3000);  
       digitalWrite(10,LOW);
       digitalWrite(9,LOW);
       digitalWrite(8,LOW);
    
//piscar led azul     
       
        for (j = 10; j >= 0; j -= 1) {
    
          
          lcd.clear(); 
          lcd.setCursor(0,0);
          lcd.print("Aguardando");
          lcd.setCursor(0,1);
          lcd.println(j);
          digitalWrite(6, HIGH);
          delay(700);
          digitalWrite(6, LOW);
          delay(300); 
         
       }
    
     }
  
}
  







  

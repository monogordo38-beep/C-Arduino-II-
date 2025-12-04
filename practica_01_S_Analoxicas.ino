/*

Documentación simple do programa (Práctica 2 II)
Autor: Brais Gude Martínez
Data: 02/12/2025
  
  Descrición: Este programa solicita ao usuario unha cor e un tempo a través do porto serie.
  Activa o LED correspondente nos pins 13 a 8 durante o tempo indicado.
  Xestiona erros se a cor non é válida.

*/

String cor = "";
float Tempo = -999.;
int pin = -99;

void setup() {
  Serial.begin(9600);
  // Configuración de Pins a usar no loop.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  
}

void loop(){
  Serial.println("Dime a cor do LED que queres acender (azul, amarelo, branco, vermello, laranxa, verde):");
  while(Serial.available() == 0) {} //Espera ata que haxa algo no Buffer
  cor = Serial.readString();
  Serial.println("Dime cantos segundos debe estar ON ou OFF");
  while(Serial.available() == 0) {} //Espera ata que haxa algo no Buffer
  Tempo = 1000 * Serial.parseFloat(); //Convertimos segundos a milisegundos
  
  if (cor == "verde")         {pin = 5;} //Lóxica para a selección das cores.
  else if (cor == "laranxa")  {pin = 3;}
  else if (cor == "amarelo")  {pin = 10;}
  else if (cor == "azul")     {pin = 11;}
  else if (cor == "vermello") {pin = 6;}
  else if (cor == "branco")   {pin = 9;}
  else                        {pin = -99;}
  
  switch (pin) { //Actuación en pin dixital con apagado e acendido.
    case 5: 
    digitalWrite(5, HIGH);
    delay(Tempo);
    digitalWrite(5, LOW);
    delay(Tempo);
    break; 
    
    case 3:
    digitalWrite(3, HIGH); //Actuación en pin dixital con apagado e acendido.
    delay(Tempo);
    digitalWrite(3, LOW);
    delay(Tempo);
    break;
    
    case 10:
      for(int i = 0; i < 256; i++){ //Actuación en pin analóxico PWM (acendido).
        analogWrite(10, i);
        delay(Tempo/256); 
      }
      for(int i = 255; i >= 0; i--){ //Actuación en pin analóxico PWM (apagado).
        analogWrite(10, i);
        delay(Tempo/256); 
      }
    break;
    
    case 11:
       for(int i = 0; i < 256; i++){ //Actuación en pin analóxico PWM (acendido).
        analogWrite(11, i);
        delay(Tempo/256); 
      }
      for(int i = 255; i >= 0; i--){ //Actuación en pin analóxico PWM (apagado).
        analogWrite(11, i);
        delay(Tempo/256); 
      }
    break;
    
    case 6:
       for(int i = 0; i < 256; i++){ //Actuación en pin analóxico PWM (acendido).
        analogWrite(6, i);
        delay(Tempo/256); 
      }
      for(int i = 255; i >= 0; i--){ //Actuación en pin analóxico PWM (apagado).
        analogWrite(6, i);
        delay(Tempo/256); 
      }
    break;
    
    case 9:
       for(int i = 0; i < 256; i++){ //Actuación en pin analóxico PWM (acendido).
        analogWrite(9, i);
        delay(Tempo/256); 
      }
      for(int i = 255; i >= 0; i--){ //Actuación en pin analóxico PWM (apagado).
        analogWrite(9, i);
        delay(Tempo/256); 
      }
    break;
    
    default: 
      Serial.println("A cor que me indicaches non existe"); //Xestión de erros.
      Serial.println("Escoller outra cor");
    break;  
   }
  
}
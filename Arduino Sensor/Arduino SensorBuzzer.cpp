//Configuração de Distancia Mínima em centimetros
const int distancia_carro = 10; 

//Sensor
const int TRIG = 3;
const int ECHO = 2;

const int ledGreen = 7;
const int ledRed = 8;
const int buzzer = 9;

// Variaveis para funcionamento do Buzzer
float seno;
int frequencia;

void setup() {
  Serial.begin(9600);
  
  //Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  //LED
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  //Buzzer
  pinMode(buzzer, OUTPUT); 
  
}
void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);

    if(distancia <= distancia_carro){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer();
    }
    else{
      Serial.print("Livre: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    }
  delay(100);
  
}
int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}
void tocaBuzzer(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 2000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}

}
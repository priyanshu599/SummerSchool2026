//one LED will blink once

int LED1=1;
int LED2=2;
int LED3=3;
int LED4=4;

/*(void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
 }
*/

//one LED will blink once
/*void loop()
{
  digitalWrite(LED1, HIGH);
  delay(100); 
  digitalWrite(LED1, LOW);
  delay(100); 
  
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100); 
  
  digitalWrite(LED3, HIGH);
  delay(100); 
  digitalWrite(LED3, LOW);
  delay(100);
  
  digitalWrite(LED4, HIGH);
  delay(100);
  digitalWrite(LED4, LOW);
  delay(100);
}
*/
//Random led will blink
int leds[]= {1,2,3,4};

void setup(){
  for (int i=0;i<4;i++){
    pinMode(leds[i],OUTPUT);
  }
  randomSeed(analogRead(A0));
}

void loop(){
  int count= random(0,4);
  for(int i=0;i<count;i++){
    digitalWrite(leds[random(0,4)],HIGH);
  }
  delay(random(50, 200));
  
  for(int i=0;i<4;i++){
    digitalWrite(leds[i],LOW);
  }
  delay(random(50, 200));
}
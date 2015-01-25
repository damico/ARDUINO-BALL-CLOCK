/* Ball Bearing Time Machine Clock, controlled by Arduino		*/
/* Author: Jose Ricardo de Oliveira Damico <jd.comment@gmail.com>	*/

int inPin = 12; 
int stopPin = 11;
int relayPin = 10;  
int state = 0;
int min = 25;
int hour = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(stopPin, INPUT);
  pinMode(relayPin, OUTPUT); 
}

void loop()
{
  int startState = digitalRead(inPin);
  int stopState = digitalRead(stopPin);
  
  if(stopState == 0 && state == 1){ 
    Serial.print("\tENGINE OFF! \n");
    state = 0;
    digitalWrite(relayPin, LOW);
  }
  if(startState == 1 && state == 0){
    state = 1;
    delay(5500);
    digitalWrite(relayPin, HIGH);
    Serial.print("\rENGINE ON ==> \t");
    min++;
    if(min == 60){min=0; hour++;}
    if(hour == 13) hour = 1;
    Serial.print(hour);
    Serial.print(":");
    if(min < 10) Serial.print("0");
    Serial.print(min);
    Serial.print("\r");
    delay(2000);
  }
    
  delay(1);
  
}



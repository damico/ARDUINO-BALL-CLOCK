/*
    Ball Bearing Time Machine Clock, controlled by Arduino
    Copyright (C) 2015 - Jose Ricardo de Oliveira Damico

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    <jd.comment@gmail.com>	

*/

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



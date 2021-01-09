/*  
 *   Developer: Parv Narang
*/

int pwm_speedA = 150;
int pwm_speedB = 145;
int bed;
int count = 0;

void setup() {
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(3, OUTPUT);

pinMode(13, INPUT);
pinMode(2, INPUT);
pinMode(4, INPUT);
pinMode(7, INPUT);
pinMode(12, INPUT);


Serial.begin(9600);
Serial.print("Enter the bed no. and the status ");
//Serial.print( bed);
}
void loop() {

  if(bed == 0){
    
    while(Serial.available()>0){
      int bed = Serial.parseInt();
      int stat = Serial.parseInt();
      Serial.print("   Bed No. - ");
      Serial.print( bed);
      
      Serial.print("   Status = ");
      Serial.print( stat);
      
      if(Serial.read() == '\n'){
        Serial.print("    Going to bed number - " );
        Serial.print(bed);
  
        while(bed == 1 || bed == 2 || bed == 3 || bed == 4 || bed == 5 ||bed ==6){      //function for 2 beds has to be added......
                                                                                       // A(1&2)  B(3&4) C(1&3) D(2&4) E()
          lfr();
          if(digitalRead(2) == LOW && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == LOW){
            count++;
          }
            
          /*else if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
            count--;
            stop();
            
            
            
          }
            while(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
                stop();
                delay(2000);
                turn();
                count--;
                Serial.print(         count);
                break;
          
            }*/
            
             while(count==1 && bed == 1){
              stop();
              delay(2000);
              while(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == LOW){
              left();  
              }
              break;
          
              //Serial.print(   count);
             
              }
            while(count == 1 && bed == 2){
              stop();
              delay(2000);
              while(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == HIGH){
              right();  
              }
              break;
              
            }
      }
    }
  }

}
}

void forward(){
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  analogWrite(5, 150);
  analogWrite(3, 150);
}

void backward(){
  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);

  analogWrite(5, 100);
  analogWrite(3, 100);
  
}

void left(){
  
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);

  analogWrite(3,150);
  analogWrite(5, 150);
  
}

void right(){
  
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  
  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  analogWrite(3, 150);
  analogWrite(5, 150);
  
}

void stop(){
  
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);

  analogWrite(5, 0);
  analogWrite(3, 0);
  
}
void turn() {
  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  analogWrite(3, 100);
  analogWrite(5, 100);

}


void lfr(){
  
  if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == LOW && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  forward();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == LOW){
  left();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  right();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == LOW){
  forward();
  }
 /* else if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH){
  forward();
  }*/
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == LOW && digitalRead(12) == HIGH && digitalRead(13) == LOW ){
  right();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == LOW && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == LOW && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == LOW ){
  right();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == LOW && digitalRead(4) == HIGH && digitalRead(12) == HIGH && digitalRead(13) == HIGH){
  left();
  }
  else if(digitalRead(2) == HIGH && digitalRead(7) == HIGH && digitalRead(4) == HIGH && digitalRead(12) == LOW && digitalRead(13) == HIGH){
  left();
  }
  else{
    
  }
}

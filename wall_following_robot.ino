int leftpush = 7;
int rightpush = 6;
int photodiode=A1;
int fmotor=12;
int lmotor1=9;
int lmotor2=11;
int rmotor1=8;
int rmotor2=10;
int hf=0;
int hl=0;
int hr=0;
int time1=0;
int time2=0;
int interval=0;
int wall=0;
int flag=0;
int currenttime=0;
int T=2000;//time length to recognise it as a wall
int sensor=800;//threshould reading
void setup() {
    pinMode(leftpush, INPUT);  
    pinMode(rightpush, INPUT);  
    pinMode(photodiode, INPUT); 
    pinMode(fmotor, OUTPUT); 
    pinMode(lmotor1,OUTPUT); 
    pinMode(lmotor2, OUTPUT); 
    pinMode(rmotor1,OUTPUT); 
    pinMode(rmotor2, OUTPUT); 
    Serial.begin(9600);    
    digitalWrite(fmotor,LOW); 
    digitalWrite(lmotor1,LOW);
    digitalWrite(lmotor2,LOW);
    digitalWrite(rmotor1,LOW);
    digitalWrite(rmotor2,LOW);
}
void loop() {   
     //ensure it close to wall
     if(wall<5){
       if(analogRead(photodiode)<=sensor&&hf==0){
          digitalWrite(fmotor,HIGH); 
          digitalWrite(rmotor1,LOW);
          digitalWrite(rmotor2,LOW);
          
        }
        else if(analogRead(photodiode)>=sensor||interval<=T){
          if(analogRead(photodiode)>=sensor){
          digitalWrite(fmotor,LOW); }
           hf=1;//hf=1 means already close to the wall
       //when it close to front wall, move to left if when it haven't touch wall in the left
         if(hl==0&&hf==1){
         digitalWrite(lmotor1,HIGH);
         digitalWrite(lmotor2,HIGH);
         digitalWrite(rmotor1,LOW);
         digitalWrite(rmotor2,LOW);
         }
       //testing on gap
          if(analogRead(photodiode)<=sensor&&flag==0){
           flag=1;
           time1=millis();
           } 
          if(flag==1){
            if (analogRead(photodiode)>=sensor){
             time2=millis();
             interval=time2-time1;
              if(interval<T){
                flag=0;
                interval=0;
                hr=0;
               } 
            }
            else if(flag==1&&analogRead(photodiode)<=sensor){
            currenttime=millis();
            interval=currenttime-time1;
            if(interval>=T){
              digitalWrite(lmotor1,LOW);
              digitalWrite(lmotor2,LOW);
              flag=0;
              interval=0;
              hf=0;
              hl=0;
              hr=0;
              wall=wall+1;
              }
            }
          } 
              
       
       
      //if it touch the wall in the left side, start to move to right side
      else if(digitalRead(leftpush)==0||hr==1){
        Serial.println("babaababab");
        digitalWrite(rmotor1,HIGH);
        digitalWrite(rmotor2,HIGH);
        digitalWrite(lmotor1,LOW);
        digitalWrite(lmotor2,LOW);
        hr=1;//start to move to right
        hl=1;//have been touch left wall
        if(analogRead(photodiode)<=sensor&&flag==0){
        time1=millis();
        flag=1;
        }
        if(flag==1){
          if (analogRead(photodiode)>=sensor){
            time2=millis();
            interval=time2-time1;
            if(interval<T){
              flag=0;
              interval=0;
              } 
            }
            else if(flag==1&&analogRead(photodiode)<=sensor){
            currenttime=millis();
            interval=currenttime-time1;
            if(interval>=T){
              digitalWrite(rmotor1,LOW);
              digitalWrite(rmotor2,LOW);
              flag=0;
              interval=0;
              hf=0;
              hl=0;
              hr=0;
              wall=wall+1;
              }}
          }
        }   
}
     }
if(wall==5){
  digitalWrite(fmotor,HIGH);
  delay(2000);
  digitalWrite(fmotor,LOW);
  wall=6;
  }
}







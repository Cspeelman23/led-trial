int blue1 = 5;
int blue2 = 6;
int blue3 = 7;
int red1 = 9;
int red2 = 10;
int red3 = 11;
int green = 12;
int green2 = 13;

int countB = 0;
int countR = 0;
bool win = false;

void setup() {
  Serial.begin (9600);
  pinMode(3,INPUT); //blue button
  pinMode(2,INPUT); //red button
  pinMode(blue1,OUTPUT);
  pinMode(blue2,OUTPUT);
  pinMode(blue3,OUTPUT);
  pinMode(red1,OUTPUT);
  pinMode(red2,OUTPUT);
  pinMode(red3,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(green2,OUTPUT);
}

void loop() {
 int bluebutton = digitalRead(3);
 int redbutton = digitalRead(2);
  
  if(bluebutton == HIGH){
    Serial.println("blue");
    countB++;
    Serial.println(countB);
    delay(200);
  }
   if(redbutton == HIGH){
    Serial.println("red");
    countR++;
    Serial.println(countR);
    delay(200);
  }
//_________________________
  if(countB ==1){
    //on b1, off others
    digitalWrite(blue1,HIGH);
    digitalWrite(blue2,LOW); 
    digitalWrite(blue3,LOW);
  }
  else if(countB ==2){
    // on 1 and 2, off other
    digitalWrite(blue1,HIGH);
    digitalWrite(blue2,HIGH); 
    digitalWrite(blue3,LOW);
  }
  else if (countB >= 3){
    //on all blue
    digitalWrite(blue1,HIGH);
    digitalWrite(blue2,HIGH); 
    digitalWrite(blue3,HIGH);
  }
  else{
    //error or just started
    Serial.println("begin");
  }
//________________________________
  if(countR ==1){
    //on r1, off others
    digitalWrite(red1,HIGH);
    digitalWrite(red2,LOW); 
    digitalWrite(red3,LOW);
  }
  else if(countR ==2){
    // on 1 and 2, off other
    digitalWrite(red1,HIGH);
    digitalWrite(red2,HIGH); 
    digitalWrite(red3,LOW);
  }
  else if (countR >= 3){
    //on all red
    digitalWrite(red1,HIGH);
    digitalWrite(red2,HIGH); 
    digitalWrite(red3,HIGH);
  }
  else{
    //error
    Serial.println("begin2");
  }

  if(countB >= 4 && win==false){
     digitalWrite(green,HIGH);
     win = true;
  }

  if(countR >= 4 && win==false){
    digitalWrite(green2, HIGH);
    win = true;
    
    
  }

  

}


int E1 = 5;  
int M1 = 4; 
int E2 = 6;                      
int M2 = 7;                        
int val1=0;
int val2=0;
int stp=31w;

String state="\0";

 
void setup() 
{ 
    pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT); 
    digitalWrite(M1,HIGH);   
    digitalWrite(M2, HIGH);       
    analogWrite(E1, 0);  
    analogWrite(E2, 0);  
    Serial.begin(9600);
} 
 
void loop() 
{ 

  while (Serial.available()){    
    state = String(char(Serial.read()));
    writeMotor(state);
  }
  if (!Serial.available()){
    if (state != "\0") {
      //if data is available
      Serial.println(">"+state); //show the data
    state = ""; //clear the data
    }
  }
  delay(30); 

}


void writeMotor(String s){
  if(s=="w"){
    if(val1+stp<255) val1+=stp;    
    digitalWrite(M1, val1>0);   
    analogWrite(E1, abs(val1));   //PWM Speed Control
    Serial.println("E1["+String(val1)+"]");
  }
  else if(s=="x"){
   if(val1-stp>-254) val1-=stp;
   digitalWrite(M1, val1>0);   
   analogWrite(E1, abs(val1));   //PWM Speed Control
   Serial.println("E1["+String(val1)+"]");
  }
  else if(s=="q"){
    if(val2+stp<255) val2+=stp;
    digitalWrite(M2, val2>0);   
    analogWrite(E2, abs(val2));   //PWM Speed Control
    Serial.println("E2["+String(val2)+"]");
  }
  else if(s=="z"){
    if(val2-stp>-255)val2-=stp;
    digitalWrite(M2, val2>0);   
    analogWrite(E2, abs(val2));   //PWM Speed Control
    Serial.println("E2["+String(val2)+"]");
  }    
  else if (s=="a"){
      val2=0;
      digitalWrite(M2, HIGH);   
      analogWrite(E2, 0); 
  }
 else if (s=="s"){
      val1=0;
      digitalWrite(M1, HIGH);   
      analogWrite(E1, 0); 
  }
  else if (s==" "){
    val1=0;
    val2=0;    
    analogWrite(E1, 0);
    analogWrite(E2, 0);
  }
}






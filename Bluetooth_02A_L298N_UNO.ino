# include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10,11);
//Connecting HC-05 to MEGA
//https://www.apdaga.com/2017/11/arduino-mega-bluetoth-communication-to.html
//#include <L298N.h>
// Pin definition
 int IN1 = 6;
 int IN2 = 5;
 int EN1 = 7;
 int IN3 = 4;
 int IN4 = 3;
 int EN2 = 2;
// Create one motor instance
//L298N motor(EN, IN1, IN2);
void setup()
{
  pinMode(EN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600); //Tx0 and Rx0  //Set Baud Rate to 9600 for Serial Communication Tx0 and Rx0
  bluetoothSerial.begin(9600);  //Tx1 and Rx1  //Connected to Bluetooth Module HC-05 (Bluetooth 2.0)
  //pinMode(13, OUTPUT);  //Set Pin 13 as Output (Connected to LED)

  Serial.println("press \"a\" or \"A\" to switch ON the LED");  //To Desktop
  Serial.println("press \"b\" or \"B\" to switch OFF the LED");
  bluetoothSerial.println("press \"a\" or \"A\" to switch ON the LED"); //To mobile
  bluetoothSerial.println("press \"b\" or \"B\" to switch OFF the LED");
  //motor.setSpeed(130);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  if(bluetoothSerial.available()>0)
  {
    
    int speed = 600;
    char buffer_value = bluetoothSerial.read();
    Serial.println(buffer_value);
    if(buffer_value == 'a' || buffer_value == 'A') //forward
    {
      //digitalWrite(13, HIGH);    //Turn ON LED
      //Serial.println("LED ON");  //Arduino Terminal of Desktop 
      //Serial1.println("LED ON"); //Bluetooth Terminal on Mobile
      digitalWrite(IN1 , HIGH);
      digitalWrite(IN2 , LOW);
      digitalWrite(IN3 , HIGH);
      digitalWrite(IN4 , LOW); 
      analogWrite(EN1 , speed);
      analogWrite(EN2 , speed);        
      delay(200);
      
    }
    else if(buffer_value == 'c' || buffer_value == 'C') //stop
    {
      digitalWrite(IN1 , LOW);
      digitalWrite(IN2 , LOW);
      digitalWrite(IN3 , LOW);
      digitalWrite(IN4 , LOW);
      // analogWrite(EN1 , speed);
      // analogWrite(EN2 , speed);        
      delay(200); 
    }     
    
    else if(buffer_value == 'b' || buffer_value == 'B') //reverse
    {
      //digitalWrite(13, LOW);      //Turn OFF LED
      //Serial.println("LED OFF");  //Arduino Terminal on Desktop
     // Serial1.println("LED OFF"); //Bluetooth Terminal on Mobile
      digitalWrite(IN1 , LOW);
      digitalWrite(IN2 , HIGH);
      digitalWrite(IN3 , LOW);
      digitalWrite(IN4 , HIGH);
      analogWrite(EN1 , speed);
      analogWrite(EN2 , speed);
      delay(200);
          
    }
    else if(buffer_value == 'd') // left
    {
      digitalWrite(IN1 , HIGH);
      digitalWrite(IN2 , LOW);
      digitalWrite(IN3 , LOW);
      digitalWrite(IN4 , HIGH);
      delay(200);
      stop();        
      
    }
    else if(buffer_value == 'e') //right
    {
      digitalWrite(IN1 , LOW);
      digitalWrite(IN2 , HIGH);
      digitalWrite(IN3 , HIGH);
      digitalWrite(IN4 , LOW);
      delay(200);
      stop();        
      
    }                       
    else if(buffer_value <= 1023)     
    {
      speed = buffer_value;     
      analogWrite(EN1 , speed);
      analogWrite(EN2 , speed);
    }
  }
}
void stop()
{
  digitalWrite(IN1 , LOW);
  digitalWrite(IN2 , LOW);
  digitalWrite(IN3 , LOW);
  digitalWrite(IN4 , LOW);  
  delay(100);    
}  
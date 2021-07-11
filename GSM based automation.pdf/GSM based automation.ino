#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
String incomingData;
String message = "";
int relay_pin1 = 2;
int relay_pin2 = 3;
void setup()
{
  Serial.begin(115200);
  SIM900.begin(19200);
  pinMode(relay_pin1, OUTPUT); 
  digitalWrite(relay_pin1, HIGH);
  pinMode(relay_pin2, OUTPUT); 
  digitalWrite(relay_pin2, HIGH);
  SIM900.print("AT+CMGF=1\r");  
  delay(100);
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(100);
}
void loop()
{

  receive_message();
  if(incomingData.indexOf("Turn_on1")>=0)

  {
    digitalWrite(relay_pin1, LOW);
    message = "Switch1 is turned ON";
    send_message(message);
  }
  if(incomingData.indexOf("Turn_off1")>=0)
  {
    digitalWrite(relay_pin1, HIGH);
    message = "Switch1 is turned OFF";
    send_message(message);
  }        
  if(incomingData.indexOf("Turn_on2")>=0)

  {
    digitalWrite(relay_pin2, LOW);
    message = "Switch2 is turned ON";
    send_message(message);
  }
  if(incomingData.indexOf("Turn_off2")>=0)
  {
    digitalWrite(relay_pin2, HIGH);
    message = "Switch2 is turned OFF";
    send_message(message);
  }        
}
void receive_message()
{
  if (SIM900.available() > 0)
  {
    incomingData = SIM900.readString(); 
    Serial.print(incomingData); 
    delay(10); 
  }
}
void send_message(String message)
{
  SIM900.println("AT+CMGF=1");    
  delay(100);  
  SIM900.println("AT+CMGS=\"+918919245044\""); 
  delay(100);
  SIM900.println(message);   
  delay(100);
  SIM900.println((char)26);  
  delay(100);
  SIM900.println();
  delay(1000);  
}

















  



  

  

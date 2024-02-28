// read from ThingSpeak
// at River side

#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = 1663880;                // Channel ID
const char * myCounterReadAPIKey = "CY4Y6YIFW2BCEI40";      // Read API Key
const char * myCounterWriteAPIKey = "HCMOVUM8FG3ZCOOB";      // Write API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;                                 // The field you wish to read

void setup()
{
  pinMode(13,OUTPUT); // RELAY
  pinMode(5,OUTPUT);  //GREEN indicator
  pinMode(4,OUTPUT);  //RED indicator
  
  
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("GNXS827098B2", "B43D0887F020");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber2, myCounterReadAPIKey);

 Serial.print("Signal Received :  ");
 Serial.println(A);
 
 digitalWrite(13,A);  //RELAY Signal/out on pin D7 of ESP

 if(A == 1){
 digitalWrite(5, HIGH);   // MOTOR ON  
 } 

 if(A == 0){
 digitalWrite(4, HIGH);   // MOTOR OFF  
 }  
 
}

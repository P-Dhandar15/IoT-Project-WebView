  // write on ThingSpeak
 // at tank side

#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>


// CLOUD SETUP //

WiFiClient  client;
unsigned long counterChannelNumber = 2222282;                // Channel ID
const char * myCounterReadAPIKey = "27PCVAR1Q55V3IB7";      // Read API Key
const char * myCounterWriteAPIKey = "S57URCTDHE231S7H";      // Write API Key

const int FieldNumber1 = 1;                                 // Ultrasonic
const int FieldNumber2 = 2;                                 // Motor on oof

const int FieldNumber3 = 3;                                 // water level High / Low 
 

// ULTRASONIC SETUP//

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void setup()
{
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("Pranav", "12345678");                 // write wifi name & password           

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

  pinMode(13,OUTPUT);
}


void loop() 
{
  int distance = 0.01723 * readUltrasonicDistance(D2, D3);

  Serial.print("Water Level : ");      //print Water level
  Serial.print(distance);
  Serial.println(" cm");
 
  ThingSpeak.writeField(counterChannelNumber ,FieldNumber1 ,distance ,myCounterWriteAPIKey);    // send Water level to cloud

 if(distance >= 10){
  Serial.println("tank is empty");
    ThingSpeak.writeField(counterChannelNumber ,FieldNumber2 ,1 ,myCounterWriteAPIKey);  }      // Water Level below than 100 ON Motor

  else if(distance < 4){
    Serial.println("tank is full");
    ThingSpeak.writeField(counterChannelNumber ,FieldNumber2 ,0 ,myCounterWriteAPIKey);       //Water level less than 11 means tank full : OFF Motor
    
    digitalWrite(13,HIGH);  }  //LED indicator 

    if(distance <= 5){
      ThingSpeak.writeField(counterChannelNumber ,FieldNumber3 ,1 ,myCounterWriteAPIKey);     //Water Level HIGH
      }

    else if(distance >5){
      ThingSpeak.writeField(counterChannelNumber ,FieldNumber3 ,0 ,myCounterWriteAPIKey);     //Water Level LOW
      }
      
 delay(100);
}

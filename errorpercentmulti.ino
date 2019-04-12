#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include "ThingSpeak.h"
//SERVO MOTOR
#include <Servo.h>   //servo library
Servo servo;

const char* ssid = "shahima";
const char* password = "12345678";
int perc;//variable showing percentage filled
int x = 15; //dimension of waste bin
int y = 15;
int z = 15;
int error;
WiFiClient client;
unsigned long myChannelNumber = 710604;
const char * myWriteAPIKey = "GLLAPXH5G4VV7GIU";
unsigned long myChannelNumber1 = 745576;
const char * myWriteAPIKey1 = "M99Y5AISCW374C5J";



int servoPin = D0;


//pins for ultra1
const int trigPin1 = D6;  //D4(2)
const int echoPin1 = D7;  //D3(0)

//pins for ultra2
const int trigPin2 = D1;
const int echoPin2 = D3;

//pins for ultra3
const int trigPin3 = D1;
const int echoPin3 = D4;

//pins for ultra4
const int trigPin4 = D1;
const int echoPin4 = D5;

//pins for ultra5
const int trigPin5 = D6;
const int echoPin5 = D2;

// defines variables
long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;
long duration4;
int distance4;
long duration5;
int distance5;

int val1,val2,val3;
int val;
void setup() {

  Serial.begin(9600); // Starts the serial communication
  Serial.println("start");
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin4, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin4, INPUT); // Sets the echoPin as an Input

  pinMode(trigPin5, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin5, INPUT); // Sets the echoPin as an Input


  //setting up wifi connection
  WiFi.begin(ssid, password);
  // Connect to WiFi network
  ThingSpeak.begin(client);

  //SERVO MOTOR
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(0);         //close cap on power on
  delay(1000);
  servo.detach();

}

void loop() {

// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);

// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
delay(100);


// Clears the trigPin
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);

// Calculating the distance
distance2= duration2*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance2: ");
Serial.println(distance2);
delay(100);
 




// Clears the trigPin
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration3 = pulseIn(echoPin3, HIGH);

// Calculating the distance
distance3= duration3*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance3: ");
Serial.println(distance3);
delay(100);





// Clears the trigPin
digitalWrite(trigPin4, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin4, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin4, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration4 = pulseIn(echoPin4, HIGH);

// Calculating the distance
distance4= duration4*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance4: ");
Serial.println(distance4);
delay(100); 




  // Clears the trigPin
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration5 = pulseIn(echoPin5, HIGH);

  // Calculating the distance
  distance5 = duration5 * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance5: ");
  Serial.println(distance5);
  delay(1000);









//WRITE CODE TO SEND DATA TO THINGSPEAK
//FOR WASTEBIN 1

if(distance4<x) {
  val3=90;
  val=val3;
  Serial.println("waste percentage:");
  Serial.println(val);
  //ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);
  }
 

 if(distance3<y || distance5<x){
  val2=60;
  val=val2;
  Serial.println("waste percentage:");
  Serial.println(val);
 // ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);
  }
  
if(distance2<z){
  val1=30;
  val=val1;
Serial.println("waste percentage:");
  Serial.println(val);
  //ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);
}

//ERROR DETECTION
Serial.print("val3sensor90:");

Serial.println(val3);
Serial.print("val2sensor60:");
Serial.println(val2);
Serial.print("val1sensor30:");
Serial.println(val1);


//data entering to thingspeak
if(val3==90){val=val3;
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);}

else if(val2==60){val=val2;
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);}
else if(val1==30){val=val1;
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
  delay(100);}






//error detecting
if (val3==90){if (val2!=60 || val1!=30){error=1;Serial.println("error detected");}}
 
 if(val2==60){if(val1!=30){error=1;Serial.println("error detected");}}

 ThingSpeak.writeField(myChannelNumber1, 1,error, myWriteAPIKey1);



  
if(distance1<15 && distance4>x){
  //if hand on the distance 10...30 cm
 servo.attach(servoPin);
  delay(1);
 servo.write(90);  
 delay(5000);       //wait 5 seconds
 servo.write(0);    
 delay(1000);
 servo.detach();   
  
  }
 
val2=val3=val1=0;
error=0;
}


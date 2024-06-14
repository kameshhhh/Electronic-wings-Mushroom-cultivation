#include <Wire.h>

#include <WiFi.h>

#include <PubSubClient.h>

#include <SPI.h>

#include <LoRa.h>

#include "SSD1306.h"

#include<Arduino.h>

SSD1306 display (0x3c, 4, 15);

#define SS 18

#define RST 14

#define DIO 26

#define BAND 433E6 //915E6

float temperature = 0;

float humidity = 0;

float co2 = 0;

float lux = 0;

String b1, b2, b3, b4, b5, b6, b7, b8, b9, b10; int bl1, b21, b31, b41, b51;#define WIFISSID "R&D LABS" // Put your WifiSSID her

#define PASSWORD "" // Put your wifi password here

#define TOKEN "BBFF-qdRXUwDXgmxKrx8FAnq9chQ8V4WCEF"

#define MQTT _CLIENT_NAME "ESP32 BME680 Station" // M

Define Constants

#define VARIABLE LABEL1 "Temperature" // Assing the

#define VARIABLE_LABEL2 "Humidity" // Assing the va

#define VARIABLE LABEL3 "co2"

#define VARIABLE LABEL4 "lux"

#define DEVICE_LABEL "esp32"

char mqttBroker [] = "industrial.api.ubidots.com";

char payload [1000];

char topic1 [150];

char topic2 [150];

char topic3 [150];

char topic4 [150];include <Wire.h>

Publimat

1.

#include <LoRa

#inciode 3801306.h

Binclude Arduino.h> sap1306 dispіну (0x3, 4, 15),

0eflon 55 10

24

26

erine BAND 43386//91

float temperature 이

float humidity 02

float Jun 01

Braing bì, 12, 13, 14, 15, bé, b7, be, b9, b10 int bil, bai, b31, 41, 51:

#define MIFISSID "RAD LABS // Put your WifissID hei

#define PASSWORD"" // Put your wifi password here #define TOKEN "BBPF-QAEXUWDXgmxKrx@PAnq9chQ@V4WCBP"

#define MOTT CLIENT NAME "ESP32_BME660_Station" // !

Define constants

#define VARIABLE LABELİ "Temperature" // Assing the

#define VARIABLE LABEL2 "Humidity" // Assing the var

#define VARIABLE LABELS "002"

#define VARIABLE LABEL4 "lux"

#define DEVICE LABEL "esp32"

char payload [1000];

char mottBroker [] "industrial.api.ubidots.com";

char topicl [150];

char topic2[150]; char topic3[150];

char topic4 (150);WiFiClient ubidots;

PubSubClient client (ubidots);

void callback(char* topic, byte payload, unsigned int length)

char p[length + 1];

memcpy(p, payload, length);

p[length] = NULL;

String message (p);

Serial.write (payload, length);

Serial.println(topic);

void reconnect()

// Loop until we're reconnected while (tclient.connected())

//Serial.println("Attempting MQTT connection...");

// Attemp to connect

if (client.connect (MQTT_CLIENT NAME, TOKEN, ""))

//Serial.println("Connected"); Felse

Serial.print ("Failed, rc=");

Serial.print(client.state());

Serial.println(" try again in 2 seconds");

// Wait 2 seconds before retrying

delay(2000);

Main Functions

void setup()

(pinMode (25, OUTPUT); //Send success, LED w:

pinMode (16, OUTPUT);

digitalWrite(16, LOW); // set GPIO16 10

delay(50);

digitalWrite(16, HIGH);

Serial.begin(9600);

while (!Serial); //If just the the basic ft

display.init();

// Initialising the UI will init the displa

display.flipScreenVertically();

display.setFont (ArialMT_Plain_10);

display.setTextAlignment (TEXT ALIGN_LEFT);

display.display();

display.drawString (5, 5, "LoRa Reciver");

SPI.begin(5, 19, 27, 18);

LoRa.setPins (SS, RST, DIO);

//Serial.println("LoRa Reciver");

if (LoRa.begin(BAND)) {

Serial.println("Starting LoRa failed!");

while (1);}

//Serial.println("LoRa Initial OK!");

display.drawString (5, 20, "LoRa Initializing OK!");

display.display();

// delay (2000);

// WiFi.begin(WIFISSID, PASSWORD);

// //Serial.println();

// //Serial.print("Waiting for WiFi Connection .");

// while (WiFi.status() != WL CONNECTED)

// delay(500);

//Serial.print(".");

// //Serial.println("");

// // Serial.println("WiFi Connected");

// //Serial.println("IP address: ");

// Serial.println(WiFi.localIP());

// client.setServer(mqttBroker, 1883);

// client.setCallback(callback);

Serial.println("CLEARDATA");

// Clear all Excel sheet dat

// Label columns: A for date, B for time, C for temperature and Serial.println("LABEL, Date, Time, Temperature, Humidity, co2, lux");

}

void loop()

int packetSize LoRa.parsePacket();

if (packetSize) {

// received a packets

// Serial.print("Received packet. ");

display.clear();

display.setFont (ArialMT Plain 10);

display.display();

// read packet while (LoRa.available()) {

String a LoRa.readString(); //Serial.println(a);

int al a.indexOf("a");

int a2a.indexOf("b");

int a3 a.indexOf("c"); int a4a.indexOf("d");

int a5a.indexOf("e");

int a6 a.indexOf("1");

int a7 a.indexOf("g");

int a8a.indexOf("h");

int a9 a.indexOf("i");

int a10 a.indexOf("");

int alla.indexOf("k");

int a12a.indexOf("1");

int a13a.indexOf("m");

int a14

a.indexOf("n");

int a15

a.indexOf("0");

int a16 a.indexOf("p");

int a17

a.indexOf("q");

int a18

a.indexOf("r");

int a19

a.indexOf("s");

int a20

a.indexOf("t");

50

63/75
bla.substring(al 1, a2);

b2a.substring(al 1, 4);

b3a.substring(a5 1, 46);

b4 a.substring(a7 1, a8); b5a.substring(a9+ 1, a10);

b6a.substring(all 1, 12);

67 a.substring(a13 1, 14);

be a.substring(a15 1, 16);

b9 a.substring(a17 1, a18);

b10a.substring(a19+ 1, a20);

bli bl.toint()) //

// b21b2.toint(); b31b3.toint();

// b41b4.toint();

50

Serial.print("DATA, DATE, TIME, "); //Serial.print("temperature");

Serial.print(bl); Serial.print(",");

//Serial.print("humidity = ");

Serial.print(b2);

Serial.print(",");

//Serial.print("co2" Serial.print(b3);

Serial.print(",");

//Serial.print("lux"

Serial.print(b4);

Serial.println(".");

display.drawstring (5, 0, "Date: String(b7)+"/"+ String(b6)+"/"+String(b5)); ));

display.drawstring (5, 10, "Time: String(b8)+":"+ String(b9)+":"+String(b10

display.drawstring (5, 20, "Temperature: String(bl)+ "C");

display.drawstring (5, 30, "Humidity: string (b2)"H");

display.drawString (5, 40, "C02: String (b3) + PEM");

display.drawstring (5, 50, "Light: +String(b4)+" lux");

display.display())

}

delay(100);
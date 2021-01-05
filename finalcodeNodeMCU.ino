#include <ESP8266WiFi.h>

String apiWriteKey="12F0Z977O1FPJ9NO";
const char* ssid = "JCApartemento";
const char* password = "Tunisia+216";
const char* server = "api.thingspeak.com";
float resolution = 3.3/1023;

WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to WiFi ...");

  WiFi.begin(ssid, password);

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");}
    Serial.println("");
    Serial.print("Nodemcu connected to WiFi ...");
    Serial.println(ssid);
    Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:
  float beta = (analogRead(A0)*resolution)*100;

  if(client.connect(server,80)){
    String tsData = apiWriteKey;
           tsData +="&field1=";
           tsData +=String(beta);
           tsData +="\r\n\r\n"; 

     client.print("POST /update HTTP/1.1\n");
     client.print("Host: api.thingspeak.com\n");

    client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY:"+apiWriteKey+"\n");
      client.print("Content-Type:application/x-www-form-urlencoded\n");
      client.print("Content-Length:");
      client.print(tsData.length());
      client.print("\n\n");
      client.print(tsData);
    Serial.print("Beta1");
      Serial.print(beta);
     Serial.print("Attention");
      Serial.print(beta*2);
      Serial.println("Uploaded to Thingspeak server");
    
    }
    client.stop();
    Serial.println("Waiting to upload next reading ...");
    Serial.println();
    delay(15000);

}

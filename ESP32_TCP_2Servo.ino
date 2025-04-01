#include <WiFi.h>
#include <ESP32Servo.h>
#include <string.h>

// Replace with your network credentials
const char* ssid = "Galaxy A73 5G";
const char* password = "Password";

// Create a WiFi server on port 80
WiFiServer server(8000);
Servo servo1;
Servo servo2;

int servo1Pin = 13; // GPIO pin for the first servo
int servo2Pin = 12; // GPIO pin for the second servo

int pos1 = 0; // Position for servo 1
int pos2 = 0; // Position for servo 2

void setup() 
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();

  // Attach the servo to pin 13
  servo1.attach(servo1Pin); 
  servo2.attach(servo2Pin); 

  
}

void loop() 
{
  WiFiClient client = server.available();
  if (client) 
  {
   while(1)
   { 
    String data,request = "";
    unsigned long timeout = millis();  // Start a timeout counter

    // Read data from the client with a timeout
    while (client.available() || (millis() - timeout) < 750) 
    {
      if (client) 
      {
        //String data = ;
        Serial.println("New Client connected");
        data = client.readStringUntil('\n');  // Read the incoming string
        Serial.println("Received: " + data);
      }
    // Parse the incoming string to extract servo positions
      if (data.indexOf("servo1") > -1) 
      {
        pos1 = data.substring(data.indexOf("servo1:") + 7, data.indexOf(" ")).toInt();
        servo1.write(pos1);  // Move servo 1
        Serial.println("Servo 1 set to: " + String(pos1));
      }
    
      if (data.indexOf("servo2") > -1) 
      {
        pos2 = data.substring(data.indexOf("servo2:") + 7).toInt();
        servo2.write(pos2);  // Move servo 2
        Serial.println("Servo 2 set to: " + String(pos2));
      }
    }

    request.trim();
    // Parse the angle from the request
    
   }
    // Close the client connection
    client.stop();
  }
}

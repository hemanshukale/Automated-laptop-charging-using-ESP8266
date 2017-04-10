const char* ssid_rout0 = "Winterfell";
const char* pass_rout0 = "AryaStark";

#include <ESP8266WiFi.h>

IPAddress ip1(10, 42, 3, 204);
IPAddress gateway1(10, 42, 3, 1);
IPAddress subnet(255, 255, 255, 0);

WiFiClient client;
WiFiServer server(999);

bool sta = false;
const char* onoff[] = {"off","on"};

String rep0 = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

unsigned long lastp = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(12, OUTPUT);
digitalWrite(12, HIGH); delay(9); sta = true;
// charger turns on by default - 
// in case the code freezes or any other problem appears, just restart ESP to start charger

Serial.begin(115200);

  WiFi.disconnect();  
  Serial.println("Wifi disconnected...");

  delay(300);
  WiFi.mode(WIFI_STA);
  Serial.println("Mode Set...");
  
 delay(300);
  //WiFi.mode(WIFI_AP_STA);
 Serial.println("Mode Set...");
      
  WiFi.begin(ssid_rout0, pass_rout0);
  WiFi.config(ip1, gateway1, subnet);

  delay(3000);
server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if (Serial.available())
    {
      String a = Serial.readString();
      if (a.indexOf("rrr") != -1 ) 
        {
          ESP.restart();
        }
    }
delay(7);

WiFiClient client = server.available(); // Check if a client has connected
String reply = "";
  if ( client.available() ) 
  {
    String rec = client.readStringUntil('\r'); client.setTimeout(30);
    Serial.println("Got Some Data ");
    
delay(7);
    // Steing to send - swig / swih
    //Serial.println(rec);
  if (rec.indexOf("favicon.ico ") == -1 )
   {
    int ind1 = rec.indexOf("HTTP/1.1");
    int ind2 = rec.indexOf("GET /");

   if( ind1 != -1 && ind2 != -1)
   {
    String rec2 = rec.substring(ind2 + 5 , ind1);
    if (rec2.indexOf("swi") != -1)
      {
          char var = rec2[3];
          switch (var)
          {
            case 'g' : { digitalWrite(12, HIGH); sta = true; reply = "Turned on"; } break;
            case 'h' : { digitalWrite(12, LOW);  sta = false;reply = "Turned off" ;} break;
            default : {reply = "Bad letter";} break;
          }
        
      }
      else if (rec2.indexOf("sta") != -1)
     {
      reply = onoff[sta];
     }
     else reply = "Bad Request";
   }
   else reply = "Bad Request";
   client.println(rep0 + reply);
  delay(7);
  }
  
  }
delay(3);

  if (millis() - lastp > 6000 )
{
    Serial.print("sta -> ");
    Serial.println(onoff[sta]);
    lastp = millis();
}
}

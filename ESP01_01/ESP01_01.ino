#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include "writeAnything.h"
#include <ESP8266mDNS.h>


extern "C" {
#include "user_interface.h"
}


#define LED 2
#define DEBUG true



void firstConnectSSID();
void  handleHome();
void handleNotFound();
void handleSentData();
void handleRestart();
struct Data
{
  char APSSID [20];
  char APPass[20];
  char ssid[20] ;
  char pass[20] ;
  byte APCh;
} data;

struct Link
{
  char data[3][100];
  union {
    char all;
    struct {
      boolean text1: 1;
      boolean text2: 1;
      boolean text3: 1;
      boolean d: 1;
      boolean e: 1;
      boolean f: 1;
      boolean g: 1;
      boolean h: 1;
    };
  };
};

struct Setting
{
  union {
    char all;
    struct {
      boolean a: 1;
      boolean b: 1;
      boolean c: 1;
      boolean d: 1;
      boolean e: 1;
      boolean f: 1;
      boolean g: 1;
      boolean h: 1;
    };
  } ;
} setting;

ESP8266WebServer server ( 80 );
MDNSResponder mdns;
String MSG[3] ;
unsigned long last ;
boolean getOnce = true;
unsigned int x;



void restartESP(unsigned int wait)
{
  Serial.println("#m030303REBOOT");
  delay(wait);
  ESP.restart();
}

void setup() {
  delay(8000);
  pinMode ( LED, OUTPUT );
  digitalWrite ( LED, 0 );
  Serial.begin(2400);
  delay(1000);
  //isiEEPROMLink();
  isiEEPROMSetting();

  sprintf(data.APSSID, "sdasd");
  sprintf(data.APSSID, "pp");
  bacaEEPROMLinkText();
  bacaEEPROMSetting();
  const char *ssid = data.APSSID;
  const char *password = data.APSSID;
  WiFi.hostname(data.APSSID);
  wifi_station_set_auto_connect(1);
  WiFi.softAP(ssid, password, data.APCh);
  if (DEBUG)
  {
    Serial.print(" data.APSSID :");
    Serial.println(data.APSSID);
    Serial.print(" data.APPass :");
    Serial.println(data.APPass);
    Serial.print(" data.APCh :");
    Serial.println(data.APCh);
    WiFi.softAP(data.APSSID, data.APPass, data.APCh);
  }

  IPAddress myIP = WiFi.softAPIP();
  if (DEBUG)

  {
    Serial.print(" AP IP : "); Serial.println(myIP);

    Serial.print(" data.ssid :");
    Serial.println(data.ssid);
    Serial.print(" data.pass :");
    Serial.println(data.pass);
  }
  byte timeOut = 0;

  WiFi.begin(data.ssid, data.pass);
  Serial.print("#m070400"); Serial.println(data.ssid);
  while ( WiFi.status() != WL_CONNECTED && timeOut < 5 ) {
    delay ( 1000 );
    timeOut++;
  }
  if (timeOut >= 5) Serial.print ("#m200498No Wifi\n");
  else
  {
    if (DEBUG) {
      Serial.print ( "#m100998Connected\n" );
    }
  }
  timeOut = 0;
  delay(2000);
  Serial.println ( "#m350402I'M OK" );
  //server.on ("/", handleHome);
  //server.on ("/update", handleSentData);
  //server.onNotFound ( handleNotFound );                   // bila tiddak di index server
  server.begin();
}

void loop() {
  server.handleClient();
  if (WiFi.status() == WL_CONNECTED && getOnce == true) {getOnce = firstConnectSSID();}
  unsigned long now = millis();
  if (now - last >= 120000) { // 2 minute
    last = now;
    

    if (WiFi.status() != WL_CONNECTED)
    {
      WiFi.reconnect();
      getOnce = true;
    }
    else
    {
      String data = "#MB00";
      data += randomMSG();
      Serial.println(data);
      x++;
      if (x >= 5)
      {
        getHTTP();
        //getTimeOnline();
        x = 0;
      }
    }
  }

}

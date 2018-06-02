void getHTTP ()
{
  HTTPClient http;
  //Serial.printf(link.data[0]);
  Link link;
  EEPROM.begin(512);
  EEPROM_readAnything(6, link);
  EEPROM.end();
  for (byte i = 0; i < 3; i++)
  {
    if (!link.text1&& i=0) {
      MSG[i]=link.text1;
      i++;
    }
    if (!link.text2&& i=1) {
      MSG[i]=link.text2;
      i++;
    if (!link.text3&& i=2) {
      MSG[i]=link.text3;
      break;
    }
    http.begin(link.data[i]); //HTTP
    // start connection and send HTTP header
    int httpCode = http.GET();
    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        //payload.replace("~~~~~~~~~~~~~~", " ## ");
        MSG[i] = payload;
      }
    } else {
      Serial.printf(" [HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();

  }
}

boolean firstConnectSSID()
{
  char name[10] = "esp01";
  Serial.print("#m100902Connected \n");
  //if(DEBUG) 
  delay(2000);
  Serial.print("#m050105");Serial.println(WiFi.localIP());
  if (mdns.begin(name))
    if(DEBUG)Serial.println("MDNS OK");

  MDNS.addService("http", "tcp", 80);
  delay(2000);
  getHTTP();
  //getTimeOnline();
  yield();
  int s = (millis() - (randomMSG().length() * 2)) % 50;
  randomSeed(s);
  String data = "#MB00";
  data += randomMSG();
  Serial.println(data);
  return false;
}

#include <SimpleDHT.h>
#include <TimerOne.h>               // timer 0 untuk DMD


# define DHT11_PIN 4

SimpleDHT11 dht11;
 int err = SimpleDHTErrSuccess;
  
void DHTSampling()
{
  Timer1.detachInterrupt();
  if ((err = dht11.read(DHT11_PIN, &DHTSuhu, &DHTLembab, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  Timer1.attachInterrupt( ScanDMD );
}


String randomMSG()
{
  byte timeOut = 0;
  byte randn;
  String temp ;
  do
  {
    timeOut++;
    randn = rand() % 3;
    temp = MSG [randn];
    //Serial.print ("random :");Serial.println(randn);
    if (timeOut > 10) return "No Data";
  } while (temp == "");
  return temp ;
}

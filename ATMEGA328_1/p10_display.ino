#include <SPI.h>                    // SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <TimerOne.h>               // timer 0 untuk DMD

#define WHITE 0xFF
#define BLACK 0

void dmdInit() {
  Timer1.initialize( 1000 );              //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
  Timer1.attachInterrupt( ScanDMD );      //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()
  dmd.clearScreen( true );                //true is normal (all pixels off), false is negative (all pixels on)
  dmd.selectFont(minimalis);

}

void ScanDMD()
{
  dmd.scanDisplayBySPI();
}

//############# Fungsi Kecerahan DMD #################################

void setKecerahan(unsigned int brighness)
{
   if (brighness >=1025) brighness = readEEPROM (0, BIT_PANJANG);                                 // baca EEPROM di alamat 0 ,16bit data
  else
  {
   if (brighness != 0 || brighness >= 1020)brighness = fscale( 1, 1024, 1, 1024, brighness, -5);    // merubah skala dari linier ke logaritmik
  }
  //terang=100;
  updateEEPROM (0, brighness, BIT_PANJANG);                                                 // update EEPROM di alamat 0 ,16bit data
  //brighness =1024;
  Timer1.pwm(PIN_DMD_nOE, brighness); //0~1024 [10 16 25 40 65 100 160 250 400 640 1024]

}

//####################################################################
//############### Fungsi Menampilkan jam KOTAK #######################

void runClockBox(byte LOKASI_JAM_X, byte LOKASI_JAM_Y)
// draws the hour hand
{
  
  const byte x_secMin [] = {8, 9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14, 13, 12, 11, 10, 9, 8,   7, 6, 5, 4, 3,      2, 1, 0, 0, 0,      0, 0, 0, 0, 0,    0, 0, 0, 0, 0,  0, 0, 0, 1, 2,  3, 4, 5, 6, 7};
  const byte y_secMin [] = {0, 0, 0, 0, 0,    0, 0, 0, 1, 2,      3, 4, 5, 6, 7,      8, 9, 10, 11, 12,   13, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3,  2, 1, 0, 0, 0,  0, 0, 0, 0, 0};
  byte x_hour [] = {0, 11, 11, 11, 11, 9, 7, 4, 4, 4, 4, 6, 7};
  byte y_hour [] = {0, 4, 6, 7, 11, 11, 11, 11, 9, 7, 4, 4, 4};
  byte x_hour_c, y_hour_c;
  byte temp;

  if (second == 0) dmd.drawFilledBox(LOKASI_JAM_X + 1, LOKASI_JAM_Y + 1, LOKASI_JAM_X + 14, LOKASI_JAM_Y + 14, BLACK); // kosongkan jarum menit dan jam
  temp = hour;
  if (temp == 0)temp = 12;
  if (temp > 12)
  {
    temp -= 12; // only 12 hours on analogue clocks
  }

  //==== menentukan titik tengah (pusat) jarum
  if (temp <= 5)x_hour_c = LOKASI_JAM_X + 8;
  else x_hour_c = LOKASI_JAM_X + 7;

  if (temp <= 3) y_hour_c = LOKASI_JAM_Y + 7;
  else if (temp <= 8) y_hour_c = LOKASI_JAM_Y + 8;
  else if (temp <= 12) y_hour_c = LOKASI_JAM_Y + 7;

  dmd.drawLine( x_hour_c, y_hour_c, LOKASI_JAM_X + x_hour[temp], LOKASI_JAM_Y + y_hour[temp], WHITE ); // menggambar jarum jam
  // draw minute
  byte x_min_c, y_min_c;
  if (minute <= 29)x_min_c = LOKASI_JAM_X + 8;
  else x_min_c = LOKASI_JAM_X + 7;

  if (minute <= 14) y_min_c = LOKASI_JAM_Y + 7;
  else if (minute <= 44) y_min_c = LOKASI_JAM_Y + 8;
  else if (minute <= 59) y_min_c = LOKASI_JAM_Y + 7;

  dmd.drawLine( x_min_c, y_min_c, LOKASI_JAM_X + x_secMin[minute], LOKASI_JAM_Y + y_secMin[minute], WHITE );

  // draw Second
  dmd.drawBox(LOKASI_JAM_X, LOKASI_JAM_Y, LOKASI_JAM_X + 15, LOKASI_JAM_Y + 15, WHITE);
  dmd.writePixel( LOKASI_JAM_X + x_secMin[second], LOKASI_JAM_Y + y_secMin[second], BLACK);
}
//####################################################################
//################# Fungsi menampilkan jam tulisan ###################
void jamAngka(byte x, byte y)
{
  dmd.selectFont(minimalis);

  if (hour == 0)hour = 24;
   if (hour<10){
    sprintf(MSG, "0%d",hour);
  } else {
    sprintf(MSG, "%d",hour);
  }
  if (minute<10){
    sprintf(MSG, "%s:0%d",MSG,minute);
  } else {
    sprintf(MSG, "%s:%d",MSG,minute);
  }
  if (second<10){
    sprintf(MSG, "%s:0%d",MSG,second);
  } else {
    sprintf(MSG, "%s:%d",MSG,second);
  }
  dmd.drawString(  x, y, MSG , strlen(MSG) , WHITE, BLACK );
}
//####################################################################
//############# Fungsi menampilkan Suhu ##############################
void tampilSuhu(byte x, byte y)
{
  suhu = getTemp3231Celcius();
  byte riil = suhu;
  byte cacah = (suhu - riil) * 100;
  riil += readEEPROM (2, BIT_PANJANG);
  
  sprintf(MSG, "%d,%d`C", riil, cacah);
  dmd.drawString(  x, y, MSG , strlen(MSG) , WHITE, BLACK );
}
void tampilKelembaban(byte x, byte y)
{
  sprintf(MSG, "%d%%", DHTLembab);
  dmd.drawString(  x, y, MSG , strlen(MSG) , WHITE, BLACK );
}

///###################################################################
void drawTextClockBig(byte x_pos, byte y_pos)
{
  dmd.selectFont(angka6x13);
  if (hour<10){
    sprintf(MSG, "0%d",hour);
  } else {
    sprintf(MSG, "%d",hour);
  }

  dmd.drawString(x_pos+1, y_pos, MSG , strlen(MSG) , WHITE, BLACK );
  
  dmd.drawFilledBox(x_pos+ 16, y_pos+4, x_pos+17, y_pos+6, WHITE);
  dmd.drawFilledBox(x_pos+ 16, y_pos+8, x_pos+17, y_pos+10, WHITE);

  if (minute<10){
    sprintf(MSG, "0%d",minute);
  } else {
    sprintf(MSG, "%d",minute);
  }
  dmd.drawString(x_pos+ 20, y_pos, MSG , strlen(MSG) , WHITE, BLACK );
    if (second<10){
    sprintf(MSG, ":0%d",second);
  } else {
    sprintf(MSG, ":%d",second);
  }

  dmd.selectFont(Font3x5);
  dmd.drawString(x_pos+ 36, y_pos , MSG , strlen(MSG) , WHITE, BLACK );
  //Serial.println(jam);
  }
///###################################################################

void drawTextClock(byte x_pos, byte y_pos)
{
  //dmd.clearScreen(0);

  if (hour<10){
    sprintf(MSG, "0%d",hour);
  } else {
    sprintf(MSG, "%d",hour);
  }
  
  dmd.selectFont(angka6x13);
  dmd.drawString(  x_pos+ 3, y_pos, MSG , strlen(MSG) , WHITE, BLACK );

  if (minute<10){
    sprintf(MSG, "0%d",minute);
  } else {
    sprintf(MSG, "%d",minute);
  }

  dmd.selectFont(Font3x5);
  dmd.drawString(x_pos+ 22, y_pos , MSG , strlen(MSG) , WHITE, BLACK );

  if (second<10){
    sprintf(MSG, "0%d",second);
  } else {
    sprintf(MSG, "%d",second);
  }

  dmd.selectFont(Font3x5);
  dmd.drawString(x_pos+ 22, y_pos +7, MSG , strlen(MSG) , WHITE, BLACK );

  int n;
  n = second + 1;

  if (n % 2 == 0) {

    dmd.drawFilledBox(x_pos+ 18, y_pos+4, x_pos+19, y_pos+6, BLACK);
    dmd.drawFilledBox(x_pos+ 18, y_pos+8, x_pos+19, y_pos+10, BLACK);
  } else {
    dmd.drawFilledBox(x_pos+ 18, y_pos+4, x_pos+19, y_pos+6, WHITE);
    dmd.drawFilledBox(x_pos+ 18, y_pos+8, x_pos+19, y_pos+10, WHITE);
  }
}

///###################################################################

//####################################################################
//############# Fungsi menampilkan Scrooling #########################
void tampilMarque(uint8_t y,uint16_t spd)
{
  dmd.drawMarquee(MSG, strlen(MSG), (32 * DISPLAYS_ACROSS) - 1,y, WHITE,BLACK);
  long start = millis();
  long timer = start;
  boolean ret = false;
  if (spd==0) spd = readEEPROM (3, BIT_PANJANG);
  while (!ret) {
    if ((timer + spd) < millis()) {
      ret = dmd.stepMarquee(-1, 0);
      timer = millis();
    }
  }
  DHTSampling();
  disp= rand() % 7;
}
//####################################################################
//############# Fungsi menampilkan hari tanggal ######################
void tampilkanHariTanggal()
{
  char hari[][7] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};
  char bulanTeks[][9] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

  sprintf(MSG, " %s, %d %s 20%d", hari[dayOfWeek-1], dayOfMonth, bulanTeks[month-1], year);

  dmd.selectFont(Comic_Sans_MS_Custom_13);
  tampilMarque(0,0); // 0 = default (eeprom)
}
//####################################################################
//##################### Menampilkan static text ######################
void staticText(byte x, byte y, byte sec, char text[MAX_ST_TXT])
{
  /*
   * sec = delay in second
   * 
   * sec = 99 || 0 (cleanscreen and  no hold)
   * sec = 97 (no hold wihout clean before)
   * sec = 98 (clean up and reset)
   * sec = 91~97 (no clean, hold in sec (hold = sec -90)[ hold 1 sec = 91]
   * sec < 90 || sec!=0 (cleanscreen , and hold in second)
   */
  if (sec>=0 && !(sec>=91&&sec<=97)) dmd.clearScreen(BLACK);
  dmd.drawString(  x,  y, text, strlen(text), WHITE,BLACK );
  if(sec>=98) return;
  else if (sec==98) 
  {
    status=0;
    return;
  }
  else if (sec>=1)
  {
    if (sec>90) sec -=90;
    delay (sec*950); 
    dmd.clearScreen(BLACK); 
    status=0;
  } 
}
//####################################################################


void displayClockSqrTemp() {
  dmd.selectFont(SystemFont5x7);
  tampilSuhu(19, 4);
  runClockBox(0, 0);
}

void displayClockDateBig() {
  runClockBox(0, 0);
  drawDateTextBig(19, 0);
}

void displayClockSqrAndMini() {
  jamAngka(19, 4);
  runClockBox(0, 0);
}

void displayClockSqrHum() {
  dmd.selectFont(SystemFont5x7);
  tampilKelembaban(20, 4);
  runClockBox(0, 0);
}

void displayClockBig() {
  drawTextClockBig(8, 0);
}

void displayClockMid() {
  drawTextClock(15, 0);
}

void displayClockMini() {
  jamAngka(19, 4);
}

void displayTemp() {
  dmd.selectFont(Comic_Sans_MS_Custom_13);
  tampilSuhu(19, 1);
}

void displayHum() {
  dmd.selectFont(Comic_Sans_MS_Custom_13);
  tampilKelembaban(19, 0);
}

void displayDateBig() {
  drawDateTextBig(16, 0);
}


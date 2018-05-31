void displayClockSqrTemp(){
  dmd.clearScreen(0 );
  dmd.selectFont(minimalis);
  tampilSuhu(19, 4);  
  runClockBox(0, 0); 
}

void displayClockSqrAndMini(){
  dmd.clearScreen(0 );
  jamAngka(19, 4);
  runClockBox(0, 0); 
}

void displayClockSqrHum(){
  dmd.clearScreen(0 );
  dmd.selectFont(minimalis);
  tampilKelembaban(19, 7);  
  runClockBox(0, 0); 
}

void displayClockBig(){
  dmd.clearScreen(0 );
  drawTextClockBig(8,0); 
}

void displayClockMid(){
  dmd.clearScreen(0 );
  drawTextClock(15, 0);
}

void displayClockMini(){
  dmd.clearScreen(0 );
  jamAngka(19, 4);
}

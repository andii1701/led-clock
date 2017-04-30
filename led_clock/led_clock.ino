#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

byte LEDBRIGHTNESS = 32; // 0-255

int previousMinute = -1;

// If you're using the full breakout...
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
// If you're using the FeatherWing version
//Adafruit_IS31FL3731_Wing matrix = Adafruit_IS31FL3731_Wing();


// 3x4 font from https://groups.google.com/forum/#!topic/puzzlescript/fwS7x57qd8E
byte a2[8]= {B01100000,
             B10100000,
             B11100000,
             B10100000, 0x00, 0x00, 0x00, 0x00};

byte b2[8]= {B11000000,
             B11100000,
             B10100000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte c2[8]= {B11100000,
             B10000000,
             B10000000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte d2[8]= {B11000000,
             B10100000,
             B10100000,
             B11100000, 0x00, 0x00, 0x00, 0x00};


byte one[8]= {B01000000,
              B11000000,
              B01000000,
              B11100000, 0x00, 0x00, 0x00, 0x00};

byte two[8]= {B01100000,
              B11100000,
              B10000000,
              B11100000, 0x00, 0x00, 0x00, 0x00};

byte three[8]= {B11100000,
                B01100000,
                B00100000,
                B11100000, 0x00, 0x00, 0x00, 0x00};

byte four[8]= {B10000000,
               B10100000,
               B11100000,
               B00100000, 0x00, 0x00, 0x00, 0x00};

byte five[8]= {B11000000,
               B11100000,
               B00100000,
               B11100000, 0x00, 0x00, 0x00, 0x00};

byte six[8]= {B11100000,
              B11000000,
              B10100000,
              B11100000, 0x00, 0x00, 0x00, 0x00};

byte seven[8]= {B11100000,
                B00100000,
                B01000000,
                B10000000, 0x00, 0x00, 0x00, 0x00};

byte eight[8]= {B11100000,
                B11100000,
                B10100000,
                B11100000, 0x00, 0x00, 0x00, 0x00};

byte nine[8]= {B11100000,
               B10100000,
               B01100000,
               B11100000, 0x00, 0x00, 0x00, 0x00};

byte zero[8]= {B11100000,
               B10100000,
               B10100000,
               B11100000, 0x00, 0x00, 0x00, 0x00};

char *noArray[] = {zero, one, two, three, four, five, six, seven, eight, nine};


byte a[8] = {0x00, 0x7c, 0x44, 0x44, 0x7c, 0x44, 0x00, 0x00};
byte b[8] = {0x00, 0x7c, 0x44, 0x78, 0x44, 0x7c, 0x00, 0x00};
byte c[8] = {0x00, 0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00, 0x00};
byte d[8] = {0x00, 0x78, 0x44, 0x44, 0x44, 0x78, 0x00, 0x00};
byte e[8] = {0x00, 0x7c, 0x40, 0x78, 0x40, 0x7c, 0x00, 0x00};
byte f[8] = {0x00, 0x7c, 0x40, 0x70, 0x40, 0x40, 0x00, 0x00};
byte g[8] = {0x00, 0x7c, 0x40, 0x4c, 0x44, 0x7c, 0x00, 0x00};
byte h[8] = {0x00, 0x44, 0x44, 0x7c, 0x44, 0x44, 0x00, 0x00};
byte i[8] = {0x00, 0x7c, 0x10, 0x10, 0x10, 0x7c, 0x00, 0x00};
byte j[8] = {0x00, 0x0c, 0x04, 0x04, 0x44, 0x7c, 0x00, 0x00};
byte k[8] = {0x00, 0x44, 0x48, 0x70, 0x48, 0x44, 0x00, 0x00};
byte l[8] = {0x00, 0x40, 0x40, 0x40, 0x40, 0x7c, 0x00, 0x00};
byte m[8] = {0x00, 0x44, 0x6c, 0x54, 0x44, 0x44, 0x00, 0x00};
byte n[8] = {0x00, 0x44, 0x64, 0x54, 0x4c, 0x44, 0x00, 0x00};
byte o[8] = {0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00, 0x00};
byte p[8] = {0x00, 0x78, 0x44, 0x78, 0x40, 0x40, 0x00, 0x00};
byte q[8] = {0x00, 0x7c, 0x44, 0x44, 0x7c, 0x10, 0x00, 0x00};
byte r[8] = {0x00, 0x78, 0x44, 0x78, 0x44, 0x44, 0x00, 0x00};
byte s[8] = {0x00, 0x7c, 0x40, 0x7c, 0x04, 0x7c, 0x00, 0x00};
byte t[8] = {0x00, 0x7c, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00};
byte u[8] = {0x00, 0x44, 0x44, 0x44, 0x44, 0x7c, 0x00, 0x00};
byte v[8] = {0x00, 0x44, 0x44, 0x28, 0x28, 0x10, 0x00, 0x00};
byte w[8] = {0x00, 0x44, 0x44, 0x54, 0x54, 0x28, 0x00, 0x00};
byte x[8] = {0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00, 0x00};
byte y[8] = {0x00, 0x44, 0x44, 0x28, 0x10, 0x10, 0x00, 0x00};
byte z[8] = {0x00, 0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00, 0x00};

byte ze[8] = {0x00, 0x7c, 0x4c, 0x54, 0x64, 0x7c, 0x00, 0x00};
byte on[8] = {0x00, 0x10, 0x30, 0x10, 0x10, 0x38, 0x00, 0x00};
byte tw[8] = {0x00, 0x78, 0x04, 0x38, 0x40, 0x7c, 0x00, 0x00};
byte th[8] = {0x00, 0x7c, 0x04, 0x38, 0x04, 0x7c, 0x00, 0x00};
byte fo[8] = {0x00, 0x40, 0x40, 0x50, 0x7c, 0x10, 0x00, 0x00};
byte fi[8] = {0x00, 0x7c, 0x40, 0x78, 0x04, 0x78, 0x00, 0x00};
byte si[8] = {0x00, 0x7c, 0x40, 0x7c, 0x44, 0x7c, 0x00, 0x00};
byte se[8] = {0x00, 0x7c, 0x04, 0x08, 0x10, 0x10, 0x00, 0x00};
byte ei[8] = {0x00, 0x7c, 0x44, 0x7c, 0x44, 0x7c, 0x00, 0x00};
byte ni[8] = {0x00, 0x7c, 0x44, 0x7c, 0x04, 0x7c, 0x00, 0x00};

void setup() {

  
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  
  /*matrix.drawBitmap(0, 0, nine, 3, 4, 64);
  matrix.drawBitmap(4, 0, zero, 3, 4, 64);
  matrix.drawBitmap(8, 0, three, 3, 4, 64);
  matrix.drawBitmap(12, 0, four, 3, 4, 64);

  matrix.drawBitmap(0, 5, five, 3, 4, 64);
  matrix.drawBitmap(4, 5, six, 3, 4, 64);
  matrix.drawBitmap(8, 5, seven, 3, 4, 64);
  matrix.drawBitmap(12, 5, eight, 3, 4, 64);*/

}

String twoDigitInt2String(int i)  {
  String s = String(i);
  if (i < 10)  {
    s = '0'+s;
  }
  return s;
}

void loop() {
  DateTime now = rtc.now();
  int currentMinute = now.minute();
  int currentHour = now.hour();
  
  if (previousMinute != currentMinute)  {
      previousMinute = currentMinute;
      String min = twoDigitInt2String(currentMinute);
      String hour = twoDigitInt2String(currentHour);
      matrix.clear();
      matrix.drawBitmap(0, 0, (byte*)noArray[(int)hour[0]-'0'], 3, 4, LEDBRIGHTNESS);
      matrix.drawBitmap(4, 0, (byte*)noArray[(int)hour[1]-'0'], 3, 4, LEDBRIGHTNESS);
      matrix.drawBitmap(8, 0, (byte*)noArray[(int)min[0]-'0'], 3, 4, LEDBRIGHTNESS);
      matrix.drawBitmap(12, 0, (byte*)noArray[(int)min[1]-'0'], 3, 4, LEDBRIGHTNESS);
  }
  
  
  
   
    /*Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7,12,30,6));
    
    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
    
    Serial.println();
    delay(3000);
*/
}


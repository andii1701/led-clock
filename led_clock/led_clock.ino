#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

byte LEDBRIGHTNESS = 32; // 0-255

int previousMinute = -1;

bool DEBUG = true;

// If you're using the full breakout...
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
// If you're using the FeatherWing version
//Adafruit_IS31FL3731_Wing matrix = Adafruit_IS31FL3731_Wing();



//3x9 number digit font bitmaps
byte one[]= {B01000000,
             B11000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B01000000,
             B11100000};

byte two[]= {B11100000,
             B00100000,
             B00100000,
             B00100000,
             B11100000,
             B10000000,
             B10000000,
             B10000000,
             B11100000};

byte three[]= {B11100000,
               B00100000,
               B00100000,
               B00100000,
               B11100000,
               B00100000,
               B00100000,
               B00100000,
               B11100000};

byte four[]= {B10100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000};

byte five[]= {B11100000,
              B10000000,
              B10000000,
              B10000000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B11100000};


byte six[]=  {B11100000,
              B10000000,
              B10000000,
              B10000000,
              B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000};

byte seven[]={B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000};

byte eight[]={B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000};

byte nine[]={ B11100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000,
              B00100000,
              B00100000,
              B00100000,
              B00100000};

byte zero[]={ B11100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B10100000,
              B11100000};

char *noArray[] = {zero, one, two, three, four, five, six, seven, eight, nine};


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
  
}

String convertIntTo2DigitString(int i)  {
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

  if (DEBUG)  {
    currentMinute = now.second();
    currentHour = currentMinute;
  }
  
  if (previousMinute != currentMinute)  {
      previousMinute = currentMinute;
      String min = convertIntTo2DigitString(currentMinute);
      String hour = convertIntTo2DigitString(currentHour);

      matrix.clear();
      matrix.drawBitmap(0, 0, (byte*)noArray[(int)hour[0]-'0'], 3, 9, LEDBRIGHTNESS);
      matrix.drawBitmap(4, 0, (byte*)noArray[(int)hour[1]-'0'], 3, 9, LEDBRIGHTNESS);
      matrix.drawBitmap(8, 0, (byte*)noArray[(int)min[0]-'0'], 3, 9, LEDBRIGHTNESS);
      matrix.drawBitmap(12, 0, (byte*)noArray[(int)min[1]-'0'], 3, 9, LEDBRIGHTNESS);
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


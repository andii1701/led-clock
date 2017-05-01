#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

byte LED_BRIGHTNESS = 32;

// If you're using the full breakout...
Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();
// If you're using the FeatherWing version
//Adafruit_IS31FL3731_Wing matrix = Adafruit_IS31FL3731_Wing();

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  smile_look_left_bmp[] =
  { B00111100,
    B01000010,
    B11001001,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
   smile_look_right_bmp[] =
  { B00111100,
    B01000010,
    B10010011,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  sick_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10101001,
    B10010101,
    B01000010,
    B00111100 },
  sick2_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10010101,
    B10101001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };


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

 
byte e2[8]= {B11100000,
             B11000000,
             B10000000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte f2[8]= {B11100000,
             B11000000,
             B10000000,
             B10000000, 0x00, 0x00, 0x00, 0x00};

byte g2[8]= {B11100000,
             B10000000,
             B10100000,
             B11000000, 0x00, 0x00, 0x00, 0x00};

byte h2[8]= {B10100000,
             B10100000,
             B11100000,
             B10100000, 0x00, 0x00, 0x00, 0x00};

byte i2[8]= {B11100000,
             B01000000,
             B01000000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte l2[8]= {B10000000,
             B10000000,
             B10000000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte m2[8]= {B11100000,
             B11100000,
             B10100000,
             B10100000, 0x00, 0x00, 0x00, 0x00};
             
byte n2[8]= {B11000000,
             B10100000,
             B10100000,
             B10100000, 0x00, 0x00, 0x00, 0x00};
             
byte o2[8]= {B11000000,
             B10100000,
             B10100000,
             B01100000, 0x00, 0x00, 0x00, 0x00};

byte p2[8]= {B11000000,
             B10100000,
             B11100000,
             B10000000, 0x00, 0x00, 0x00, 0x00};
             
byte r2[8]= {B11000000,
             B10100000,
             B11000000,
             B10100000, 0x00, 0x00, 0x00, 0x00};

byte s2[8]= {B11000000,
             B11100000,
             B00100000,
             B11100000, 0x00, 0x00, 0x00, 0x00};

byte t2[8]= {B11100000,
             B01000000,
             B01000000,
             B01000000, 0x00, 0x00, 0x00, 0x00};

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

byte minus2[8]= {B00000000,
                 B11100000,
                 B00000000,
                 B00000000, 0x00, 0x00, 0x00, 0x00};

byte bang2[8]= {B01000000,
                 B01000000,
                 B00000000,
                 B01000000, 0x00, 0x00, 0x00, 0x00};

char *noArray[] = {zero, one, two, three, four, five, six, seven, eight, nine};



void setup() {

  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  
}

void default_amination()  {
   int mDelay = 1000;
   matrix.clear();
   matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(mDelay);

   matrix.clear();
   matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(mDelay);

   matrix.clear();
   matrix.drawBitmap(5, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(mDelay);

   matrix.clear();
   matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(mDelay);
  
}


void get_a_cnc()  {
   int mDelay = 3000;
   matrix.clear();
   matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(1000);

   matrix.clear();
   matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(1000);

   matrix.clear();
   matrix.drawBitmap(5, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(1000);

   matrix.clear();
   matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
   delay(1000);

   matrix.clear();
   matrix.drawBitmap(0, 0, g2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(4, 0, e2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(8, 0, t2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(12, 0, a2, 3, 4, LED_BRIGHTNESS);

   matrix.drawBitmap(0, 5, c2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(4, 5, n2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(8, 5, c2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(12, 5, bang2, 3, 4, LED_BRIGHTNESS);
   delay(mDelay);
   matrix.clear();
   matrix.drawBitmap(0, 0, l2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(4, 0, a2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(8, 0, m2, 3, 4, LED_BRIGHTNESS);
   matrix.drawBitmap(12, 0, o2, 3, 4, LED_BRIGHTNESS);
   delay(1000);
}


void stop_here()  {
  LED_BRIGHTNESS = 64;
  matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(3000);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, s2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, t2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, p2, 3, 4, LED_BRIGHTNESS);

  delay(3000);
  
  //matrix.clear();

  matrix.drawBitmap(0, 5, h2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, e2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 5, r2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 5, e2, 3, 4, LED_BRIGHTNESS);

  delay(3000);
  
  //matrix.clear();
}

void ill_be_good()  {
  LED_BRIGHTNESS = 32;
  matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(6000);

  matrix.clear();
  matrix.drawBitmap(0, 0, i2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, l2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, l2, 3, 4, LED_BRIGHTNESS);

  matrix.drawBitmap(0, 5, b2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, e2, 3, 4, LED_BRIGHTNESS);
  delay(3000);
  matrix.clear();
  
  matrix.drawBitmap(0, 0, g2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, d2, 3, 4, LED_BRIGHTNESS);

  matrix.drawBitmap(0, 5, bang2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, bang2, 3, 4, LED_BRIGHTNESS);
  delay(3000);

  matrix.clear();
  matrix.drawBitmap(4, 5, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(3000);

  matrix.drawBitmap(0, 0, l2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, a2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, m2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, o2, 3, 4, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(4, 5, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(3000);
}


void frown_and_hide()  {
  LED_BRIGHTNESS = 32;
  matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(4, 0, frown_bmp, 8, 8, LED_BRIGHTNESS);
  delay(6000);

  matrix.clear();
  matrix.drawBitmap(0, 0, i2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, l2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, l2, 3, 4, LED_BRIGHTNESS);

  matrix.drawBitmap(0, 5, b2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, e2, 3, 4, LED_BRIGHTNESS);
  delay(1000);
  matrix.clear();
  
  matrix.drawBitmap(0, 0, g2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, d2, 3, 4, LED_BRIGHTNESS);
  delay(3000);

  matrix.clear();
  matrix.drawBitmap(4, 5, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(3000);
}

void hand_tool_hipster()  {
  LED_BRIGHTNESS = 64;
  matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(4, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(3000);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, h2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, a2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, n2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, d2, 3, 4, LED_BRIGHTNESS);

  matrix.drawBitmap(0, 5, t2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 5, o2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 5, l2, 3, 4, LED_BRIGHTNESS);

  delay(3000);
  
  matrix.clear();
  matrix.drawBitmap(0, 0, h2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, i2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, p2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, minus2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(0, 5, s2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 5, t2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 5, e2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 5, r2, 3, 4, LED_BRIGHTNESS);
  
  delay(3000);
  
  matrix.clear();

  matrix.drawBitmap(0, 0, l2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(4, 0, a2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(8, 0, m2, 3, 4, LED_BRIGHTNESS);
  matrix.drawBitmap(12, 0, o2, 3, 4, LED_BRIGHTNESS);
  delay(3000);
}

void demo()  {
   matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_bmp, 8, 8, 255);
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(3, 0, neutral_bmp, 8, 8, 64);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, frown_bmp, 8, 8, 32);
  delay(500);

  matrix.clear();
  matrix.drawPixel(0, 0, 255);  
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, matrix.width()-1, matrix.height()-1, 127);
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, matrix.width(), matrix.height(), 255);
  matrix.fillRect(2,2, matrix.width()-4, matrix.height()-4, 20);
  delay(500);

  matrix.clear();
  matrix.drawCircle(8,4, 4, 64);
  matrix.drawCircle(8,4, 2, 32);
  delay(500);


  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(100);
  for (int8_t x=0; x>=-32; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    delay(100);
  }

  matrix.setTextSize(2);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(32);
  matrix.setRotation(1);
  for (int8_t x=7; x>=-64; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("World");
    delay(100);
  }
}

void frown_netural_smile()  {
     matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(3, 0, neutral_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, frown_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(2, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, neutral_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(4, 0, frown_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_look_left_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);
  
  matrix.clear();
  matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_look_right_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, smile_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, sick_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);

  matrix.clear();
  matrix.drawBitmap(3, 0, sick2_bmp, 8, 8, LED_BRIGHTNESS);
  delay(500);
}


void loop() {
  //frown_netural_smile();
  //demo();
  default_amination();
  //stop_here();
  //hand_tool_hipster();
  //ill_be_good();
  //get_a_cnc();
  //frown_and_hide();
}

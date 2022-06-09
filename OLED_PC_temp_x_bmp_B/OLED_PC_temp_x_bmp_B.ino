#include <SPI.h>
#include <Wire.h>
#include <AHT10.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "i2c.h"
#include "i2c_BMP280.h"
BMP280 bmp280;

#include "OLED_Bmp.h"
#include <avr/wdt.h> 
#include <avr/sleep.h>

#define SCREEN_WIDTH 128 // OLED 寬度像素
#define SCREEN_HEIGHT 64 // OLED 高度像素
// 設定OLED
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

AHT10 myAHT10(AHT10_ADDRESS_0X38);
int metemp_A,TEMP_i,TEMP_Animation,Counter_TEMP;

void setup() {

  
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 一般1306 OLED的位址都是0x3C// 偵測是否安裝好OLED了
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  display.clearDisplay();
  display.setTextSize(2);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(0,0);
      
  if (bmp280.initialize()) 
  {
    
  }
  else
  {
    display.setCursor(30,0);
  display.println(F("BMP")); //OLED
  display.println(F("  Fail !!!"));
  display.setTextSize(1);
  display.setCursor(10,56);
  display.print(F("Please button REST "));
  display.display();
  Serial.println(F("Could not find a valid BMP085 sensor, check wiring!")); //檢測BMP085有無連線
  delay(1500);
  while (1) {} //死機
  }
  
 if (myAHT10.begin() != true)
  {
  display.setCursor(35,0);
  display.println(F("AHT10")); //OLED
  display.println(F("  Fail !!!"));
  display.setTextSize(1);
  display.setCursor(10,56);
  display.print(F("Please button REST "));
  display.display();
  Serial.println(F("AHT10 not connected or fail to load calibration coefficient")); //(F()) save string to flash & keeps dynamic memory free
   delay(1500);
    while (1) {}
  }
  
}

void loop() {
  wdt_enable(WDTO_8S);

 bmp280.awaitMeasurement(); 
float BMP_T ;
bmp280.getTemperature(BMP_T) ;
BMP_T=BMP_T-1;
float BMP_Pa;
bmp280.getPressure(BMP_Pa);

static float BMP_MA,BMP_MB;

  bmp280.getAltitude(BMP_MA);
 // bmp280.getAltitude_TW(BMP_MB);
  BMP_MB = (BMP_MB * 10 + BMP_MA)/11;
  //BMP_MA=bmp.readAltitude();
 // BMP_MB=bmp.readAltitude(1008);
 // BMP_MB = (BMP_MB * 10 + BMP_MA)/11;
 bmp280.triggerMeasurement();
  
//float BMP_Pa2=bmp.readAltitude();
//float BMP_M2=bmp.readAltitude(1008));
float AHT_T=myAHT10.readTemperature();
float AHT_H=myAHT10.readHumidity();
byte Temp_MAX = ((AHT_T+BMP_T)/2);




    Serial.print(F("Temperature = "));
    //Serial.print(bmp.readTemperature());
    Serial.print(BMP_T);
    Serial.println(F(" *C"));
    
    Serial.print(F("Pressure = "));
   // Serial.print(bmp.readPressure());
    Serial.print(BMP_Pa);
    Serial.println(F(" Pa"));
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print(F("Altitude = "));
    //Serial.print(bmp.readAltitude());
    Serial.print(BMP_MA);
    Serial.println(F(" meters"));

   
    Serial.print(F("Pressure at sealevel (calculated) = "));
    //Serial.print(bmp.readSealevelPressure());
    Serial.print(BMP_Pa);
    Serial.println(F(" Pa"));

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print(F("Real altitude = "));
    Serial.print(BMP_MB);
    //Serial.print(bmp.readAltitude(101500));
    Serial.println(F(" meters"));


    Serial.print(F("Temperature: ")); 
    //Serial.print(myAHT10.readTemperature());
    Serial.print(AHT_T);
    Serial.println(F(" +-0.3C"));
    
    Serial.print(F("Humidity...: ")); 
    //Serial.print(myAHT10.readHumidity());
    Serial.print(AHT_H);    
    Serial.println(F(" +-2%"));
 
    Serial.println((AHT_T+BMP_T)/2); //test two temp

    metemp_A=metemp_A+1;  //測試當機
    Serial.println(metemp_A); //測試當機
    Serial.println();
    delay(100);
    
  display.clearDisplay();


for(TEMP_i=1 ; TEMP_i<=4 ; TEMP_i=TEMP_i+1){
  display.drawBitmap(0,0,logo_line,128, 64, 1); //線顯示
//溫度圖片
//
display.drawBitmap(0,0,logo_T,8, 20, 1);
   if (((AHT_T+BMP_T)/2>=26) && ((AHT_T+BMP_T)/2) <= 33){
    display.drawBitmap(0,0,logo_TT,8, 20, 1);
  }
  else if (((AHT_T+BMP_T)/2)>=34 && ((AHT_T+BMP_T)/2) <= 38){
    display.drawBitmap(0,0,logo_TTT,8, 20, 1);
  }
  else if (((AHT_T+BMP_T)/2)>=39){
    display.drawBitmap(0,0,logo_TTTT,8, 20, 1);
  }
//////////
//  

  display.drawBitmap(0,28,logo_H,8, 12, 1);
  display.setTextSize(2);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(10,2);
  display.print(F(": ")); 
  display.print((AHT_T+BMP_T)/2,1);
  display.println(F(" C"));
  display.setCursor(10,25);
  display.print(F(": ")); 
  display.print(AHT_H,1);
  display.println(F(" %"));
  display.setTextSize(1);
  display.setCursor(0,48);
  display.print(F("Pressure: ")); 
  display.print(BMP_Pa/1000);
  display.println(F(" kPa"));
  display.print(F("Altitude: "));
  display.print(BMP_MA);
  display.print(F(" m"));
  display.display();
  delay(800);
}
 // sleep_enable();// 啟用睡眠模式
 // sleep_cpu ();  // 進入睡眠模式
 
display.clearDisplay();
  
  if (Counter_TEMP<=1){
Counter_TEMP=Counter_TEMP+1;
  }
  else if (Counter_TEMP>=2){
     Big_temp_display();
     Counter_TEMP=0;
  }

   wdt_reset();
}


void Big_temp_display(void) {
//     byte Temp_MAX = ((myAHT10.readTemperature()+bmp.readTemperature())/2);
float Temp_BMP;
 bmp280.getTemperature(Temp_BMP);
 Temp_BMP=Temp_BMP-1;
byte Temp_MAX =((myAHT10.readTemperature()+Temp_BMP)/2);
    for(TEMP_Animation =1 ; TEMP_Animation<=100 ; TEMP_Animation=TEMP_Animation+1)
  {
    if(Temp_MAX <= 8){
  display.drawBitmap(0,TEMP_Animation,logo_COOL10, 26, 26, 1);
  display.drawBitmap(20,TEMP_Animation-30,logo_COOL10, 26, 26, 1);
  display.drawBitmap(50,TEMP_Animation-60,logo_COOL10, 26, 26, 1);
  display.drawBitmap(-10,TEMP_Animation-55,logo_COOL10, 26, 26, 1);
  display.drawBitmap(18,TEMP_Animation-85,logo_COOL10, 26, 26, 1);
  Big_temp();
  display.display();
  
  TEMP_Animation=TEMP_Animation+10;
  delay(60);
    }
    else if (Temp_MAX >= 9 && Temp_MAX <= 18){
 
  display.drawBitmap(0,0,logo_COOL15_A, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);
  display.drawBitmap(0,0,logo_COOL15_B, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL15_C, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL15_D, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30); 


  
  TEMP_Animation=TEMP_Animation+22;
  
    }
    else if (Temp_MAX >= 19 && Temp_MAX <= 28){
  
/*  display.drawBitmap(0,0,logo_COOL20_A, 42, 40, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);
  display.drawBitmap(0,0,logo_COOL20_B, 42, 40, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL20_C, 42, 40, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30); */
  display.drawBitmap(0,0,logo_COOL21_A, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL21_B, 62, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);
  TEMP_Animation=TEMP_Animation+16;
  
    }
else if (Temp_MAX >= 29 ){

   display.drawBitmap(0,0,logo_COOL30_A, 63, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);
  display.drawBitmap(0,0,logo_COOL30_B, 63, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL30_C, 63, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30);  
  display.drawBitmap(0,0,logo_COOL30_D, 63, 64, 1);
  Big_temp();
  display.display();
  display.clearDisplay();
  delay(30); 
  TEMP_Animation=TEMP_Animation+22;
    }
    
display.clearDisplay();
//Serial.println(TEMP_Animation);

  }
}

void Big_temp(void) { 
//  byte Temp_MAX = ((myAHT10.readTemperature()+bmp.readTemperature())/2);

float Temp_BMP;
 bmp280.getTemperature(Temp_BMP);
 Temp_BMP=Temp_BMP-1;
byte Temp_MAX =((myAHT10.readTemperature()+Temp_BMP)/2);

  display.setTextSize(5);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(68,13);
  display.print(Temp_MAX);
}

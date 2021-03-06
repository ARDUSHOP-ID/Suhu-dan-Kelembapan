/*************************************************************
  This example shows how value can be pushed from Arduino to
  Serial Monitor dan LCD 1602        
                                                                        
   ;;`  .;;;;;  ;;;;:  ;;` `;;  ;;;;  ;;  :;.  ;;;;`  ;;;;:   ;;  ;;;;, 
  ,;;;  .;:.;;, ;;:;;; ;;` `;; ;; ,;: ;;  :;. ;;;:;;  ;;.;;.  ;;  ;;:;;,
  ;;;;  .;: :;, ;;  ;; ;;` `;; ;;;,   ;;,,;;. ;;  ,;, ;; ,;,  ;;  ;;  ;;
 `;:`;, .;;;;;  ;;  ;; ;;` `;;  ;;;;, ;;;;;;.`;;  .;: ;;;;;   ;;  ;;  ;;
 :;;;;; .;:.;;  ;;  ;; ;;` `;; `. `;; ;;  :;. ;;  :;, ;;``    ;;  ;;  ;;
 ;;;;;; .;: ;;. ;;:;;: .;;:;;. ;;..;; ;;  :;. ;;;:;;  ;;   ;; ;;  ;;:;;
 
  WARNING :
  For this example you'll need library & Arduino part :
    Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  Need Arduino Part :
  https://www.tokopedia.com/ardushopid
  or Whatsapp Only 082111545939
  Find Me on FB :
  https://id-id.facebook.com/people/Ardushop-Id/100015723427957
  
  Pin DHT >> Pin Arduino
  1 VCC   >>    +5V
  2 DATA  >>    Pin 6 Digital
  3 NC    >>    Tidak dipakai
  4 GND   >>    GND
  
  Pin Potensiometer >> Pin Arduino&LCD
  1. KAKI KIRI      >>  GND
  2. KAKI TENGAH    >>  KE PIN 3 VEE LCD
  3. KAKI KANAN     >>  +5V
    
  Pin LCD >> Pin Arduino
  1  GND  >>    GND
  2  VCC  >>    +5V
  3  VEE  >>  Ke Pin Tengah Potensiometer
  4  RS   >>    Pin 12 Digital
  5  RW   >>    GND
  6  RE   >>    Pin 11 Digital
  7  D0   >>    Tidak dipakai
  8  D1   >>    Tidak dipakai
  9  D2   >>    Tidak dipakai
  10 D3   >>    Tidak dipakai
  11 D4   >>    Pin 10 Digital
  12 D5   >>    Pin 9 Digital
  13 D6   >>    Pin 8 Digital
  14 D7   >>    Pin 7 Digital
  15 A    >>    +5V
  16 K    >>    GND
 *************************************************************/
 
#include <DHT.h>  //menyertakan library DHT kedalam program
#include <LiquidCrystal.h> //menyertakan library LCD

#define DHTPIN 6  //pasang sensor pada pin 6 digital
#define DHTTYPE DHT11 //kita menggunakan jenis sensor DHT11, ubah jika kamu gunakan sensor lain seperti DHT22 (AM2302) atau DHT21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE); //deklarasi pin sensor dengan jenis sensor yang dipilih

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); //pin yang dipakai LCD


void setup() {
  lcd.begin(16, 2); //mengatur ukuran lcd yang dipakai
  dht.begin(); //program komunikasi atau setup untuk sensor DHT
  Serial.begin(9600); //program komunikasi atau setup untuk serial monitor dan kecepatan komunikasi (baudrate)
}

void loop() {
  float kelembapan = dht.readHumidity(); //menyimpan nilai kelembapan pada variabel kelembapan
  float suhu = dht.readTemperature(); //menyimpan nilai suhu pada variabel suhu
  delay(500); //mengatur jeda waktu pembacaan sensor selama 500 milidetik
  Serial.print(kelembapan); //menampilkan nilai kelembapan pada Serial Monitor
  Serial.print("%"); //Simbol persen satuan kelembapan
  Serial.print(" "); //menambahkan spasi
  Serial.print(suhu); //menampilkan nilai suhu pada Serial Monitor
  Serial.println("*C"); //Satuan Derajat Suhu
    
    //menampilkan nilai kelembapan pada LCD
    lcd.setCursor(0, 0); //
    lcd.print("kelembapan.: "); 
    lcd.print((int) kelembapan);
    lcd.print("%");
    //menampilkan nilai suhu pada LCD
    lcd.setCursor(0, 1);
    lcd.print("Suhu.: "); 
    lcd.print((int) suhu);
    lcd.print((char)223); //Simbol Derajat di LCD
    lcd.print("C ");
}


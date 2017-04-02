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
    VCC   >>    +5V
    DATA  >>    Pin 6 Digital
    NC    >>    Tidak dipakai
    GND   >>    GND
    
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

#define DHTPIN 6  //kita pasang sensor pada pin 6 digital
#define DHTTYPE DHT11 //kita menggunakan jenis sensor DHT11, ubah jika kamu gunakan sensor lain seperti DHT22 (AM2302) atau DHT21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE); //deklarasi pin sensor dengan jenis sensor yang dipilih

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); //pin yang dipakai LCD

int buzzer = 5; //kita menggunakan pin 5 untuk buzzer indikator suara alarm
int led_awas = 4; //kita menggunakan pin 5 untuk led merah indikator awas
int led_aman = 3; //kita menggunakan pin 4 untuk led hijau indikator aman

void setup() {
  lcd.begin(16, 2); //mengatur ukuran lcd yang dipakai
  dht.begin(); //program komunikasi atau setup untuk sensor DHT
  pinMode(led_awas, OUTPUT); //mengatur led sebagai OUTPUT
  pinMode(led_aman, OUTPUT); //mengatur led sebagai OUTPUT
  pinMode(buzzer, OUTPUT); //mengatur buzzer sebagai OUTPUT
  Serial.begin(9600); //program komunikasi atau setup untuk serial monitor dan kecepatan komunikasi (baudrate)
}
/*
  Need Arduino Part :
  https://www.tokopedia.com/ardushopid
  or Whatsapp Only 082111545939
  Find Me on FB :
  https://id-id.facebook.com/people/Ardushop-Id/100015723427957
*/
void loop() {
  float kelembapan = dht.readHumidity(); //menyimpan nilai kelembapan pada variabel kelembapan
  float suhu = dht.readTemperature(); //menyimpan nilai suhu pada variabel suhu
  delay(200); //mengatur jeda waktu pembacaan sensor selama 200 milidetik
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
    
    //kondisi if dibawah ini, silahkan di atur sesuai dengan kebutuhan kamu
 
  if ( kelembapan > 82.10){      //jika kelembapan lebih besar dari 82.10
     digitalWrite(led_awas, HIGH);   //led merah menyala
     digitalWrite(buzzer, HIGH);   //buzzer menyala
     digitalWrite(led_aman, LOW);    //led hijau mati
         }

 else if( suhu > 32.10){         //jika suhu lebih besar dari 32.10 
     digitalWrite(led_awas, HIGH);   //led merah menyala
     digitalWrite(buzzer, HIGH);   //buzzer menyala
     digitalWrite(led_aman, LOW);    //led hijau mati
         }
          
 else{                           //jika tidak   
     digitalWrite(led_aman, HIGH);  //led hijau menyala
     digitalWrite(led_awas, LOW);    //led merah mati
     digitalWrite(buzzer, LOW);    //buzzer mati
        } 
}


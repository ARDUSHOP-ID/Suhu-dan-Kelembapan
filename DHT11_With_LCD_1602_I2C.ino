/*************************************************************
  This example shows how value can be pushed from Arduino to
  Serial Monitor dan LCD 1602 I2C        
                                                                        
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
    LiquidCrystal I2C libraries :
    https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library

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

  Pin LCD I2C >>  Pin Arduino
    VCC       >>  +5V
    GND       >>  GND
    SDA       >>  A4/SDA
    SCL       >>  A5/SCL
 *************************************************************/
 
#include <DHT.h>  //menyertakan library DHT kedalam program
#include <LiquidCrystal_I2C.h>


#define DHTPIN 6  //kita pasang sensor pada pin 6 digital
#define DHTTYPE DHT11 //kita menggunakan jenis sensor DHT11, ubah jika kamu gunakan sensor lain seperti DHT22 (AM2302) atau DHT21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE); //deklarasi pin sensor dengan jenis sensor yang dipilih

LiquidCrystal_I2C lcd(0x27, 16, 2); // Set Alamat I2C dan Ukuran LCD
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  lcd.begin(); // Inisiasi LCD I2C
  lcd.backlight(); // Menyalakan Backlight LCD
  dht.begin(); //program komunikasi atau setup untuk sensor DHT
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
}


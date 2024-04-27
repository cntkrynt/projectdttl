#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int pinTemp = A1; //definisi pin tempat input sensor suhu
int fan = 9; //definisi pin tempat output kipas (dc motor)
int tempMin = 25; //definisi suhu terkecil
int tempMax = 35; //definisi suhu terbesar
float fanSpeed; //pembacaan pwm (speed) kipas
int fanLCD; //pembacaan tampilan kecepatan di lcd 
float temp = pinTemp; //pembacaan sensor suhu
int led = 12; //definisi pin tempat output led

void setup() {
  Serial.begin(  9600  ); //serial komunikasi arduino
  pinMode(pinTemp,INPUT );
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(fan, OUTPUT); //mengidentifikasi kipas sebagai output
  pinMode(led, OUTPUT); //mengidentifikasi led sebagai output
}

void loop() {
  float temp = analogRead(pinTemp); //mendefinisikan temp sebagai pembacaan sensor suhu
  temp = (temp *5.0*100.0)/1023.0; //konversi suhu yang terbaca ke celcius////5v arduino per 8 bit dikurang ketelitian semuaya dibagi 0,01v untuk menyatakan celcius
  if(temp > tempMax) //Jika suhu T > suhu_maks, maka kipas berputar maksimum (fanspeed = 100%) dan indikator LED menyala
       {        
         digitalWrite(led, HIGH);  //LED sebagai Indikator Suhu ruangan melebihi suhu_maks 
         analogWrite(fan, 255);    //Kipas berputar maksimum (sekitar 17000 rpm)
         fanLCD = 100; //tampilan persentase kecepatan kipas di lcd
       }
  else if((temp>=tempMin)&&(temp<=tempMax)){ //membaca suhu antara suhu minimal dan suhu maksimal
    fanSpeed = map(temp, tempMin, tempMax, 50, 255); //membaca otomatis kecepatannya lewat pwm bit arduino
    fanLCD = map(temp, tempMin, tempMax, 0, 100); //menampilkan persentase kecepatan 
  analogWrite(fan, fanSpeed); //menampilkan kecepatan pada layar
    digitalWrite(led, HIGH); //menampilkan output lampu
  } 
  else if(temp < tempMin){ //membaca suhu dibawah suhu minimal
    fanSpeed = 0; //mendefinisikan kecepatan nol saat suhu seperti itu
    fanLCD = 0; //menampilkan persen nol pada layar lcd
  analogWrite(fan, fanSpeed); //menampilkan kecepatan pada layar
    digitalWrite(led, LOW); //menampilkan output lampu
  }
  // set the cursor to column 0, line 0
  // (note: line 0 is the first row, since counting begins with 0):
  lcd.setCursor(0, 0);
  //menampilkan suhu yang sudah terbaca di lcd
  lcd.print("Suhu: ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  //menampilkan kecepatan yang sudah terbaca di lcd
  lcd.print("Speed: ");
  lcd.print(fanLCD);
  lcd.print("%");
  //delay selama 0.2s untuk menampilkan ulang suhu dan kecepatannya
  delay( 200 );
  lcd.clear();
}
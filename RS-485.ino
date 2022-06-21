#include <M5Stack.h> //Menambhakan library m5stack
void setup() {       //Menginisialisasi fungsi void
M5.begin();          //Menghubungkan library M5stack dengan board M5stack
M5.Power.begin();    //Menginisiasi wire dengan I2C
Serial.begin(115200); //Alamat serial begin
// Serial2.begin(unsigned long baud, uint32_t config, int8_t rxPin, int8_t txPin, bool invert)
Serial2.begin(115200, SERIAL_8N1, 16, 17); //Mengambil data dari Pin 16 dan 17
pinMode(5, OUTPUT); //Inisialisai Pin
digitalWrite(5, 1); //Pin 5 dalam kondisi High
}
void loop() {      //Pengulangan
if(Serial.available()) {  //Pengecekan Port Serial kemudian menghasilkan byte
int ch = Serial.read(); // Membaca hasil data
Serial2.write(ch);      // Menulis hasil data
}
if(Serial2.available()) { //Pengecekan Port Serial kemudian menghasilkan byte
int ch = Serial2.read();  //Membaca hasil data
Serial.write(ch);         //Menulis hasil data
}
}

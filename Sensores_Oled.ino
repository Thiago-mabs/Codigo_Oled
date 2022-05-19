#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
const int SensorTensaoPin=A1; 
float TensaoEntrada;
float TensaoSaida;
float ValorTensao;
const int SensorCorrentePin=A0;
float Tensao;
float ValorCorrente;
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
}

void loop() {
  ValorTensao = analogRead(SensorTensaoPin); 
  TensaoSaida = (ValorTensao * 5)/1024;     
  TensaoEntrada = TensaoSaida * 5;
  Tensao = analogRead(SensorCorrentePin * 5)/1024;
  Tensao = Tensao - 2.5 + 0.007;
  ValorCorrente = Tensao/0.04;
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(WHITE); 
  display.setCursor(1,20); 
  display.print("Tensão: "); 
  display.setCursor(1,25);
  display.print(TensaoSaida);
  display.setCursor(1,30);
  display.print("V");
  display.setCursor(2,20); 
  display.print("Corrente: "); 
  display.setCursor(2,25);
  display.print(ValorCorrente);
  display.setCursor(2,30);
  display.print("A");
  display.display(); 
  delay(1000);
}

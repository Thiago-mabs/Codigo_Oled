#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Método para iniciar o display, fazendo a comunicação com I2C
  display.clearDisplay(); //Comando para limpar o display
  

}

void loop() {
  display.clearDisplay();
  display.setTextSize(1); //Comando para escolher o tamanho da fonte 1-8
  display.setTextColor(WHITE); //Comando para escolher a cor do texto
  display.setCursor(1,20); //Comando para "setar" a posição do texto
  display.print("Hello World!!"); //Comando para escrever uma mensagem no display
  display.display(); //Comando para encerrar o código 
}

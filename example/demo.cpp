/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/

#include "../src/ssd1306_i2c.h"
#include <stdio.h>
#include <wiringPi.h>


int main() {

	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

   	ssd1306_display(); //Adafruit logo is visible
	ssd1306_clearDisplay();
/*
    delay(5000);
    // test
	char* text = "This is demo for SSD1306 i2c driver for Raspberry Pi";
	ssd1306_drawString(text);
	ssd1306_display();
	delay(5000);

	ssd1306_dim(1);

*/    
//    ssd1306_startscrollright(00,0xFF);
//	delay(5000);

//	ssd1306_clearDisplay();
//	ssd1306_fillRect(10,10, 50, 20, WHITE);
//	ssd1306_fillRect(80, 10, 130, 50, WHITE);


//  ssd1306_invertDisplay(1);

    ssd1306_clearDisplay();
    for (int i = 0; i < 128; ++i) {
        ssd1306_drawPixel(i, 0, WHITE);
    }
    for (int i = 0; i < 128; ++i) {
        ssd1306_drawPixel(i, 32/2, WHITE);
    }
    for (int i = 0; i < 128; ++i) {
        ssd1306_drawPixel(i, 31, WHITE);
    }

    int minY = 0;
    int maxY = 31;

    for (int i = minY; i < 64; ++i) {
        ssd1306_drawPixel(0, i, WHITE);
    }
    for (int i = minY; i < 64; ++i) {
        ssd1306_drawPixel(127, i, WHITE);
    }

    ssd1306_fillRect(2, 2, 8, 13, WHITE);


    // ssd1306_dim(1);
    ssd1306_display();


    while (true) {
        delay(1000);
        fflush(stdout);
    }

	//ssd1306_display();

    return 0;
}

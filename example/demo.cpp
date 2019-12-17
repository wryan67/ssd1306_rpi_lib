/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/

#include "../src/ssd1306_i2c.h"
#include <stdio.h>
#include <math.h>
#include <wiringPi.h>

static const double PI = 3.14159265358979;

int random(int low, int high) {
    double r = (double)rand() / RAND_MAX;

    return low + (r * (1 + high - low));
}

void drawSine(float offset) {
        bool first=true;;
        int lx=-1,ly=-1;
        double vx=0;
        float vmax=2;
	for (int x=0;x<128;++x) {
          vx= offset+(6*PI)*x/128.0;
          int y=16-sin(vx)*15;
          if (first) {
            first=false;
            ssd1306_drawPixel(x, y, WHITE);
          } else {
            ssd1306_drawLine(lx,ly,x, y, WHITE);
          }
          lx=x;
          ly=y;
        }
}

int main() {
    int seed;
    FILE* fp;
    fp = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(seed), 1, fp);
    fclose(fp);
    srand(seed);

	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

   	ssd1306_display(); //Adafruit logo is visible
//      ssd1306_invertDisplay(1);

    while (true) {
        ssd1306_clearDisplay();
        ssd1306_dim(0);

        for (int i = 0; i < 15; ++i) {
            for (int i = 0; i < 10; ++i) {
                ssd1306_drawPixel(random(0, 127), random(0, 31), WHITE);
            }
            ssd1306_display();
        }


        ssd1306_dim(1);
        delay(300);
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

    
        ssd1306_moveCursor(2, 5);

        ssd1306_drawString("Hello World!!!");

        ssd1306_fillRect(85, 2, 8, 13, WHITE);

        ssd1306_display();


        ssd1306_drawCircle(110, 16, 15, WHITE);

    // clock
        for (double d = 0; d < 360; d += 360/12) {
            int x2, y2;

            ssd1306_arcPoint(110, 16, 12, d, &x2, &y2);

            ssd1306_drawLine(110, 16, x2, y2, WHITE);
        }


    // base lines
        ssd1306_drawLine(15, 29, 30, 29, WHITE);
        ssd1306_drawLine(15, 30, 30, 30, WHITE);

    // hash marks    
        ssd1306_drawLine(20, 18, 20, 25, WHITE);
        ssd1306_drawLine(25, 18, 25, 25, WHITE);


    // test endpoint lines
            
        ssd1306_quickLine(0, 18, 20, 29, BLACK);
        ssd1306_drawLine (5, 18, 25, 29, BLACK);


    //    ssd1306_drawPixel(35, 29, BLACK);

    // diagonal lines

        for (int i = 32; i < 100; i += 5) {
            ssd1306_drawLine(32, 18, i, 29, WHITE);
        }
    
        ssd1306_display();



        delay(2000);

  
        for (int i=0;i<75;++i) {
          ssd1306_clearDisplay();
          drawSine(i*(PI*0.1));
          ssd1306_display();
        }




        fflush(stdout);
    }

	//ssd1306_display();

    return 0;
}



all:  demo

demo: objects
	g++ example/demo.cpp obj/*.o -lwiringPi -o demo


objects:  src/ssd1306_i2c.c src/ssd1306_i2c.h src/oled_fonts.h
	@mkdir -p obj
	gcc -c src/ssd1306_i2c.c -o obj/ssd1306_i2c.o -lm


clean:
	rm -f obj/*.o demo

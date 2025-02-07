#include <xinu.h>

typedef unsigned short u16;
// u16 *videoBuffer = (u16 *)0x6000000;
// #define scanlinecounter *(volatile u16 *)0x4000006
extern void gui_set_pixel(int x, int y, u16 color);
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
void drawImage3(int x, int y, int width, int height, const u16* image);
// void delay();
void waitForVBlank();

void drawRect(int x, int y, int width, int height, u16 color) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			gui_set_pixel(x + i, y + j, color);
		}
	}
}

void drawHollowRect(int x, int y, int width, int height, u16 color) {
	for (int i = 0; i < width; i++) {
		gui_set_pixel(x + i, y, color);
		gui_set_pixel(x + i, y + (height - 1), color);
	}
	for (int j = 0; j < height; j++) {
		gui_set_pixel(x, y + j, color);
		gui_set_pixel(x + (width - 1), y + j, color);
	}
}

void drawImage3(int x, int y, int width, int height, const u16* image) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			u16 color = *(image + i + (width * j));
			gui_set_pixel(x + i, y + j, color);
		}
	}
}

void delay_galaga() {
	for (int a = 0; a < 10; a++) {
		a++;
	}
}

void waitForVBlank() {
	sleepms(20);
	// while(scanlinecounter > 160);
	// while(scanlinecounter < 160);
}

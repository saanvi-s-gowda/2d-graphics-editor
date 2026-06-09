#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

char picture[HEIGHT][WIDTH];

void clearPicture() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            picture[i][j] = EMPTY;
        }
    }
}

void displayPicture() {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}
void setPixel(int x, int y) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        picture[y][x] = PIXEL;
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1) {
        setPixel(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
void drawRectangle(int x1, int y1, int x2, int y2) {
    drawLine(x1, y1, x2, y1);
    drawLine(x2, y1, x2, y2);
    drawLine(x2, y2, x1, y2);
    drawLine(x1, y2, x1, y1);
}
void drawCircle(int cx, int cy, int radius) {
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while(y >= x) {
        setPixel(cx + x, cy + y);
        setPixel(cx - x, cy + y);
        setPixel(cx + x, cy - y);
        setPixel(cx - x, cy - y);

        setPixel(cx + y, cy + x);
        setPixel(cx - y, cy + x);
        setPixel(cx + y, cy - x);
        setPixel(cx - y, cy - x);

        x++;

        if(d > 0) {
            y--;
            d += 4 * (x - y) + 10;
        }
        else {
            d += 4 * x + 6;
        }
    }
}
void drawTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}
int main(){
    int choice;
clear picture();
print("2D Graphics Editor\n");
printf("Canvas size:%dx%d\n";WIDTH,HEIGHT);
printf("Use coordinates xy.\n");
printf("x range:0 to %d\n",WIDTH-1);
printf("y range:0 to %d\n",HEIGHT-1);

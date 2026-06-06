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

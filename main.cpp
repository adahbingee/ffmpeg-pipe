#include <stdio.h>
#include <stdlib.h>
// includes for setmode
#include <fcntl.h>
#include <io.h>

int imgSizeX = 1920;
int imgSizeY = 1080;
int imgNum   = 0;

int mvX      = 100;
int mvY      = -20;

int main(int argc, char *argv[]) {
    imgNum = atoi(argv[1]);
    
    // change to binary stdout mode (avoid 0x0A be changed into 0x0D 0x0A)
    setmode(2, _O_BINARY);
    
    char *img = new char[imgSizeX*imgSizeY*3];
    
    for (int i = 0; i < imgNum; ++i) {
        for (int y = 0; y < imgSizeY; ++y) {
            for (int x = 0; x < imgSizeX; ++x) {
                int offset = y*imgSizeX*3 + x*3;
                img[offset+0] = (y+i*mvY) & 0xFF;
                img[offset+1] = (x+i*mvX) & 0xFF;
                img[offset+2] = 0x00;
            }
        }
        fwrite(img, 1, imgSizeX*imgSizeY*3, stderr);
    }
    
    fflush(stderr);
    delete [] img;
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
// includes for setmode
#include <fcntl.h>
#include <io.h>

int imgSizeX = 1920;
int imgSizeY = 1080;
int imgNum   = 100;

int main() {
    // change to binary stdout mode (avoid 0x0A be changed into 0x0D 0x0A)
    setmode(1, _O_BINARY);
    
    char *img = new char[imgSizeX*imgSizeY*3];
    
    for (int i = 0; i < imgNum; ++i) {
        for (int y = 0; y < imgSizeY; ++y) {
            for (int x = 0; x < imgSizeX; ++x) {
                int offset = y*imgSizeX*3 + x*3;
                img[offset+0] = (y-i*2) & 0xFF;
                img[offset+1] = (x+i*5) & 0xFF;
                img[offset+2] = 0x00;
            }
        }
        fwrite(img, 1, imgSizeX*imgSizeY*3, stdout);
    }
    
    fflush(stdout);
    delete [] img;
    return 0;
}
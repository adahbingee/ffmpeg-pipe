#include <stdio.h>

// includes for setmode
#include <fcntl.h>
#include <io.h>

int imgSizeX = 1920;
int imgSizeY = 1080;
int imgNum   = 100;

int main() {
    // change to binary stdout mode (avoid 0x0A be changed into 0x0D 0x0A)
    setmode(1, _O_BINARY);
    
    for (int i = 0; i < imgNum; ++i) {
        for (int y = 0; y < imgSizeY; ++y) {
            for (int x = 0; x < imgSizeX; ++x) {
                unsigned char color[3] = {0x00, (x+i*5) & 0xFF, 0x00};
                fwrite(color, 1, 3, stdout);
            }
        }
    }
    
    fflush(stdout);
    
    return 0;
}
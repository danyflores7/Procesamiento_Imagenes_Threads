#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *f = fopen("./img/prueba1.bmp", "rb");
    if (!f) { printf("err\n"); return 1; }
    unsigned char header[54];
    fread(header, 1, 54, f);
    int offset = *(int*)&header[10];
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(short*)&header[28];
    int comp = *(int*)&header[30];
    int img_size = *(int*)&header[34];
    printf("Offset: %d\nWidth: %d\nHeight: %d\nBPP: %d\nCompression: %d\nImgSize: %d\n", offset, width, height, bpp, comp, img_size);
    fclose(f);
    return 0;
}

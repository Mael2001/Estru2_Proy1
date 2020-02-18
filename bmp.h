#ifndef BMP_H
#define BMP_H
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <limits>
#include <stdio.h>
#include <stdint.h>
#include <cstring>
#include <QLabel>

using namespace std;

class bmp{
    public:
    char TYPE[2];
    int SIZE;
    uint16_t RESERVED1;
    uint16_t RESERVED2;
    int OFFSET;
    int BITMAPINFOHEADER;
    int WIDTH;
    int HEIGHT;
    uint16_t NUM_PLANES;
    uint16_t NUM_BITS;
    int COMPRESSION;
    int IMAGEDATA;
    int HORIZONTAL_RES;
    int VERTICAL_RES;
    int NUM_COLOR;
    int NUM_IMP;

    void unpack(char paquete[54]);
    void print();
    uint16_t bpp(){
        return NUM_BITS;
    };
    int getheight(){
        return HEIGHT;
    };
    int getwidth(){
        return WIDTH;
    };
    int getsize(){
        return SIZE;
    };
    int getOff(){
        return OFFSET;
    };
};
#endif // BMP_H

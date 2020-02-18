#include "mybmp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cstddef>
#include <QApplication>


uint16_t red_mask = 0xF800;
uint16_t green_mask = 0x7E0;
uint16_t blue_mask = 0x1F;

int main(int argc, char *argv[])
{

    MyBMP f;
    char filename [20] ="f256.bmp";
    cout << "Bmp file:" << flush; // force output

    f.OpenBmp(filename);
    f.PrintHeader();

    QApplication a(argc, argv);
    cout<<"Bits per Pixel: "<< f.getbpp()<<endl;

    if(f.getbpp()==8){
        const size_t width=f.getwidth();
        const size_t height=f.getheight();
        QImage image(width,height,(QImage::Format_Indexed8));
        image.setColorCount(256);
        FILE* file = fopen(filename, "rb");
        unsigned char basura[54];
        fread(basura, 1, 54, file);

        int padding = (width*1 + 3) & (~3);
            unsigned char* imagedata = new unsigned char[padding];
            int y=height-1;
            QVector<QRgb> tabla;
            for(int i=0;i<256;i++){
                tabla.push_back(qRgb(i,i,i));
            }
            image.setColorTable(tabla);
            for(int i = 0; i < height; i++)
            {
                int pos=0;

                fread(imagedata, sizeof(unsigned char), padding, file);
                for(int j = 0; j < width*1; j += 1)
                {
                    image.setPixel(pos,y,(int)imagedata[j]);
                    pos++;
                }
                y--;
            }
        QLabel lbl;
        lbl.setPixmap(QPixmap::fromImage(image));
        lbl.show();
        return a.exec();

    }else if(f.getbpp()==16){
        const size_t width=f.getwidth();
        const size_t height=f.getheight();

        QImage image(width,height,QImage::Format_RGB16);
        FILE* file = fopen(filename, "rb");
        unsigned char basura[54];
        fread(basura, 1, 54, file);

        int padding = (width*2 + 3) & (~3);
            unsigned char* imagedata = new unsigned char[padding];
            unsigned char tmp;
            int y=height-1;

            for(int i = 0; i < height; i++)
            {
                int pos=0;
                fread(imagedata, sizeof(unsigned char), padding, file);
                for(int j = 0; j < width*2; j += 2)
                {
                    char proba[2];
                    memcpy(&proba[0],&imagedata[j],1);
                    memcpy(&proba[1],&imagedata[j+1],1);

                    uint16_t pixel;
                    memcpy(&pixel,&proba,2);

                    uint8_t red_value = (pixel & red_mask) >> 11;
                    uint8_t green_value = (pixel & green_mask) >> 5;
                    uint8_t blue_value = (pixel & blue_mask);

                    uint8_t red   = red_value << 3;
                    uint8_t green = green_value << 2;
                    uint8_t blue  = blue_value << 3;

                    image.setPixelColor(pos,y,qRgb(red,green,blue));
                    pos++;
                }
                y--;
            }

        QLabel lbl;
        lbl.setPixmap(QPixmap::fromImage(image));
        lbl.show();
        return a.exec();

    }else if(f.getbpp()==24){
        const size_t width=f.getwidth();
        const size_t height=f.getheight();
        QImage image(width,height,QImage::Format_BGR888);

        FILE* file = fopen(filename, "rb");
        unsigned char basura[54];
        fread(basura, 1, 54, file);

        int padding = (width*3 + 3) & (~3);
        unsigned char* imagedata = new unsigned char[padding];
        unsigned char tmp;
        int y=height-1;

            for(int i = 0; i < height; i++)
            {
                int pos=0;
                fread(imagedata, sizeof(unsigned char), padding, file);
                for(int j = 0; j < width*3; j += 3)
                {
                    tmp = imagedata[j];
                    imagedata[j] = imagedata[j+2];
                    imagedata[j+2] = tmp;
                    image.setPixelColor(pos,y,qRgb((uint8_t)imagedata[j],(uint8_t)imagedata[j+1],(uint8_t)imagedata[j+2]));
                    pos++;
                }
                y--;
            }
        QLabel lbl;
        lbl.setPixmap(QPixmap::fromImage(image));
        lbl.show();
        return a.exec();

    }

}

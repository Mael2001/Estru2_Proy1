#include "bmp.h"


void bmp::unpack(char paquete[54]){
    char tipo[2];
    tipo[0]=paquete[0];
    tipo[1]=paquete[1];

    char size[4];
    size[0]=paquete[2];
    size[1]=paquete[3];
    size[2]=paquete[4];
    size[3]=paquete[5];

    char reserver1[2];
    reserver1[0]=paquete[6];
    reserver1[1]=paquete[7];

    char reserver2[2];
    reserver2[0]=paquete[8];
    reserver2[1]=paquete[9];

    char off[4];
    off[0]=paquete[10];
    off[1]=paquete[11];
    off[2]=paquete[12];
    off[3]=paquete[13];

    char bitmapinfo[4];
    bitmapinfo[0]=paquete[14];
    bitmapinfo[1]=paquete[15];
    bitmapinfo[2]=paquete[16];
    bitmapinfo[3]=paquete[17];

    char width[4];
    width[0]=paquete[18];
    width[1]=paquete[19];
    width[2]=paquete[20];
    width[3]=paquete[21];

    char height[4];
    height[0]=paquete[22];
    height[1]=paquete[23];
    height[2]=paquete[24];
    height[3]=paquete[25];

    char numplanes[2];
    numplanes[0]=paquete[26];
    numplanes[1]=paquete[27];

    char colpix[2];
    colpix[0]=paquete[28];
    colpix[1]=paquete[29];

    char compress[4];
    compress[0]=paquete[30];
    compress[1]=paquete[31];
    compress[2]=paquete[32];
    compress[3]=paquete[33];

    char image[4];
    image[0]=paquete[34];
    image[1]=paquete[35];
    image[2]=paquete[36];
    image[3]=paquete[37];

    char horres[4];
    horres[0]=paquete[38];
    horres[1]=paquete[39];
    horres[2]=paquete[40];
    horres[3]=paquete[41];

    char vertres[4];
    vertres[0]=paquete[42];
    vertres[1]=paquete[43];
    vertres[2]=paquete[44];
    vertres[3]=paquete[45];

    char nomcol[4];
    nomcol[0]=paquete[46];
    nomcol[1]=paquete[47];
    nomcol[2]=paquete[48];
    nomcol[3]=paquete[49];

    char impcol[4];
    impcol[0]=paquete[50];
    impcol[1]=paquete[51];
    impcol[2]=paquete[52];
    impcol[3]=paquete[53];

    memcpy(TYPE,tipo,2);
    memcpy(&SIZE,size,4);
    memcpy(&RESERVED1,reserver1,2);
    memcpy(&RESERVED2,reserver2,2);
    memcpy(&OFFSET,off,4);
    memcpy(&BITMAPINFOHEADER,bitmapinfo,4);
    memcpy(&WIDTH,width,4);
    memcpy(&HEIGHT,height,4);
    memcpy(&NUM_PLANES,numplanes,2);
    memcpy(&NUM_BITS,colpix,2);
    memcpy(&COMPRESSION,compress,4);
    memcpy(&IMAGEDATA,image,4);
    memcpy(&HORIZONTAL_RES,horres,4);
    memcpy(&VERTICAL_RES,vertres,4);
    memcpy(&NUM_COLOR,nomcol,4);
    memcpy(&NUM_IMP,impcol,4);

};

void bmp::print(){
    char type[3];
    type[2]='\0';
    memcpy(type,TYPE,2);


    cout<<"*************************"<<endl;
    cout << "Tipo: " << type << endl;
    cout << "Size: " << SIZE << endl;
    cout << "Reservado 1: "<<RESERVED1<<endl;
    cout << "Reservado 2: " << RESERVED2 << endl;
    cout << "Offset: " << OFFSET << endl;
    cout<<"Size of BitmapInfoHeader: "<<BITMAPINFOHEADER<<endl;
    cout<<"Image Width in pixels: "<<WIDTH<<endl;
    cout<<"Image Height in pixels: "<<HEIGHT<<endl;
    cout<<"Number of Planes In Image: "<<NUM_PLANES<<endl;
    cout<<"Number of Bits Per Pixel: "<<NUM_BITS<<endl;
    cout<<"Compression Type: "<<COMPRESSION<<endl;
    cout<<"Size of Image Data: "<<IMAGEDATA<<endl;
    cout<<"Horizontal Res in Pixels Per Meter: "<<HORIZONTAL_RES<<endl;
    cout<<"Vertical Res in Pixels Per Meter: "<<VERTICAL_RES<<endl;
    cout<<"Number of Colors in Image: "<<NUM_COLOR<<endl;
    cout<<"Number of Important Colors: "<<NUM_IMP<<endl;
    cout<<"*************************"<<endl;

};

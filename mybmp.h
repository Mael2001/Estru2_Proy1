#ifndef MYBMP_H
#define MYBMP_H
#include "bmp.h"

bmp clase;

class MyBMP{
    private:
        ifstream file_bmp;

        void ReadHeader(){
            file_bmp.seekg(0, ios_base::beg);
            file_bmp.read((char *) reg_header, sizeof(reg_header));
            clase.unpack(reg_header);
        };

    public:
        char reg_header[54];
        uint16_t getbpp(){
            return clase.bpp();
        };
        int getwidth(){
            return  clase.getwidth();
        };
        int getheight(){
            return clase.getheight();
        };

        void OpenBmp(const char * filename){
            file_bmp.open(filename, ifstream::in|ifstream::binary);
            ReadHeader();
        };
        void PrintHeader(){
            clase.print();
        };
        int getSize(){
            return clase.getsize();
        };
        int getOffset(){
            return clase.getOff();
        }
};
#endif // MYBMP_H

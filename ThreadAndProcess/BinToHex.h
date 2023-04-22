#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 

#pragma waring(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
     使用方法 : bin2hex -b adress filename
     -b : 指示hex文件起始地址
     address : hex文件的起始地址(FIXME:当前版本只支持k字节边界)
     filename : 待转换的文件名
     示例 : bin2hex -b 32k rom.bin
*/
class BinToHex
{
public:
    BinToHex(int argc, char* argv[]);
    ~BinToHex();
    void calc_start_adr(char* buf);
    void start_convert(void);
    int Do(int argc, char* argv[]);



private:
    FILE* fp_read;               /* 待读取文件句柄 */
    FILE* fp_write;              /* 待写入文件句柄 */
    unsigned long start_adr;     /* 转换成Hex格式的起始地址 */
    unsigned short cur_base;     /* 转换成Hex格式的当前地址高16位 */
    unsigned short cur_offset;   /* 转换成Hex格式的当前地址低16位 */
    unsigned char read_buf[16] = {0};
    unsigned char write_buf[48] = {0};

};


#if 0

#define _CRT_SECURE_NO_WARNINGS 1 

#pragma waring(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE* fp_read;               /* 待读取文件句柄 */
FILE* fp_write;              /* 待写入文件句柄 */


unsigned long start_adr;     /* 转换成Hex格式的起始地址 */
unsigned short cur_base;     /* 转换成Hex格式的当前地址高16位 */
unsigned short cur_offset;   /* 转换成Hex格式的当前地址低16位 */
unsigned char read_buf[16];
unsigned char write_buf[48];

void calc_start_adr(char* buf)
{
    unsigned int len;

    len = strlen(buf);

    if ((buf[len - 1] != 'k') && (buf[len - 1] != 'K')) {
        printf("Invalid argument.\n");
        exit(-1);
    }
    buf[len - 1] = 0;

    start_adr = atoi(buf);
    start_adr = start_adr * 1024;
    cur_base = start_adr >> 16;
    cur_offset = (unsigned short)start_adr;
}

void start_convert(void)
{
    unsigned char cnt;
    unsigned char read_num;
    unsigned char cksum, highc, lowc;

    /* 设置当前地址高16位 */
    highc = cur_base >> 8;
    lowc = (unsigned char)cur_base;
    cksum = 2 + 4 + highc + lowc;
    cksum = 0xFF - cksum;
    cksum = cksum + 1;
    sprintf(write_buf, ":02000004%04x%02x", cur_base, cksum);
    write_buf[15] = 0x0D; write_buf[16] = 0x0A;
    fwrite(write_buf, 1, 17, fp_write);

    read_num = fread(read_buf, 1, 16, fp_read);
    while (read_num == 16) {
        /* 写入读取的16字节 */
        highc = cur_offset >> 8;
        lowc = (unsigned char)cur_offset;
        cksum = 0x10 + highc + lowc;
        for (cnt = 0; cnt < 16; cnt++) {
            cksum += read_buf[cnt];
        }
        cksum = 0xFF - cksum;
        cksum = cksum + 1;

        sprintf(write_buf, ":10%02x%02x00%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            highc, lowc,
            read_buf[0], read_buf[1], read_buf[2], read_buf[3],
            read_buf[4], read_buf[5], read_buf[6], read_buf[7],
            read_buf[8], read_buf[9], read_buf[10], read_buf[11],
            read_buf[12], read_buf[13], read_buf[14], read_buf[15],
            cksum);
        write_buf[43] = 0x0D; write_buf[44] = 0x0A;
        fwrite(write_buf, 1, 45, fp_write);

        /* 计算当前地址低16位，当越限时写入当前地址高16位 */
        if (cur_offset == 65520) {
            cur_offset = 0;
            cur_base++;
            highc = cur_base >> 8;
            lowc = (unsigned char)cur_base;
            cksum = 2 + 4 + highc + lowc;
            cksum = 0xFF - cksum;
            cksum = cksum + 1;
            sprintf(write_buf, ":02000004%04x%02x", cur_base, cksum);
            write_buf[15] = 0x0D; write_buf[16] = 0x0A;
            fwrite(write_buf, 1, 17, fp_write);
        }
        else {
            cur_offset += 16;
        }

        read_num = fread(read_buf, 1, 16, fp_read);
    }

    /* 写入剩余的字节 */
    if (read_num) {
        highc = cur_offset >> 8;
        lowc = (unsigned char)cur_offset;
        cksum = read_num + highc + lowc;
        for (cnt = 0; cnt < read_num; cnt++) {
            cksum += read_buf[cnt];
        }
        cksum = 0xFF - cksum;
        cksum = cksum + 1;

        sprintf(write_buf, ":%02x%02x%02x00", read_num, highc, lowc);
        for (cnt = 0; cnt < read_num; cnt++) {
            sprintf(&write_buf[9 + cnt * 2], "%02x", read_buf[cnt]);
        }
        sprintf(&write_buf[9 + cnt * 2], "%02x", cksum);
        write_buf[11 + read_num * 2] = 0x0D;
        write_buf[12 + read_num * 2] = 0x0A;
        fwrite(write_buf, 1, 13 + read_num * 2, fp_write);
    }

    /* 写入终止序列 */
    sprintf(write_buf, ":00000001FF");
    write_buf[11] = 0x0D; write_buf[12] = 0x0A;
    fwrite(write_buf, 1, 13, fp_write);
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage : %s -b address filename.xxx\n", argv[0]);
        printf("-b : indicate the starting address convert to.\n");
        printf("address : starting address.\n");
        printf("filename.xxx : file to be converted.\n");
        printf("output :   filename.hex\n");
        printf("example : %s -b 64k rom.bin\n", argv[0]);
        return -1;
    }
    if (strcmp(argv[1], "-b"))
    {
        printf("Invalid argument.\n");
        return -1;
    }
    fp_read = fopen(argv[3], "rb");
    if (fp_read == NULL)
    {
        printf("Can't open file %s", argv[3]);
        return -1;
    }
    fp_write = fopen("rom.hex", "w");
    if (fp_write == NULL)
    {
        printf("Can't create file rom.hex");
        return -1;
    }
    calc_start_adr(argv[2]);
    start_convert();
    fclose(fp_read);
    fclose(fp_write);
    printf("Convert Seccessfully!\n");
    return 0;
}
#endif // 0


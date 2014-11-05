#ifndef DNSHEADER_H
#define DNSHEADER_H

#include <p3.h>

struct Header {
    // HEADER
    unsigned short id; // identification number
 
    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag
 
    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available
 
    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};

class DNSHeader {
public:
    DNSHeader();
    unsigned char getID();
    unsigned char getTC();
    unsigned char getAA();
    unsigned char getOpcode();
    unsigned char getQR();
 
    unsigned char getRcode();
    unsigned char getCD();
    unsigned char getAD();
    unsigned char getZ();
    unsigned char getRA();
 
    unsigned short getQCount();
    unsigned short getAnsCount();
    unsigned short getAuthCount();
    unsigned short getAddCount();

    Header getPacket();

private:
    unsigned short id;
 
    unsigned char rd;
    unsigned char tc;
    unsigned char aa;
    unsigned char opcode;
    unsigned char qr;
 
    unsigned char rcode;
    unsigned char cd;
    unsigned char ad;
    unsigned char z;
    unsigned char ra;
 
    unsigned short qCount;
    unsigned short ansCount;
    unsigned short authCount;
    unsigned short addCount;
};

#endif
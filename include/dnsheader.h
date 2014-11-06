#ifndef DNSHEADER_H
#define DNSHEADER_H

#include <p3.h>

struct Header {
    // HEADER
    unsigned short id; // identification number
 
    unsigned char qr :1; // query/response flag
    unsigned char opcode :4; // purpose of message
    unsigned char aa :1; // authoritive answer
    unsigned char tc :1; // truncated message
    unsigned char rd :1; // recursion desired
 
    unsigned char ra :1; // recursion available
    unsigned char z :1; // its z! reserved
    unsigned char rcode :4; // response code
    
//    unsigned char cd :1; // checking disabled
//    unsigned char ad :1; // authenticated data
 
    unsigned short qCount; // number of question entries
    unsigned short ansCount; // number of answer entries
    unsigned short authCount; // number of authority entries
    unsigned short addCount; // number of resource entries
};

class DNSHeader {
public:
    DNSHeader();
    DNSHeader(unsigned short id, unsigned char tc, unsigned char aa, unsigned char opcode, unsigned char qr, unsigned char rcode, /*unsigned char cd, unsigned char ad, */unsigned char z,     unsigned char ra, unsigned short qcount, unsigned short ansCount, unsigned short authCount, unsigned short addCount);

    void setID(unsigned short id);
    void setTC(unsigned char tc);
    void setAA(unsigned char aa);
    void setOpcode(unsigned char opcode);
    void setQR(unsigned char qr);
 
    void setRcode(unsigned char rcode);
    //void setCD(unsigned char cd);
    //void setAD(unsigned char ad);
    void setZ(unsigned char z);
    void setRA(unsigned char ra);
 
    void setQCount(unsigned short qcount);
    void setAnsCount(unsigned short ansCount);
    void setAuthCount(unsigned short authCount);
    void setAddCount(unsigned short addCount);

    unsigned short getID();
    unsigned char getTC();
    unsigned char getAA();
    unsigned char getOpcode();
    unsigned char getQR();
 
    unsigned char getRcode();
    //unsigned char getCD();
    //unsigned char getAD();
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
    //unsigned char cd;
    //unsigned char ad;
    unsigned char z;
    unsigned char ra;
 
    unsigned short qCount;
    unsigned short ansCount;
    unsigned short authCount;
    unsigned short addCount;
};

#endif
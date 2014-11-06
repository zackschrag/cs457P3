#ifndef DNSPACKET_H
#define DNSPACKET_H

#include <p3.h>
#include <dnsheader.h>
#include <dnsquestion.h>
#include <dnsresourcerecord.h>

struct Packet {
    struct Header header;
    struct Question question;
    // struct Answer answer;
    // struct Authority authority;
    // struct Additional additional;
};

class DNSPacket {
public:
	DNSPacket(string ip, DNSHeader h, DNSQuestion q, DNSResourceRecord ans, 
    DNSResourceRecord auth, DNSResourceRecord addl);

    string getIP();
    DNSHeader getHeader();
    DNSQuestion getQuestion();
    DNSResourceRecord getAnswer();
    DNSResourceRecord getAuthority();
    DNSResourceRecord getAdditional();

	Packet getPacket();

private:
    string ip;
	DNSHeader header;
	DNSQuestion question;
    DNSResourceRecord answer;
    DNSResourceRecord authority;
    DNSResourceRecord additional;
};

#endif

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
	DNSPacket(string ip, string qname, short qtype, short qclass);

    DNSHeader getHeader();
    DNSQuestion getQuestion();
    DNSResourceRecord getAnswer();
    DNSResourceRecord getAuthority();
    DNSResourceRecord getAdditional();

	Packet getPacket();

private:
	DNSHeader header;
	DNSQuestion question;
    DNSResourceRecord answer;
    DNSResourceRecord authority;
    DNSResourceRecord additional;
};

#endif

#ifndef DNSQUESTION_H
#define DNSQUESTION_H

#include <p3.h>

struct Question {
	unsigned short qnameLength;
	char qname[256];
	unsigned short qtype;
	unsigned short qclass;
};

class DNSQuestion {
public:
	DNSQuestion(string qname, unsigned short qtype, unsigned short qclass);

	string getQname();
	unsigned short getQtype();
	unsigned short getQclass();
	Question getPacket();

private:
	string qname;
	unsigned short qtype;
	unsigned short qclass;
};

#endif
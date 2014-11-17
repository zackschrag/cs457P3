#ifndef CLIENT_H
#define CLIENT_H

#include <p3.h>

#define DNS_PORT "53"

struct Header {
	unsigned short id;

	unsigned qr :1;
	unsigned opcode :4;
	unsigned aa :1;
	unsigned tc :1;
	unsigned rd :1;
	unsigned ra :1;
	unsigned z :3;
	unsigned rcode :4;

	unsigned short qdcount;
	unsigned short ancount;
	unsigned short nscount;
	unsigned short arcount;
};

struct Question {
	// name
	//char *qname;
	unsigned short qtype;
	unsigned short qclass;
};

struct ResourceRecord {
	// name
	unsigned short type;
	unsigned short rclass;
	int ttl;
	unsigned short rdlength;
	int rdata;
};

class Client {
public:
	Client();
	~Client();

	char* sendQuery(char *domainName, string dnsServer);
	Header parseHeader(char *responseBuffer);
	Question parseQuestion(char *responseBuffer);
	ResourceRecord parseAnswer(char *responseBuffer);
	ResourceRecord parseAuthority(char *responseBuffer);
	ResourceRecord parseAdditional(char *responseBuffer);

private:
	char *tempName;
	char *responseBuffer;
	int socketToServer;

	char* nameToDNS(char *domainName);

};

#endif
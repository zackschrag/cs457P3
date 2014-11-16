#ifndef CLIENT_H
#define CLIENT_H

#include <p3.h>

#define DNS_PORT "53"

struct Header {
	short id;
	short flags;
	short qdcount;
	short ancount;
	short nscount;
	short arcount;
};

struct Question {
	short qtype;
	short qclass;
};

struct ResourceRecord {

};

class Client {
public:
	Client();
	~Client();

	//	Requests server for a UDP connection.
	//	Returns socket descriptor if successful, -1 if not.
	void sendQuery(char *domainName, string dnsServer);
	char* nameToDNS(char *domainName);
	Header parseHeader(char *responseBuffer);
	Question parseQuestion(char *responseBuffer);
	ResourceRecord parseAnswer(char *responseBuffer);
	ResourceRecord parseAuthority(char *responseBuffer);
	ResourceRecord parseAdditional(char *responseBuffer);

private:
	char *tempName;
	int socketToServer;

};

#endif
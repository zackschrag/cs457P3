#ifndef CLIENT_H
#define CLIENT_H

#include <p3.h>
#include <dnspacket.h>

#define DNS_PORT "53"

class Client {
public:
	Client();
	~Client();

	DNSPacket sendQuery(char *domainName, string dnsServer);
	void parsePacket(char *responseBuffer, DNSPacket *dp);
	void parseHeader(char *responseBuffer, DNSPacket *dp);
	void parseQuestion(char *responseBuffer, DNSPacket *dp);
	void parseAnswer(char *responseBuffer, DNSPacket *dp);
	void parseAuthority(char *responseBuffer, DNSPacket *dp);
	void parseAdditional(char *responseBuffer, DNSPacket *dp);

private:
	char *tempName;
	char *responseBuffer;
	int socketToServer;

	DNSPacket *dp;

	char* nameToDNS(char *domainName);

};

#endif
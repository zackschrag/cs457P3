#ifndef CLIENT_H
#define CLIENT_H

#include <p3.h>
#include <dnspacket.h>
#include <dnsquestion.h>

#define DNS_PORT "53"

class Client {
public:
	Client();
	~Client();

	DNSPacket sendQuery(char *domainName, string dnsServer);
	void parsePacket(char *responseBuffer, DNSPacket *dp);
	char* parseHeader(char *responseBuffer, DNSPacket *dp);
	char* parseQuestion(char *responseBuffer, DNSPacket *dp);
	char* parseResourceRecord(char *responseBuffer, DNSPacket *dp, int rrtype);

private:
	char *tempName;
	char *responseBuffer;
	//char responseBuffer[1000];
	int socketToServer;

	DNSPacket *dp;

	char* nameToDNS(char *domainName);
	string DNSToName(string dnsName);

};

#endif
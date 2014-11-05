#ifndef CLIENT_H
#define CLIENT_H

#include <p3.h>
#include <dnspacket.h>
#include <dnsheader.h>
#include <dnsquestion.h>
#include <dnsresourcerecord.h>

#define DNS_PORT "53"

class Client {
public:
	Client();
	~Client();

	//	Requests server for a UDP connection.
	//	Returns socket descriptor if successful, -1 if not.
	void sendQuery(DNSPacket query);

private:
	int socketToServer;

};

#endif
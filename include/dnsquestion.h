#ifndef DNSQUESTION_H
#define DNSQUESTION_H

#include <p3.h>

class DNSQuestion {
public:
	DNSQuestion();

	string getQname();
	char getQtype();
	char getQclass();

	void setQname(string newName);
	void setQtype(char newType);
	void setQclass(char newClass);

private:
	string qname;
	char qtype;
	char qclass;
};

#endif
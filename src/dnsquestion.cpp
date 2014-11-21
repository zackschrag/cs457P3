#include <dnsquestion.h>

DNSQuestion::DNSQuestion() {
	
}

string DNSQuestion::getQname() {
	return qname;
}

char DNSQuestion::getQtype() {
	return qtype;
}

char DNSQuestion::getQclass() {
	return qclass;
}

void DNSQuestion::setQname(string newName) {
	qname = newName;
}

void DNSQuestion::setQtype(char newType) {
	qtype = newType;
}

void DNSQuestion::setQclass(char newClass) {
	qclass = newClass;
}
#include <dnspacket.h>
#include <dnsheader.h>
#include <dnsquestion.h>
#include <dnsresourcerecord.h>

DNSPacket::DNSPacket(string ip, DNSHeader h, DNSQuestion q, DNSResourceRecord ans, 
	DNSResourceRecord auth, DNSResourceRecord addl) {
	this->ip = ip;
	this->header = h;
	this->question = q;
	this->answer = ans;
	this->authority = auth;
	this->additional = addl;
}

string DNSPacket::getIP() {
	return ip;
}

DNSHeader DNSPacket::getHeader() {
	return header;
}

DNSQuestion DNSPacket::getQuestion() {
	return question;
}

DNSResourceRecord DNSPacket::getAnswer() {
	return answer;
}

DNSResourceRecord DNSPacket::getAuthority() {
	return authority;
}

DNSResourceRecord DNSPacket::getAdditional() {
	return additional;
}

Packet DNSPacket::getPacket() {
	Packet p;
	p.header = header.getPacket();
	p.question = question.getPacket();

	cout << "size of header: " << sizeof(p.header) << endl;
	cout << "size of question: " << sizeof(p.question) << endl;
	//memcpy(&qp.qname, qname.c_str(), sizeof(qp.qname));
	//qp.qtype = htons(1);
	//qp.qclass = htons(1);
	return p;
}


#include <p3.h>
#include <dnsquestion.h>

DNSQuestion::DNSQuestion() {

}

DNSQuestion::DNSQuestion(string qname, unsigned short qtype, unsigned short qclass) {
	this->qname = qname;
	this->qtype = qtype;
	this->qclass = qclass;
}

void DNSQuestion::setQname(string qname) {
	this->qname = qname;
}

void DNSQuestion::setQtype(unsigned short qtype) {
	this->qtype = qtype;
}

void DNSQuestion::setQclass(unsigned short qclass) {
	this->qclass = qclass;
}

string DNSQuestion::getQname() {
	return qname;
}

unsigned short DNSQuestion::getQtype() {
	return qtype;
}

unsigned short DNSQuestion::getQclass() {
	return qclass;
}

Question DNSQuestion::getPacket() {
	Question qp;
	qp.qnameLength = htons(qname.length());
	memcpy(&qp.qname, qname.c_str(), sizeof(qp.qname));
	qp.qtype = htons((unsigned short)1);
	qp.qclass = htons((unsigned short)1);
	return qp;
}


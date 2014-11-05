#include <dnsquestion.h>

DNSQuestion::DNSQuestion(string ip, string qname, short qtype, short qclass) {
	this->ip = ip;
	this->qname = qname;
	this->qtype = qtype;
	this->qclass = qclass;
}

string DNSQuestion::getIP() {
	return ip;
}

string DNSQuestion::getQname() {
	return qname;
}

short DNSQuestion::getQtype() {
	return qtype;
}

short DNSQuestion::getQclass() {
	return qclass;
}

QuestionPacket DNSQuestion::getPacket() {
	QuestionPacket qp;
	qp.qnameLength = htons(qname.length());
	cout << "Length: " << qp.qnameLength << endl;
	memcpy(&qp.qname, qname.c_str(), sizeof(qp.qname));
	qp.qtype = htons(1);
	qp.qclass = htons(1);
	return qp;
}


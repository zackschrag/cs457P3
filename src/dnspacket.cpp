#include <dnspacket.h>

DNSPacket::DNSPacket() {
	dnsQuestions = new vector<DNSQuestion>();
	dnsAnswers = new vector<DNSResourceRecord>();
	dnsAuthorities = new vector<DNSResourceRecord>();
	dnsAdditionals = new vector<DNSResourceRecord>();
}

DNSPacket::~DNSPacket() {
	// delete questions;
	// delete answers;
	// delete authorities;
	// delete additionals;
}

DNSPacket::DNSPacket(Header h, vector<Question> q, vector<ResourceRecord> ans, vector<ResourceRecord> auth, vector<ResourceRecord> addl, char *qname) {
	// header = h;
	// questions = q;
	// answers = ans;
	// authorities = auth;
	// additionals = addl;

	// setQname(qname);
}

Header DNSPacket::getHeader() {
	return header;
}

// vector<Question> DNSPacket::getQuestions() {
// 	return *questions;
// }

// vector<ResourceRecord> DNSPacket::getAnswers() {
// 	return *answers;
// }

// vector<ResourceRecord> DNSPacket::getAuthorities() {
// 	return *authorities;
// }

// vector<ResourceRecord> DNSPacket::getAdditionals() {
// 	return *additionals;
// }

string DNSPacket::getQname() {
	return qname;
}

int DNSPacket::getNumberOfQuestions() {
	return numberOfQuestions;//questions->size();
}

int DNSPacket::getNumberOfAnswers() {
	return numberOfAnswers;//answers->size();
}

int DNSPacket::getNumberOfAuthorities() {
	return numberOfAuthorities;//authorities->size();
}

int DNSPacket::getNumberOfAdditionals() {
	return numberOfAdditionals;//additionals->size();
}

void DNSPacket::setNumberOfQuestions(int num) {
	numberOfQuestions = num;
}

void DNSPacket::setNumberOfAnswers(int num) {
	numberOfAnswers = num;
}

void DNSPacket::setNumberOfAuthorities(int num) {
	numberOfAuthorities = num;
}

void DNSPacket::setNumberOfAdditionals(int num) {
	numberOfAdditionals = num;
}

void DNSPacket::setQname(string newName) {
	qname = newName;
	// this->qname = "";
	// for (unsigned int i = 0; i < strlen(newName); i++) {
	// 	this->qname += newName[i];
	// }
}

void DNSPacket::setHeader(Header h) {
	header.id = h.id;
	header.qr = h.qr;
	header.opcode = h.opcode;
	header.aa = h.aa;
	header.tc = h.tc;
	header.rd = h.rd;
	header.ra = h.ra;
	header.z = h.z;
	header.rcode = h.rcode;
	header.qdcount = h.qdcount;
	header.ancount = h.ancount;
	header.nscount = h.nscount;
	header.arcount = h.arcount;
}

void DNSPacket::setQuestions(vector<Question> q) {
	//questions = q;
}

void DNSPacket::addDNSQuestion(DNSQuestion q) {
	dnsQuestions->push_back(q);
}

void DNSPacket::addDNSAnswer(DNSResourceRecord rr) {
	dnsAnswers->push_back(rr);
}

void DNSPacket::addDNSAuthority(DNSResourceRecord auth) {
	dnsAuthorities->push_back(auth);
}

void DNSPacket::addDNSAdditional(DNSResourceRecord addl) {
	dnsAdditionals->push_back(addl);
}

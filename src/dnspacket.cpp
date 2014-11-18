#include <dnspacket.h>

DNSPacket::DNSPacket() {

}

DNSPacket::DNSPacket(Header h, vector<Question> q, vector<ResourceRecord> ans, vector<ResourceRecord> auth, vector<ResourceRecord> addl, char *qname) {
	header = h;
	questions = q;
	answers = ans;
	authorities = auth;
	additionals = addl;

	setQname(qname);
}

Header DNSPacket::getHeader() {
	return header;
}

vector<Question> DNSPacket::getQuestions() {
	return questions;
}

vector<ResourceRecord> DNSPacket::getAnswers() {
	return answers;
}

vector<ResourceRecord> DNSPacket::getAuthorities() {
	return authorities;
}

vector<ResourceRecord> DNSPacket::getAdditionals() {
	return additionals;
}

string DNSPacket::getQname() {
	return qname;
}

void DNSPacket::setQname(char *newName) {
	this->qname = "";
	for (unsigned int i = 0; i < strlen(newName); i++) {
		this->qname += newName[i];
	}
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
	questions = q;
}

void DNSPacket::addQuestion(Question q) {
	questions.push_back(q);
}

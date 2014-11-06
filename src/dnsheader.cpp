#include <dnsheader.h>

DNSHeader::DNSHeader() {
	
}

DNSHeader::DNSHeader(unsigned short id, unsigned char tc, unsigned char aa, unsigned char opcode, unsigned char qr, unsigned char rcode, /*unsigned char cd, unsigned char ad, */unsigned char z, unsigned char ra, unsigned short qcount, unsigned short anscount, unsigned short authcount, unsigned short addcount) {
	this->id = id;
	this->tc = tc;
	this->aa = aa;
	this->opcode = opcode;
	this->qr = qr;
	this->rcode = rcode;
	this->z = z;
	this->ra = ra;
	this->qCount = qcount;
	this->ansCount = anscount;
	this->authCount = authcount;
	this->addCount = addcount;
}

unsigned short DNSHeader::getID() {
	return id;
}

unsigned char DNSHeader::getTC() {
	return tc;
}

unsigned char DNSHeader::getAA() {
	return aa;
}

unsigned char DNSHeader::getOpcode() {
	return opcode;
}

unsigned char DNSHeader::getQR() {
	return qr;
}
 
unsigned char DNSHeader::getRcode() {
	return rcode;
}

// unsigned char DNSHeader::getCD() {
// 	return cd;
// }

// unsigned char DNSHeader::getAD() {
// 	return ad;
// }

unsigned char DNSHeader::getZ() {
	return z;
}

unsigned char DNSHeader::getRA() {
	return ra;
}
 
unsigned short DNSHeader::getQCount() {
	return qCount;
}

unsigned short DNSHeader::getAnsCount() {
	return ansCount;
}

unsigned short DNSHeader::getAuthCount() {
	return authCount;
}

unsigned short DNSHeader::getAddCount() {
	return addCount;
}

Header DNSHeader::getPacket() {
	Header h;
	h.id = htons(id);
	h.rd = rd;
	h.tc = tc;
	h.aa = aa;
	h.opcode = opcode;
	h.qr = qr;
	h.rcode = rcode;
	//h.cd = cd;
	//h.ad = ad;
	h.z = z;
	h.ra = ra;
	h.qCount = htons(qCount);
	h.ansCount = ansCount;
	h.authCount = authCount;
	h.addCount = addCount;
	return h;
}
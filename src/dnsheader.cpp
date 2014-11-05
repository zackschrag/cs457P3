#include <dnsheader.h>

DNSHeader::DNSHeader() {
	
}

unsigned char DNSHeader::getID() {
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

unsigned char DNSHeader::getCD() {
	return cd;
}

unsigned char DNSHeader::getAD() {
	return ad;
}

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

// Header DNSHeader::getPacket() {
	
// }
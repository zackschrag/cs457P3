#include <dnsresourcerecord.h>

DNSResourceRecord::DNSResourceRecord() {
	rRdata = new unsigned char[100];
}

string DNSResourceRecord::getName() {
	return rName;
}

short DNSResourceRecord::getType() {
	return rType;
}

short DNSResourceRecord::getClass() {
	return rClass;
}

int DNSResourceRecord::getTTL() {
	return rTTL;
}

short DNSResourceRecord::getRdlength() {
	return rRdlength;
}

unsigned char* DNSResourceRecord::getRdata() {
	return rRdata;
}

void DNSResourceRecord::setName(string newName) {
	rName = newName;
}

void DNSResourceRecord::setType(short newType) {
	rType = newType;
}

void DNSResourceRecord::setClass(short newClass) {
	rClass = newClass;
}

void DNSResourceRecord::setTTL(int newTTL) {
	rTTL = newTTL;
}

void DNSResourceRecord::setRdlength(short newLength) {
	rRdlength = newLength;
}

void DNSResourceRecord::setRdata(unsigned char *newData) {
	for (unsigned int i = 0; i < strlen((char*) newData); i++) {
		rRdata[i] = newData[i];
	}
}
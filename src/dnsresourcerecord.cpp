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

/*
*	DEBUGGING ONLY: only works well for IPv4
*/
void DNSResourceRecord::printRdata() {
	int length = 0;
	int i = 0;
	while (rRdata[i] != '\0') {
		length++;
		i++;
	}
	//cout << "length: " << length << endl;
	//if (isdigit(rRdata[1])) {
		for (i = 0; i < length; i++) {
			cout << (int) rRdata[i] << ".";
		}
		cout << endl;
	// }
	// else {
	// 	for (i = 0; i < length; i++) {
	// 		cout << rRdata[i];
	// 	}
	// 	cout << endl;
	// }
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
	int length = 0;
	int i = 0;
	while (newData[i] != '\0') {
		length++;
		i++;
	}
	//cout << "length: " << length << endl;
	for (i = 0; i < length; i++) {
		rRdata[i] = newData[i];
	}
	rRdata[length] = '\0';
}
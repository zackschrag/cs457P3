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

unsigned char* DNSResourceRecord::getRdataAsIPv6() {
	return IPv6Rdata;
}

string DNSResourceRecord::getRdataAsString() {
	string strRdata = "";
	unsigned int length = strlen((char*) rRdata);
	for (unsigned int i = 0; i < length; i++) {
		strRdata += to_string((int) rRdata[i]);
		strRdata += '.';
	}
	strRdata.pop_back();
	strRdata += '\0';
	return strRdata;
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
			//cout << (int) rRdata[i] << ".";
		}
		//cout << endl;
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
	if (rType == 28) {
		//cout << "????" << endl;
		char *ipv6 = new char[100];
		inet_ntop(AF_INET6, newData, ipv6, INET6_ADDRSTRLEN);
		//cout << ipv6 << endl;
		IPv6Rdata = (unsigned char*) ipv6;
	}
	//else {
		//memset(rRdata, 0, 100);
		int length = 0;
		int i = 0;
		while (newData[i] != '\0') {
			length++;
			i++;
		}
		//cout << "length: " << length << endl;
		for (i = 0; i < length; i++) {
			rRdata[i] = newData[i];
			//cout << (int) rRdata[i] << endl;
		}
		rRdata[length] = '\0';
	//}
}

void DNSResourceRecord::setRdataAsIPv6(unsigned char *newData) {
	// cout << "egjwreognjworig" << endl;
	// char *ipv6 = new char[100];
	// inet_ntop(AF_INET6, newData, ipv6, INET6_ADDRSTRLEN);
	// cout << ipv6 << endl;
	// //rRdata = ipv6;
	// memset(rRdata, 0, strlen((char*)newData));
	// for (unsigned int i = 0; i < strlen(ipv6); i++) {
	// 	rRdata[i] = newData[i];
	// 	//cout << (int) rRdata[i] << endl;
	// }
	// rRdata[strlen(ipv6)] = '\0';
	//delete ipv6;
}

bool DNSResourceRecord::isNS() {
	return (rType == 2);
}

bool DNSResourceRecord::isIPv4() {
	return (rType == 1);
}

bool DNSResourceRecord::isIPv6() {
	return (rType == 28);
}

bool DNSResourceRecord::isCname() {
	return (rType == 5);
}
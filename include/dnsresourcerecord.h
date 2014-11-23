#ifndef DNSRESOURCERECORD_H
#define DNSRESOURCERECORD_H

#include <p3.h>

class DNSResourceRecord {
public:
	DNSResourceRecord();

	string getName();
	short getType();
	short getClass();
	int getTTL();
	short getRdlength();
	unsigned char* getRdata();
	void printRdata();

	void setName(string newName);
	void setType(short newType);
	void setClass(short newClass);
	void setTTL(int newTTL);
	void setRdlength(short newLength);
	void setRdata(unsigned char *newData);

private:
	string rName;
	short rType;
	short rClass;
	int rTTL;
	short rRdlength;
	unsigned char *rRdata;
};

#endif
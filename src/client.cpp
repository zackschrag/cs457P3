#include <client.h>
#define BUFFER_SIZE 1000

Client::Client() {
	responseBuffer = new char[BUFFER_SIZE];
	tempName = new char[100];
	dp = new DNSPacket();
}

Client::~Client() {
	delete [] tempName;
	delete [] responseBuffer;
	delete dp;
}

/*
*	Constructs DNS packet and sends query to dnsServer
*/
DNSPacket* Client::sendQuery(char *domainName, string dnsServer, short recordType) {
	Header h;
	h.id = htons(getpid());
	//h.flags = htons(0);
	h.qr = 0;
	h.opcode = 0;
	h.aa = 0;
	h.tc = 0;
	h.rd = 0;
	h.ra = 0;
	h.z = 0;
	h.rcode = 0;

	h.qdcount = htons(1);
	h.ancount = htons(0);
	h.nscount = htons(0);
	h.arcount = htons(0);

	Question q;
	//cout << "domainName: " << domainName << endl;

	char *qname = nameToDNS(domainName);
	// cout << "qname: " << endl;
	// for (unsigned int i = 0; i < strlen(qname); i++) {
	// 	cout << qname[i] << " ";
	// }
	// cout << endl;
	//cout << "type: " << recordType << endl;
	q.qtype = htons(recordType);

	q.qclass = htons(1);

	char queryBuffer[256];
	//char responseBuffer[500];
	memset(queryBuffer, 0, sizeof(queryBuffer));
	memset(responseBuffer, 0, BUFFER_SIZE);

	memcpy(queryBuffer, &h, sizeof(h));
	memcpy(queryBuffer+(sizeof(h)), qname, strlen(qname)+1);
	memcpy(queryBuffer+(sizeof(h)+strlen(qname)+1), &q, sizeof(q));

	int queryLength = sizeof(h) + strlen(qname)+1 + sizeof(q);

	int sock, numbytes, i;

	struct sockaddr_in dest;

	sock = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);
 
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(dnsServer.c_str());

    //cout << "Sending packet to " << dnsServer << endl;
    if((numbytes = sendto(sock,queryBuffer, queryLength,0,(struct sockaddr*)&dest,sizeof(dest))) < 0) {
        perror("sendto failed");
    }
    //cout << "bytes sent: " << numbytes << endl;

    i = sizeof(dest);
    //cout << "Receiving answer..." << endl;
    if( (numbytes = recvfrom (sock,responseBuffer, BUFFER_SIZE, 0, (struct sockaddr*)&dest , (socklen_t*)&i )) < 0) {
        perror("recvfrom failed");
    }
    //cout << "bytes received: " << numbytes << endl;
    close(sock);
	memset(qname, 0, strlen(qname)+1);
    parsePacket(responseBuffer, dp);
    return dp;
}

/* 
*	DEBUGGING ONLY
*/
const char *byte_to_binary(int x)
{
    static char b[17];
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

/* 
*	DEBUGGING ONLY
*/
void PrintHex(char* buf, int amountToPrint){

    int i;
    for(i = 0; i < amountToPrint; i++){

        printf("%x ",*buf);
        if(i % 16 == 10) cout << endl;
        buf = buf + 1;

    }

}

void Client::parsePacket(char *responseBuffer, DNSPacket *dp) {
	char *currPlace = parseHeader(responseBuffer, dp);
	currPlace = parseQuestion(currPlace, dp);

	for (int i = 0; i < dp->getNumberOfAnswers(); i++) {
		currPlace = parseResourceRecord(currPlace, dp, 0);		
		//cout << "&" << endl;
	}

	for (int i = 0; i < dp->getNumberOfAuthorities(); i++) {
		currPlace = parseResourceRecord(currPlace, dp, 1);
		//cout << "!" << endl;
	}

	for (int i = 0; i < dp->getNumberOfAdditionals(); i++) {
		//cout << i << endl;
		currPlace = parseResourceRecord(currPlace, dp, 2);
		//cout << "@" << endl;
	}
	//cout << "$" << endl;
}

/*
*	Parses header and places into DNSPacket data structure. Returns pointer to 1st question.
*/
char* Client::parseHeader(char *responseBuffer, DNSPacket *dp) {
	Header result;
	unsigned short flags;

	memcpy(&result.id, responseBuffer, sizeof(result.id));
	memcpy(&flags, responseBuffer+2, sizeof(flags));
	memcpy(&result.qdcount, responseBuffer+4, sizeof(result.qdcount));
	memcpy(&result.ancount, responseBuffer+6, sizeof(result.ancount));
	memcpy(&result.nscount, responseBuffer+8, sizeof(result.nscount));
	memcpy(&result.arcount, responseBuffer+10, sizeof(result.arcount));
	
	result.id = ntohs(result.id);
	flags = ntohs(flags);
	unsigned short mask = 32768;	// 10000000 00000000

	result.qr = (flags & (mask)) && 1;
	result.opcode = (flags & (30720));
	result.aa = (flags & (mask = mask >> 5)) && 1;
	result.tc = (flags & (mask = mask >> 1)) && 1;
	result.rd = (flags & (mask = mask >> 1)) && 1;
	result.ra = (flags & (mask = mask >> 1)) && 1;
	result.z = (flags & (112));
	result.rcode = (flags & (15));

	result.qdcount = ntohs(result.qdcount);
	result.ancount = ntohs(result.ancount);
	result.nscount = ntohs(result.nscount);
	result.arcount = ntohs(result.arcount);

	if (result.rcode == 3) {
		cout << "NXDOMAIN -- Requested domain does not exist." << endl;
		exit(0);
	}
	dp->setHeader(result);
	dp->setNumberOfQuestions(result.qdcount);
	dp->setNumberOfAnswers(result.ancount);
	dp->setNumberOfAuthorities(result.nscount);
	dp->setNumberOfAdditionals(result.arcount);
	return responseBuffer+sizeof(Header);
}

/*
*	Parses a question and places into DNSPacket data structure. Returns pointer to next question or 1st answer.
*/
char* Client::parseQuestion(char *startBuffer, DNSPacket *dp) {
	Question result;
	string qname = "";
	int ctr = 0;
	while (*startBuffer != '\0') {
		qname += startBuffer[ctr];
		startBuffer++;
	}
	startBuffer++;
	memcpy(&result.qtype, startBuffer, sizeof(result.qtype));
	memcpy(&result.qclass, startBuffer+sizeof(result.qtype), sizeof(result.qclass));
	result.qtype = ntohs(result.qtype);
	result.qclass = ntohs(result.qclass);
	dp->setQname(qname);

	DNSQuestion *dq = new DNSQuestion();

	dq->setQname(DNSToName(qname));
	dq->setQtype(result.qtype);
	dq->setQclass(result.qclass);
	dp->addDNSQuestion(*dq);

	return startBuffer+sizeof(result);
}

/*
*	rrtype: 0 = Answer, 1 = Authority, 2 = Additional
*/
char* Client::parseResourceRecord(char *startBuffer, DNSPacket *dp, int rrtype) {
	//cout << *startBuffer << endl;
	ResourceRecord result;

	string name = "";
	bool isPtr = false;

	char *currPtr = startBuffer;
	while (*currPtr != '\0') {
		if (*currPtr == (char) 192) {
			// It's a pointer
			isPtr = true;
			unsigned int offset = (unsigned char) *(currPtr+1);
			currPtr = responseBuffer+offset;
		}
		else {
			name += *currPtr;				
			currPtr++;
		}
	}
	if (isPtr) {
		startBuffer+=2;
	}
	else {
		startBuffer = currPtr;
	}

	memcpy(&result.type, startBuffer, sizeof(result.type));
	memcpy(&result.rclass, startBuffer+2, sizeof(result.rclass));
	memcpy(&result.ttl, startBuffer+4, sizeof(result.ttl));
	memcpy(&result.rdlength, startBuffer+8, sizeof(result.rdlength));
	startBuffer += 10;

	result.type = ntohs(result.type);
	result.rclass = ntohs(result.rclass);
	result.ttl = ntohl(result.ttl);
	result.rdlength = ntohs(result.rdlength);

	unsigned char rdata[100];
	//unsigned char *rdata0 = new unsigned char[100];
	memset(&rdata, 0, sizeof(rdata));

	if (!(result.type == 5)) {
		for (unsigned int i = 0; i < result.rdlength; i++) {
			rdata[i] = *startBuffer;
			startBuffer++;
		}
		rdata[result.rdlength] = '\0';
	}
	else {
		currPtr = startBuffer;
		int j = 0;
		while (*currPtr != '\0') {
			if (*currPtr == (char) 192) {
				// It's a pointer
				isPtr = true;
				unsigned int offset = (unsigned char) *(currPtr+1);
				currPtr = responseBuffer+offset;
			}
			else {			
				rdata[j] = *currPtr;
				j++;
				currPtr++;
			}
		}
		if (isPtr) {
			startBuffer+=2;
		}
		else {
			startBuffer = currPtr;
		}
	}
	//memcpy(&rdata0, rdata, sizeof(ra))

	// char *ipv6 = new char[100];
	// inet_ntop(AF_INET6, &rdata, ipv6, INET6_ADDRSTRLEN);
	// cout << ipv6 << endl;
	DNSResourceRecord *rr = new DNSResourceRecord();

	rr->setName(DNSToName(name));
	rr->setType(result.type);
	rr->setClass(result.rclass);
	rr->setTTL(result.ttl);
	rr->setRdlength(result.rdlength);
	// if (result.type == 28) {
	// 	rr->setRdataAsIPv6(rdata);
	// }
	// else {
	rr->setRdata(rdata);	
	//}
	
	//rr->rRdata = rdata;
	

	//cout << "here0" << endl;
	if (rrtype == 0) {
		dp->addDNSAnswer(*rr);
	}
	else if (rrtype == 1) {
		dp->addDNSAuthority(*rr);
	}
	else if (rrtype == 2) {
		dp->addDNSAdditional(*rr);
	}
	//cout << "here1" << endl;
	return startBuffer;
}

/*
*	Converts the domain name input by the user into DNS format
*	Ex: www.google.com --> 3www6google3com
*/
char* Client::nameToDNS(char *domainName) {
	tempName[0] = '.';
	strcat(tempName, domainName);
	int ctr = 0;
	int numCtr = 0;
	char numbers[10];

	for (unsigned int i = 1; i <= strlen(tempName); i++) {
		if ( (tempName[i] == '.') || (i == strlen(tempName)) ) {
			if (i == strlen(tempName)) {
				tempName[i] = '\0';
			}
			numbers[numCtr] = ctr;
			ctr = 0;
			numCtr++;
		}
		else {
			ctr++;
		}
	}
	numCtr = 0;
	for (unsigned int i = 0; i < strlen(tempName); i++) {
		if (tempName[i] == '.') {
			tempName[i] = numbers[numCtr];
			numCtr++;
		}
	}
	return tempName;
}

/*
*	Converts the DNS format into domain name
*	Ex: 3www6google3com --> www.google.com 
*/
string Client::DNSToName(string dnsName) {
	string newName = "";
	unsigned int i = 0;

	if (dnsName.at(dnsName.length()-1) == '.') {
		dnsName.pop_back();
	}

	while (i < dnsName.length()) {
		int num = (int) dnsName.at(i);
		dnsName = dnsName.replace(i, 1, ".");

		i += num;
		i++;
	}
	dnsName += '\0';
	newName = dnsName.substr(1);
	return newName;
}
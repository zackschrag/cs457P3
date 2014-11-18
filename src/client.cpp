#include <client.h>

Client::Client() {
	responseBuffer = new char[500];
	dp = new DNSPacket();
}

Client::~Client() {
	delete tempName;
	delete responseBuffer;
	delete dp;
}

/*
*	Constructs DNS packet and sends query to dnsServer
*/
DNSPacket Client::sendQuery(char *domainName, string dnsServer) {
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
	char *qname = nameToDNS(domainName);
	q.qtype = htons(1);
	q.qclass = htons(1);

	char queryBuffer[256];
	//char responseBuffer[500];
	memset(queryBuffer, 0, sizeof(queryBuffer));
	//memset(responseBuffer, 0, sizeof(responseBuffer));

	memcpy(queryBuffer, &h, sizeof(h));
	memcpy(queryBuffer+(sizeof(h)), qname, strlen(qname)+1);
	memcpy(queryBuffer+(sizeof(h)+strlen(qname)+1), &q, sizeof(q));

	int sock, numbytes, i;

	struct sockaddr_in dest;

	sock = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP);
 
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(dnsServer.c_str());

    cout << "Sending packet to " << dnsServer << endl;
    if((numbytes = sendto(sock,queryBuffer,sizeof(queryBuffer),0,(struct sockaddr*)&dest,sizeof(dest))) < 0) {
        perror("sendto failed");
    }
    cout << "bytes sent: " << numbytes << endl;

    i = sizeof(dest);
    cout << "Receiving answer..." << endl;
    if( (numbytes = recvfrom (sock,responseBuffer, 400 , 0 , (struct sockaddr*)&dest , (socklen_t*)&i )) < 0) {
        perror("recvfrom failed");
    }
    cout << "bytes received: " << numbytes << endl;
    close(sock);

    parsePacket(responseBuffer, dp);
    // parseHeader(responseBuffer, *dp);
    //Header responseHeader = dp->getHeader();
    vector<Question> responseQuestions = dp->getQuestions();
    dp->setQname(domainName);
    cout << responseQuestions.at(0).qtype << endl;
    cout << responseQuestions.at(0).qclass << endl;
    cout << dp->getQname() << endl;

    // cout << responseHeader.id << endl;
    // cout << endl;
    // cout << responseHeader.qr << endl;
    // cout << responseHeader.opcode << endl;
    // cout << responseHeader.aa << endl;
    // cout << responseHeader.tc << endl;
    // cout << responseHeader.rd << endl;
    // cout << responseHeader.ra << endl;
    // cout << responseHeader.z << endl;
    // cout << responseHeader.rcode << endl;
    // cout << endl;
    // cout << responseHeader.qdcount << endl;
    // cout << responseHeader.ancount << endl;
    // cout << responseHeader.nscount << endl;
    // cout << responseHeader.arcount << endl;

    return *dp;
    //return responseBuffer;
    //Question response
    // cout << responseHeader.id << endl;
    // cout << endl;
    // cout << responseHeader.qr << endl;
    // cout << responseHeader.opcode << endl;
    // cout << responseHeader.aa << endl;
    // cout << responseHeader.tc << endl;
    // cout << responseHeader.rd << endl;
    // cout << responseHeader.ra << endl;
    // cout << responseHeader.z << endl;
    // cout << responseHeader.rcode << endl;
    // cout << endl;
    // cout << responseHeader.qdcount << endl;
    // cout << responseHeader.ancount << endl;
    // cout << responseHeader.nscount << endl;
    // cout << responseHeader.arcount << endl;

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

void Client::parsePacket(char *responseBuffer, DNSPacket *dp) {
	parseHeader(responseBuffer, dp);
	parseQuestion(responseBuffer+sizeof(Header), dp);
	//parseAnswer()
}

void Client::parseHeader(char *responseBuffer, DNSPacket *dp) {
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
	dp->setHeader(result);
	//return result;
}

void Client::parseQuestion(char *startBuffer, DNSPacket *dp) {
	Question result;

	while (*startBuffer != '\0') {
		startBuffer++;
	}
	startBuffer++;
	memcpy(&result.qtype, startBuffer, sizeof(result.qtype));
	memcpy(&result.qclass, startBuffer+sizeof(result.qtype), sizeof(result.qclass));
	result.qtype = ntohs(result.qtype);
	result.qclass = ntohs(result.qclass);
	dp->addQuestion(result);
	//dp->setQuestions(result);
	//return result;
}

void Client::parseAnswer(char *startBuffer, DNSPacket *dp) {
	ResourceRecord result;
	//cout << *startBuffer << endl;
	while (*startBuffer != '\0') {
		//cout << &startBuffer << " ";
		startBuffer++;
	}
	//startBuffer++;
	//startBuffer+=2;
	// memcpy(&result.namePtr, startBuffer, sizeof(result.namePtr));//+sizeof(result.type)+sizeof(result.rclass)+sizeof(result.ttl)+sizeof(result.rdlength));
	// memcpy(&result.type, startBuffer+2, sizeof(result.type));
	// memcpy(&result.rclass, startBuffer+4, sizeof(result.rclass));
	// memcpy(&result.ttl, startBuffer+6, sizeof(result.ttl));
	// memcpy(&result.rdlength, startBuffer+10, sizeof(result.rdlength));
	memcpy(&result, startBuffer,16);
	
	result.namePtr = ntohs(result.namePtr);
	result.type = ntohs(result.type);
	result.rclass = ntohs(result.rclass);
	result.ttl = ntohl(result.ttl);
	result.rdlength = ntohs(result.rdlength);

	cout << "In method:" << endl;
	cout << result.namePtr << endl;
	cout << result.type << endl;
	cout << result.rclass << endl;
	cout << result.ttl << endl;
	cout << result.rdlength << endl;
	//return result;
}

/*
*	Converts the domain name input by the user into DNS format
*	Ex: www.google.com --> 3www6google3com
*/
char* Client::nameToDNS(char *domainName) {
	tempName = new char;
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



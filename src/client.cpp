#include <client.h>

Client::Client() {
}

Client::~Client() {
	delete tempName;
}

void Client::sendQuery(char *domainName, string dnsServer) {
	Header h;
	h.id = htons(getpid());
	h.flags = htons(0);
	h.qdcount = htons(1);
	h.ancount = htons(0);
	h.nscount = htons(0);
	h.arcount = htons(0);

	Question q;
	char *qname = nameToDNS(domainName);
	q.qtype = htons(1);
	q.qclass = htons(1);

	char queryBuffer[256];
	char responseBuffer[500];
	memset(queryBuffer, 0, sizeof(queryBuffer));
	memset(responseBuffer, 0, sizeof(responseBuffer));

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
    // Header responseHeader = parsePacket(responseBuffer);

    //	cout << "---" << endl;
	// for (unsigned int i = 0; i < sizeof(responseBuffer); i++) {
	// 	cout << responseBuffer[i] << " ";
	// }
	// cout << "\n---" << endl;

}

char* Client::nameToDNS(char *domainName) {
	// Ex: www.google.com --> 3www6google3com
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
	cout << "numbers: " << endl;
	numCtr = 0;
	for (unsigned int i = 0; i < strlen(tempName); i++) {
		if (tempName[i] == '.') {
			tempName[i] = numbers[numCtr];
			numCtr++;
		}
	}
	return tempName;
}


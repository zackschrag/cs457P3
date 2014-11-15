#include <p3.h>
#include <client.h>
#include <dnsquestion.h>

struct Header0 {
	short id;
	short flags;
	short qdcount;
	short ancount;
	short nscount;
	short arcount;
};

struct Question0 {
	char qname[14];
	short qtype;
	short qclass;
};

int main(int arc, char **argv) {
	Client c;
	Header0 h;
	h.id = htons(1);
	h.flags = htons(0);
	h.qdcount = htons(1);
	h.ancount = htons(0);
	h.nscount = htons(0);
	h.arcount = htons(0);

	Question0 q;
	char test[14] = {'3','w','w','w','3','c','n','n','3','c','o','m','0'};
	memcpy(q.qname, test, 14);

	q.qtype = htons(1);
	q.qclass = htons(1);

	char queryBuffer[sizeof(h)+sizeof(q)];
	char responseBuffer[400];
	memset(queryBuffer, 0, sizeof(queryBuffer));
	memset(responseBuffer, 0, sizeof(responseBuffer));

	memcpy(queryBuffer, &h, sizeof(h));
	memcpy(queryBuffer+12, &q, sizeof(q));

	cout << "---" << endl;
	for (unsigned int i = 0; i < sizeof(h) + sizeof(q); i++) {
		cout << queryBuffer[i];
	}
	cout << "\n---" << endl;

	// int sockfd;
 //    struct addrinfo hints, *servinfo, *p;
 //    int rv;
 //    int numbytes;

 //    memset(&hints, 0, sizeof hints);
 //    hints.ai_family = AF_INET;
 //    hints.ai_socktype = SOCK_DGRAM;

	// struct sockaddr_in dest;
	// dest.sin_family = AF_INET;
 //    dest.sin_port = htons(53);
 //    dest.sin_addr.s_addr = inet_addr(ROOT_A_A);

 //    if ((rv = getaddrinfo(ROOT_A_A, DNS_PORT, &hints, &servinfo)) != 0) {
 //        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
 //    }

 //    // loop through all the results and make a socket
 //    for(p = servinfo; p != NULL; p = p->ai_next) {
 //        if ((sockfd = socket(p->ai_family, p->ai_socktype,
 //                p->ai_protocol)) == -1) {
 //            perror("talker: socket");
 //            continue;
 //        }

 //        break;
 //    }

 //    if (p == NULL) {
 //        fprintf(stderr, "talker: failed to bind socket\n");
 //    }

 //    do {
 //    	numbytes = sendto(sockfd, queryBuffer, strlen(queryBuffer), 0, (struct sockaddr*)&dest, sizeof(dest)); //p->ai_addr, p->ai_addrlen);
 //    	printf("talker: sent %d bytes to %s\n", numbytes, packet.getIP().c_str());
 //    	sleep(1);
 //    } while (numbytes > 0);
 //    freeaddrinfo(servinfo);

 //    printf("talker: sent %d bytes to %s\n", numbytes, packet.getIP().c_str());
 //    close(sockfd);


	// DNSHeader header(1,'1','0','0','0','0','0','0',1,0,0,0);
	// DNSQuestion question("3www3cnn3com0", 1, 1);
	// DNSResourceRecord answer;
	// DNSResourceRecord authority;
	// DNSResourceRecord additional;

 //    cout << "id: " << sizeof(header.getPacket().id) << endl;
 //    cout << "tc: " << sizeof(header.getPacket()) << endl;
 //    cout << "aa: " << sizeof(header.getAA()) << endl;
 //    cout << "opcode: " << sizeof(header.getOpcode()) << endl;
 //    cout << "qr: " << sizeof(header.getQR()) << endl;
 
 //    cout << "getRcode: " << sizeof(header.getRcode()) << endl;
 //    cout << "z: " << sizeof(header.getZ()) << endl;
 //    cout << "ra: " << sizeof(header.getRA()) << endl;
 //    cout << "qcount: " << sizeof(header.getQCount()) << endl;
 //    cout << "ans: " << sizeof(header.getAnsCount()) << endl;
 //    cout << "auth: " << sizeof(header.getAuthCount()) << endl;
 //    cout << "add: " << sizeof(header.getAddCount()) << endl;

	// DNSPacket packet(ROOT_A_A, header, question, answer, authority, additional);
//	c.sendQuery(packet);
	//c.requestConnection(ROOT_A_A);
	//DNSQuestion q((string) ROOT_A_A, "www.cnn.com", 1, 1);
	//c.sendQuestion(q);
	return 0;
}
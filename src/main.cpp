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
	h.id = htons(3);
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
		cout << queryBuffer[i] << " ";
	}
	cout << "\n---" << endl;



	int sock, numbytes, i;
	//struct sockaddr_in a;
	struct sockaddr_in dest;

	sock = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP); //UDP packet for DNS queries
 
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(/*ROOT_A_A*/"129.82.45.181");


    char buf[3] = {'t','h','a'};
    cout << "Sending Packet..." << endl;
    if((numbytes = sendto(sock,queryBuffer,30,0,(struct sockaddr*)&dest,sizeof(dest))) < 0) {
        perror("sendto failed");
    }
    cout << "bytes sent: " << numbytes << endl;

    i = sizeof dest;
    cout << "Receiving answer..." << endl;
    if( (numbytes = recvfrom (sock,responseBuffer, 400 , 0 , (struct sockaddr*)&dest , (socklen_t*)&i )) < 0) {
        perror("recvfrom failed");
    }
    cout << "bytes received: " << numbytes << endl;


   	cout << "---" << endl;
	for (unsigned int i = 0; i < sizeof(responseBuffer); i++) {
		cout << (short) responseBuffer[i] << " ";
	}
	cout << "\n---" << endl;


	cout << htons(0) << endl;
	cout << ntohs(-128) << endl;
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
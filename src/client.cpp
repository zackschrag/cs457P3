#include <client.h>

Client::Client() {
	socketToServer = -1;
}

Client::~Client() {
	close(socketToServer);
}

void Client::sendQuery(DNSPacket packet) {
	cout << "DEBUG: Sending question..." << endl;
	// cout << "DEBUG: qname: " << query.getQname() << endl;
	// cout << "DEBUG: qtype: " << query.getQtype() << endl;
	// cout << "DEBUG: qclass: " << query.getQclass() << endl;

	//struct DNS_HEADER *dns = NULL;
 
    // dest.sin_family = AF_INET;
    // dest.sin_port = htons(53);
    // dest.sin_addr.s_addr = inet_addr(dns_servers[0]); //dns servers
 
    //Set the DNS structure to standard queries
    // dns = (struct DNS_HEADER *)&buf;
 
    // dns->id = (unsigned short) htons(getpid());
    // dns->qr = 0; //This is a query
    // dns->opcode = 0; //This is a standard query
    // dns->aa = 0; //Not Authoritative
    // dns->tc = 0; //This message is not truncated
    // dns->rd = 1; //Recursion Desired
    // dns->ra = 0; //Recursion not available! hey we dont have it (lol)
    // dns->z = 0;
    // dns->ad = 0;
    // dns->cd = 0;
    // dns->rcode = 0;
    // dns->q_count = htons(1); //we have only 1 question
    // dns->ans_count = 0;
    // dns->auth_count = 0;
    // dns->add_count = 0;

	// char questionBuffer[262];
	// char responseBuffer[400];
	// memset(questionBuffer, 0, sizeof(questionBuffer));
	// memset(responseBuffer, 0, sizeof(responseBuffer));

	// //DNS_HEADER packetHeader;
	// //packetHeader.

	// QuestionPacket qp = query.getPacket();
	// cout << "QuestionPacket..." << endl;
	// cout << "DEBUG: Length: " << qp.qnameLength << endl;
	// cout << "DEBUG: qname: " << query.getQname() << endl;
	// cout << "DEBUG: qtype: " << query.getQtype() << endl;
	// cout << "DEBUG: qclass: " << query.getQclass() << endl;

	// memcpy(questionBuffer, &qp, sizeof(questionBuffer));

	// cout << "---" << endl;
	// for (int i = 0; i < 262; i++) {
	// 	cout << (char) questionBuffer[i];
	// }
	// cout << "\n---" << endl;

	// memcpy(questionBuffer+2, qp.qname, sizeof(qp.qname));
	// memcpy(questionBuffer+258, qp.qtype, sizeof(short));
	// memcpy(questionBuffer+260, qp.qclass, sizeof(short));

	// int sockfd;
 //    struct addrinfo hints, *servinfo, *p;
 //    int rv;
 //    int numbytes;

 //    memset(&hints, 0, sizeof hints);
 //    hints.ai_family = AF_INET;
 //    hints.ai_socktype = SOCK_DGRAM;

 //    if ((rv = getaddrinfo(ROOT_A_A, DNS_PORT, &hints, &servinfo)) != 0) {
 //        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
 //        //return 1;
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
 //        //return 2;
 //    }

 //    if ((numbytes = sendto(sockfd, questionBuffer, strlen(questionBuffer), 0,
 //             p->ai_addr, p->ai_addrlen)) == -1) {
 //        perror("talker: sendto");
 //        exit(1);
 //    }

 //    freeaddrinfo(servinfo);

 //    printf("talker: sent %d bytes to %s\n", numbytes, query.getIP().c_str());
 //    close(sockfd);
}




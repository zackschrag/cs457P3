#include <p3.h>
#include <client.h>
#include <dnspacket.h>

void usage() {
	cerr << "Usage: myresolver <domain-name> [RRTYPE code]" << endl;
}

int main(int argc, char **argv) {
	Client c;
	string RRTYPE;
	char *domainName;
	if ( !((argc == 2) || (argc == 3)) ) {
		usage();
	}
	if (argc == 3) {
		RRTYPE = argv[2];
	}
	domainName = argv[1];
    DNSPacket dnspacket = c.sendQuery(domainName, "208.67.220.220");//ROOT_A_A);
	// Header responseHeader = c.parseHeader(responseBuffer);
 //    cout << responseHeader.id << endl;
 //    cout << endl;
 //    cout << responseHeader.qr << endl;
 //    cout << responseHeader.opcode << endl;
 //    cout << responseHeader.aa << endl;
 //    cout << responseHeader.tc << endl;
 //    cout << responseHeader.rd << endl;
 //    cout << responseHeader.ra << endl;
 //    cout << responseHeader.z << endl;
 //    cout << responseHeader.rcode << endl;
 //    cout << endl;
 //    cout << responseHeader.qdcount << endl;
 //    cout << responseHeader.ancount << endl;
 //    cout << responseHeader.nscount << endl;
 //    cout << responseHeader.arcount << endl;
 //    cout << endl;

    // This will need to be a while loop
	// Question responseQuestion = c.parseQuestion(responseBuffer+sizeof(responseHeader));
	// cout << responseQuestion.qtype << endl;
	// cout << responseQuestion.qclass << endl;
	// cout << endl;

	// int headerSize = sizeof(Header);
	// int querySize = sizeof(Question);
	// int nameSize = strlen(domainName)+2;	// the 2 is to account for the '\0' character and the first character of the DNS name format
	// int questionSize = querySize + nameSize;
	// char *answerStart = responseBuffer + (headerSize + querySize);
	

	// cout << "sizeof query: " << questionSize << endl;

	// ResourceRecord responseAnswer = c.parseAnswer(answerStart);	
	// int answerSize = sizeof(ResourceRecord)+responseAnswer.rdlength;
	// cout << sizeof(ResourceRecord) << endl;
	// cout << responseAnswer.rdlength << endl;
	// cout << "answer size: " << answerSize << endl;
	
	return 0;
}
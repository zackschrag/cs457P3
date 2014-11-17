#include <p3.h>
#include <client.h>

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
	char* responseBuffer = c.sendQuery(domainName, "208.67.220.220");//ROOT_A_A);
	Header responseHeader = c.parseHeader(responseBuffer);
    cout << responseHeader.id << endl;
    cout << endl;
    cout << responseHeader.qr << endl;
    cout << responseHeader.opcode << endl;
    cout << responseHeader.aa << endl;
    cout << responseHeader.tc << endl;
    cout << responseHeader.rd << endl;
    cout << responseHeader.ra << endl;
    cout << responseHeader.z << endl;
    cout << responseHeader.rcode << endl;
    cout << endl;
    cout << responseHeader.qdcount << endl;
    cout << responseHeader.ancount << endl;
    cout << responseHeader.nscount << endl;
    cout << responseHeader.arcount << endl;
    cout << endl;
    // This will need to be a while loop
	Question responseQuestion = c.parseQuestion(responseBuffer+sizeof(responseHeader));
	cout << responseQuestion.qtype << endl;
	cout << responseQuestion.qclass << endl;
	cout << endl;

	for (int i = 0; i < responseHeader.ancount; i++) {
		ResourceRecord responseAnswer = c.parseAnswer(responseBuffer+sizeof(responseHeader)+strlen(domainName)+1+sizeof(responseQuestion));	
		cout << responseAnswer.type << endl;
		cout << responseAnswer.rclass << endl;
		cout << responseAnswer.ttl << endl;
		cout << responseAnswer.rdlength << endl;
		cout << responseAnswer.rdata << endl;
	}
	
	return 0;
}
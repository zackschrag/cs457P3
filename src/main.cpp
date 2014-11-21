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
    DNSPacket dnspacket = c.sendQuery(domainName, ROOT_A_A);//"205.171.2.65");//"208.67.222.222");//ROOT_A_A);

	return 0;
}
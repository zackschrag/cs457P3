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
	c.sendQuery(domainName, ROOT_K_A);
	return 0;
}
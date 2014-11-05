#include <p3.h>
#include <client.h>
#include <dnsquestion.h>

int main(int arc, char **argv) {
	cout << "Hello world" << endl;
	Client c;
	//c.requestConnection(ROOT_A_A);
	DNSQuestion q((string) ROOT_A_A, "www.cnn.com", 1, 1);
	c.sendQuestion(q);
	return 0;
}
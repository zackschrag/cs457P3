#include <p3.h>
#include <client.h>
#include <dnsquestion.h>

int main(int arc, char **argv) {
	Client c;
	DNSHeader header(1,'1','0','0','0','0','0','0',1,0,0,0);
	DNSQuestion question("www.cnn.com", 1, 1);
	DNSResourceRecord answer;
	DNSResourceRecord authority;
	DNSResourceRecord additional;

    cout << "id: " << sizeof(header.getPacket().id) << endl;
    cout << "tc: " << sizeof(header.getPacket()) << endl;
    cout << "aa: " << sizeof(header.getAA()) << endl;
    cout << "opcode: " << sizeof(header.getOpcode()) << endl;
    cout << "qr: " << sizeof(header.getQR()) << endl;
 
    cout << "getRcode: " << sizeof(header.getRcode()) << endl;
    cout << "z: " << sizeof(header.getZ()) << endl;
    cout << "ra: " << sizeof(header.getRA()) << endl;
    cout << "qcount: " << sizeof(header.getQCount()) << endl;
    cout << "ans: " << sizeof(header.getAnsCount()) << endl;
    cout << "auth: " << sizeof(header.getAuthCount()) << endl;
    cout << "add: " << sizeof(header.getAddCount()) << endl;

	DNSPacket packet(ROOT_A_A, header, question, answer, authority, additional);
	c.sendQuery(packet);
	//c.requestConnection(ROOT_A_A);
	//DNSQuestion q((string) ROOT_A_A, "www.cnn.com", 1, 1);
	//c.sendQuestion(q);
	return 0;
}
#include <p3.h>
#include <client.h>
#include <dnspacket.h>

void usage() {
	cerr << "Usage: myresolver <domain-name> [RRTYPE code]" << endl;
}

void printAnswers(vector<DNSResourceRecord> answerList, vector<DNSResourceRecord> cnames){

     cout << ";; ANSWER SECTION:\n";

        if(answerList.empty()){
            cout << "No answers available\n\n";    
        }
        
        unsigned int i;
        for (i = 0; i < cnames.size(); i++) {
        	DNSResourceRecord curr = cnames.at(i);
			cout << curr.getName() << "\t\t" << curr.getTTL() << "\t" << "IN\t";
			cout << "CNAME\t";
			cout << curr.getRdata() << "\t\t";
			cout << endl;
        }

        for(i = 0; i < answerList.size(); i++){

            DNSResourceRecord responseAnswer;

            responseAnswer = answerList.at(i);

            cout << responseAnswer.getName() << "\t\t" << responseAnswer.getTTL() << "\t" << "IN\t";

                if(responseAnswer.getType() == 1){
                    cout << "A\t";
                } else if(responseAnswer.getType() == 5){
                    cout << "CNAME\t";

                } else if (responseAnswer.getType() == 28) {
                    cout << "AAAA\t";
                    cout << responseAnswer.getRdataAsIPv6() << endl;
                }

            if (responseAnswer.isIPv4()) {
				cout << responseAnswer.getRdataAsString() << endl;
			}
            // if(responseAnswer.getType() == 1){
            //     //cout << (int) responseAnswer.ip1 << '.' << (int) responseAnswer.ip2 << '.' << (int) responseAnswer.ip3 << '.' << (int) responseAnswer.ip4 << endl;
            //     cout << responseAnswer.getRdataAsString() << endl;
            // } else if(responseAnswer.type == 5){
            //     //cout << responseAnswer.cname << endl;
            // }
        }
}

int main(int argc, char *argv[]) {
	Client c;
	string RRTYPE;
	char *domainName;
	vector<DNSResourceRecord> *cnameAnswers = new vector<DNSResourceRecord>();
	//char domainName[100];

	if ( !((argc == 2) || (argc == 3)) ) {
		usage();
	}
	if (argc == 3) {
		RRTYPE = argv[2];
	}
	if (argc == 2) {
		RRTYPE = 'A';
	}
	//memset(&domainName, 0, strlen(argv[1]));
	domainName = argv[1];
	//memcpy(domainName, argv[1], strlen(argv[1]));
	short recordType = 1;
	if (RRTYPE == "AAAA") {
		recordType = 28;
	}
	//"205.171.2.65");//"208.67.222.222");//ROOT_A_A);
	// For cname "204.74.108.238"

	string nextServer = ROOT_A_A;//"204.74.108.238";
	bool found = false;

	while (!found) {
		DNSPacket *dnspacket = c.sendQuery(domainName, nextServer, recordType);	
		int numAnswers = dnspacket->getNumberOfAnswers();

		if (numAnswers > 0) {
			vector<DNSResourceRecord> answers = dnspacket->getDNSAnswers();

			DNSResourceRecord ans = answers.at(0);
			if (ans.isCname()) {
				nextServer = ROOT_A_A;
				domainName = (char*) ans.getRdata();

				//char * qaz = (char*) ans.getRdata();
				//memcpy(domainName, qaz, strlen(qaz));
				string tmp(domainName);
				tmp = c.DNSToName(tmp);
				
				for (unsigned int i = 0; i < tmp.length(); i++) {
					domainName[i] = tmp.at(i);
				}
				//cout << tmp << endl;
				cnameAnswers->push_back(ans);
				continue;
			}
			else if (ans.isIPv4()) {
				// DONE!
				//cout << "IPv4: " << endl;
				found = true;
				printAnswers(answers, *cnameAnswers);
				break;
			}
			else if (ans.isIPv6()) {
				//cout << "IPv6: " << endl;
				found = true;
				printAnswers(answers, *cnameAnswers);
				break;	
			}
		}
		else {
			if (dnspacket->getNumberOfAdditionals() > 0) {
				vector<DNSResourceRecord> *additionals = dnspacket->dnsAdditionals;
				DNSResourceRecord addl = additionals->at(0);
				// if (addl.getType() == 28) {
				// 	nextServer = addl.getRdataAsIPv6();	
				// }
				nextServer = addl.getRdataAsString();
				//cout << "nextServer: " << nextServer << endl;
			}
			else {
				cout << "NO ADDITIONAL RECORDS" << endl;
				vector<DNSResourceRecord> *authorities = dnspacket->dnsAuthorities;
				DNSResourceRecord auth = authorities->at(0);
				nextServer = auth.getRdataAsString();
				//cout << "nextServer: " << nextServer << endl;
			}
		}
		dnspacket->clearAllRecords();
	}
	delete cnameAnswers;
	return 0;
}
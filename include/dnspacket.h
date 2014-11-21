#ifndef DNSPACKET_H
#define DNSPACKET_H

#include <p3.h>
#include <dnsquestion.h>
#include <dnsresourcerecord.h>

class DNSPacket {
public:
	DNSPacket();
	~DNSPacket();
	DNSPacket(Header h, vector<Question> q, vector<ResourceRecord> ans, vector<ResourceRecord> auth, vector<ResourceRecord> addl, char *qname);
	Header getHeader();
	vector<Question> getQuestions();
	vector<ResourceRecord> getAnswers();
	vector<ResourceRecord> getAuthorities();
	vector<ResourceRecord> getAdditionals();
	string getQname();

	int getNumberOfQuestions();
	int getNumberOfAnswers();
	int getNumberOfAuthorities();
	int getNumberOfAdditionals();

	void setNumberOfQuestions(int num);
	void setNumberOfAnswers(int num);
	void setNumberOfAuthorities(int num);
	void setNumberOfAdditionals(int num);

	void setQname(string newName);
	void setHeader(Header h);
	void setQuestions(vector<Question> q);
	void setAnswer(ResourceRecord ans);

	void addQuestion(Question q);
	void addDNSQuestion(DNSQuestion q);

	void addAnswer(ResourceRecord ans);
	void addDNSAnswer(DNSResourceRecord rr);

	void addAuthority(ResourceRecord auth);
	void addDNSAuthority(DNSResourceRecord rr);

	void addAdditional(ResourceRecord addl);
	void addDNSAdditional(DNSResourceRecord rr);


	vector<DNSQuestion> *dnsQuestions;
	vector<DNSResourceRecord> *dnsAnswers;
	vector<DNSResourceRecord> *dnsAuthorities;
	vector<DNSResourceRecord> *dnsAdditionals;
private:
	//char *qname;
	string qname;
	char *rdata;
	Header header;
	vector<Question> *questions;


	vector<ResourceRecord> *answers;
	vector<ResourceRecord> *authorities;
	vector<ResourceRecord> *additionals;

	int numberOfQuestions;
	int numberOfAnswers;
	int numberOfAuthorities;
	int numberOfAdditionals;
};

#endif
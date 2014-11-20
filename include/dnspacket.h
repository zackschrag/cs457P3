#ifndef DNSPACKET_H
#define DNSPACKET_H

#include <p3.h>

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

	void setQname(char *newName);
	void setHeader(Header h);
	void setQuestions(vector<Question> q);
	void setAnswer(ResourceRecord ans);


	void addQuestion(Question q);
	void addAnswer(ResourceRecord ans);
	void addAuthority(ResourceRecord auth);
	void addAdditional(ResourceRecord addl);

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
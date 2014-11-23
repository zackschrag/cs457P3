#ifndef P3_H
#define P3_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

#define ROOT_K_A 	"193.0.14.129"
#define ROOT_K_AAAA "2001:7fd::1"

#define ROOT_B_A 	"192.228.79.201"
#define ROOT_B_AAAA "2001:500:84::b"

#define ROOT_H_A 	"128.63.2.53"
#define ROOT_H_AAAA "2001:500:1::803f:235"

#define ROOT_L_A 	"199.7.83.42"
#define ROOT_L_AAAA "2001:500:3::42"

#define ROOT_A_A 	"198.41.0.4"
#define ROOT_A_AAAA "2001:503:ba3e::2:30"

#define ROOT_M_A 	"202.12.27.33"
#define ROOT_M_AAAA "2001:dc3::35"

#define ROOT_E_A 	"192.203.230.10"
#define ROOT_E_AAAA "-1"

#define ROOT_I_A 	"192.36.148.17"
#define ROOT_I_AAAA "2001:7fe::53"

#define ROOT_C_A 	"192.33.4.12"
#define ROOT_C_AAAA "2001:500:2::c"

#define ROOT_F_A 	"192.5.5.241"
#define ROOT_F_AAAA "2001:500:2f::f"

#define ROOT_D_A 	"199.7.91.13"
#define ROOT_D_AAAA "2001:500:2d::d"

#define ROOT_G_A 	"192.112.36.4"
#define ROOT_G_AAAA "-1"

#define ROOT_J_A 	"192.58.128.30"
#define ROOT_J_AAAA "2001:503:c27::2:30"

struct Header {
	unsigned short id;

	unsigned qr :1;
	unsigned opcode :4;
	unsigned aa :1;
	unsigned tc :1;
	unsigned rd :1;
	unsigned ra :1;
	unsigned z :3;
	unsigned rcode :4;

	unsigned short qdcount;
	unsigned short ancount;
	unsigned short nscount;
	unsigned short arcount;
};

struct Question {
	// name
	//char *qname;
	unsigned short qtype;
	unsigned short qclass;
};

struct ResourceRecord {
	// name
	unsigned short namePtr;
	unsigned short type;
	unsigned short rclass;
	unsigned int ttl;
	unsigned short rdlength;
	//int rdata;
};

#endif
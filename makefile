HEADERSDIR = include
SRCDIR = src
BINDIR = bin
FLAGS = -Wall
EXEC = myresolver

all:	$(EXEC)	

myresolver:	$(BINDIR)/main.o
	g++ $(FLAGS) $(BINDIR)/client.o $(BINDIR)/dnspacket.o $(BINDIR)/dnsresourcerecord.o $(BINDIR)/dnsheader.o $(BINDIR)/dnsquestion.o $(BINDIR)/main.o -o myresolver

$(BINDIR)/main.o:	$(SRCDIR)/main.cpp $(HEADERSDIR)/p3.h $(BINDIR)/myresolver.o $(BINDIR)/usage.o $(BINDIR)/dnspacket.o $(BINDIR)/dnsquestion.o $(BINDIR)/dnsheader.o $(BINDIR)/dnsresourcerecord.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/main.cpp -c -o $(BINDIR)/main.o

$(BINDIR)/myresolver.o:	$(SRCDIR)/myresolver.cpp $(HEADERSDIR)/myresolver.h $(HEADERSDIR)/p3.h $(BINDIR)/client.o $(BINDIR)/dnspacket.o $(BINDIR)/dnsquestion.o $(BINDIR)/dnsheader.o $(BINDIR)/dnsresourcerecord.o 
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/myresolver.cpp -c -o $(BINDIR)/myresolver.o

$(BINDIR)/dnspacket.o:	$(SRCDIR)/dnspacket.cpp $(HEADERSDIR)/dnspacket.h $(HEADERSDIR)/dnsheader.h $(HEADERSDIR)/dnsquestion.h $(HEADERSDIR)/dnsresourcerecord.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnspacket.cpp -c -o $(BINDIR)/dnspacket.o

$(BINDIR)/dnsheader.o:	$(SRCDIR)/dnsheader.cpp $(HEADERSDIR)/dnsheader.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnsheader.cpp -c -o $(BINDIR)/dnsheader.o

$(BINDIR)/dnsquestion.o:	$(SRCDIR)/dnsquestion.cpp $(HEADERSDIR)/dnsquestion.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnsquestion.cpp -c -o $(BINDIR)/dnsquestion.o

$(BINDIR)/dnsresourcerecord.o:	$(SRCDIR)/dnsresourcerecord.cpp $(HEADERSDIR)/dnsresourcerecord.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnsresourcerecord.cpp -c -o $(BINDIR)/dnsresourcerecord.o

$(BINDIR)/client.o:	$(SRCDIR)/client.cpp $(HEADERSDIR)/client.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/client.cpp -c -o $(BINDIR)/client.o

$(BINDIR)/usage.o:	$(SRCDIR)/usage.cpp $(HEADERSDIR)/usage.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/usage.cpp -c -o $(BINDIR)/usage.o

clean:
	rm -f myresolver
	rm -rf bin/
	mkdir bin
HEADERSDIR = include
SRCDIR = src
BINDIR = bin
FLAGS = -Wall -std=c++11
EXEC = myresolver

all:	$(EXEC)	

myresolver:	$(BINDIR)/main.o
	g++ $(FLAGS) $(BINDIR)/client.o $(BINDIR)/main.o $(BINDIR)/dnspacket.o $(BINDIR)/dnsquestion.o $(BINDIR)/dnsresourcerecord.o -o myresolver

$(BINDIR)/main.o:	$(SRCDIR)/main.cpp $(HEADERSDIR)/p3.h $(BINDIR)/myresolver.o $(BINDIR)/dnspacket.o $(BINDIR)/dnsquestion.o $(BINDIR)/dnsresourcerecord.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/main.cpp -c -o $(BINDIR)/main.o

$(BINDIR)/myresolver.o:	$(SRCDIR)/myresolver.cpp $(HEADERSDIR)/myresolver.h $(HEADERSDIR)/p3.h $(BINDIR)/client.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/myresolver.cpp -c -o $(BINDIR)/myresolver.o

$(BINDIR)/dnspacket.o:	$(SRCDIR)/dnspacket.cpp $(HEADERSDIR)/dnspacket.h $(HEADERSDIR)/p3.h $(BINDIR)/dnsquestion.o $(BINDIR)/dnsresourcerecord.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnspacket.cpp -c -o $(BINDIR)/dnspacket.o

$(BINDIR)/dnsquestion.o:	$(SRCDIR)/dnsquestion.cpp $(HEADERSDIR)/dnsquestion.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnsquestion.cpp -c -o $(BINDIR)/dnsquestion.o

$(BINDIR)/dnsresourcerecord.o:	$(SRCDIR)/dnsresourcerecord.cpp $(HEADERSDIR)/dnsresourcerecord.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/dnsresourcerecord.cpp -c -o $(BINDIR)/dnsresourcerecord.o

$(BINDIR)/client.o:	$(SRCDIR)/client.cpp $(HEADERSDIR)/client.h $(HEADERSDIR)/p3.h
	mkdir -p bin
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/client.cpp -c -o $(BINDIR)/client.o

clean:
	rm -f myresolver
	rm -rf bin/
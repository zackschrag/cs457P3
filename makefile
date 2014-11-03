HEADERSDIR = include
SRCDIR = src
BINDIR = bin
FLAGS = -Wall
EXEC = myresolver

all:	$(EXEC)	

myresolver:	$(BINDIR)/main.o
	g++ $(FLAGS) $(BINDIR)/main.o -o myresolver

$(BINDIR)/main.o:	$(SRCDIR)/main.cpp $(HEADERSDIR)/p3.h $(BINDIR)/myresolver.o $(BINDIR)/client.o $(BINDIR)/usage.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/main.cpp -c -o $(BINDIR)/main.o

$(BINDIR)/myresolver.o:	$(SRCDIR)/myresolver.cpp $(HEADERSDIR)/myresolver.h $(HEADERSDIR)/p3.h $(BINDIR)/client.o
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/myresolver.cpp -c -o $(BINDIR)/myresolver.o

$(BINDIR)/client.o:	$(SRCDIR)/client.cpp $(HEADERSDIR)/client.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/client.cpp -c -o $(BINDIR)/client.o

$(BINDIR)/usage.o:	$(SRCDIR)/usage.cpp $(HEADERSDIR)/usage.h $(HEADERSDIR)/p3.h
	g++ $(FLAGS) -I$(HEADERSDIR) $(SRCDIR)/usage.cpp -c -o $(BINDIR)/usage.o

clean:
	rm myresolver
	rm -rf bin/
	mkdir bin
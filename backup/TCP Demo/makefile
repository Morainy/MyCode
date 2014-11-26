Client:Client.o RIO.o
	g++ -o Client Client.o RIO.o
Server:Server.o RIO.o
	g++ -o Server Server.o RIO.o
Client.o:Client.cpp
	g++ -c Client.cpp
Server.o:Server.cpp
	g++ -c Server.cpp
RIO.o:RIO.c RIO.h
	g++ -c RIO.c
clean:*.o *~
	rm *.o *~

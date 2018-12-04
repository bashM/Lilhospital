
hospital: main.o linkedlist.o patient.o
	g++ main.o linkedlist.o patient.o -o hospital

main.o: main.cpp linkedlist.h patient.h
	g++ -c main.cpp

linkedlist.o: linkedlist.cpp linkedlist.h patient.h
	g++ -c linkedlist.cpp

patient.o: patient.cpp patient.h
	g++ -c patient.cpp

clean:
	rm *.o hospital



all: bsim

bsim: BankSimApp.o PriorityQueue.h BinaryHeap.h Queue.h Event.o EmptyDataCollectionException.o
	g++ -Wall -g -o bsim BankSimApp.o Event.o EmptyDataCollectionException.o -std=c++17

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -g -c BankSimApp.cpp -std=c++17
	
Event.o: Event.h Event.cpp
	g++ -Wall -g -c Event.cpp -std=c++17

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -g -c EmptyDataCollectionException.cpp -std=c++17

clean:	
	rm -f bsim *.o

# Bank Simulation

A simulation to calculate an approximation of the average time a customer has to wait for service from that branch's only teller and and to evaluate potential improvements if the bank hires more tellers.

## Features

This simulation models the behaviour of customers arriving and being served at the bank. It uses two key data structures:
- Queue ADT: Simulates the customer line.
- Priority Queue ADT: Manages events such as arrivals and departures, implemented with a Binary Heap for efficient priority handling.

The simulation processes events in order of priority:
- Earlier times take precedence.
- Arrival (A) events are prioritized over Departure (D) events when occurring at the same time.

### Details

The Bank Simulation application uses a Queue to simulate the line-up at the bank teller and a Priority Queue to store the Event objects, using some of their characteristics as the priority value.

The Queue ADT class simulates the line-up at the bank teller. The Priority Queue ADT class utilizes a Binary Heap ADT class.

## Usage

Use the provided Makefile to compile and run the project

```console
make
```

The Bank Simulation application is not to open and read input files, but it is to read input files from the command line as follows:

```console
./bsim < simulationShuffled3.in
```

Input and output:
- Input: Each input file describes a sequence of arrival and departure events.
- Output: The program prints the simulation results in a specific format, showing the order of events and key statistics, including the average customer wait time.
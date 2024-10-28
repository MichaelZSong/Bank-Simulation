# Bank Simulation

A simulation to calculate an approximation of the average time a customer has to wait for service from that branch's only teller and how much improvement we can expect if the bank hired a given number of additional tellers.

## Details

The Bank Simulation application uses a Queue to simulate the line-up at the bank teller and a Priority Queue to store the Event objects, using some of their characteristics as the priority value.

The Queue ADT class simulates the line-up at the bank teller. The Priority Queue ADT class utilizes a Binary Heap ADT class.

## Usage

The Bank Simulation application is not to open and read input files, but it is to read input files from the command line as follows:

```console
./bsim < simulationShuffled3.in
```
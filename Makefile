CC=gcc
CXX=g++
CFLAGS=-O2 -fopenmp -std=c99
CXXFLAGS=-O2 -fopenmp
EXECS= mathomp primecheckerTester
# This Makefile is for testing the executables of all the functions of this library!

all: $(EXECS)

primecheckerTester: primecheckerTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

clean:
	rm -f $(EXECS) *.o
CC=gcc
CXX=g++
CFLAGS=-O2 -fopenmp -std=c99
CXXFLAGS=-O2 -fopenmp
EXECS= TesterPrograms/primecheckerTester TesterPrograms/sinusCalcTester TesterPrograms/ArrayTester
# This Makefile is for testing the executables of all the functions of this library!

all: $(EXECS)

TesterPrograms/primecheckerTester: TesterPrograms/primecheckerTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

TesterPrograms/sinusCalcTester: TesterPrograms/sinusCalcTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

TesterPrograms/ArrayTester: TesterPrograms/ArrayTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

clean:
	rm -f $(EXECS) *.o
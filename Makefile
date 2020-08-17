CC=gcc
CXX=g++
CFLAGS=-O2 -fopenmp -std=c99
CXXFLAGS=-O2 -fopenmp
EXECS= bin/primecheckerTester bin/sinusCalcTester bin/ArrayTester bin/BenchmarkTester
# This Makefile is for testing the executables of all the functions of this library!

all: $(EXECS)

bin/primecheckerTester: TesterPrograms/primecheckerTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

bin/sinusCalcTester: TesterPrograms/sinusCalcTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

bin/ArrayTester: TesterPrograms/ArrayTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

bin/BenchmarkTester: TesterPrograms/benchmarkTester.cpp
	$(CXX) -o $@ $< mathomp.cpp $(CXXFLAGS)

clean:
	rm -f $(EXECS) *.o
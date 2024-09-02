###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Scott Fullenbaum

MAKEFLAGS += -L #Do not delete

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

DatumStack.o: DatumStack.cpp DatumStack.h
	${CXX} ${CXXFLAGS} -c DatumStack.cpp

#RPNCalc.o rule
RPNCalc.o: RPNCalc.cpp RPNCalc.h
	${CXX} ${CXXFLAGS} -c RPNCalc.cpp

#testing_main.o rule
testing_main.o: testing_main.cpp
	${CXX} ${CXXFLAGS} -c testing_main.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

#creates testing_main executable
testing_main: RPNCalc.o DatumStack.o testing_main.o Datum.o
	${CXX} ${LDFLAGS} -o testing_main testing_main.o RPNCalc.o DatumStack.o \
						Datum.o

CalcYouLater: RPNCalc.o DatumStack.o main.o Datum.o
	${CXX} ${LDFLAGS} -o CalcYouLater main.o RPNCalc.o DatumStack.o Datum.o

provide:
	provide comp15 proj2_calcyoulater DatumStack.h \
						DatumStack.cpp README \
						testing_main.cpp RPNCalc.cpp RPNCalc.h \
						Makefile  main.cpp unit_tests.h

##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^

clean: 
	rm DatumStack.o parser.o Datum.o
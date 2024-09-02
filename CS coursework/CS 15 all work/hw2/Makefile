###########################################################################
##                    Makefile for HW2 (CharLinkedList)                   ##
###########################################################################

CXX      = clang++
CXXFLAGS = -c -g3 -std=c++11 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3

unit_test: unit_test_driver.o CharLinkedList.o 
	${CXX} ${LDFLAGS} unit_test_driver.o CharLinkedList.o

CharLinkedList.o: CharLinkedList.cpp CharLinkedList.h
	${CXX} ${CXXFLAGS} CharLinkedList.cpp

clean:
	@rm -rf *.o *~
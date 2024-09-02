#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

#Builds metrosim proggram
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o station.o
	${CXX} ${LDFLAGS} -o MetroSim MetroSim.o PassengerQueue.o Passenger.o \
						 station.o main.o
	

#This rule builds main.o
main.o: main.cpp MetroSim.o
	${CXX} ${CXXFLAGS} -c main.cpp


#This rule builds MetroSim.o
MetroSim.o: MetroSim.cpp MetroSim.h
	${CXX} ${CXXFLAGS} -c MetroSim.cpp

#This rule builds Station.o
station.o: station.cpp station.h
	${CXX} ${CXXFLAGS} -c station.cpp

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	${CXX} ${CXXFLAGS} -c PassengerQueue.cpp


#This rule builds testing main
testing_main: MetroSim.o PassengerQueue.o Passenger.o station.o 
	${CXX} ${CXXFLAGS} -o test testing_main.cpp MetroSim.o PassengerQueue.o \
						Passenger.o station.o 



# The below rule will be used by unit_test.
# Please add any other .o files that are needed by PassengerQueue,
# and any other .o files you wish to test. 
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o
	$(CXX) $(CXXFLAGS) $^



# This rule provides your final submission 
# NOTE: Don't forget to add any additional files you want to submit to this
#		rule! If you do not add them, they will not be submitted.
provide:
	provide comp15 proj1_MetroSim PassengerQueue.h \
				    PassengerQueue.cpp \
				    Passenger.h Passenger.cpp  \
					station.h station.cpp \
					MetroSim.h MetroSim.cpp \
					testing_main.cpp main.cpp \
					test_commands.txt mytest.txt \
					medium_stations.txt small_stations.txt \
					unit_tests.h Makefile README 

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out

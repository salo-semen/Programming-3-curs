CXX = g++
FLAGS = -std=c++20 -Iinclude
SOURCES =	src/1.cpp \
		  	src/Date.cpp \
		  	src/Realty.cpp \
		 	src/Apartment.cpp \
		   	src/VillageHouse.cpp

all:
	$(CXX) $(FLAGS) $(SOURCES)

clean:
	rm -rf a.out

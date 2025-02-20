CXX = g++
FLAGS = -std=c++20
SOURCES = 1.cpp Date.cpp Realty.cpp Apartment.cpp VillageHouse.cpp

all:
	$(CXX) $(FLAGS) $(SOURCES)

clean:
	rm -rf a.out

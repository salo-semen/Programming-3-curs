CXX = g++
FLAGS = -std=c++20 -Iinclude -I/opt/homebrew/Cellar/qt/6.8.2_1/lib/QtWidgets.framework/Headers -I/opt/homebrew/Cellar/qt/6.8.2_1/lib/QtCore.framework/Headers
QT_FLAGS =  -F/opt/homebrew/Cellar/qt/6.8.2_1/lib -framework QtWidgets -framework QtCore
SOURCES = src/main.cpp \
          src/Date.cpp \
          src/Realty.cpp \
          src/Apartment.cpp \
          src/VillageHouse.cpp \
          src/Realization.cpp

all:
	$(CXX) $(FLAGS) $(QT_FLAGS) $(SOURCES)

start:
	./a.out

clean:
	rm -rf a.out
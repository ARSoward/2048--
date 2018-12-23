CXX = g++
CXXFLAGS = -Wall -g

2048: 2048.o tile.o board.o
	$(CXX) $(CXXFLAGS) -o 2048 2048.o tile.o board.o

2048.o: board.h tile.h

tile.o: tile.h

board.o: board.h tile.h


MazeProblem.exe: maze.o main.o
	g++ maze.o main.o -static -o MazeProblem.exe

maze.o: maze.cpp maze.h
	g++ maze.cpp -static -c

main.o: main.cpp maze.h
	g++ main.cpp -static -c
build:
	g++ -std=c++11 Cube.cpp Wall.cpp maze-rs.cpp  -o maze

run:
	./maze

clean:
	rm maze

CFLAGS = -std=c++11
CC = g++
vertex.o: Vertex.h Vertex.cpp
	$(CC) -c Vertex.cpp $(CFLAGS)
ray.o: Ray.h Ray.cpp
	$(CC) -c Ray.cpp $(CFLAGS)
intersection.o: Intersection.h Intersection.cpp
	$(CC) -c Intersection.cpp $(CFLAGS)
StraightSkeleton.o: StraightSkeleton.h StraightSkeleton.cpp
	$(CC) -c StraightSkeleton.cpp $(CFLAGS)
CLL.o: CLL.h CLL.cpp
	$(CC) -c CLL.cpp $(CFLAGS)
CLLNode.o: CLLNode.h CLLNode.cpp
	$(CC) -c CLLNode.cpp $(CFLAGS)

test: vertex.o ray.o intersection.o StraightSkeleton.o CLLNode.o CLL.o
	$(CC)  Vertex.o Ray.o Intersection.o StraightSkeleton.o CLLNode.o CLL.o test.cpp $(CFLAGS)






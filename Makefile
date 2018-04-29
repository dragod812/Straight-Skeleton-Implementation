LIBS = -std=c++11 -lglfw -lGL -ldl -lX11 -lpthread -lXrandr -std=c++11 -lGLU -w
CC = g++
CFLAGS = -Wall -Iinclude
GLADH = include/glad.h
GLADC = include/glad.c
GLAD = glad.o $(GLADH)
shader = include/shader.h
StraightSkeleton = Vertex.o Ray.o Intersection.o StraightSkeleton.o CLLNode.o CLL.o
i = include/

Vertex.o: $(i)Vertex.h $(i)Vertex.cpp
	$(CC) -c $(i)Vertex.cpp $(CFLAGS)
Ray.o: $(i)Ray.h $(i)Ray.cpp
	$(CC) -c $(i)Ray.cpp $(CFLAGS)
Intersection.o: $(i)Intersection.h $(i)Intersection.cpp
	$(CC) -c $(i)Intersection.cpp $(CFLAGS)
StraightSkeleton.o: $(i)StraightSkeleton.h $(i)StraightSkeleton.cpp
	$(CC) -c $(i)StraightSkeleton.cpp $(CFLAGS)
CLL.o: $(i)CLL.h $(i)CLL.cpp
	$(CC) -c $(i)CLL.cpp $(CFLAGS)
CLLNode.o: $(i)CLLNode.h $(i)CLLNode.cpp
	$(CC) -c $(i)CLLNode.cpp $(CFLAGS)



main: $(StraightSkeleton) main.cpp $(medianh) $(convexhull) $(point) $(GLAD) $(shader)
	g++ $(StraightSkeleton) main.cpp $(GLAD) $(LIBS) $(CFLAGS)
glad.o: $(GLADH)
	g++ -c $(GLADC)



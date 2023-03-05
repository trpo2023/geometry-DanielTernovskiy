all: HelloWorld

HelloWorld: HelloWorld.c
	gcc -Wall -Werror -o HelloWorld HelloWorld.c

clean:
	rm HelloWorld

run:
	./HelloWorld

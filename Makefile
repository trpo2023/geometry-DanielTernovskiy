all: HelloWorld

HelloWorld: HelloWorld.c
	gсс -Wall -Werror -o HelloWorld HelloWorld.c

clean:
	rm HelloWorld

run:
	./myprog

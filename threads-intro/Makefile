
FLAGS = -Wall -pthread
INCLUDES = ../include

all: t0 t0b t1

clean:
	rm -f t0 t1

t0: t0.c
	gcc -I $(INCLUDES) -o t0 t0.c $(FLAGS)

t0b: t0b.c
	gcc -I $(INCLUDES) -o t0b t0b.c $(FLAGS)

t1: t1.c
	gcc -I $(INCLUDES) -o t1 t1.c $(FLAGS)

OBJS	= main.o parser.o xover.o mutation.o chromosome.o gene.o population.o linked_list.o
SOURCE	= main.c FileIO/parser.c Operations/xover.c Operations/mutation.c Genetic_Hierarchical_Structures/chromosome.c Genetic_Hierarchical_Structures/gene.c Genetic_Hierarchical_Structures/population.c Utils/linked_list.c
HEADER	= FileIO/parser.h Operations/xover.h Operations/mutation.h Genetic_Hierarchical_Structures/chromosome.h Genetic_Hierarchical_Structures/gene.h Genetic_Hierarchical_Structures/population.h Utils/linked_list.h
OUT	= GA
CC	 = gcc
FLAGS	 = -g -c -Wall -std=gnu11
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

parser.o: FileIO/parser.c
	$(CC) $(FLAGS) FileIO/parser.c 

xover.o: Operations/xover.c
	$(CC) $(FLAGS) Operations/xover.c 

mutation.o: Operations/mutation.c
	$(CC) $(FLAGS) Operations/mutation.c 

chromosome.o: Genetic_Hierarchical_Structures/chromosome.c
	$(CC) $(FLAGS) Genetic_Hierarchical_Structures/chromosome.c

gene.o: Genetic_Hierarchical_Structures/gene.c
	$(CC) $(FLAGS) Genetic_Hierarchical_Structures/gene.c

population.o: Genetic_Hierarchical_Structures/population.c
	$(CC) $(FLAGS) Genetic_Hierarchical_Structures/population.c

linked_list.o: Utils/linked_list.c
	$(CC) $(FLAGS) Utils/linked_list.c 

clean:
	rm -f $(OBJS) $(OUT)
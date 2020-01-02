//
// Created by x1 doa on 25.12.2019.
//
#ifndef ASSIGNMENT3_POPULATION_H
#define ASSIGNMENT3_POPULATION_H
#include "chromosome.h"
#include <stdio.h>
typedef struct{
    NodePointer first_chromosome_node_ptr;
    NodePointer last_chromosome_node_ptr;
    int generation;
    Chromosome* best_chromosome;
}Population;

Population *new_population();


void change_best_chromosome_if_exist_better_one(Population *population);

void order_population(Population *population);

void printf_population(Population *population_ptr);
#endif //ASSIGNMENT3_POPULATION_H

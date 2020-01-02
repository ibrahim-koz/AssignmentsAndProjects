//
// Created by x1 doa on 25.12.2019.
//

#ifndef ASSIGNMENT3_GEN_H
#define ASSIGNMENT3_GEN_H
#include <stdbool.h>
#include "../Utils/linked_list.h"

typedef struct{
    int var;
    int digit;
    int fitness;
} Gene;

Gene *gene_constructor(int var, int digit);

void refresh_fitness(Gene *gene_ptr);
#endif //ASSIGNMENT3_GEN_H

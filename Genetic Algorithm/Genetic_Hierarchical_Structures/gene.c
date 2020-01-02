//
// Created by x1 doa on 25.12.2019.
//


#include <stdlib.h>
#include "gene.h"
#include <math.h>

Gene *gene_constructor(int var, int digit) {
    Gene *new_gen = malloc(sizeof(Gene));
    new_gen->var = var;
    new_gen->digit = digit;
    new_gen->fitness = var * pow(2, digit);
    return new_gen;
}

void refresh_fitness(Gene *gene_ptr) {
    gene_ptr->fitness = gene_ptr->var * pow(2, gene_ptr->digit);
}






//
// Created by x1 doa on 25.12.2019.
//
#include "gene.h"

#ifndef ASSIGNMENT3_CHROMOSOME_H
#define ASSIGNMENT3_CHROMOSOME_H

typedef struct {
    NodePointer first_gene;
    NodePointer last_gene;
    int total_fitness;
    float rank;
} Chromosome;

Chromosome *chromosome_constructor(NodePointer first_gene, NodePointer last_gene);

bool chromosome_compare(pVoid first_chromosome_node_ptr, pVoid second_chromosome_node_ptr);

void total_fitness(Chromosome *chromosome);



#endif //ASSIGNMENT3_CHROMOSOME_H

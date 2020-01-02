//
// Created by x1 doa on 25.12.2019.
//

#include "chromosome.h"
#include <stdio.h>
#include <stdlib.h>

Chromosome *chromosome_constructor(NodePointer first_gene, NodePointer last_gene) {
    Chromosome *new_chromosome_pt = malloc(sizeof(Chromosome));
    new_chromosome_pt->first_gene = first_gene;
    new_chromosome_pt->last_gene = last_gene;
    new_chromosome_pt->total_fitness = 0;
    new_chromosome_pt->rank = -1;
    return new_chromosome_pt;
}

bool chromosome_compare(pVoid first_chromosome_node_ptr, pVoid second_chromosome_node_ptr) {
    bool key = false;
    if (((Chromosome *) ((NodePointer) first_chromosome_node_ptr)->iData)->total_fitness <=
        ((Chromosome *) ((NodePointer) second_chromosome_node_ptr)->iData)->total_fitness)
        key = true;
    return key;
}

void total_fitness(Chromosome *chromosome) {
    NodePointer temp = chromosome->first_gene;
    chromosome->total_fitness = 0;
    while (temp != NULL){
        refresh_fitness(((Gene *) temp->iData));
        chromosome->total_fitness += ((Gene *) temp->iData)->fitness;
        int x = ((Gene *) temp->iData)->var;
        temp = temp->pNextNode;
    }
}

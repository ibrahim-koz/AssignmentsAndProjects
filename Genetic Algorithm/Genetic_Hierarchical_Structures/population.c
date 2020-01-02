//
// Created by x1 doa on 25.12.2019.
//

#include <stdio.h>
#include "population.h"
#include <limits.h>
Population *new_population(){
    Population *new_population = malloc(sizeof(Population));
    new_population->first_chromosome_node_ptr = NULL;
    new_population->last_chromosome_node_ptr = NULL;
    new_population->generation = 0;
    new_population->best_chromosome = malloc(sizeof(Chromosome));
    new_population->best_chromosome->total_fitness = INT_MAX;
    return new_population;
}

void change_best_chromosome_if_exist_better_one(Population *population_ptr){
    if (((Chromosome *)population_ptr->first_chromosome_node_ptr->iData)->total_fitness < (population_ptr->best_chromosome->total_fitness) ){
        NodePointer first_gene = NULL;
        NodePointer last_gene = NULL;
        NodePointer temp_gen_ptr = ((Chromosome *)(population_ptr->first_chromosome_node_ptr->iData))->first_gene;
        while (temp_gen_ptr != NULL) {
            Gene *new_gen_ptr = gene_constructor(((Gene *)temp_gen_ptr->iData)->var, ((Gene *)temp_gen_ptr->iData)->digit);
            append_node(&first_gene, &last_gene, new_gen_ptr, sizeof(Gene));
            temp_gen_ptr = temp_gen_ptr->pNextNode;
        }
        population_ptr->best_chromosome = chromosome_constructor(first_gene, last_gene);
        population_ptr->best_chromosome->total_fitness = ((Chromosome *)population_ptr->first_chromosome_node_ptr->iData)->total_fitness;
    }

}

void order_population(Population *population_ptr) {
    NodePointer temp_chr_ptr = population_ptr->first_chromosome_node_ptr;
    while (temp_chr_ptr != NULL) {
        total_fitness(((Chromosome *) (temp_chr_ptr->iData)));
        temp_chr_ptr = temp_chr_ptr->pNextNode;
    }
    MergeSort(&(population_ptr->first_chromosome_node_ptr), chromosome_compare);
    change_best_chromosome_if_exist_better_one(population_ptr);
}

void printf_population(Population *population_ptr) {
    printf("GENERATION: %d\n", population_ptr->generation);
    NodePointer temp_chr_ptr = population_ptr->first_chromosome_node_ptr;
    while (temp_chr_ptr != NULL) {
        NodePointer temp_gen_ptr = ((Chromosome*)(temp_chr_ptr->iData))->first_gene;
        printf("%d", ((Gene *)(temp_gen_ptr->iData))->var);
        temp_gen_ptr = temp_gen_ptr->pNextNode;
        while (temp_gen_ptr != NULL) {
            printf(":%d", ((Gene *)(temp_gen_ptr->iData))->var);
            temp_gen_ptr = temp_gen_ptr->pNextNode;
        }
        int x = ((Chromosome*)(temp_chr_ptr->iData))->total_fitness;
        printf(" -> %d\n", ((Chromosome*)(temp_chr_ptr->iData))->total_fitness);
        temp_chr_ptr = temp_chr_ptr->pNextNode;
    }
    printf("Best chromosome found so far: ");
    NodePointer temp_gen_ptr = population_ptr->best_chromosome->first_gene;
    printf("%d", ((Gene *)(temp_gen_ptr->iData))->var);
    temp_gen_ptr = temp_gen_ptr->pNextNode;
    while (temp_gen_ptr != NULL) {
        printf(":%d", ((Gene *)(temp_gen_ptr->iData))->var);
        temp_gen_ptr = temp_gen_ptr->pNextNode;
    }
    printf(" -> %d\n", population_ptr->best_chromosome->total_fitness);
}

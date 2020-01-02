//
// Created by x1 doa on 25.12.2019.
//

#ifndef ASSIGNMENT3_XOVER_H
#define ASSIGNMENT3_XOVER_H

#include "../Utils/linked_list.h"
#include "../Genetic_Hierarchical_Structures/chromosome.h"
#include "../Genetic_Hierarchical_Structures/population.h"
#include "../FileIO/parser.h"

void xover_chromosomes(Population *population_ptr, ParsedLine *pairs_of_chromosome, int start, int stop);

#endif //ASSIGNMENT3_XOVER_H

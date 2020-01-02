//
// Created by x1 doa on 25.12.2019.
//

#include "xover.h"



void xover_chromosomes(Population *population_ptr, ParsedLine *pairs_of_chromosome, int start, int stop) {
    NodePointer first_chromosome_node_ptr;
    NodePointer second_chromosome_node_ptr;

    int swap_term;
    NodePointer first_temp_gen_ptr;
    NodePointer second_temp_gen_ptr;
    for (int i = 0; i < (pairs_of_chromosome->token_size / 2); i++) {
        first_chromosome_node_ptr = return_node_pointer(population_ptr->first_chromosome_node_ptr, pairs_of_chromosome->tokens[2 * i] - 1);
        second_chromosome_node_ptr = return_node_pointer(population_ptr->first_chromosome_node_ptr, pairs_of_chromosome->tokens[2 * i +  1] - 1);

        first_temp_gen_ptr = return_node_pointer(((Chromosome *)(first_chromosome_node_ptr->iData))->first_gene,  start);
        second_temp_gen_ptr = return_node_pointer(((Chromosome *)(second_chromosome_node_ptr->iData))->first_gene, start);
        for (int j = 0; j < stop - start + 1; j++) {
            pVoid temp = first_temp_gen_ptr->iData;
            first_temp_gen_ptr->iData = second_temp_gen_ptr->iData;
            second_temp_gen_ptr->iData = temp;
            first_temp_gen_ptr = first_temp_gen_ptr->pNextNode;
            second_temp_gen_ptr = second_temp_gen_ptr->pNextNode;
        }
    }
    return;
}



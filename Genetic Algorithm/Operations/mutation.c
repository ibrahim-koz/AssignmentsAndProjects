//
// Created by x1 doa on 25.12.2019.
//

#include "mutation.h"

void mutate_population(Population *population_ptr, int place) {
    NodePointer temp_chr_ptr = population_ptr->first_chromosome_node_ptr;
    while (temp_chr_ptr != NULL){
        NodePointer temp_gen_ptr = return_node_pointer(((Chromosome *)(temp_chr_ptr->iData))->first_gene, place);
        ((Gene *)(temp_gen_ptr->iData))->var = !(((Gene *)(temp_gen_ptr->iData))->var);
        temp_chr_ptr = temp_chr_ptr->pNextNode;
    }
    return;
}

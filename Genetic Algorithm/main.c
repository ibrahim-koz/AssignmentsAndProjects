#include <stdio.h>
#include <stdlib.h>
#include "FileIO/parser.h"
#include "Operations/xover.h"
#include "Operations/mutation.h"
#include "Genetic_Hierarchical_Structures/population.h"


int main(int argc, char *argv[]) {

    //All input files read via parser.h. Parser.h provides me reading denoted file line by line and then parse it easily.

    ParsedLines *population_file = parse_lines();
    population_file->read_and_parse_lines(population_file, "population", ":");

    ParsedLines *selection_file = parse_lines();
    selection_file->read_and_parse_lines(selection_file, "selection", " :");

    ParsedLines *xover_file = parse_lines();
    xover_file->read_and_parse_lines(xover_file, "xover", ":");

    ParsedLines *mutate_file = parse_lines();
    mutate_file->read_and_parse_lines(mutate_file, "mutate", "");

    Population *population_ptr = new_population();

    for (int i = 0; i < population_file->parsed_line_number; i++) {
        NodePointer first_gene = NULL;
        NodePointer last_gene = NULL;
        int token_size = (population_file->parsed_lines_ + i)->token_size;
        for (int j = 0; j < token_size; j++) {
            Gene *new_gen_ptr = gene_constructor((population_file->parsed_lines_ + i)->tokens[j], token_size - 1 - j);
            append_node(&first_gene, &last_gene, new_gen_ptr, sizeof(Gene));
        }
        Chromosome *new_chromosome_ptr = chromosome_constructor(first_gene, last_gene);
        append_node(&(population_ptr->first_chromosome_node_ptr), &(population_ptr->last_chromosome_node_ptr),
                    new_chromosome_ptr, sizeof(Chromosome));
    }


    order_population(population_ptr);
    printf_population(population_ptr);

    for (int i = 0; i < selection_file->parsed_line_number; i++) {
        //işlemler soldan sağa, sağdan sola olacak şekilde düzelt.


        xover_chromosomes(population_ptr, selection_file->parsed_lines_ + i,
                          (xover_file->parsed_lines_ + i)->tokens[0] - 1,
                          (xover_file->parsed_lines_ + i)->tokens[1] - 1);

        mutate_population(population_ptr, (mutate_file->parsed_lines_ + i)->tokens[0] - 1);
        population_ptr->generation += 1;
        order_population(population_ptr);
        printf_population(population_ptr);
    }

    return 0;

}

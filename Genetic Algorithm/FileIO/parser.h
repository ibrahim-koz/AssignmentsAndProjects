//
// Created by x1 doa on 24.12.2019.
//

#ifndef ASSIGNMENT3_PARSER_H
#define ASSIGNMENT3_PARSER_H
#include <stdbool.h>

typedef struct
{
    int *tokens;
    int token_size;
}ParsedLine;

struct ParsedLines_Structure{
    ParsedLine *parsed_lines_;
    int parsed_line_number;
    void (*read_and_parse_lines)(struct ParsedLines_Structure *self, char *file_name, char *delimiter);
};

typedef struct ParsedLines_Structure ParsedLines;

ParsedLine parse_line(char *line, char *delimiter);

void read_and_parse_lines(ParsedLines *self, char *file_name, char *delimiter);

ParsedLines *parse_lines();

#endif //ASSIGNMENT3_PARSER_H

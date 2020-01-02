//
// Created by x1 doa on 24.12.2019.
//

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
ParsedLine parse_line(char *line, char *delimiter)
{
    ParsedLine parsed_line = {malloc(sizeof(int)), 0};
    char *token;
    /* get the first token */
    token = strtok(line, delimiter);

    /* walk through other tokens and the tokens*/
    while (token != NULL)
    {
        parsed_line.token_size++;
        parsed_line.tokens = realloc(parsed_line.tokens, sizeof(int) * parsed_line.token_size);
        parsed_line.tokens[parsed_line.token_size - 1] = atoi(token);
        token = strtok(NULL, delimiter);
    }
    return parsed_line;
}

void read_and_parse_lines(ParsedLines *parsed_lines, char *file_name, char *delimiter)
{
    //Read the data and parsing it.
    ParsedLine parsed_line;
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_name, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (strcmp(line, "\r\n") == 0 || strcmp(line, "") == 0)
            continue;
        (parsed_lines->parsed_line_number)++;
        parsed_lines->parsed_lines_ = realloc(parsed_lines->parsed_lines_, sizeof(ParsedLine) * parsed_lines->parsed_line_number);
        line[strcspn(line, "\r\n")] = '\0';
        parsed_line = parse_line(line, delimiter);
        parsed_lines->parsed_lines_[parsed_lines->parsed_line_number -1] = parsed_line;
    }
    fclose(fp);
    if (line)
        free(line);
}

ParsedLines *parse_lines(){
    ParsedLines *self = malloc(sizeof(ParsedLines));
    self->parsed_line_number = 0;
    self->parsed_lines_ = malloc(sizeof(ParsedLine));
    self->read_and_parse_lines = &read_and_parse_lines;
    return self;
}




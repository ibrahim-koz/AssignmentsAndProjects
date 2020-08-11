#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#define _GNU_SOURCE

struct Matrix
{
    int **rows;
    int row_size;
};

struct Row
{
    char **tokens;
    int token_size;
};

void fill_row(struct Row *row, struct Matrix *matrix)
{
    (*matrix).row_size++;
    (*matrix).rows = realloc((*matrix).rows, sizeof(int *) * ((*matrix).row_size));
    *((*matrix).rows + (*matrix).row_size - 1) = malloc(sizeof(int) * (*row).token_size);

    for (int i = 0; i < (*row).token_size; i++)
    {
        (*matrix).rows[(*matrix).row_size - 1][i] = atoi((*row).tokens[i]);
    }
}

struct Row split_line(char *line, char *delimiter)
{
    struct Row row = {malloc(sizeof(char *)), 0};
    char *token;
    /* get the first token */
    token = strtok(line, delimiter);

    /* walk through other tokens and the tokens*/
    while (token != NULL)
    {
        row.token_size++;
        row.tokens = realloc(row.tokens, sizeof(char *) * row.token_size);
        row.tokens[row.token_size - 1] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(row.tokens[row.token_size - 1], token);
        token = strtok(NULL, delimiter);
    }
    return row;
}

void free_matrix(struct Matrix *matrix)
{
    for (int i = 0; i < (*matrix).row_size; i++)
    {
        free(*((*matrix).rows + i));
    }
    free((*matrix).rows);
}
struct Matrix read_file(char *file_name)
{
    //Read the data and parceing it.
    FILE *fp;
    struct Matrix matrix = {(int **)malloc(sizeof(int *)), 0};
    char *line = NULL;
    struct Row row;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_name, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        line[strcspn(line, "\n")] = '\0';
        row = split_line(line, " ");
        fill_row(&row, &matrix);
        for (int i = 0; i < row.token_size; i++)
        {
            free(row.tokens[i]);
        }
        free(row.tokens);
    }
    fclose(fp);
    if (line)
        free(line);
    return matrix;
}

int multiply_matrices(struct Matrix mapmatrix, struct Matrix keymatrix, int start_coords[2])
{
    int sum = 0;
    int row_start = start_coords[0];
    int col_start = start_coords[1];
    // key matrix is a square matrix so we needn't the info of column size of key matrix.
    for (int i = 0; i < keymatrix.row_size; i++)
    {
        for (int j = 0; j < keymatrix.row_size; j++)
        {
            printf("%d ", mapmatrix.rows[row_start + i][col_start + j]);
            sum += mapmatrix.rows[row_start + i][col_start + j] * keymatrix.rows[i][j];
        }
        printf("\n");
    }
    printf("sum: %d\n", sum);
    return sum;
}

int main(int argc, char *argv[])
{
    //size of map matrix
    int size_of_map[2];
    char *str = argv[1];
    size_of_map[0] = atoi(strtok(str, "x"));
    size_of_map[1] = atoi(strtok(NULL, ""));

    //size of key matrix
    int size_of_key = atoi(argv[2]);

    //read -> mapmatrix.txt

    struct Matrix mapmatrix = read_file("mapmatrix.txt");

    //read -> keymatrix.txt

    struct Matrix keymatrix = read_file("keymatrix.txt");

    //game

    int start_coords[2] = {0, 0};
    int product;
    int row_bound = (size_of_map[0] - 1) - size_of_key + 1;
    int col_bound = (size_of_map[1] - 1) - size_of_key + 1;
    bool is_continued = true;
    char c;
    while (is_continued)
    {
        product = multiply_matrices(mapmatrix, keymatrix, start_coords);

        int remainder = product % 5;

        switch (remainder)
        {
        // Found treasure
        case 0:
            printf("Game over. Congratulations you've found the treasure successfully.\n");
            is_continued = false;
            break;
        // Go up
        case 1:
            if (start_coords[0] - 3 >= 0)
                start_coords[0]-=3;
            else{
                printf("Opposite ");
                start_coords[0]+=3;
            }

            printf("Key will be moved to towards the upper direction.\n");
            break;
        // Go down
        case 2:
            if (start_coords[0] + 3 <= row_bound)
                start_coords[0]+=3;
            else{
                printf("Opposite ");
                start_coords[0]-= 3;
            }

            printf("Key will be moved to towards the downside direction.\n");
            break;
        // Go right
        case 3:
            if (start_coords[1] + 3 <= col_bound)
                start_coords[1]+=3;
            else{
                printf("Opposite ");
                start_coords[1]-= 3;
            }
            printf("Key will be moved to towards the right direction.\n");
            break;
        // Go left
        case 4:
            if (start_coords[1] - 1 >= 0)
                start_coords[1]-=3;
            else{
                printf("Opposite ");
                start_coords[1]+=3;
            }
            printf("Key will be moved to towards the left direction.\n");
            break;
        }
    }

    //free mapmatrix

    free_matrix(&mapmatrix);

    //free key matrix

    free_matrix(&keymatrix);

    printf("this is a change");

    return 0;
}

//matrisin column sayısını da programa dinamik olarak ekle daha sonra.

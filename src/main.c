#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "../include/lexer.h"

#define INPUT_SIZE 1024

int main(void)
{
    printf("====================================\n");
    printf("        Shellforge - Milestone 2\n");
    printf("      Tokenizer + Lexer Enabled\n");
    printf("====================================\n");

    while (1)
    {
        char *input = readline("shellforge$ ");

        if (input == NULL)
        {
            printf("\nExiting Shellforge...\n");
            break;
        }

        /* Ignore empty input */
        if (strlen(input) == 0)
        {
            free(input);
            continue;
        }

        /* Exit command */
        if (strcmp(input, "exit") == 0)
        {
            free(input);
            break;
        }

        /* Store command in history */
        add_history(input);

        token_list_t list;

        if (lexer(input, &list) == 0)
        {
            token_print(&list);
        }

        free(input);
    }

    return 0;
}

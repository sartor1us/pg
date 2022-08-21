#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    char *Lowercase_Letters = "abcdefghijklmnopqrstuvwxyz";
    char *Uppercase_Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *Digits = "0123456789";
    char *Punctuation = "!#$&'()*+,-./:;<=>?@[]^_`{|}~";
    char Symbols[91];
    int Password_Length, Argument;

    if(argc <= 1)
    {
        printf("ERROR: no arguments given. Execute pg -h for arguments list.\n");
        return EXIT_FAILURE;
    }

    while((Argument = getopt(argc, argv, "s:ludph")) != -1)
    {
        switch(Argument)
        {
            case 's':
            {
                Password_Length = atoi(optarg);
                break;
            }
            case 'l':
            {
                strcat(Symbols, Lowercase_Letters);
                break;
            }
            case 'u':
            {
                strcat(Symbols, Uppercase_Letters);
                break;
            }
            case 'd':
            {
                strcat(Symbols, Digits);
                break;
            }
            case 'p':
            {
                strcat(Symbols, Punctuation);
                break;
            }
            case 'h':
            {
                printf("pg -- password generator\nUsage: pg -s <PASSWORD SIZE> <EXTRA ARGUMENTS>\n\n"
                "Arguments:\n-h -- show this information\n-s -- password size (required argument)\n"
                "-l -- include lowercase letters in password\n-u -- include uppercase letters\n"
                "-d -- include digits\n-p -- include punctuation\n");
                return EXIT_SUCCESS;
            }
        }
    }
    
    if(Password_Length <= 0)
    {
        printf("ERROR: invalid password length. Execute pg -h for help.\n");
        return EXIT_FAILURE;
    }
    if(strlen(Symbols) != 0)
    {
        for(; Password_Length != 0; --Password_Length)
        {
            int n = rand() % strlen(Symbols);
            printf("%c", Symbols[n]);
        }
    }
    else
    {
        printf("ERROR: no symbols for password defined. Execute pg -h for help.\n");
        return EXIT_FAILURE;
    }
    printf("\n");
    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <time.h>
#include "Task.c"
#include "ipop.c"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide a number as an argument.\n");
        return 1;
    }

    char *endptr;
    long int number = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0')
    {
        printf("Invalid input: %s is not a number.\n", argv[1]);
        return 1;
    }
    readTodoListFromFile();
    markCompleted(number);
    writeTodoListToFile();
    return 0;
}
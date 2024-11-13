#include <stdio.h>
#include <time.h>
#include "Task.c"
#include "ipop.c"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please provide a task.\n");
        return 1;
    }
    readTodoListFromFile();
    srand(time(NULL));
    int num = rand() * 100 + LENGTH_OF_LINKED_LIST;
    addTask(num, argv[1], 0);
    writeTodoListToFile();
    return 0;
}
#include <stdio.h>
#include "Task.c"
#include "ipop.c"

int main()
{
    readTodoListFromFile();
    Task *tmp = head;
    while (tmp)
    {
        printNode(tmp);
        tmp = tmp->next;
    }
    return 0;
}
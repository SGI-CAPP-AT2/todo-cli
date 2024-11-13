#include <stdio.h>

#ifndef TASK
#include "Task.c"
#endif

#define filename "__SavedTasks.txt"

void writeTodoListToFile()
{
    FILE *fp = fopen(filename, "w+");
    if (fp == NULL)
    {
        printf("File Created !");
        return;
    }

    Task *temp = head;
    while (temp != NULL)
    {
        fprintf(fp, "%d. %s-%d\n", temp->taskNumber, temp->description, temp->isCompleted);
        temp = temp->next;
    }

    fclose(fp);
}
void readTodoListFromFile()
{
    FILE *fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("File Created !");
        return;
    }

    head = NULL;
    Task *ptr = NULL;
    Task *tail = NULL;
    char line[100];

    while (fgets(line, 100, fp) != NULL)
    {
        int taskNumber;
        char description[100];
        int isCompleted;
        sscanf(line, "%d. %[^-]-%d", &taskNumber, description, &isCompleted);
        addTask(taskNumber, description, isCompleted);
    }

    fclose(fp);
}
void printNode(Task *node)
{
    printf("ID: %d ___ \n %s\n -> %s\n__\n", node->taskNumber, node->description, node->isCompleted == 0 ? "PENDING" : "COMPLETED");
}
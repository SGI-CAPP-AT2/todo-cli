#include <stdlib.h>
#include <string.h>
#define TASK
typedef struct _Task
{
    int taskNumber;
    char *description;
    int isCompleted;
    struct _Task *next;
} Task;

Task *head = NULL;
int LENGTH_OF_LINKED_LIST = 0;
Task *createTask(int taskNumber, char *description, int isComplete)
{
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->taskNumber = taskNumber;
    newTask->description = (char *)malloc(strlen(description) + 1);
    strcpy(newTask->description, description);
    newTask->isCompleted = isComplete;
    newTask->next = NULL;
    return newTask;
}

void addTask(int taskNumber, char *description, int isComplete)
{
    Task *newTask = createTask(taskNumber, description, isComplete);
    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        Task *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTask;
    }

    LENGTH_OF_LINKED_LIST++;
}
void markCompleted(int taskNumber)
{
    Task *temp = head;
    while (temp != NULL)
    {
        if (temp->taskNumber == taskNumber)
        {
            temp->isCompleted = 1;
            break;
        }
        temp = temp->next;
    }
}

void deleteTask(int taskNumber)
{
    Task *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->taskNumber == taskNumber)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp->description);
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

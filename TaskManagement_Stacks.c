#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#define MAX_TASKS 100

struct Task {
    char description[100];
    int year;
    int month;
    int day;
    int importance;
};	

struct TaskStack {
    struct Task tasks[MAX_TASKS];
    int top;
};

const char *monthNames[] = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

void initializeStack(struct TaskStack *stack) {
    stack->top = -1;
}

void push(struct TaskStack *stack, struct Task task) {
    if (stack->top < MAX_TASKS - 1) {
        stack->top++;
        strcpy(stack->tasks[stack->top].description, task.description);
        stack->tasks[stack->top].year = task.year;
        stack->tasks[stack->top].month = task.month;
        stack->tasks[stack->top].day = task.day;
        stack->tasks[stack->top].importance = task.importance;
        printf("Task added: %s\n", task.description);
    } else {
        printf("Task stack is full. Cannot add more tasks.\n");
    }
}

void pop(struct TaskStack *stack) {
    if (stack->top >= 0) {
        printf("Task removed: %s\n", stack->tasks[stack->top].description);
        stack->top--;
    } else {
        printf("Task stack is empty. Nothing to remove.\n");
    }
}

bool isValidDate(int year, int month, int day) {
    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

   
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return false;
            }
        } else if (day > 28) {
            return false;
        }
    }

    return true;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayTasks(struct TaskStack stack) {
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i <= stack.top; i++) {
        printf("Task: %s, Date: %s %02d, %04d, Importance: %d\n",
               stack.tasks[i].description, monthNames[stack.tasks[i].month - 1],
               stack.tasks[i].day, stack.tasks[i].year, stack.tasks[i].importance);
    }
}

int main() {
    struct TaskStack tasks;
    initializeStack(&tasks);
    struct Task newTask;

    while (1) {
        printf("\nTask Management Menu:\n");
        printf("1. Add Task\n");
        printf("2. Remove Last Task\n");
        printf("3. View Current Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Task Description: ");
                clearInputBuffer(); 
                scanf(" %99[^\n]", newTask.description);

                
                int year, month, day;
                printf("Enter Task Date (YYYYMMDD): ");
                if (scanf("%4d%2d%2d", &year, &month, &day) != 3 || !isValidDate(year, month, day)) {
                    printf("Invalid date format. Please enter a valid date in YYYYMMDD format.\n");
                    clearInputBuffer(); 
                    continue; 
                }

                newTask.year = year;
                newTask.month = month;
                newTask.day = day;

                printf("Enter Task Importance: ");
                scanf("%d", &newTask.importance);

                push(&tasks, newTask);
                break;
            case 2:
                pop(&tasks);
                break;
            case 3:
                displayTasks(tasks);
                break;
            case 4:
                printf("Exiting the Task Management.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

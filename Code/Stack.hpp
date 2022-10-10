#ifndef STACK_H
#define STACK_H

#include <iostream>

#define MAXTAM 10
#define MAX_DELIVERY 7

typedef struct
{
    int id = 0;
    int products[MAXTAM];
    float price;
    float distance;
    int stacksize;
} Order;

typedef struct
{
    Order Stack[MAX_DELIVERY];
    int Top;
    int Size;
} TStack;

int ordnum = 0;

void CreateEmptyStack(TStack *stack);
bool VerifyEmptyStack(TStack *stack);
bool VerifyFullStack(TStack *stack);
void Push(TStack *stack, Order item);
void PrintStack(TStack *stack, Order item);
void Pop(TStack *stack, Order *item);
Order PopOff(TStack *stack, int item);

#endif
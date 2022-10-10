#include <iostream>
#include "Stack.hpp"

using namespace std;

void CreateEmptyStack(TStack *stack) //Cria uma pilha vazia.
{
    stack->Top = 0;
}

bool VerifyEmptyStack(TStack *stack) //Verifica se a pilha está vazia.
{
    if (stack->Top == 0)
        return true;
    return false;
}

bool VerifyFullStack(TStack *stack) //Verifica se há espaço na pilha.
{
    if (stack->Top == MAXTAM)
        return true;
    return false;
}

void Push(TStack *stack, Order item) //Empilha os itens na pilha.
{
    if (VerifyFullStack(stack))
    {
        cout << "Push error";
        return;
    }
    stack->Stack[stack->Top] = item;
    stack->Top++;
    stack->Size++;
    return;
}

void PrintStack(TStack *stack, Order item) //Imprime todos os itens da pilha.
{
    for (int i = stack->Top - 1; i >= 0; i--)
    {
        cout << "Product ID: " << stack->Stack[i].id << "\n";
        cout << "Product distance: " << stack->Stack[i].distance << "\n";
        cout << "Total Price: " << stack->Stack[i].price << "\n";
        cout << "Products: ";
        for (int j = 0; j < ordnum; j++) 
        {
            cout << stack->Stack[i].products[j] << " ";
        }
        cout << endl
             << endl;
    }
    cout << endl;
}

void Pop(TStack *stack, Order *item) //Desempilha o item no topo da pilha.
{
    stack->Top--;
    *item = stack->Stack[stack->Size];
}

Order PopOff(TStack *stack, int item) //Desempilha algum item específico da pilha.
{
    for(int i = 0; i < stack->Top; i++) 
    {
        if(stack->Stack[i].id == item) {
            Order remv = stack->Stack[i];
            for(int j = i; j < stack->Top; j++) 
            {
                stack->Stack[j] = stack->Stack[j+1];
            }
            stack->Top--;
            return remv;
        }
    }
}

int FindStack(TStack *stack, int id) //Função para encontrar algum item específico na pilha.
{
    for (int i = 0; i < MAXTAM; i++)
    {
        if (stack->Stack[i].id == id)
        {
            cout << "Product ID:\t" << stack->Stack[i].id << "\n";
            cout << "Product distance:\t" << stack->Stack[i].distance << "\n";
            cout << "Total Price:\t" << stack->Stack[i].price << endl;
            cout << "Products: ";
            for (int j = 0; j < MAXTAM; j++)
            {
                cout << stack->Stack[i].products[j] << ", ";
            }
            cout << endl
                 << endl;
        }
        cout << endl;
    }
}
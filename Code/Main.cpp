#include <iostream>
#include <windows.h>
#include <fstream>
#include "Stack.hpp"
#include "Stack.cpp"

using namespace std;

void menu1()
{
    system("cls");
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"; //Menu principal.
    cout << "▓                           ▓\n";
    cout << "▓    MOLLIE'S HAMBURGERS    ▓\n";
    cout << "▓                           ▓\n";
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n";
    cout << "\n1. Add new order\n";
    cout << "2. See all orders\n";
    cout << "3. Find order\n";
    cout << "4. Print delivery list\n";
    cout << "5. Deliver\n";
    cout << "0. Exit\n\n";
}

void menu2()
{
    system("cls");
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"; //Cardápio.
    cout << "▓                           ▓\n";
    cout << "▓    MOLLIE'S HAMBURGERS    ▓\n";
    cout << "▓                           ▓\n";
    cout << "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n";
    cout << "\n1. Tempest Burgers   R$10,00\n";
    cout << "2. Breakfast Burgers   R$12,00\n";
    cout << "3. Storm King Burger   R$15,00\n";
    cout << "4. All-in-one Burger   R$18,00\n";
    cout << "5. Fairy Queen Shake   R$4,00\n";
    cout << "6. Wicked Oni Special  R$20,00\n";
    cout << "0. Return.\n\n";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int choice1, choice2 = 0, yn; //Declarção de variáveis.
    float prices[] = {NULL, 10.0, 12.0, 15.0, 18.0, 4.0, 20.0}; //Preço dos produtos.
    TStack productsS, aux; //Declaração da pilha principal e a pilha auxiliar.
    Order item;
    int idfind, orderid = 0, biggest_distance, size, stacksize;
    CreateEmptyStack(&productsS); //Criação da pilha.
    FILE *file = fopen("restaurant.bin", "r"); //Leitura dos dados no arquivo binário.
    if (file != NULL)
    {
        while (fread(&item, sizeof(Order), 1, file))
        {
            if (item.id > orderid)
            {
                orderid = item.id;
            }
            Push(&productsS, item);
        }
    }

    orderid++;
    do
    {
        menu1();
        cout << "Choose an option:\n";
        cin >> choice1;
        system("cls"); //Usuário escolhe alguma opção do menu principal.
        switch (choice1)
        {
        case 1:
        {
            item.id = orderid;
            item.stacksize = 0;
            do
            {
                system("cls");
                menu2();
                cout << "What do you wish to order?\n\n"; //Escolha do item do cardápio.
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\t";
                    cin >> yn; //Usuário decide se ele quer adicionar mais um item.
                    if (yn != 1) //Se yn não for 1, ele retorna ao menu principal.
                    {
                        break;
                    }
                }
                break;
                case 2:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\t";
                    cin >> yn;
                    if (yn != 1)
                    {
                        break;
                    }
                }
                break;
                case 3:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\t";
                    cin >> yn;
                    if (yn != 1)
                    {
                        break;
                    }
                }
                break;
                case 4:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\n";
                    cin >> yn;
                    if (yn != 1)
                    {
                        break;
                    }
                }
                break;
                case 5:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\n";
                    cin >> yn;
                    if (yn != 1)
                    {
                        break;
                    }
                }
                break;
                case 6:
                {

                    item.products[item.stacksize] = choice2;
                    item.price += prices[choice2];

                    ordnum += 1;

                    cout << "\n\nDo you wish to order something else?(Y=1/N=0)\t";
                    cin >> yn;
                    if (yn != 1)
                    {
                        break;
                    }
                }
                break;
                case 0:
                {
                    break;
                }
                break;
                }
                if (yn != 1)
                {
                    break;
                }
            } while (yn == 1);
            cout << "\nDistance to delivery location (in km):\t";
            cin >> item.distance;
            Push(&productsS, item); //Empilha os itens na pilha.
            orderid = orderid + 1;
        }
        break;
        case 2:
        {
            PrintStack(&productsS, item); //Imprime todos os itens da pilha.
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            cin >> idfind;
            system("cls");
            FindStack(&productsS, idfind); //Imprime algum item específico da pilha.
            system("pause");
        }
        break;
        case 4:
        {
            system("cls");
            if (VerifyEmptyStack(&productsS))
            {
                cout << "Empty delivery bag!\n";
            }
            else
            {
                TStack aux;
                CreateEmptyStack(&aux); //Criação da pilha auxiliar.
                size = productsS.Top;
                for (int i = 0; i < size; i++)
                {
                    Pop(&productsS, &item); //Inserção dos itens da pilha principal na pilha auxiliar.
                    Push(&aux, item);
                }
                size = aux.Top;
                for (int j = 0; j < size; j++)
                {
                    biggest_distance = 0;
                    for (int i = 0; i < aux.Top; i++)
                    {
                        if (biggest_distance < aux.Stack[i].distance) //Organização quanto a distãncia.
                        {
                            biggest_distance = aux.Stack[i].distance;
                            idfind = aux.Stack[i].id;
                        }
                    }
                    Push(&productsS, PopOff(&aux, idfind)); //Inserção dos itens na pilha auxiliar na pilha principal.
                }
                cout << "Delivery bag organized.\n";
            }
            system("pause");
            system("cls");
        }
        break;
        case 5:
        {
            if (VerifyEmptyStack(&productsS))
            {
                cout << "No items to be delivered";
            }
            else
            {
                Pop(&productsS, &item); //Retira e "entrega" o item no topo da pilha.
                cout << "\n\nProduct Delivered.";
            }
        }
        break;
        }
    } while (choice1 != 0);

    file = fopen("restaurant.bin", "w"); //Salva os dados do programa no arquivo binário.
    stacksize = productsS.Size;
    for (int i = 0; i < stacksize; i++)
    {
        Pop(&productsS, &item);
        fwrite(&item, sizeof(Order), 1, file);
    }

    cout << endl;
    return 0;
}
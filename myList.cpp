// myList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "l.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    list* head = NULL;
    generate(head);
    int x;
    int val, id;
    while (true) {
        menu();
        std::cin >> x;
        switch (x) {
        case(1):
        case(2):
            std::cout << "\n" << "Введите значение:" << "\n";
            std::cin >> val;
            push(head, val);
            break;
        case(3):

            show(head);
            break;
        case(4):

            std::cout << "\n" << "Введите новое значение:" << "\n";
            std::cin >> val;
            std::cout << "\n" << "Введите идентификационное значение:" << "\n";
            std::cin >> id;
            addbefore(head, val, id);
            break;
        case(5):
            std::cout << "\n" << "Введите новое значение:" << "\n";
            std::cin >> val;
            std::cout << "\n" << "Введите идентификационное значение:" << "\n";
            std::cin >> id;
            addafter(head, val, id);
            break;
        case(6):
            std::cout << "\n" << "Введите новое значение:" << "\n";
            std::cin >> val;
            tail(head, val);
            break;
        case(7):
            pop(head);
            break;
        case(8):
            poptail(head);
            break;
        case(9):
            std::cout << "\n" << "Введите значение:" << "\n";
            std::cin >> id;
            del(head, id);
            break;
        case(10):
            firstonly(head);
            break;
        case(0):
            return 0;
        }
        _getch();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

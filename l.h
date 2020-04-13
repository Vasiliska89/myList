#include <iostream>
#include <locale>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
struct list {
    int id;
    list* next;
};
void menu();
void push(list*& head, int val);
void show(list* sp);
void addbefore(list*& sp, int val, int id);
void addafter(list*& sp, int val, int id);
void tail(list*& sp, int val);
void pop(list*& sp);
void poptail(list*& sp);
void del(list*& sp, int id);
void firstonly(list*& sp);
void generate(list*& head);

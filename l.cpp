#include "l.h"

void menu() {
    std::cout << "\n";
    std::cout << "1 - ввести первый элемент" << "\n";
    std::cout << "2 - вставить в начало" << "\n";
    std::cout << "3 - вывести список" << "\n";
    std::cout << "4 - вставка до заданного элемента" << "\n";
    std::cout << "5 - вставка после заданного элемента" << "\n";
    std::cout << "6 - вставка в хвост" << "\n";
    std::cout << "7 - удалить первый элемент" << "\n";
    std::cout << "8 - удалить последний элемент" << "\n";
    std::cout << "9 - удалить заданный элемент" << "\n";
    std::cout << "10 - индивидуальное задание - оставить в списке L только первые вхождения одинаковых элементов" << "\n";
    std::cout << "0 - выход" << "\n";
}
void push(list*& head, int val) {
    list* tmp = new list;
    tmp->id = val;
    tmp->next = head;
    head = tmp;
}
void show(list* sp) {
    while (sp != NULL)
    {
        std::cout << sp->id << " ";
        sp = sp->next;
    }
}
void addbefore(list*& sp, int val, int id) {
    if (sp->id == id) push(sp, val);
    else {
        if (sp->next != NULL && sp->next->id == id) {
            list* tmp = new list;
            tmp->id = val;
            tmp->next = sp->next;
            sp->next = tmp;
        }
        else {
            if (sp->next == NULL) std::cout << "\n" << "Данные некорректны." << "\n";
            else addbefore(sp->next, val, id);
        }
    }
}
void addafter(list*& sp, int val, int id) {
    if (sp->id == id) {
        list* tmp = new list;
        tmp->id = val;
        tmp->next = sp->next;
        sp->next = tmp;
    }
    else {
        if (sp->next != NULL) addafter(sp->next, val, id);
        else std::cout << "\n" << "Данные некорректны." << "\n";
    }
}
void tail(list*& sp, int val) {
    if (sp->next == NULL) {
        list* tmp = new list;
        tmp->id = val;
        tmp->next = NULL;
        sp->next = tmp;
    }
    else tail(sp->next, val);
}
void pop(list*& sp) {
    sp = sp->next;
}
void poptail(list*& sp) {
    if (sp->next == NULL) sp = NULL;
    else poptail(sp->next);
}
void del(list*& sp, int id) {
    if (sp->id == id) {
        list* tmp = sp->next;
        free(sp);
        sp = tmp;
    }
    else {
        if (sp->next != NULL && sp->next->id == id) sp->next = sp->next->next;
        else {
            if (sp->next != NULL) del(sp->next, id);
            else std::cout << "\n" << "Данные некорректны." << "\n";
        }
    }
}
void del2(list*& sp, int id) {
    if (sp->next != NULL && sp->next->id == id) {
        list* tmp = sp->next->next;
        free(sp->next);
        sp->next = tmp;
        del2(sp, id);
    }
    else if (sp->next != NULL && sp->next->id != id) del2(sp->next, id);

}
void firstonly(list*& sp) {
    del2(sp, sp->id);
    if (sp->next != NULL)firstonly(sp->next);
}
void generate(list*& head) {
    srand(time(0));
    push(head, rand()%10);
    for (int i = 0; i < 9; i++) {
        tail(head, rand() % 10);
    }
}
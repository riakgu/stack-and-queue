#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define info(Q) (Q).info
#define head(Q) (Q).head
#define tail(Q) (Q).tail
#define info(S) (S).info
#define top(S) (S).top

const int nMax = 10;

struct Customer {
    string nama;
    string phone;
    string tipe;
    string no_polisi;
};

struct Invoice {
    Customer cust;
    int total;
};

struct Queue {
    Customer info[nMax];
    int head;
    int tail;
};

struct Stack {
    Invoice info[nMax];
    int top;
};

void createQueue(Queue &Q);
bool isEmptyQ(Queue Q);
bool isFullQ(Queue Q);
void enQueue(Queue &Q, Customer x);
Customer deQueue(Queue &Q);
void printQueue(Queue Q);

void createStack(Stack &S);
bool isEmptyS(Stack Q);
bool isFullS(Stack Q);
void push(Stack &S, Invoice x);
Invoice pop(Stack &S);
void printStack(Stack S);

void enter();
void intro();
int selectMenu();
void findMax(Stack S);

#endif // TUBES_H_INCLUDED

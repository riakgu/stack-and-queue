#include "tubes.h"

//QUEUE
void createQueue(Queue &Q){
    head(Q) = 0;
    tail(Q) = 0;
}

bool isEmptyQ(Queue Q){
    if (head(Q) == 0  && tail(Q) == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFullQ(Queue Q){
    if (head(Q) == 1  && tail(Q) == nMax) {
        return true;
    } else {
        return false;
    }
}

void enQueue(Queue &Q, Customer x){
    if (isFullQ(Q)){
        cout <<"Antrian penuh!";
    } else if (isEmptyQ(Q)){
        head(Q) = 1;
        tail(Q) = 1;
        info(Q)[tail(Q)] = x;
    } else {
        tail(Q) = tail(Q)+1;
        info(Q)[tail(Q)] = x;
    }
}

Customer deQueue(Queue &Q){
    Customer x;
    x = info(Q)[head(Q)];
    if (head(Q)==tail(Q)){
        createQueue(Q);
    }else{
        head(Q) = head(Q) + 1;
    }
    return x;
}

void printQueue(Queue Q){
    if (isEmptyQ(Q)) {
        cout << "Queue kosong";
    } else {
        for (int i = head(Q); i <= tail(Q); i++) {
            cout << "No_polisi: " << info(Q)[i].no_polisi << endl;
            cout << "Nama: " << info(Q)[i].nama << endl;
            cout << "Phone: " << info(Q)[i].phone << endl;
            cout << "Tipe: " << info(Q)[i].tipe << endl;
            enter();
        }
    }
}

//STACK
void createStack(Stack &S){
    top(S) = 0;
}

bool isEmptyS(Stack S){
    if (top(S) == 0) {
        return true;
    } else {
        return false;
    }
}

bool isFullS(Stack S){
    if (top(S) == nMax) {
        return true;
    } else {
        return false;
    }
}

void push(Stack &S, Invoice x){
    if (isFullS(S)) {
        cout <<"Stack penuh!";
    } else {
        top(S) = top(S) + 1;
        info(S)[top(S)] = x;
    }
}

Invoice pop(Stack &S){
    Invoice x;
    x = info(S)[top(S)];
    top(S) = top(S) - 1;
    return x;
}

void printStack(Stack S){
    if (isEmptyS(S)) {
        cout <<"Stack kosong!";
    } else {
        for (int i = top(S); i >= 1; i--) {
            cout << "Nama: " << info(S)[i].cust.nama << endl;
            cout << "Phone: " << info(S)[i].cust.phone << endl;
            cout << "No Polisi: " << info(S)[i].cust.no_polisi << endl;
            cout << "Tipe: " << info(S)[i].cust.tipe << endl;
            cout << "Total: " << info(S)[i].total << endl;
            enter();
        }
    }
}


//PROSEDUR TAMBAHAN
void enter(){
    cout << "===================================================" << endl;
}

void intro() {
    enter();
    cout << "             Service Center Yamaha        " << endl;
    enter();
    cout << "                     Oleh:                " << endl;
    cout << "              Rizky Akbar Gusnaen         " << endl;
    cout << "                Helmi Dermawan            " << endl;
    enter();
}

int selectMenu() {
    cout << "====================== MENU =======================" << endl;
    cout << "1. Memasukan data pelanggan ke dalam antrian" << endl;
    cout << "2. Memproses semua data di dalam antrian" << endl;
    cout << "3. Menampilkan semua invoice" << endl;
    cout << "4. Menampilkan invoice dengan total biaya terbesar" << endl;
    cout << "0. Exit" << endl;
    cout << "====================== MENU =======================" << endl;
    cout << "Pilihan menu: " ;

    int input = 0;
    cin >> input;
    enter();
    return input;
}

void findMax(Stack S) {
    int Max = top(S);
    for (int i = top(S); i >= 1; i--) {
        if (info(S)[Max].total < info(S)[i].total) {
            Max = i;
        }
    }
    cout << "Nama: " << info(S)[Max].cust.nama << endl;
    cout << "Phone: " << info(S)[Max].cust.phone << endl;
    cout << "No. Polisi: " << info(S)[Max].cust.no_polisi << endl;
    cout << "Tipe: " << info(S)[Max].cust.tipe << endl;
    cout << "Total: " << info(S)[Max].total << endl;
}

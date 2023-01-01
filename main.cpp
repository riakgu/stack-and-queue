#include "tubes.h"

#include <iostream>

using namespace std;

int main()
{
    // Inisialisasi queue dan stack
    Queue Q;
    Stack S;
    createQueue(Q);
    createStack(S);

    intro();

    // Menu
    int pilihan = 0;
    pilihan = selectMenu();
    while (pilihan != 0) {
        switch(pilihan) {
        case 1:
            char ch;
            ch = 'y';
            do {
                // Baca informasi pelanggan
                Customer c;
                cout << "Masukkan nama pelanggan: ";
                cin >> c.nama;
                cout << "Masukkan nomor telepon: ";
                cin >> c.phone;
                cout << "Masukkan tipe kendaraan: ";
                cin >> c.tipe;
                cout << "Masukkan nomor polisi: ";
                cin >> c.no_polisi;

                // Masukkan pelanggan ke antrian
                enQueue(Q,c);

                // Tampilkan informasi pelanggan yang baru saja masuk ke antrian
                enter();
                cout << "Pelanggan " << c.nama << " telah masuk ke antrian!" << endl;
                enter();
                cout << "Apakah pelanggan datang ke service center (y/n)? ";
                cin >> ch;
                enter();

            } while (ch != 'n');

            break;
        case 2:
            while (!isEmptyQ(Q)) {
                // Ambil pelanggan pertama dari antrian
                int i = head(Q);
                Invoice a;
                a.cust = info(Q)[i];

                // Tampilkan informasi pelanggan yang sedang diproses
                cout << "Memproses pelanggan dengan rincian sebagai berikut:" << endl;
                enter();
                cout << "Nama: " << a.cust.nama << endl;
                cout << "Phone: " << a.cust.phone << endl;
                cout << "Tipe motor: " << a.cust.tipe << endl;
                cout << "No polisi: " << a.cust.no_polisi << endl;
                enter();
                cout << "Pelanggan " << a.cust.nama << " berhasil diproses!" << endl;
                enter();

                // Input tanggal dan total biaya
                cout << "Masukan biaya: ";
                cin >> a.total ;
                enter();

                // Masukkan invoice pelanggan ke tumpukan
                push(S,a);

                //Menghapus antrian yang sudah diproses
                Customer c = deQueue(Q);
            }

            // Tampilkan pesan bahwa semua pelanggan telah selesai diproses
            cout << "Semua pelanggan telah selesai diproses." << endl;
            enter();
            break;
        case 3:
            printStack(S);
            break;
        case 4:
            findMax(S);
            break;
        }
        pilihan = selectMenu();
    }
    return 0;
}

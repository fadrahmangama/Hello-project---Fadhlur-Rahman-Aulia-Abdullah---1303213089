#include "queue.h"
#include "stack.h"
Queue createQueue(Queue Q)
{
    Head(Q) = NULL;
    Tail(Q) = NULL;
    return Q;
}

addressQ allocate(infotypeQ p)
{
    addressQ Q = new elmQueue;
    Info(Q) = p;
    Next(Q) = NULL;
    return Q;
}

void enqueue(Queue &Q, infotypeQ p)
{
    addressQ Qnew = allocate(p);
    if (Head(Q) == NULL)
    {
        Head(Q) = Qnew;
        Tail(Q) = Qnew;
    }
    else
    {
        Next(Tail(Q)) = Qnew;
        Tail(Q) = Qnew;
    }
}

void dequeue(Queue &Q, infotypeQ &p)
{
    if (Head(Q) == NULL)
    {
        cout << "Queue kosong" << endl;
    }
    else
    {
        addressQ Qdel = Head(Q);
        p = Info(Qdel);
        Head(Q) = Next(Qdel);
        delete Qdel;
    }
}

bool isQueueEmptyQ(Queue Q)
{
    return (Head(Q) == NULL);
}

void printQueue(Queue Q)
{
    if (isQueueEmptyQ(Q))
    {
        cout << "Queue kosong" << endl;
    }
    else
    {
        addressQ Qprint = Head(Q);
        while (Qprint != NULL)
        {
            cout << Info(Qprint) << " ";
            Qprint = Next(Qprint);
        }
        cout << endl;
    }
}

int charToInt(char c)
{
    return static_cast<int>(c) - 48;
}

char intTochar(int x){
//        char digits[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//        return digits[i];
                // Membaca nilai x dari input
        int arr[x]; // Membuat array dengan ukuran x

        // Perulangan untuk mengisi elemen array
        for (int i = 0; i <= x; i++)
        {
                arr[i] = i;
        }

//        // Menampilkan elemen array
//        for (int i = 0; i <= hasil; i++)
//        {
//                cout << arr[i] << " ";
//        }

        return arr[x];


}

void hasilOperasi(Queue &Q)
{
    addressQ Pkali = Head(Q);
    while (Pkali != NULL)
    {
        if (Info(Pkali) == '*')
        {
            int Akali = charToInt(Info(Next(Pkali)));
            int Bkali = charToInt(Info(Next(Next(Pkali))));
            int hasilkali = Akali * Bkali;
            Info(Pkali) = hasilkali + 48;
            Next(Pkali) = NULL;
        }
        Pkali = Next(Pkali);
    }

    addressQ Pbagi = Head(Q);
    while (Pbagi != NULL)
    {
        if (Info(Pbagi) == '/')
        {
            int Abagi = charToInt(Info(Next(Pbagi)));
            int Bbagi = charToInt(Info(Next(Next(Pbagi))));
            int hasilbagi = Abagi / Bbagi;
            Info(Pbagi) = hasilbagi + 48;
            Next(Pbagi) = NULL;
        }
        Pbagi = Next(Pbagi);
    }

    addressQ Ptambah = Head(Q);
    while (Ptambah != NULL)
    {
        if (Info(Ptambah) == '+')
        {
            int Atambah = charToInt(Info(Next(Ptambah)));
            int Btambah = charToInt(Info(Next(Next(Ptambah))));
            int hasilTambah = Atambah + Btambah;
            Info(Ptambah) = hasilTambah + 48;
            Next(Ptambah) = NULL;
        }
        Ptambah = Next(Ptambah);
    }

    addressQ Pkurang = Head(Q);
    while (Pkurang != NULL)
    {
        if (Info(Pkurang) == '-')
        {
            int Akurang = charToInt(Info(Next(Pkurang)));
            int Bkurang = charToInt(Info(Next(Next(Pkurang))));
            int hasilkurang = Akurang - Bkurang;
            Info(Pkurang) = hasilkurang + 48;
            Next(Pkurang) = NULL;
        }
        Pkurang = Next(Pkurang);
    }

    printQueue(Q);
}



int QueueLength(Queue &Q){
    addressQ a;
    a = Head(Q);
    int u=1;
    while (a!=Tail(Q)){
        a=Next(a);
        u+=1;
    }
    return u;
}

int selectMenu(){
  cout<<"==========================================KALKULATOR A=============================================="<<endl<<endl;
  cout<<"SELAMAT DATANG DI PROGRAM KALKULATOR A"<<endl;
  cout<<"KALKULATOR INI AKAN MENGHITUNG OPERASI ARITMATIKA DENGAN CARA MENKONVERSIKAN NOTASI INFIX KE PREFIX"<<endl<<endl<<endl;
  cout<<"==============================================MENU=================================================="<<endl;
  cout<<"1.Lakukan Kalkulasi"<<endl;
  cout<<"0.Exit()"<<endl;
  cout<<"Pilihan menu : ";
  int input;
  cin>>input;
  return input;
}




#include <iostream>
using namespace std;

// ADT Stack
#include <iostream>
using namespace std;

typedef char infotypeQ;
typedef struct elmQueue *addressQ;

struct elmQueue
{
    infotypeQ info;
    addressQ next;
};

struct Queue
{
    addressQ Head;
    addressQ Tail;
};

#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define InfoHead(Q) (Q).Head->info
#define InfoTail(Q) (Q).Tail->info
#define Next(P) (P)->next
#define Info(P) (P)->info

Queue createQueue(Queue Q);
addressQ allocate(infotypeQ p);
void enqueue(Queue &Q, infotypeQ p);
void dequeue(Queue &Q, infotypeQ &p);
bool isQueueEmptyQ(Queue Q);
void printQueue(Queue Q);
int charToInt(char c);
void hasilOperasi(Queue &Q);
int QueueLength(Queue &Q);
char intTochar(int i);
int selectMenu();

#ifndef INTSTACK_H_INCLUDED
#define INTSTACK_H_INCLUDED

#include <iostream>
#include <stack>
using namespace std;

const int maxT = 100;
typedef int infotypeS2;
typedef int address;

struct intStack{
    infotypeS2 T[maxT];
    address TOP;
};

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Elmt(S,i) (S).T[(i)]

bool isStackEmpty(intStack S);
bool isStackFull(intStack S);
intStack createStack(intStack S);
void push(intStack &S, infotypeS2 p);
void pop(intStack &S, infotypeS2 &p);
void printStack(intStack S);






#endif // INTSTACK_H_INCLUDED

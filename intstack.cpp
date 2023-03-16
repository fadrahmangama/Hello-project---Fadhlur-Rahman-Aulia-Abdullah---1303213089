#include "intstack.h"

bool isStackEmpty(intStack S){
    if (Top(S)==0){
        return true;
    } else {
        return false;
    }
}

bool isStackFull(intStack S){
    if (Top(S)==maxT){
        return true;
    } else {
        return false;
    }
}

intStack createStack(intStack S){
    Top(S) = 0;
    return S;
}

void push(intStack &S, infotypeS2 p){
    if (isStackFull(S)){
        cout << "Stack penuh" << endl;
    } else {
        Top(S)++;
        InfoTop(S) = p;
    }
}

void pop(intStack &S, infotypeS2 &p){
    if (isStackEmpty(S)){
       cout<<"Stack Kosong"<<endl;
        p='0';
    } else {
        p = InfoTop(S);
        Top(S)--;
    }
}

void printStack(intStack S){
    for (int i = Top(S); i > 0; i--){
            cout <<S.T[i]<<" ";
    }
        cout << endl;
}

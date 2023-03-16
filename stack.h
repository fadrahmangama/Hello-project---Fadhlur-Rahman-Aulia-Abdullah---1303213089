#include <iostream>
#include <cctype>
#include <stack>
using namespace std;

const int maxElm = 100;

typedef char infotype;
typedef int address;

struct Stack{
    infotype T[maxElm];
    address TOP;
};

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Elmt(S,i) (S).T[(i)]

bool isStackEmpty(Stack S);
bool isStackFull(Stack S);
Stack createStack(Stack S);
void push(Stack &S, infotype p);
void pop(Stack &S, infotype &p);
void printStack(Stack S);
bool isOperator (char c);
bool isOperand(char c);
int Prioritas (char c);
string infixToPostfix (Stack S, string infix);
string infixToPrefix(Stack S,string infix);
Stack CariOp(string prefix);
int stackLength(Stack &Q);
//int cariOP(Stack stackPrefix);



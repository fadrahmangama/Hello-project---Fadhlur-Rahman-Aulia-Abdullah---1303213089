#include "stack.h"
#include "queue.h"

bool isStackEmpty(Stack S){
    if (Top(S)==0){
        return true;
    } else {
        return false;
    }
}

bool isStackFull(Stack S){
    if (Top(S)==maxElm){
        return true;
    } else {
        return false;
    }
}

Stack createStack(Stack S){
    Top(S) = 0;
    return S;
}

void push(Stack &S, infotype p){
    if (isStackFull(S)){
        cout << "Stack penuh" << endl;
    } else {
        Top(S)++;
        InfoTop(S) = p;
    }
}

void pop(Stack &S, infotype &p){
    if (isStackEmpty(S)){
       cout<<"Stack Kosong"<<endl;
        p='0';
    } else {
        p = InfoTop(S);
        Top(S)--;
    }
}

void printStack(Stack S){
    for (int i = Top(S); i > 0; i--){
            cout <<S.T[i]+'0'<<" ";
    }
        cout << endl;
    }

bool isOperator (char c){
   if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
   } else {
        return false;
   }

}

bool isOperand(char c){
    if (c>='A'&&c<='Z'){
        return true;
    } else if (c>='a' && c<='z'){
        return true;
    } else if (c>='0'&&c<='9'){
        return true;
    }
    return false;
}

int Prioritas (char c){
    if ((c == '+') || (c == '-')){
        return 1;
    } else if ((c == '*') || (c == '/')){
        return 2;
    } else if ((c=='^')){
        return 3;
    }
    return -1;
}

bool isHigher(char op1, char op2){
    int p1 = Prioritas(op1);
    int p2 = Prioritas(op2);
    if (p1==p2){
        if (op1=='^'){
            return false;
        }
        return true;
    }
    return (p1>p2);
}


string infixToPostfix (Stack S, string infix){
    string postfix;
    infotype p ;
    for(int i=0;i<infix.length();i++){
        if (isOperand(infix[i])==true){
            postfix+=infix[i];
        }else if (infix[i]=='('){
            push(S,infix[i]);
        }else if (infix[i]==')'){
            while(InfoTop(S)!='(' && (!isStackEmpty(S))){
                    char temp = InfoTop(S);
                    postfix+=temp;
                    pop(S,p);
            } if (InfoTop(S)=='('){
                    pop(S,p);
            }
        } else if (isOperator(infix[i])){
            if (isStackEmpty(S)){
                push(S,infix[i]);
            } else {
                if (Prioritas(infix[i])>Prioritas(InfoTop(S))){
                    push(S,infix[i]);
                }else if (Prioritas(infix[i])==Prioritas(InfoTop(S))&&infix[i]=='^'){
                    push(S,infix[i]);
                } else {
                    while (!isStackEmpty(S) && (Prioritas(infix[i])<=Prioritas(InfoTop(S)))){
                        postfix+=InfoTop(S);
                        pop(S,p);
                    }
                    push(S,infix[i]);
                }

                }
            }
        }
        while (!isStackEmpty(S)){
            postfix+=InfoTop(S);
            pop(S,p);
        }
        return postfix;

}




string infixToPrefix(Stack S,string infix){
    int size = infix.length();
    string reversedInfix="";
    string reversedPrefix="";

    for(int i = size-1;i>=0;i--){
        reversedInfix=reversedInfix+infix[i];
    }
    infix = reversedInfix;
    for (int i = 0;i<size;i++){
        if (infix[i]=='('){
                infix[i]=')';
        } else if (infix[i]==')'){
                infix[i]='(';
        }
    }

    string prefix = infixToPostfix(S,infix);
    int prefSize = prefix.length();
    for (int i = prefSize-1;i>=0;i--){
        reversedPrefix+=prefix[i];
    }
    return reversedPrefix;



}

Stack CariOp(string prefix){
    Stack OP;
    for (int i = 0;i<prefix.length();i++){
        if (isOperator(prefix[i])){
            push(OP,prefix[i]);
        }
    }
    return OP;
}



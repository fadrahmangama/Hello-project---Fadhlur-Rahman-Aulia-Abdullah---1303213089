#include "queue.h"
#include"stack.h"
#include"intstack.h"



int main()
{
  int pilihan;
  pilihan = selectMenu();
  while (pilihan !=0){
    switch (pilihan){
    case 1:
        string infix;
        Stack S;
        S = createStack(S);

        cout<<"MASUKKAN BILANGAN DALAM NOTASI INFIX : ";
        cin>>infix;
        cout<<endl;
        string prefix = infixToPrefix(S,infix);

        intStack Arithmetic;
        infotypeS2 popo;
        infotype p;
        infotype Operator;
        Stack OP;
        infotypeS2 Op1,Op2;
        int conv1,conv2;
        int hasil;

        Arithmetic = createStack(Arithmetic);
        for (int i = prefix.length()-1;i>=0;i--){
            if (isOperand(prefix[i])){
                popo = charToInt(prefix[i]);
                push(Arithmetic,popo);
            } else if (isOperator(prefix[i])){
                pop(Arithmetic,Op1);
                pop(Arithmetic,Op2);
                    if (prefix[i]=='+'){
                        hasil = (Op1+Op2);
                    } else if (prefix[i]=='-'){
                        hasil = (Op1-Op2);
                    } else if (prefix[i]=='*'){
                        hasil = (Op1*Op2);
                    } else if (prefix[i]=='/'){
                        hasil = (Op1/Op2);
                    }
                    push(Arithmetic,hasil);
            }
        }
        cout<<"Notasi Prefix : "<<prefix<<endl;
        cout<<"Hasil : ";
        printStack(Arithmetic);
        cout<<"Kembali ke Menu Utama ? (Y/N)";
        string YN;
        cin>>YN;
        cout<<endl;
        if (YN=="Y"){
            break;
        } else if (YN=="N"){

             cout<<endl;
             cout<<"==============================PROGRAM SELESAI============================"<<endl;
             exit(0);

        }


    }

    pilihan = selectMenu();

  }
  cout<<endl;
  cout<<"==============================PROGRAM SELESAI============================"<<endl;




    return 0;
}

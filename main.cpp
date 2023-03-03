#include <iostream>
#include <string.h>
#include "Pila.h"

using namespace std;

int main()
{
    int opc,tamexp;
    do{
        system("cls");
        Pila postfija;
        Pila Mystack;
        char expinf[30],expos[30]={' '},simbolo;
        cout<<"\n\tIngresa la expresion infija: ";
        cin>>expinf;

        tamexp=strlen(expinf);
        strupr(expinf);

        for(int i=0;i<tamexp;i++){
            simbolo=expinf[i];
            if(simbolo=='('){
                Mystack.Push(simbolo);
            }else if(simbolo==')'){
                while(Mystack.Tope()!='('){
                    postfija.Push(Mystack.Tope());
                    Mystack.Pop();
                }
                Mystack.Pop();

            }else if(simbolo>='A' && simbolo<='Z'){
                postfija.Push(simbolo);
            }else{
                while(!Mystack.Vacia() && Mystack.Prioridad(simbolo)<=Mystack.Prioridad(Mystack.Tope())){
                    postfija.Push(Mystack.Tope());
                    Mystack.Pop();
                }
                Mystack.Push(simbolo);
            }
        }
        while(!Mystack.Vacia()){
            postfija.Push(Mystack.Tope());
            Mystack.Pop();
        }
        for(int i=0;i<tamexp;i++){
            if(!postfija.Vacia()){
                expos[i]=postfija.Pop();
            }
        }
        strrev(expos);
        cout<<"\n\tExpresion postfija: "<<expos<<endl;
        cout<<"\n\tDesea convertir otra expresion?"<<"\n\t1. Si   2. No"<<endl;
        cout<<"\n\tIngresa la opcion: ";
        cin>>opc;
    }while(opc!=2);
    return 0;
}

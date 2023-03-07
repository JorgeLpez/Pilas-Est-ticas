#include "Pila.h"

Pila::Pila()
{
    tope=-1;
}

bool Pila::Vacia()
{
    return tope==-1;
}

bool Pila::Llena()
{
    return tope==TAM-1;
}

bool Pila::Push(char dato)
{
    if(!Llena()){
        tope++;
        datos[tope]=dato;
        return true;
    }else{
        std::cout<<"\nError!, La pila esta llena."<<std::endl;
        return false;
    }
}

char Pila::Pop()
{
    if(Vacia()){
        std::cout<<"\nLa pila esta vacia!"<<std::endl;
    } else {
        tope--;
        return datos[tope+1];
    }
}

char Pila::Tope()
{
    return datos[tope];
}

int Pila::Prioridad(char simbolo)
{
    int priori;
    switch(simbolo){
        case '/':   priori=2;
                    break;
        case '*':   priori=2;
                    break;
        case '-':   priori=1;
                    break;
        case '+':   priori=1;
                    break;
        case ')':   priori=0;
                    break;
        case '(':   priori=0;
                    break;
    }
    return priori;
}

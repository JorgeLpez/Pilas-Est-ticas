#ifndef PILA_H
#define PILA_H
#include<iostream>
#define TAM 50

class Pila
{
    private:
        char datos[TAM];
        int tope;

    public:
        Pila();
        bool Vacia();
        bool Llena();
        bool Push(char);
        char Tope();
        char Pop();
        int Prioridad(char);
};

#endif // PILA_H

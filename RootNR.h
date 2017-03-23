#include<iostream>
#include<cmath>
#define EPS 0.000000001 // Definindo Epsilon

class RootNR{
    private:
        Function *aFunction; // Ponteiro da classe Function
        double derivative(double x); // Método para encontrar a derivada de determinada função
    public:
        RootNR(Function *aFunction); // Construtor da classe passando um ponteiro da classe Function como parâmetro
        double findRoot(); // Método para encontrar uma raíz da função
};

double RootNR :: derivative(double x){
    return ((aFunction -> function(x + EPS)) - aFunction -> function(x))/EPS; // retorna o resultado da derivada:
                                                                              //(f(x+EPS) - f(x)) / EPS
}

double RootNR :: findRoot(){
    double xo = 0; // Ponto qualquer do eixo das abscissas
    int iteration = 0;  // Número de iterações para descobrir o resultado da raíz
    if(aFunction -> function(xo) != 0) // Verifica se o ponto xo não é a própria raiz
        {
        double xI = xo - (aFunction -> function(xo)/ this -> derivative(xo)); // xI recebe o valor do ponto xo menos
                                                                              // o valor da derivada nesse ponto xo
        double resultado = xo - xI; // resultado recebe o resultado da subtração entre xo e xI
        iteration++;
        if(resultado < 0){  // Verifica se o resultado é negativo
                resultado *= -1; // Se for negativo, vira positivo
        }

        while(resultado > EPS ){ // Repete o processo até que o resultado seja menor que o EPS definido anteriormente
            xo = xI; // O xo recebe o valor do ultimo xI
            xI = xo - (aFunction -> function(xo)/ this -> derivative(xo)); // xI recebe o valor do ponto xo menos
                                                                           // o valor da derivada nesse ponto xo
            iteration++; // o numero de iterações aumenta em 1
            resultado = xo - xI;
            if(resultado < 0){
                resultado *= -1;
            }
        }
        std::cout << "Iterador: " << iteration << std::endl; // Apresenta o número de iterações;
        return xI;  // Retorna o valor do ponto xI, a Raíz da função
    }
    else{ // Caso o ponto xo não for a própria raíz, ele é retornado
        std::cout << "Iterador: " << iteration << std::endl;
        return xo;
    }
}

RootNR :: RootNR(Function *aFunction){
    this->aFunction = aFunction; // O atributo da classe que é o ponteiro da classe Function, recebe o ponteiro
                                 // passado como referência
}

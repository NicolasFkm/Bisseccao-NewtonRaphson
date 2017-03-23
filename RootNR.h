#include<iostream>
#include<cmath>
#define EPS 0.000000001 // Definindo Epsilon

class RootNR{
    private:
        Function *aFunction; // Ponteiro da classe Function
        double derivative(double x); // M�todo para encontrar a derivada de determinada fun��o
    public:
        RootNR(Function *aFunction); // Construtor da classe passando um ponteiro da classe Function como par�metro
        double findRoot(); // M�todo para encontrar uma ra�z da fun��o
};

double RootNR :: derivative(double x){
    return ((aFunction -> function(x + EPS)) - aFunction -> function(x))/EPS; // retorna o resultado da derivada:
                                                                              //(f(x+EPS) - f(x)) / EPS
}

double RootNR :: findRoot(){
    double xo = 0; // Ponto qualquer do eixo das abscissas
    int iteration = 0;  // N�mero de itera��es para descobrir o resultado da ra�z
    if(aFunction -> function(xo) != 0) // Verifica se o ponto xo n�o � a pr�pria raiz
        {
        double xI = xo - (aFunction -> function(xo)/ this -> derivative(xo)); // xI recebe o valor do ponto xo menos
                                                                              // o valor da derivada nesse ponto xo
        double resultado = xo - xI; // resultado recebe o resultado da subtra��o entre xo e xI
        iteration++;
        if(resultado < 0){  // Verifica se o resultado � negativo
                resultado *= -1; // Se for negativo, vira positivo
        }

        while(resultado > EPS ){ // Repete o processo at� que o resultado seja menor que o EPS definido anteriormente
            xo = xI; // O xo recebe o valor do ultimo xI
            xI = xo - (aFunction -> function(xo)/ this -> derivative(xo)); // xI recebe o valor do ponto xo menos
                                                                           // o valor da derivada nesse ponto xo
            iteration++; // o numero de itera��es aumenta em 1
            resultado = xo - xI;
            if(resultado < 0){
                resultado *= -1;
            }
        }
        std::cout << "Iterador: " << iteration << std::endl; // Apresenta o n�mero de itera��es;
        return xI;  // Retorna o valor do ponto xI, a Ra�z da fun��o
    }
    else{ // Caso o ponto xo n�o for a pr�pria ra�z, ele � retornado
        std::cout << "Iterador: " << iteration << std::endl;
        return xo;
    }
}

RootNR :: RootNR(Function *aFunction){
    this->aFunction = aFunction; // O atributo da classe que � o ponteiro da classe Function, recebe o ponteiro
                                 // passado como refer�ncia
}

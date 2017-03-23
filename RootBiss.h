#include<iostream>
#include<cmath> // Biblioteca com funções matemáticas
#include<windows.h> // Biblioteca para utilizar a função rand()
#define EPS 0.000000001 // Definindo Epsilon

class RootBiss{
    private:
        Function *aFunction; // Ponteiro da classe Function
    public:
        RootBiss(Function *aFunction); // // Construtor da classe passando um ponteiro da classe Function como parâmetro
        double findRoot(); // Método para encontrar uma raíz da função
};

double RootBiss :: findRoot(){
    double a = 0, b = 0; // pontos a e b do eixo das abscissas
        while(aFunction -> function(b) * aFunction -> function(a) > 0){ // Enquanto a função no ponto a multiplicada
                                                                        // pelo ponto b for negativa ficará em loop
            b = -50+(rand()%(100 + 50)); // b receberá números aleátorios entre 100 e -50
        }
    if( a > b ){
        a += b;
        b = a - b;
        a -= b;
    }
    int contador = 0;   // contador de quantas vezes o processo irá se repetir
    double iterations = ((log10(b-a)) - (log10(EPS)))/log10(2);     // iterations recebe o número de iterações necessarias
    if(aFunction -> function(a) != 0 && aFunction -> function(b) != 0){// Verifica se o ponto a ou b são raízes
                                                                    //de acordo com a fórmula
        double c = (a+b)/2; // c recebe o valor do ponto médio entre a e b
        contador++; // contador aumenta em 1
        for(contador =1; (b-a) > EPS ; contador++){ // Enquanto o contador for menor que iterations, vai repetir o
                                                                         // processo e somar 1 no contador
            if((aFunction -> function(c)) * (aFunction -> function(a)) > 0){ // Verifica se a função no ponto a multiplicada
                                                                             // pela função no ponto c resulta em numero positivo
                a = c; // Se sim, o ponto a recebe o valor do ponto médio
            }
            else{
                b = c; // Se não o ponto b recebe o valor do ponto médio
            }
            c = (a+b)/2; // Novamente o ponto médio é calculado
            }
        std::cout << "Numero de iteracoes: " << contador << std::endl; // Apresenta o número de iterações
        return c; // Retorna o valor do ponto c
    }
    else{ // Caso um dos dois pontos seja alguma raíz
        std::cout << "Numero de iteracoes: " << contador << std::endl; // Apresenta o número de iterações
        if(aFunction -> function(a) == 0){ // Verifica se o ponto a é raíz
            return a; // Retorna o ponto a
        }
        else{ // Caso não seja o ponto a
            return b; // Retorna o ponto b
        }
    }
}

RootBiss:: RootBiss(Function *aFunction){
    this -> aFunction = aFunction; // O atributo da classe que é o ponteiro da classe Function, recebe o ponteiro
                                   // passado como referência
}


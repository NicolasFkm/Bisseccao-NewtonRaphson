#include<iostream>
#include<cmath> // Biblioteca com fun��es matem�ticas
#include<windows.h> // Biblioteca para utilizar a fun��o rand()
#define EPS 0.000000001 // Definindo Epsilon

class RootBiss{
    private:
        Function *aFunction; // Ponteiro da classe Function
    public:
        RootBiss(Function *aFunction); // // Construtor da classe passando um ponteiro da classe Function como par�metro
        double findRoot(); // M�todo para encontrar uma ra�z da fun��o
};

double RootBiss :: findRoot(){
    double a = 0, b = 0; // pontos a e b do eixo das abscissas
        while(aFunction -> function(b) * aFunction -> function(a) > 0){ // Enquanto a fun��o no ponto a multiplicada
                                                                        // pelo ponto b for negativa ficar� em loop
            b = -50+(rand()%(100 + 50)); // b receber� n�meros ale�torios entre 100 e -50
        }
    if( a > b ){
        a += b;
        b = a - b;
        a -= b;
    }
    int contador = 0;   // contador de quantas vezes o processo ir� se repetir
    double iterations = ((log10(b-a)) - (log10(EPS)))/log10(2);     // iterations recebe o n�mero de itera��es necessarias
    if(aFunction -> function(a) != 0 && aFunction -> function(b) != 0){// Verifica se o ponto a ou b s�o ra�zes
                                                                    //de acordo com a f�rmula
        double c = (a+b)/2; // c recebe o valor do ponto m�dio entre a e b
        contador++; // contador aumenta em 1
        for(contador =1; (b-a) > EPS ; contador++){ // Enquanto o contador for menor que iterations, vai repetir o
                                                                         // processo e somar 1 no contador
            if((aFunction -> function(c)) * (aFunction -> function(a)) > 0){ // Verifica se a fun��o no ponto a multiplicada
                                                                             // pela fun��o no ponto c resulta em numero positivo
                a = c; // Se sim, o ponto a recebe o valor do ponto m�dio
            }
            else{
                b = c; // Se n�o o ponto b recebe o valor do ponto m�dio
            }
            c = (a+b)/2; // Novamente o ponto m�dio � calculado
            }
        std::cout << "Numero de iteracoes: " << contador << std::endl; // Apresenta o n�mero de itera��es
        return c; // Retorna o valor do ponto c
    }
    else{ // Caso um dos dois pontos seja alguma ra�z
        std::cout << "Numero de iteracoes: " << contador << std::endl; // Apresenta o n�mero de itera��es
        if(aFunction -> function(a) == 0){ // Verifica se o ponto a � ra�z
            return a; // Retorna o ponto a
        }
        else{ // Caso n�o seja o ponto a
            return b; // Retorna o ponto b
        }
    }
}

RootBiss:: RootBiss(Function *aFunction){
    this -> aFunction = aFunction; // O atributo da classe que � o ponteiro da classe Function, recebe o ponteiro
                                   // passado como refer�ncia
}


#include<iostream>
#include<cmath>

class Function{
    public:
        double function(double x);
};

double Function :: function(double x){
        return (pow(x, 2) + 5*x - 4);

}



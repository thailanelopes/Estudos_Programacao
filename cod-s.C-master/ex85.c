#include <stdio.h>

int E_Triangulo(float a, float b, float c);
float Perimetro(float a, float b, float c);
float areaTrapezio(float a, float b, float c);

int main(){

    float a, b, c, resp, at, p;

    scanf("%f %f %f", &a, &b, &c);

    resp = E_Triangulo(a, b, c);

    if(resp == 1){
        p = Perimetro(a, b, c);
        printf("Perimetro = %.1f\n", p);
    }
    else{
        at = areaTrapezio(a, b, c);
        printf("Area = %.1f\n", at);
    }

    return 0;
}

int E_Triangulo(float a, float b, float c){

    if(a < b+c && b < a+c && c < a+b){
        return 1;
    }
    return 0;
}

float Perimetro(float a, float b, float c){
    return a + b + c;
}

float areaTrapezio(float a, float b, float c){
    return ((a+b)*c)/2;
}

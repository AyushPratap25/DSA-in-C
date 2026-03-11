#include <stdio.h>

typedef struct
{
    double real;
    double img;
} complex;

complex add(complex, complex);

int main() {
    complex c1, c2;
    printf("Eneter c1 real and img: ");
    scanf("%lf %lfi", &c1.real, &c1.img);

    printf("\n\nEnter c2 real and img: ");
    scanf("%lf %lfi", &c2.real, &c2.img);
    


    complex c3 = add (c1, c2);

    if (c3.img < 0)
        printf("\n%.2lf - %.2lfi", c3.real, -c3.img);
    else 
        printf("\n%.2lf + %.2lfi", c3.real, c3.img);
    
    return 0;
}

complex add(complex c1, complex c2)
{
    complex c3;
    c3.real = c2.real + c1.real;
    c3.img = c2.img + c1.img;
    return c3;

}


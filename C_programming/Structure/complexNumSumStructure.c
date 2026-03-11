// first create the structure basically the template
// then that template can be used as a ds to store and retrive values
// perform operations and get the result
// note: think of "struct <tagName>"" as a data type like int, flaot, double and so


#include <stdio.h>

struct complex // this is the template or say UD data type
{
    double real;
    double img;
};

// function normal as we do just insted of int, float and so 
// we have UD data type "struct complex"
// make sure to follow the template created
struct complex add(struct complex c1, struct complex c2) // using the format 
{
    struct complex c3;
    c3.real = c1.real + c2.real; // operation
    c3.img = c1.img + c2.img;
    return c3;
}

int main()
{
    struct complex a1, a2, sum;

    printf("Input the 1st complex numeber (real and imag part): ");
    scanf("%lf %lf", &a1.real, &a1.img); // don't forget the '&' sign
    printf("Input the 2nd complex numeber (real and imag part): ");
    scanf("%lf %lf", &a2.real, &a2.img);

    sum = add(a1, a2); // funct call

    // condition to overcome the issue what if sum of img part is negative
    if (sum.img > 0) printf("sum: %.2lf + %.2lfi", sum.real, sum.img); // for positive
    else printf("sum: %.2lf - %.2lfi", sum.real, -sum.img); // for negative

    return 0; // success

}
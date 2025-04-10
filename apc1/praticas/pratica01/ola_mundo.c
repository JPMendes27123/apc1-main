#include <stdio.h>

int main() {

    int a, b, *c;

    a = 0;
    b = 3;


    c = &a;  

    *c = *c + 1; 



    c = &b;    

    b = b + 4;  



printf("valores de a: %i e b: %i. \n", a, b );

return 0;

}
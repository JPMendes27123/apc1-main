#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pint = malloc(sizeof (int));
    *pint = 5;
    
    
    short int *psint = malloc(sizeof (short int) * 2);
    psint[1] = 7;
    psint[0] = 3;
    
    printf("pint: %p, *pint: %d\n", pint, *pint);
    printf("&psint[0]: %p, psint[0]: %d\n", &psint[0], psint[0]);
    printf("&psint[1]: %p, psint[1]: %d\n", &psint[1], psint[1]);
    
    psint = realloc(psint, sizeof (short int) * 4);
    
    free(pint);
    free(psint);
    
    return 0;
}
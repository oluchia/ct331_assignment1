#include <stdio.h>

int main(int arg, char* argc[]){
    printf("Hello assignment1.\n");
    printf("Hello assignment1.\n");

    int x = 1;
    int *xp = &x;
    long y = 8; 
    
    double d = 10.00;
    double *yp = &d;
    
    char c = 'a';
    char *zp = &c;
    char **z = &zp;
    
    printf("Size of variable: %lu \n", sizeof(x));
    printf("Size of variable: %lu \n", sizeof(*xp));
    printf("Size of variable: %lu \n", sizeof(y));
    printf("Size of variable: %lu \n", sizeof(*yp));
    printf("Size of variable: %lu \n", sizeof(**z));
  
}


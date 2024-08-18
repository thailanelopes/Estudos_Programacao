#include <stdio.h>
#include <stdlib.h>

long int string2int( const char * str );

int main(){

    char str[128];
    long int n;

    while( scanf("%s", str) != EOF ){
        n = string2int( str );
        printf("%ld %ld\n", n, n*2);
    }

    return 0;
}

long int string2int( const char * str ){
    return atol(str);
}

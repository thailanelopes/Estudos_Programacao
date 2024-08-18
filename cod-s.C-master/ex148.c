#include <stdio.h>
#include <string.h>

int main(){

    int n;
    scanf("%d", &n);

    int i, leds, tamanho;
    char str[101];

    while(n > 0){
        scanf("%s", str);

        tamanho = strlen(str);

        leds = 0;
        for(i = 0; i < tamanho; i++){
            if('1' == str[i]){
                leds += 2;
            }
            else if('2' == str[i] || '3' == str[i] || '5' == str[i]){
                leds += 5;
            }
            else if('4' == str[i]){
                leds += 4;
            }
            else if('6' == str[i] || '9' == str[i] || '0' == str[i]){
                leds += 6;
            }
            else if('7' == str[i]){
                leds += 3;
            }
            else if('8' == str[i]){
                leds += 7;
            }
        }
        printf("%d leds\n", leds);
        n--;
    }

    return 0;
}

#include <stdio.h>

int main(){
    // Variaveis de entrada.
    unsigned long int codigo;
    float precoCompra, precoVenda;
    int numVenda;

    // Variaveis auxiliares.
    int j;
    float lucro, maiorLucro, venda;

    // Variaveis que vão ser exibidas na tela, no final.
    int lucroMenor, lucroMaiorIgual, lucroMaior;
    unsigned long int codigoMaiorLucro, codigoMaisVendida;
    float totalCompras, totalVendas, percentualLucroTotal;

    totalCompras = 0;
    totalVendas = 0;
    lucroMenor = 0;
    lucroMaiorIgual = 0;
    lucroMaior = 0;
    j = 0;
    while(scanf("%lu %f %f %d", &codigo, &precoCompra, &precoVenda, &numVenda) != EOF){

        // Lucro menor que 10%.
        if(precoVenda < precoCompra * 1.1){
            lucroMenor++;
        }
        // Lucro maior ou igual a 10% e menor ou igual a 20%.
        if(precoVenda >= precoCompra*1.1 && precoVenda <= precoCompra*1.2){
            lucroMaiorIgual++;
        }
        // Lucro maior que 20%.
        if(precoVenda > precoCompra*1.2){
            lucroMaior++;
        }
        // Codigo da mercadoria que gerou maior lucro.
        lucro = (precoVenda - precoCompra) * numVenda;
        if(j == 0){
            maiorLucro = lucro;
            codigoMaiorLucro = codigo;
        }
        else if(lucro > maiorLucro){
            maiorLucro = lucro;
            codigoMaiorLucro = codigo;
        }
        // Código da mercadoria mais vendida.
        if(j == 0){
            venda = numVenda;
            codigoMaisVendida = codigo;
        }
        else if(venda < numVenda){
            venda = numVenda;
            codigoMaisVendida = codigo;
        }
        j++;
        // Valor total de compra e de venda de todas as mercadoria.
        totalCompras += precoCompra * numVenda;
        totalVendas += precoVenda * numVenda;

    }
    // Percentual do lucro total
    percentualLucroTotal = ((totalVendas - totalCompras)*100) / totalCompras;

    // Imprimir informaçoes na tela
    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", lucroMenor);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", lucroMaiorIgual);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", lucroMaior);
    printf("Codigo da mercadoria que gerou maior lucro: %lu\n", codigoMaiorLucro);
    printf("Codigo da mercadoria mais vendida: %lu\n", codigoMaisVendida);
    printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n", totalCompras, totalVendas, percentualLucroTotal);

    return 0;
}

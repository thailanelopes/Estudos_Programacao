#variáveis
maior = 0

#entrada
numero = int(input("Informe um número: "))

while  numero != 0:
    if numero > maior:
        maior = numero
    numero = int(input("informe um número: "))
print("O maior número é {0}: ".format(maior))
        
#entradas
numero = int(input("Informe um número: "))

#processamento

if (numero % 2 == 0):
    print("O número {0} é par.".format(numero))
else:
    print("O número {0} é ímpar.".format(numero))
if (numero > 0):
    print("O número {0} é positivo.".format(numero))
else: 
    print("O número {0} é negativo.".format(numero))
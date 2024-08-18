#variáveis
p = 0 
i = 0

#entradas

numero = int(input("Informe um número: "))

#processamento

if numero % 2 == 0:
    p = numero
    print("{0} é par".format(p))
else:
    i = numero
    print("{0} é ímpar".format(i))
#entradas
num1 = int(input("Informe o primeiro número: ")) #int() identifica que no local da String será recebido um valor numérico.
num2 = int(input("Informe o segundo número:  "))

#processamento
soma = num1 + num2
multiplicação = soma * num1

#saída
print("O resultado da multiplicação é {0}".format(multiplicação)) #{0}substitui pela primeira variável dentro do .format. 
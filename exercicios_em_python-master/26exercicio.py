#variáveis
vetor = []

#entradas
for n in range(0, 10):
    num = int(input("Informe o valor para o vetor: "))
    vetor.append(num)
    
#processamento
vetor.reverse()
for n in vetor:
    print(n)
#variáveis
vetor = [] #[] em python é chamado de lista vazia.
pares = []

for n in range(1, 11):
    vetor.append(n) #.append adiciona o valores passados para n em vetor.  
    if n % 2 == 0:
        pares.append(n)
for p in pares:
    print(p)

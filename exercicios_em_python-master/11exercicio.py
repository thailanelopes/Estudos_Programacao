#variáveis
excesso = 0
multa = 0

#entradas
peso = float(input("Informe o peso dos peixes: "))

if peso > 50:
    multa = (peso - 50) * 4.00
    excesso = 'excesso'
    print("Você deverá pagar R$ {0:.2f}".format(multa))
else: 
    multa = 0
    excesso = 0
    print("Multas: {0}".format(multa))
    print("Excesso: {0}".format(excesso))

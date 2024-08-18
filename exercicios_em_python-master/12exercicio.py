#variáveis
valor_hora = 10.00
valor_hora_excedente = 20.00
excedente = 0

#entradas
codigo = int(input("Informe o código: "))
horas_trabalhadas = float(input("Informe a quantidade de horas trabalhadas: "))

#processamento
if horas_trabalhadas > 50:
    excedente = (horas_trabalhadas - 50) * valor_hora_excedente #20.00 por hora excedente.
    salario = (50 * valor_hora) + excedente #10.00 o valor da hora
    print("Salário Total R$: {0:.2f}".format(salario))
    print("Salário excedente R$: {0:.2f}".format(excedente))
    
else:
    salario = (horas_trabalhadas * valor_hora) #10.00 o valor da hora
    print("Salário Total R$: {0:.2f}".format(salario))
    print("Salário excedente R$: {0:.2f}".format(excedente))
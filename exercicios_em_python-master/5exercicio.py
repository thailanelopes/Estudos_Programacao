#entradas

valor_por_hora = float(input("Qual valor você ganha por hora?"))
horas_trabalhadas = int(input("Quantas horas você trabalhou no mês? "))

#processamento

salario = (horas_trabalhadas * valor_por_hora)

#saída
print("Neste mês seu salário será R$ {0:.2f} ".format(salario)) #{0:.2f} formatação para adcionar 2 casas decimais no valor final.

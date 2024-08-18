#entradas
altura = float(input("Informe a sua altura: "))
sexo = input("Informe o sexo m/f: ") #não é necessário nenhum cast para a variável sexo, pois o input já é configurado para receber esse tipo de dado.

#processamento

if sexo.lower() == 'm':# .lower() pega tudo que for passado na variável sexo, e converte para minúsculo
    peso_ideal = (72.7 * altura) - 58
elif sexo.lower() == 'f':
    peso_ideal = (62.1 * altura) - 44.7
else:
    peso_ideal = 0
    print("Sexo não identificado.")
    
    #saída
print("seu peso ideal é {0:.2f}".format(peso_ideal))
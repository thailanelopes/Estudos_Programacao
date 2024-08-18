#variáveis
contador_total = 0
contator_sit_1 = 0
contator_sit_2 = 0
contator_sit_3 = 0
contator_sit_4 = 0

#entrada
identificador = int(input("Informe a identificação: "))

#processamento/processamento
while identificador != 0:
    print("1- Necessidade de esfera.")
    print("2- Necessita de limpeza.")
    print("3- Necessidade troca do cabo ou conector.")
    print("4- Quebrado ou inutilizado.")
    
    #entrada
    defeito = int(input("Informe o tipo de defeito: "))
    
    #processamento
    if defeito == 1:
        contator_sit_1 = contator_sit_1 + 1
    elif defeito == 2:
        contator_sit_2 = contator_sit_2 + 1
    elif defeito == 3:
        contator_sit_3 = contator_sit_3 + 1
    elif defeito == 4:
        contator_sit_4 = contator_sit_4 + 1
    contador_total = contador_total + 1
    #entrada
    identificador = int(input("Informe a identificação: "))

p1 = contator_sit_1 / contador_total * 100.0
p2 = contator_sit_2 / contador_total * 100.0
p3 = contator_sit_3 / contador_total * 100.0
p4 = contator_sit_4 / contador_total * 100.0
print("Quantidades de mouses: {0}".format(contador_total))
print(" SITUAÇÃO                                 QUANTIDADE      PERCENTUAL")
print("1- Necessidade de esfera                     {0}            {1:.2f}%  ".format(contator_sit_1, p1))    
print("2- Necessita de limpeza                      {0}            {1:.2f}%  ".format(contator_sit_2, p2))
print("3- Necessidade troca do cabo ou conector     {0}            {1:.2f}%  ".format(contator_sit_3, p3))
print("4-Quebrado ou inutilizado                    {0}            {1:.2f}%  ".format(contator_sit_4, p4))
  
    
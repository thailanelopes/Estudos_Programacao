#entradas
indice = float(input("Informe o índice de poluição: "))

#processamento

if indice >= 0.3 and indice < 0.4:
    print("Atenção: Indústrias do primeiro grupo devem suspender as atividades.")
elif indice >= 0.4 and indice < 0.5: #usamos elif quando queremos atribuir uma condição para else (em algumas linguagens de programação em vez de elif se usa else if )
    print("Atenção: Indústrias do primeiro e Segundo grupo devem suspender as atividades.")
elif indice >= 0.5:
    print("Atenção: Todos os grupos devem suspender as atividades.")
    
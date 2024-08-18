#entrdas
nome = input("Informe o nome: ")
senha = input("Informe a senha: ")

#processamneto

while nome == senha:
    print("Nome de usuário e senha devem ser diferentes. ")
    nome = input("Informe o nome:")
    senha = input("Informe a senha: ")
if nome != senha:
    print("Cadastro realizado com sucesso!")
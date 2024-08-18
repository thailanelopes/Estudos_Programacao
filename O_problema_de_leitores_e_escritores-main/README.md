# O problema de leitores e escritores

*O problema de Escritores e Leitores. Atividade desenvolvida para a matéria de Sistemas Operacionais*

 - O problema dos leitores e escritores modela o acesso a uma base de dados, em que basicamente
alguns processos ou threads estão lendo os dados da região crítica, somente querendo obter a
informação da mesma, que é o caso dos leitores. Quando outros processos ou threads tentam alterar
a informação da região crítica, é o caso dos escritores.
Nesse sistema, é aceitável a existência de diversos leitores na base de dados ao mesmo tempo.
Porém, se um processo necessita escrever na base de dados, nenhum leitor esta realizando acesso a
ela.

<img src="/escritores e leitores.png" alt="My cool logo"/>

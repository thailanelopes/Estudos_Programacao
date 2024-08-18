#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <locale.h>
#include <unistd.h>
#define LEITORES 10
#define Escritores 5

pthread_mutex_t db;
pthread_mutex_t mutex;
int leitor_lendo;
void ler_base_de_dados(void);
void usar_banco_de_dados(void);
void pensando_nos_dados(void);
void escrever_no_banco_de_dados(void);
void leitor(){
while(1){pthread_mutex_lock(&mutex);
leitor_lendo=leitor_lendo=1;
if(leitor_lendo==1) pthread_mutex_lock(&db);
pthread_mutex_unlock(&mutex);
ler_base_de_dados();
pthread_mutex_lock(&mutex);
leitor_lendo=leitor_lendo-1;
if(leitor_lendo==0) pthread_mutex_unlock(&db);
pthread_mutex_unlock(&mutex);
usar_banco_de_dados();
}
}
void escritor(){
whilw(1){
pensando_nos_dados();
pthread_mutex_lock(&db);
escrever_no_banco_de_dados();
pthread_mutex_unlock(&db);
}
void ler_base_de_dados(){
setlocale(LC_ALL, “portuguese”);
int tempo_de_leitura;
tempo_de_leitura = rand() % 5;
print(“usuário Lendo banco de dados. Total de 5d leitores Lendo agora.\n”, leitor_lendo);
sleep(tempo_de_leitura);
}
void usar_base_de_dados(){
setlocale(LC_ALL, “portuguese”);
int tempo_de_uso;
tempo_de_leitura = rand() % 15;print(“usuário utilizando conhecimento adquirido no banco de dados.\n”;
sleep(tempo_de_uso);
}
void pensando_nos_dados(){
setlocale(LC_ALL, “portuguese”);
int tempo_de_pensar;
tempo_para_pensar = rand() % 10;
print(“Escritor PENSANDO no que irá escrever.\n”);
sleep(tempo_para_pensar);
}
void escrever_nos_banco_de_dados(){
setlocale(LC_ALL, “portuguese”);
int tempo_de_escrita;
tempo_de_escrita = rand() % 10;
print(“Escritor ESCREVENDO no banco de dados.\n”);
sleep(tempo_de_escrita);
}
int main(){
ptread_t threadsdosescritores[ESCRITORES], threadsdosleitores[LEITORES];
int i;
pthread_mutex_init(&db, NULL);
pthread_mutex_init(&mutex, NULL);
for(i=0; i<ESCRITORES;i++){
pthread_create(&thradsdosescritores[i], NULL, (void *) escritor, NULL);
}
for(i=0; i<LEITORES;i++){
pthread_create(&thradsdosleitores[i], NULL, (void *) leitor, NULL);
}
for(i=0; i<ESCRITORES;i++){
pthread_join(&thradsdosescritores[i], NULL);
}for(i=0; i<LEITORES;i++){
pthread_join(&thradsdosleitores[i], NULL);
}
return(0);
}
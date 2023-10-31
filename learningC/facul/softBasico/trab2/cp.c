//Código escrito e pensado por Pedro Tesch e Nathan Trugilho

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	FILE *lock, *buffer;
	int v[100];
	int pid = fork();

	/* Inicializa o gerador de números aleatórios calculando o total de segundos passados desde 01/01/1970 até a data atual.
  	Desta forma, a cada execução o valor do "filho" será diferente. */
  	srand(time(NULL));
	
	if(pid == 0) {
		//Código Consumidor
		while(1) {
			//Verifica se o arquivo buffer.txt.lock existe...
			while(access("buffer.txt.lock", F_OK) == 0) {
				usleep(1200);
			}
			
			//Cria o arquivo buffer.txt.lock
			lock = fopen("buffer.txt.lock", "w");

			//Preenche o vetor com o buffer.
			buffer = fopen("buffer.txt", "r");
			int aux = 0;
			while(fscanf(buffer, "%d\n", &(v[aux])) != EOF) {
				aux++;
			} 
			fclose(buffer);
			
			//Reescreve o buffer retirando o elemento 0 do vetor.
			buffer = fopen("buffer.txt", "w");
			for(int i = 1; i < aux; i++) {
				fprintf(buffer, "%d\n", v[i]);
			}
			
			printf("[Consumidor] %d\n", v[0]);
			
			fclose(buffer);
			fclose(lock);
			
			
			remove("buffer.txt.lock");
			
			sleep(1 + rand() % 3);
		}
	} else {
		//Código Produtor	
		while(1) {
			while(access("buffer.txt.lock", F_OK) == 0){
				usleep(1200);
			}
			
			//Cria o arquivo buffer.txt.lock...
			lock = fopen("buffer.txt.lock", "w");
			
			//Gera um número aleatório entre 0 e 99.
			int random = rand() % 100;
			
			//Insere o número gerado na última linha do buffer.
			buffer = fopen("buffer.txt", "a");
			fprintf(buffer, "%d\n", random);
			
			printf("[Produtor] %d\n", random);
			
			fclose(buffer);
			fclose(lock);
			
            
            remove("buffer.txt.lock");
			
			sleep(1 + rand() % 3);
		}
	}

	return 0;
}
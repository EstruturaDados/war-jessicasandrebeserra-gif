// Desafio: Nível Novato
// Cadastro de territórios Jogo WAR com o uso de structs
//======================================================

//---Bibliotecas---

#include <stdio.h>// Biblioteca para entrada e saída de dados
#include <string.h>// Biblioteca para manipulação de strings
#include <stdlib.h>// Biblioteca para funções de alocação de memória

//---Definição de constantes---
#define MAX_TERRITORIOS 5// Máximo de territórios
#define MAX_NOME 50// Máximo de caracteres para o nome do território

//---Definição da struct para representar um território---
struct Territorio {
	char nome[MAX_NOME];// Nome do território
	char corExercito[MAX_NOME];// Cor do exército presente no território
	int tropas;// Número de tropas presentes no território
};

//---Função para limpar o buffer de entrada---
void limparBufferEntrada() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}// Limpa o buffer de entrada
}


//---Função Principal (main)---
int main() {
	struct Territorio territorios[MAX_TERRITORIOS];// Array para armazenar os territórios
	int totalTerritorios = 0;// Contador para o número total de territórios cadastrados
	char continuar;// Variável para controlar a continuação do cadastro

	for (int i = 0; i < MAX_TERRITORIOS; i++) {// Loop para cadastrar os territórios


		if (totalTerritorios >= MAX_TERRITORIOS) {// Verifica se o número máximo de territórios foi atingido
			printf("Limite de territorios atingido. Não é possível cadastrar mais.\n");
			break;// Sai do loop se o limite de territórios for atingido
		}
		printf("---Cadastro do Territorio %d:---\n", i + 1);// Exibe o número do território que está sendo cadastrado
		printf("Digite o nome do territorio: ");// Solicita ao usuário que digite o nome do território
		fgets(territorios[i].nome, MAX_NOME, stdin);// Lê o nome do território
		territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';// Remove o caractere de nova linha

		printf("Digite a cor do exercito presente no territorio: ");
		fgets(territorios[i].corExercito, MAX_NOME, stdin);// Lê a cor do exército
		territorios[i].corExercito[strcspn(territorios[i].corExercito, "\n")] = '\0';// Remove o caractere de nova linha

		printf("Digite o numero de tropas presentes no territorio: ");
		scanf("%d", &territorios[i].tropas);// Lê o número de tropas
		limparBufferEntrada();// Limpa o buffer de entrada

		totalTerritorios++;// Incrementa o contador de territórios cadastrados

		printf("\nTerritorio cadastrado com sucesso!\n");// Mensagem de sucesso após o cadastro do território

		// Pergunta se o usuário deseja continuar cadastrando territórios
		if (i < MAX_TERRITORIOS - 1) {
			printf("\nDeseja cadastrar outro territorio? (s/n): ");
			scanf("%c", &continuar);
			printf("\n");
			limparBufferEntrada();// Limpa o buffer de entrada

			if (continuar == 'n' || continuar == 'N') {
				break;// Sai do loop se o usuário não quiser continuar
			}
		}
	}
	
	printf("====Exibindo os territorios cadastrados:===\n");
	
	for (int i = 0; i < totalTerritorios; i++) { // Loop para exibir os territórios cadastrados
		printf("\nTerritorio %d:\n", i + 1);// Exibe o número do território
		printf("- Nome: %s\n", territorios[i].nome);// Exibe o nome do território
		printf("- Cor do Exercito: %s\n", territorios[i].corExercito);// Exibe a cor do exército presente no território
		printf("- Numero de Tropas: %d\n\n", territorios[i].tropas);// Exibe o número de tropas presentes no território
	}

	return 0;// Fim do programa.

}

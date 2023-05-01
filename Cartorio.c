#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio de criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é de write (escrever)
	fprintf(file, cpf); //salva o valor da variavel
	fprintf(file,", "); //virgula entre as variaveis
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,". ");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	//inicio de criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n")	;
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause")	;
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema. \n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		//inicio do menu
		printf("--- Cartório da EBAC --- \n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t 1 - Registrar nomes \n");
		printf("\t 2 - Consultar nomes \n");
		printf("\t 3 - Deletar nomes \n");
		printf("\t 4 - Sair do sistema \n");
		printf("Opção: ");
		//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) 
		{
			//inicio da seleção do menu
			case 1:
				registro(); //chamada de funções
				break;
				
			case 2:
				consulta(); //chamada de funções
				break;
				
			case 3:
				deletar(); //chamada de funções
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema! \n");
				return 0;
				break;
				
			default:
				printf("Essa opção não está disponivel! \n");
				system("pause");
				break;
			//fim da seleção do menu
		}
	}
}

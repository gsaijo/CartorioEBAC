#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio de cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" � de write (escrever)
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
	system("cls");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	//inicio de cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause")	;
	system("cls");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf, "r");
		if(file == NULL)
		{
			printf("Usu�rio deletado com sucesso! \n");
			system("pause");
		}
	}
	fclose(file);
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("--- Cart�rio da EBAC --- \n\n");
	printf("Login de administrador! \n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	system("cls");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{
	
			//inicio do menu
			printf("--- Cart�rio da EBAC --- \n\n");
			printf("Escolha a op��o desejada do menu: \n\n");
			printf("\t 1 - Registrar nomes \n");
			printf("\t 2 - Consultar nomes \n");
			printf("\t 3 - Deletar nomes \n");
			printf("\t 4 - Sair do sistema \n");
			printf("Op��o: ");
			//fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuario
		
			system("cls"); //responsavel por limpar a tela
			
			switch(opcao) 
			{
				//inicio da sele��o do menu
				case 1:
				registro(); //chamada de fun��es
				break;
					
				case 2:
				consulta(); //chamada de fun��es
				break;
					
				case 3:
				deletar(); //chamada de fun��es
				break;
					
				case 4:
				printf("Obrigado por utilizar o sistema! \n");
				return 0;
				break;
					
				default:
				printf("Essa op��o n�o est� disponivel! \n");
				system("pause");
				break;
				//fim da sele��o do menu
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}

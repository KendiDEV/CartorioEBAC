#include <stdio.h> //Biblioteca de comunica��o de usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca das Strings
int registro ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	char arquivo [40]; //Definindo variaveis
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //Comando para o usu�rio
	scanf("%s", cpf); //L� o que o usu�rio escreveu e armazena na variavel CPF
	
	strcpy(arquivo ,cpf); //Respos�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo "w"= escrever
	fprintf(file, "CPF: "); // Usado para deixar o menu mais visual
	fprintf(file, cpf); //Escreve a Variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Comanda para o usu�rio
	scanf("%s", nome); //L� o que o usu�rio escreveu e armazena na variavel nome
	
	file = fopen(arquivo, "a"); //abre o arquivo e o modifica "a"= atualizar
	fprintf(file, "\nNome: "); //Usado para deixar o menu mais visual
	fprintf (file, nome); //Escreve a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Comando para o usu�rio
	scanf("%s", sobrenome); //L� o que o usu�rio escreveu e armazena na variavel sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o modifica "a"=atualizar
	fprintf(file, "\nSobrenome: "); //Usado para deixar o menu mais visual
	fprintf(file, sobrenome); //Escreve a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Comanda para o usu�rio
	scanf("%s", cargo); //L� o que o usu�rio escreveu e armazena na variavel cargo
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o modifica "a" = atualizar
	fprintf(file, "\nCargo: "); //Usado para deixar o menu mais visual
	fprintf(file, cargo); //Escreve a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o sistema
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf [40]; //Definindo as variaveis
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: "); //Comanda para o usu�rio
	scanf("%s", cpf); //l� o que o usu�rio escreveu e armazena na variavel
	system("cls"); //Limpa a tela
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e apena o l�, sem o modificar "r"= ler (read)

	if(file == NULL) //Condicional se o valor inserido n�o estiver no bando de dados
	{
		printf("N�o foi poss�vel localizar um arquivo com este n�mero!\n\n"); //Mensagem de erro para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Pega o que h� dentro da varivel "conteudo" e para quando n�o se h� mais caracteres !=NULL
	{
		
		printf("%s", conteudo); //Visualiza para o usu�rio o que h� dentro da variavel "conteudo"
		printf("\n\n");//Pula duas linhas
    }
    fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o sistema
	
	
	
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf [40]; //Definindo a varivel
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Comanda para o usu�rio
	scanf("%s", cpf); //l� o que o usu�rio escreveu e armazena na varivel
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo na inten��o de ler "r" = ler (read)
	fclose(file); //Fecha o arquivo
	
	
	if(file == NULL) //Condicional, se o n�mero inserido n�o constar no banco de dados, a seguinte frase de erro ira aparecer:
	{
		printf("N�o foi poss�vel encontrar um usu�rio com esse n�mero\n"); //Mensagem de erro
		system("pause"); // Pausa para o sistema
	}
	else //Outra parte da condicional, caso o n�mero inserido conste no banco de dados, continuara� com a opera��o de deletar
	 {
	 	remove(cpf); //Deletar o CPF
		printf("O usu�rio foi deletado com sucesso\n"); //Mensagem para o usu�rio
		system("pause"); //Pausa no sistema
	 }
	 
}
int main ()
{
	int opcao = 0; //Definindo variaveis
	int laco = 1;
	
	for(laco=1; laco=1;) //Loop para voltar ao menu
	{
		system("cls"); //Limpar a tela
		
		 setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
		
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada no menu abaixo:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar  Nomes\n");
		printf("\t3 - Deletar  Nomes\n");
		printf("\t4 - Sair do menu\n\n"); //Fim do menu
		
		printf("Op��o: ");
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Limpar a tela
		
		switch (opcao) //Sele��o do menu
		{
			case 1:
			registro();	//Chamada de fun��o
			break;	
			
			case 2:
			consulta(); // Chamada de fun��o
			break;
			
			case 3:
			deletar(); //Chamada de fun��o
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema"); 
			return 0; //Para fechar o sistema
			break;
			
			default: // Se o valor inserido for diferente de 1,2 ou 3, este comando ira ativar
			printf("Essa op��o n�o est� dispon�vel\n");
			system ("pause"); //Pausa no sistema
			break;	
		}
		
	
	}
} 

#include <stdio.h> //Biblioteca de comunicação de usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca das Strings
int registro ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	char arquivo [40]; //Definindo variaveis
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: "); //Comando para o usuário
	scanf("%s", cpf); //Lê o que o usuário escreveu e armazena na variavel CPF
	
	strcpy(arquivo ,cpf); //Resposável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo "w"= escrever
	fprintf(file, "CPF: "); // Usado para deixar o menu mais visual
	fprintf(file, cpf); //Escreve a Variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Comanda para o usuário
	scanf("%s", nome); //Lê o que o usuário escreveu e armazena na variavel nome
	
	file = fopen(arquivo, "a"); //abre o arquivo e o modifica "a"= atualizar
	fprintf(file, "\nNome: "); //Usado para deixar o menu mais visual
	fprintf (file, nome); //Escreve a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Comando para o usuário
	scanf("%s", sobrenome); //Lê o que o usuário escreveu e armazena na variavel sobrenome
	
	file = fopen(arquivo, "a"); //Abre o arquivo e o modifica "a"=atualizar
	fprintf(file, "\nSobrenome: "); //Usado para deixar o menu mais visual
	fprintf(file, sobrenome); //Escreve a variavel no arquivo
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Comanda para o usuário
	scanf("%s", cargo); //Lê o que o usuário escreveu e armazena na variavel cargo
	
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
	
	printf("Digite o CPF a ser consultado: "); //Comanda para o usuário
	scanf("%s", cpf); //lê o que o usuário escreveu e armazena na variavel
	system("cls"); //Limpa a tela
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo e apena o lê, sem o modificar "r"= ler (read)

	if(file == NULL) //Condicional se o valor inserido não estiver no bando de dados
	{
		printf("Não foi possível localizar um arquivo com este número!\n\n"); //Mensagem de erro para o usuário
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Pega o que há dentro da varivel "conteudo" e para quando não se há mais caracteres !=NULL
	{
		
		printf("%s", conteudo); //Visualiza para o usuário o que há dentro da variavel "conteudo"
		printf("\n\n");//Pula duas linhas
    }
    fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o sistema
	
	
	
}

int deletar ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf [40]; //Definindo a varivel
	
	printf("Digite o CPF do usuário a ser deletado: "); //Comanda para o usuário
	scanf("%s", cpf); //lê o que o usuário escreveu e armazena na varivel
	
	FILE *file; //Abre o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo na intenção de ler "r" = ler (read)
	fclose(file); //Fecha o arquivo
	
	
	if(file == NULL) //Condicional, se o número inserido não constar no banco de dados, a seguinte frase de erro ira aparecer:
	{
		printf("Não foi possível encontrar um usuário com esse número\n"); //Mensagem de erro
		system("pause"); // Pausa para o sistema
	}
	else //Outra parte da condicional, caso o número inserido conste no banco de dados, continuaraá com a operação de deletar
	 {
	 	remove(cpf); //Deletar o CPF
		printf("O usuário foi deletado com sucesso\n"); //Mensagem para o usuário
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
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada no menu abaixo:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar  Nomes\n");
		printf("\t3 - Deletar  Nomes\n");
		printf("\t4 - Sair do menu\n\n"); //Fim do menu
		
		printf("Opção: ");
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Limpar a tela
		
		switch (opcao) //Seleção do menu
		{
			case 1:
			registro();	//Chamada de função
			break;	
			
			case 2:
			consulta(); // Chamada de função
			break;
			
			case 3:
			deletar(); //Chamada de função
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema"); 
			return 0; //Para fechar o sistema
			break;
			
			default: // Se o valor inserido for diferente de 1,2 ou 3, este comando ira ativar
			printf("Essa opção não está disponível\n");
			system ("pause"); //Pausa no sistema
			break;	
		}
		
	
	}
} 

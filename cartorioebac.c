#include <stdio.h>   // Biblioteca de comunicação com o usuário
#include <stdlib.h>  // Biblioteca de alocação de memória
#include <locale.h>  // Biblioteca para configuração de localização
#include <string.h>  //blibioteca reponsavel pelas strings

// Função para registrar nomes
int registro() 
{   
    //criação da string
	char arquivo[40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
	char cargo [40];
    
    //coletando informação do cpf
    printf("digite o cpf a ser cadastrado: ");
    scanf ("%s", cpf);
    
    strcpy (arquivo, cpf);//copia o valor das strings
    
    //criação/leitura do arquivo do usuario
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file,cpf);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose(file);
    
    printf("digite o nome a ser cadastrado: ");
    scanf ("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf (file, nome);
    fclose (file);
    
    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose(file);
    
    printf("digite o sobrenome a ser cadastrado: ");
    scanf ("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf (file, sobrenome);
    fclose(file);
    
    file = fopen (arquivo, "a");
    fprintf (file, ",");
    fclose(file);
    
	printf("digite o cargo a ser cadastrado: ");
    scanf ("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf (file, cargo);
    fclose (file);
    
    system("pause");    
}

// Função para consultar nomes
int consulta() 
{
	setlocale(LC_ALL, "portuguese");
	
	//criação/leitura do arquivo do usuario
    char cpf[40];
    char conteudo[200];
    
    //criação/leitura do arquivo do usuario
    printf("cite o cpf a ser consultado: ");
    scanf ("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
   
	if (file == NULL)
   {
    printf("não foi possivel localizar o usuario: \n");	
   } 
    
    
    while(fgets(conteudo, 200, file) != NULL);
    {
    	printf("essas são as informaçoés do usuario: \n");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system ("pause");
}

// Função para deletar usuários
int deletar() 
{
   //criação/leitura do arquivo do usuario
	
   char cpf[40];
   
   //criação/leitura do arquivo do usuario
   printf("digite o cpf a ser deletado: \n");
   scanf("%s", cpf);
   
   remove (cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL);
   {
       printf("este usuario não se encontra na base de dados.\n\n");
       system ("pause");
   }
}

int main() // Função principal onde todo o código se localiza
{
    int opcao = 0;
    int x = 1;

    // Configura a localidade para Português
    setlocale(LC_ALL, "portuguese");

    // Loop principal do programa
    while (x == 1) 
	{
        system("cls"); // Limpa a tela
        
        // Título
        printf("### Cartório EBAC ###\n\n");
        
        // Tela de seleção
        printf("- Selecione a opção desejada:\n\n");
        
        // Opções
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar usuário\n");
        printf("\t4 - sair do sistema\n");
        printf("\n Opção: ");
        
        // Leitura da opção do usuário
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela
        
        // chamada das funçoes
        switch (opcao) 
		{
            case 1:
                registro();
                break;  
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;
                
            case 4:
		        printf("obrigado por ultilizar o sistema!\n");
				return 0;
				break;      
                
            default: 
                printf("\t* Opção inválida.\n\n\n");
                system("pause");
                break;
        }       
    }

}


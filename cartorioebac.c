#include <stdio.h>   // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // Biblioteca de aloca��o de mem�ria
#include <locale.h>  // Biblioteca para configura��o de localiza��o
#include <string.h>  //blibioteca reponsavel pelas strings

// Fun��o para registrar nomes
int registro() 
{   
    //cria��o da string
	char arquivo[40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
	char cargo [40];
    
    //coletando informa��o do cpf
    printf("digite o cpf a ser cadastrado: ");
    scanf ("%s", cpf);
    
    strcpy (arquivo, cpf);//copia o valor das strings
    
    //cria��o/leitura do arquivo do usuario
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

// Fun��o para consultar nomes
int consulta() 
{
	setlocale(LC_ALL, "portuguese");
	
	//cria��o/leitura do arquivo do usuario
    char cpf[40];
    char conteudo[200];
    
    //cria��o/leitura do arquivo do usuario
    printf("cite o cpf a ser consultado: ");
    scanf ("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
   
	if (file == NULL)
   {
    printf("n�o foi possivel localizar o usuario: \n");	
   } 
    
    
    while(fgets(conteudo, 200, file) != NULL);
    {
    	printf("essas s�o as informa�o�s do usuario: \n");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system ("pause");
}

// Fun��o para deletar usu�rios
int deletar() 
{
   //cria��o/leitura do arquivo do usuario
	
   char cpf[40];
   
   //cria��o/leitura do arquivo do usuario
   printf("digite o cpf a ser deletado: \n");
   scanf("%s", cpf);
   
   remove (cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL);
   {
       printf("este usuario n�o se encontra na base de dados.\n\n");
       system ("pause");
   }
}

int main() // Fun��o principal onde todo o c�digo se localiza
{
    int opcao = 0;
    int x = 1;

    // Configura a localidade para Portugu�s
    setlocale(LC_ALL, "portuguese");

    // Loop principal do programa
    while (x == 1) 
	{
        system("cls"); // Limpa a tela
        
        // T�tulo
        printf("### Cart�rio EBAC ###\n\n");
        
        // Tela de sele��o
        printf("- Selecione a op��o desejada:\n\n");
        
        // Op��es
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar usu�rio\n");
        printf("\t4 - sair do sistema\n");
        printf("\n Op��o: ");
        
        // Leitura da op��o do usu�rio
        scanf("%d", &opcao);

        system("cls"); // Limpa a tela
        
        // chamada das fun�oes
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
                printf("\t* Op��o inv�lida.\n\n\n");
                system("pause");
                break;
        }       
    }

}


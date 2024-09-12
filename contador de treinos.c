/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funcoes.h"

/* Variáveis globais */
int dia, mes, ano, erro;
int diaAtletismo, mesAtletismo, anoAtletismo;
int diaNatacao, mesNatacao, anoNatacao;
int diaRugby, mesRugby, anoRugby;
int diaJudo, mesJudo, anoJudo;
int contador;
char opcao;

/* Corpo do programa */
int main()
{
	// Abertura do arquivo no modo escrita para emitir o relatório
	FILE *arquivo;
	arquivo = fopen("relatorio.txt", "w");
	// Verificação de erro na criação do arquivo
	if (arquivo == NULL)
	{
		printf("\nFalha ao criar o arquivo!!!");
		exit(1);
	}
	
	imprimeTitulo();
	printf("Este programa tem o objetivo de contar quantos treinos\nhaver%co no per%codo de 1 ano das seguintes modalidades:\n", 198, 161);
	printf("\nAtletismo - Periodicidade: a cada 2 dias.");
	printf("\nNata%c%co   - Periodicidade: a cada 3 dias.", 135, 198);
	printf("\nRugby     - Periodicidade: a cada 5 dias.");
	printf("\nJud%c      - Periodicidade: a cada 9 dias.", 147);
	printf("\n\nPressione qualquer tecla para continuar...");
	getch();
	
	do
	{	
		// Captura o ano entre 1 e 9999
		do{
			system("cls");
			imprimeTitulo();
			printf("Ano aceito: valor entre 1 e 9999.", 163);
			printf("\nDigite o ano: ");
			fflush(stdin);
			scanf("%i", &ano);
		} while (ano < 1 || ano > 9999); 
	
		// Captura o mês
		do{
			system("cls");
			imprimeTitulo();
			printf("M%cs aceito: valor entre 1 e 12.", 136);
			printf("\nDigite o m%cs: ", 136);
			fflush(stdin);
			scanf("%i", &mes);
		} while (mes < 1 || mes > 12); //Validação do mês
	
		// Captura o dia
		do
		{
			erro = 0;
			system("cls");
			imprimeTitulo();
			printf("Dia aceito: valor entre 1 e %i.", diasDoMes(mes,ano));
			printf("\nDigite o dia: ");
			fflush(stdin);
			scanf("%i", &dia);
			if (dia < 1 || dia > diasDoMes(mes,ano)) erro = 1; //Validação dos dias do mês
		}	while (erro == 1);
		
		system("cls");
		imprimeTitulo();
		printf("Data fornecida: %02i/%02i/%04i\n\n", dia, mes, ano);
		printf("Deseja continuar com essa data? [S/s]=Sim");
		fflush(stdin);
		opcao = getche();
	} while (opcao != 's' && opcao != 'S');
	
	system("cls");
	
	// Atribuindo a data inserida pelo usuário às variáveis de cada modalidade
	diaAtletismo = dia; mesAtletismo = mes; anoAtletismo = ano;
	diaNatacao = dia; mesNatacao = mes; anoNatacao = ano;
	diaRugby = dia; mesRugby = mes; anoRugby = ano;
	diaJudo = dia; mesJudo = mes; anoJudo = ano;
	
	// Exibe o cabeçalho para os dias em que as 4 modalidades coincidem
	printf("--------------------------------------------------------------------------------------------------------------------\n\n");
	printf("                                   As 4 modalidades se encontram a cada %i dias.\n\n", mmc4(2, 3, 5, 9));
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\n       DATAS ATLETISMO                DATAS NATA%c%cO                DATAS RUGBY                DATAS JUD%c\n", 128, 199, 226);
	printf("       (a cada 2 dias)                (a cada 3 dias)              (a cada 5 dias)            (a cada 9 dias)\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	// Grava o mesmo cabeçalho no relatório
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n\n");
	fprintf(arquivo, "                                   As 4 modalidades se encontram a cada %i dias.\n\n", mmc4(2, 3, 5, 9));
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "\n       DATAS ATLETISMO                DATAS NATAÇÃO                DATAS RUGBY                DATAS JUDÔ\n");
	fprintf(arquivo, "       (a cada 2 dias)                (a cada 3 dias)              (a cada 5 dias)            (a cada 9 dias)\n\n");
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n");
	
	contador = 1;
	// Imprime na tela e no relatório as datas em que as modalidades coincidem
	for(int i = 0; i < 5; i++)
	{
		printf("\n%i   | ", contador); fprintf(arquivo, "\n%i   | ", contador);
		
		printf("%02i/%02i/%04i - ", diaAtletismo, mesAtletismo, anoAtletismo);
		fprintf(arquivo, "%02i/%02i/%04i - ", diaAtletismo, mesAtletismo, anoAtletismo);
		formulaZeller(diaAtletismo, mesAtletismo, anoAtletismo, arquivo);
		incrementaData(&diaAtletismo, &mesAtletismo, &anoAtletismo, mmc4(2, 3, 5, 9));
		
		printf("%02i/%02i/%04i - ", diaNatacao, mesNatacao, anoNatacao);
		fprintf(arquivo, "%02i/%02i/%04i - ", diaNatacao, mesNatacao, anoNatacao);
		formulaZeller(diaNatacao, mesNatacao, anoNatacao, arquivo);
		incrementaData(&diaNatacao, &mesNatacao, &anoNatacao, mmc4(2, 3, 5, 9));
		
		printf("%02i/%02i/%04i - ", diaRugby, mesRugby, anoRugby);
		fprintf(arquivo, "%02i/%02i/%04i - ", diaRugby, mesRugby, anoRugby);
		formulaZeller(diaRugby, mesRugby, anoRugby, arquivo);
		incrementaData(&diaRugby, &mesRugby, &anoRugby, mmc4(2, 3, 5, 9));
		
		printf("%02i/%02i/%04i - ", diaJudo, mesJudo, anoJudo);
		fprintf(arquivo, "%02i/%02i/%04i - ", diaJudo, mesJudo, anoJudo);
		formulaZeller(diaJudo, mesJudo, anoJudo, arquivo);
		incrementaData(&diaJudo, &mesJudo, &anoJudo, mmc4(2, 3, 5, 9));
		
		contador++;
	}	
	
	// Imprime na tela e no arquivo o cabeçalho do relatório para todas as datas em que as modalidades treinam
	printf("\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n\n");
	printf("                     As modalidades treinam de %02i/%02i/%04i (", dia, mes, ano);
	fprintf(arquivo, "\n\n");
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n\n");
	fprintf(arquivo, "                     As modalidades treinam de %02i/%02i/%04i (", dia, mes, ano);
	formulaZeller2(dia, mes, ano, arquivo);
	printf(") a %02i/%02i/%04i (", dia, mes, ano+1);
	fprintf(arquivo, ") a %02i/%02i/%04i (", dia, mes, ano+1);
	formulaZeller2(dia, mes, ano+1, arquivo);
	printf(")\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\n       DATAS ATLETISMO                DATAS NATA%c%cO                DATAS RUGBY                DATAS JUD%c\n", 128, 199, 226);
	printf("       (a cada 2 dias)                (a cada 3 dias)              (a cada 5 dias)            (a cada 9 dias)\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, ")\n\n");
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n");
	fprintf(arquivo, "\n       DATAS ATLETISMO                DATAS NATAÇÃO                DATAS RUGBY                DATAS JUDÔ\n");
	fprintf(arquivo, "       (a cada 2 dias)                (a cada 3 dias)              (a cada 5 dias)            (a cada 9 dias)\n\n");
	fprintf(arquivo, "--------------------------------------------------------------------------------------------------------------------\n");
	
	// Atribuindo a data inserida pelo usuário às variáveis de cada modalidade
	diaAtletismo = dia; mesAtletismo = mes; anoAtletismo = ano;
	diaNatacao = dia; mesNatacao = mes; anoNatacao = ano;
	diaRugby = dia; mesRugby = mes; anoRugby = ano;
	diaJudo = dia; mesJudo = mes; anoJudo = ano;
	
	// Definindo os contadores para cada modalidade dependendo se o ano é bissexto ou não
	contador = 1;
	int contadorAtlet, contadorNatac, contadorRugby, contadorJudo;
	switch(diasNoAno(ano))
	{
		case 365: {contadorAtlet = (365/2)+1; contadorNatac = (365/3)+2; contadorRugby = (365/5)+2; contadorJudo = (365/9)+2; break;}
		case 366: {contadorAtlet = (366/2); contadorNatac = (366/3)+1; contadorRugby = (366/5)+2; contadorJudo = (366/9)+2; break;}
	}
	
	/* Imprime na tela e no relatório todas as datas de todas as modalidades
	   Como o atletismo é o que tem mais datas, o contador dele determina o tamanho do laço */
	for(int i = 0; i < contadorAtlet; i++)
	{
		if(contador < 10)
		{
			printf("\n%i   | ", contador);
			fprintf(arquivo, "\n%i   | ", contador);
		}
		else
		if(contador < 100)
		{
			printf("\n%i  | ", contador);
			fprintf(arquivo, "\n%i  | ", contador);
		}
		else
		{
			printf("\n%i | ", contador);
			fprintf(arquivo, "\n%i | ", contador);
		}
		
		printf("%02i/%02i/%04i - ", diaAtletismo, mesAtletismo, anoAtletismo);
		fprintf(arquivo, "%02i/%02i/%04i - ", diaAtletismo, mesAtletismo, anoAtletismo);
		formulaZeller(diaAtletismo, mesAtletismo, anoAtletismo, arquivo);
		incrementaData(&diaAtletismo, &mesAtletismo, &anoAtletismo, 2);
		if(contador < contadorNatac)
		{
			printf("%02i/%02i/%04i - ", diaNatacao, mesNatacao, anoNatacao);
			fprintf(arquivo, "%02i/%02i/%04i - ", diaNatacao, mesNatacao, anoNatacao);
			formulaZeller(diaNatacao, mesNatacao, anoNatacao, arquivo);
			incrementaData(&diaNatacao, &mesNatacao, &anoNatacao, 3);
		}
		if(contador < contadorRugby)
		{
			printf("%02i/%02i/%04i - ", diaRugby, mesRugby, anoRugby);
			fprintf(arquivo, "%02i/%02i/%04i - ", diaRugby, mesRugby, anoRugby);
			formulaZeller(diaRugby, mesRugby, anoRugby, arquivo);
			incrementaData(&diaRugby, &mesRugby, &anoRugby, 5);
		}
		if(contador < contadorJudo)
		{
			printf("%02i/%02i/%04i - ", diaJudo, mesJudo, anoJudo);
			fprintf(arquivo, "%02i/%02i/%04i - ", diaJudo, mesJudo, anoJudo);
			formulaZeller(diaJudo, mesJudo, anoJudo, arquivo);
			incrementaData(&diaJudo, &mesJudo, &anoJudo, 9);
		}		
		contador++;
	}
	fclose(arquivo);
	
	getch();
	return 0;
}
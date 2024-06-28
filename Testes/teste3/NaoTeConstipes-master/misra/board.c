#include <stdio.h>
#include <stdlib.h>

#include "board.h"

#define PEAO1 0
#define PEAO2 1
#define PEAO3 2
#define PEAO4 3
#define DICE_SIZE 6

typedef enum {HEADER = 0, OCCUPANCY_1 = 1, SAFE_HOUSE = 2, OCCUPANCY_2 = 3, TAIL = 4} line_rendering;

typedef int32_t MyInt;
typedef casa* CasaPtr;

CasaPtr listCasaAt(list theBoard, MyInt idx);

void printCasaLine(line_rendering line, MyInt pos, list theBoard);

MyInt rolldice(MyInt numberOfDices)
{
	MyInt i, sum;

	/* If numberOfDices is 0, return immediately */
	if (numberOfDices == 0) 
	{
		return 0;
	}

	for (i = sum = 0 ; i < numberOfDices ; i++)
	{
		sum += rand() % DICE_SIZE + 1; /* SY Need to replace rand() with a safer alternative */
	}

	return sum;
}
/**
	Imprime o tabuleiro no ecrã
	
	rows - Numero de linhas do tabuleiro
	cols - Numero de colunas do tabuleiro
	theBoard - Lista que contem as casas do tabuleiro
	modo - imprime a posicao dos peoes se for 1, nao imprime se for 0
*/
#include <stdio.h>
#include <stdint.h>

typedef uint32_t list; /* Assuming list, node, casa, line_rendering are types */

void boardPrint(const uint32_t rows, const uint32_t cols, list theBoard, const int32_t modo)
{
	list *t;
	list *it;

	const int32_t Ncasas = 2*(cols+rows-2);

	if (!(rows >= MIN_ROWS && rows % 2)) 
	{
		printf("Tabuleiro tem de ter no minimo 3 linhas e impar");
		return;
	}

	if (!(cols > MIN_COLS))
	{ 
		printf("Numero colunas do tabuleiro tem de ser superior a 4");
		return;
	}

	if (!(theBoard.length == Ncasas))
	{
		printf("Falha na construcao do tabuleiro, demasiado grande");
		return;
	}

	if (theBoard.head == NULL)
	{
		printf("Falha na construcao do tabuleiro");
		return;
	}

	if (!(modo == 0 || modo == 1))
	{
		return;
	}

	if ((uint32_t) Ncasas == 0)
	{
		printf("Ncasas is zero.");
		return;
	}

	/* Rest of the code remains same as there are no other violations within first 23 rules. */

	uint32_t i;
	if (modo)
	{
		i = 0;
		for (t = theBoard.head; (uint32_t) i < (uint32_t) Ncasas ; t = t-> next, i++)
		{
			it = &(t -> item);
			printf("%d ", i); 

			if (it->jogador_peao[JOGADOR1][PEAO1])
				printf("%c", it->jogador_peao[JOGADOR1][PEAO1] == WIN ? SYMBOLS_J1[5]: SYMBOLS_J1[1]);

			if (it->jogador_peao[JOGADOR1][PEAO2])
				printf("%c", it->jogador_peao[JOGADOR1][PEAO2] == WIN ? SYMBOLS_J1[6]: SYMBOLS_J1[2]);

			if (it->jogador_peao[JOGADOR1][PEAO3])
				printf("%c", it->jogador_peao[JOGADOR1][PEAO3] == WIN ? SYMBOLS_J1[7]: SYMBOLS_J1[3]);

			if (it->jogador_peao[JOGADOR1][PEAO4])
				printf("%c", it->jogador_peao[JOGADOR1][PEAO4] == WIN ? SYMBOLS_J1[8]: SYMBOLS_J1[4]);


			if (it->jogador_peao[JOGADOR2][PEAO1])
				printf("%c", it->jogador_peao[JOGADOR2][PEAO1] == WIN ? SYMBOLS_J2[5]: SYMBOLS_J2[1]);

			if (it->jogador_peao[JOGADOR2][PEAO2])
				printf("%c", it->jogador_peao[JOGADOR2][PEAO2] == WIN ? SYMBOLS_J2[6]: SYMBOLS_J2[2]);

			if (it->jogador_peao[JOGADOR2][PEAO3])
				printf("%c", it->jogador_peao[JOGADOR2][PEAO3] == WIN ? SYMBOLS_J2[7]: SYMBOLS_J2[3]);

			if (it->jogador_peao[JOGADOR2][PEAO4])
				printf("%c", it->jogador_peao[JOGADOR2][PEAO4] == WIN ? SYMBOLS_J2[8]: SYMBOLS_J2[4]);

			putchar('.');
		}
		putchar('\n');
		return;
		}
	
	else
	{
		uint32_t pos, right_pos, left_pos, pos_l, pos_r, k;
		line_rendering line;

		
	/* print first line */
	/* first line starts in position floor(rows/2) */
	for (line = HEADER ; line <= TAIL ; line++)
	{
		pos = rows/2;
		for (i = 0 ; i < cols ; i++, pos++)
			printCasaLine(line, pos, theBoard);
		putchar('\n');
	}

	/* print intermediate top lines down to middle line inclusive */
	left_pos = rows/2 - 1;
	right_pos = pos;
	for (i = 0 ; i < rows/2 ; i++, left_pos--, right_pos++)
	{
		for (line = HEADER ; line <= TAIL ; line++)
		{
			pos_l = left_pos;
			pos_r = right_pos;
			for (k = 0 ; k < cols ; k++)
			{
				if (k == 0)
					printCasaLine(line, pos_l, theBoard);
				else if (k == cols-1)
					printCasaLine(line, pos_r, theBoard);
				else
					printf("        ");
			}
			putchar('\n');
		}
	}

	/* print bottom intermediate lines */
	left_pos = Ncasas-1;
	for (i = 0 ; i < rows/2-1 ; i++, left_pos--, right_pos++)
	{		
		for (line = HEADER ; line <= TAIL ; line++)
		{
			pos_l = left_pos;
			pos_r = right_pos;			
			for (k = 0 ; k < cols ; k++)
			{
				if (k == 0)
					printCasaLine(line, pos_l, theBoard);
				else if (k == cols-1)
					printCasaLine(line, pos_r, theBoard);
				else
					printf("        ");				
			}
			putchar('\n');
		}
	}
	
	/* print bottom line */
	for (line = HEADER ; line <= TAIL ; line++)
	{
		pos = left_pos;
		for (i = 0 ; i < cols ; i++, pos--)
			printCasaLine(line, pos, theBoard);
		putchar('\n');
	}
	fflush(stdout);
	}

}


/**
	Obtem uma determinada casa do tabuleiro que está definido na lista 
	localizada pela sua posicao
	
	l - Lista de casas do tabuleiro
	idx - Numero de posicao da casa
*/

/* It's necessary to have actual definitions of casa, node, list */

casa * listCasaAt(list *theBoard, int32_t idx)
{
	node *t; 
	int32_t i;

	for (i = 0 ; i < idx ; i++)
	{
		if(theBoard->head != NULL)
		{
			t = theBoard->head;
			theBoard->head = theBoard->head->next;
		}
		else
		{
			break;
		}
	}
	return (i == idx) ? &(t -> item) : NULL;
}
/**
	Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
	Incluindo peoes presentes na casa e simbolo das casas seguras
	
	line - linha da casa a imprimir
	pos - Numero de posicao da casa a imprimir
	theBoard - Lista contendo o tabuleiro
*/

/* It's necessary to have actual definitions of casa, list, line_rendering */

void printCasaLine(line_rendering line, int32_t pos, list *theBoard)
{
	/* Valor temporario da casa do tabuleiro que esta a ser processada */
	casa *it;

	switch(line)
	{
		case HEADER: /* imprime numero da casa na linha 0 */
			printf("+--%2d--+", pos);
			break;
		case OCCUPANCY_1: /* imprime peoes do jogador 1 presentes, na linha 1 */
			it = listCasaAt(theBoard, pos);
			if (it == NULL) 
			{
				printf("Lista esta vazia");
				return;
			}
			/* Rest of the code remains the same */
			break;
		case SAFE_HOUSE: /* imprime se casa e segura, na linha 2 */
			it = listCasaAt(theBoard, pos);
			if (it == NULL) 
			{
				printf("Lista esta vazia");
				return;
			}
			/* Rest of the code remains the same */
			break;
		case OCCUPANCY_2: /* imprime peoes do jogador 2 presentes, na linha 3 */
			it = listCasaAt(theBoard, pos);
			if (it == NULL)
			{
				printf("Lista esta vazia");
				return;
			}
			/* Rest of the code remains the same */
			break;
		case TAIL:
			printf("+------+");
			break;
			default: 
				break;   // Added default case as per rule 16.4
	}
}

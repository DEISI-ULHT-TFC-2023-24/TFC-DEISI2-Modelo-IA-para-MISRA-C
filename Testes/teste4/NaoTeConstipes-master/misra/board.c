#include <stdio.h>
#include <stdlib.h>

#include "board.h"

#define PEAO1 0
#define PEAO2 1
#define PEAO3 2
#define PEAO4 3
#define DICE_SIZE 6

/**
	Names each line when a square is drawn
	The top of the square is the HEADER, and the bottom is the TAIL
*/
typedef enum {HEADER = 0, OCCUPANCY_1 = 1, SAFE_HOUSE = 2, OCCUPANCY_2 = 3, TAIL = 4} line_rendering;

/**
	Gets a specific square from the board defined in the list
	located by its position

	theBoard - List of board squares
	idx - Position number of the square
*/
casa * listCasaAt(list theBoard, int idx);

/**
	Prints the content within a board square line by line
	Including pawns present in the square and safe house symbol

	line - line of the square to print
	pos - Position number of the square to print
	theBoard - List containing the board
*/
void printCasaLine(line_rendering line, int pos, list theBoard);

/**
	Simulates the game's dice

	numberOfDices - Number of dice to roll
*/
int rolldice(int numberOfDices)
{
	int i;
	int sum = 0;

	for (i = 0; i < numberOfDices; i++)
	{
		sum += (rand() % DICE_SIZE) + 1; // Note: rand() usage needs to be reviewed per project guidelines
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

void boardPrint(const unsigned int rows, const unsigned int cols, const list theBoard, const int modo)
{
	unsigned int i;
	unsigned int k;
	unsigned int pos;
	unsigned int right_pos;
	unsigned int left_pos;
	unsigned int pos_l;
	unsigned int pos_r;
	line_rendering line;
	node *t;
	casa *it;

	const unsigned int Ncasas = 2U * (cols + rows - 2U);

	/* Assertions replaced with conditional checks and appropriate handling */
	if ((rows < MIN_ROWS) || ((rows % 2U) == 0U))
	{
		/* Handle error: Tabuleiro tem de ter no minimo 3 linhas e impar */
		return;
	}
	if (cols <= MIN_COLS)
	{
		/* Handle error: Numero colunas do tabuleiro tem de ser superior a 4 */
		return;
	}
	if (theBoard.length != Ncasas)
	{
		/* Handle error: Falha na construcao do tabuleiro, demasiado grande */
		return;
	}
	if (theBoard.head == NULL)
	{
		/* Handle error: Falha na construcao do tabuleiro */
		return;
	}
	if ((modo != 0) && (modo != 1))
	{
		/* Handle error: invalid mode */
		return;
	}

	// The rest of the function continues here...

	
		const unsigned int Ncasas = 2U * (cols + rows - 2U);
	
		if (modo != 0)
		{
			i = 0U;
			t = theBoard.head;
			while (i < Ncasas)
			{
				it = &(t->item);
				(void)printf("%u ", i); 
	
				if (it->jogador_peao[JOGADOR1][PEAO1] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR1][PEAO1] == WIN ? SYMBOLS_J1[5] : SYMBOLS_J1[1]);
				}
	
				if (it->jogador_peao[JOGADOR1][PEAO2] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR1][PEAO2] == WIN ? SYMBOLS_J1[6] : SYMBOLS_J1[2]);
				}
	
				if (it->jogador_peao[JOGADOR1][PEAO3] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR1][PEAO3] == WIN ? SYMBOLS_J1[7] : SYMBOLS_J1[3]);
				}
	
				if (it->jogador_peao[JOGADOR1][PEAO4] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR1][PEAO4] == WIN ? SYMBOLS_J1[8] : SYMBOLS_J1[4]);
				}
	
				if (it->jogador_peao[JOGADOR2][PEAO1] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR2][PEAO1] == WIN ? SYMBOLS_J2[5] : SYMBOLS_J2[1]);
				}
	
				if (it->jogador_peao[JOGADOR2][PEAO2] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR2][PEAO2] == WIN ? SYMBOLS_J2[6] : SYMBOLS_J2[2]);
				}
	
				if (it->jogador_peao[JOGADOR2][PEAO3] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR2][PEAO3] == WIN ? SYMBOLS_J2[7] : SYMBOLS_J2[3]);
				}
	
				if (it->jogador_peao[JOGADOR2][PEAO4] != 0)
				{
					(void)printf("%c", it->jogador_peao[JOGADOR2][PEAO4] == WIN ? SYMBOLS_J2[8] : SYMBOLS_J2[4]);
				}
	
				(void)putchar('.');
	
				t = t->next;  // Move to the next node
				i++;
			}
			(void)putchar('\n');
			return;
		}

	/* print first line */
	/* first line starts in position floor(rows/2) */
		unsigned int pos;
		unsigned int left_pos;
		unsigned int right_pos;
		unsigned int pos_l;
		unsigned int pos_r;
		unsigned int i;
		unsigned int k;
		line_rendering line;
	
		/* First outer loop */
		for (line = HEADER ; line <= TAIL ; line++)
		{
			pos = rows / 2U;
			for (i = 0U; i < cols; i++, pos++)
			{
				printCasaLine(line, pos, theBoard);
			}
			(void)putchar('\n');
		}
	
		/* Print intermediate top lines down to middle line inclusive */
		left_pos = (rows / 2U) - 1U;
		right_pos = pos;
		for (i = 0U; i < (rows / 2U); i++, left_pos--, right_pos++)
		{
			for (line = HEADER; line <= TAIL; line++)
			{
				pos_l = left_pos;
				pos_r = right_pos;
				for (k = 0U; k < cols; k++)
				{
					if (k == 0U)
					{
						printCasaLine(line, pos_l, theBoard);
					}
					else if (k == (cols - 1U))
					{
						printCasaLine(line, pos_r, theBoard);
					}
					else
					{
						(void)printf("        "); // Replace this function correctly as per compliance requirements.
					}
				}
				(void)putchar('\n');
			}
		}

	/* Print bottom intermediate lines */
	left_pos = Ncasas - 1U;
	for (i = 0U; i < (rows / 2U) - 1U; i++, left_pos--, right_pos++)
	{        
		for (line = HEADER; line <= TAIL; line++)
		{
			pos_l = left_pos;
			pos_r = right_pos;            
			for (k = 0U; k < cols; k++)
			{
				if (k == 0U)
				{
					printCasaLine(line, pos_l, theBoard);
				}
				else if (k == (cols - 1U))
				{
					printCasaLine(line, pos_r, theBoard);
				}
				else
				{
					/* Replace this function correctly as per compliance requirements. */
					(void)printf("        ");
				}
			}
			(void)putchar('\n');
		}
	}

	/* Print bottom line */
	for (line = HEADER; line <= TAIL; line++)
	{
		pos = left_pos;
		for (i = 0U; i < cols; i++, pos--)
		{
			printCasaLine(line, pos, theBoard);
		}
		(void)putchar('\n');
	}
	/* Replace this function correctly as per compliance requirements. */
	(void)fflush(stdout);
}

/**
	Obtem uma determinada casa do tabuleiro que está definido na lista 
	localizada pela sua posicao
	
	l - Lista de casas do tabuleiro
	idx - Numero de posicao da casa
*/

typedef struct {
	/* Define the structure of 'casa' here */
} casa;

typedef struct node {
	casa item;
	struct node *next;
} node;

typedef struct {
	node *head;
} list;

casa *listCasaAt(const list theBoard, int idx)
{
	/* pointer to a node in the list */
	node *t;

	/* iterator for the for loop */
	int i;

	t = theBoard.head;
	for (i = 0; (t != NULL) && (i < idx); t = t->next)
	{
		i++;
	}

	if (t != NULL)
	{
		return &(t->item);
	}
	else
	{
		return NULL;
	}
}

/**
	Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
	Incluindo peoes presentes na casa e simbolo das casas seguras
	
	line - linha da casa a imprimir
	pos - Numero de posicao da casa a imprimir
	theBoard - Lista contendo o tabuleiro
*/ 

/* Assuming definitions for line_rendering, list, casa, JOGADOR1, PEAO1, etc., exist */

typedef enum {
	HEADER,
	OCCUPANCY_1,
	SAFE_HOUSE,
	OCCUPANCY_2,
	TAIL
} line_rendering;

/* Define the structure of 'casa' here */
/* Assume the following structures are defined correctly */
typedef struct {
	char jogador_peao[2][4]; /* Assuming 2 players and 4 pieces each */
	bool casaSegura;
} casa;

typedef struct node {
	casa item;
	struct node *next;
} node;

typedef struct {
	node *head;
} list;

/* Function prototype for listCasaAt */

void printCasaLine(line_rendering line, int pos, list theBoard) {
	casa *it;

	switch (line) {
		case HEADER: {
			printf("+--%2d--+", pos);
			break;
		}

		case OCCUPANCY_1: {
			it = listCasaAt(theBoard, pos);
			if (it != NULL) {
				printf("| %c%c%c%c |", 
					it->jogador_peao[JOGADOR1][PEAO1] ? 
						(it->jogador_peao[JOGADOR1][PEAO1] == WIN ? SYMBOLS_J1[5] : SYMBOLS_J1[1]) : SYMBOLS_J1[0],
					it->jogador_peao[JOGADOR1][PEAO2] ? 
						(it->jogador_peao[JOGADOR1][PEAO2] == WIN ? SYMBOLS_J1[6] : SYMBOLS_J1[2]) : SYMBOLS_J1[0],
					it->jogador_peao[JOGADOR1][PEAO3] ? 
						(it->jogador_peao[JOGADOR1][PEAO3] == WIN ? SYMBOLS_J1[7] : SYMBOLS_J1[3]) : SYMBOLS_J1[0],
					it->jogador_peao[JOGADOR1][PEAO4] ? 
						(it->jogador_peao[JOGADOR1][PEAO4] == WIN ? SYMBOLS_J1[8] : SYMBOLS_J1[4]) : SYMBOLS_J1[0]);
			}
			break;
		}

		case SAFE_HOUSE: {
			it = listCasaAt(theBoard, pos);
			if (it != NULL) {
				if (it->casaSegura) {
					printf("| **** |");
				} else {
					printf("|      |");
				}
			}
			break;
		}	case OCCUPANCY_2: /* imprime peoes do jogador 2 presentes, na linha 3 */
			{
				const struct casa *it = listCasaAt(theBoard, pos);
				assert(it != NULL);
		
				char symbol1 = SYMBOLS_J2[0];
				char symbol2 = SYMBOLS_J2[0];
				char symbol3 = SYMBOLS_J2[0];
				char symbol4 = SYMBOLS_J2[0];
		
				if (it->jogador_peao[JOGADOR2][PEAO1] != 0) 
				{
					symbol1 = (it->jogador_peao[JOGADOR2][PEAO1] == WIN) ? SYMBOLS_J2[5] : SYMBOLS_J2[1];
				}
		
				if (it->jogador_peao[JOGADOR2][PEAO2] != 0)
				{
					symbol2 = (it->jogador_peao[JOGADOR2][PEAO2] == WIN) ? SYMBOLS_J2[6] : SYMBOLS_J2[2];
				}
		
				if (it->jogador_peao[JOGADOR2][PEAO3] != 0) 
				{
					symbol3 = (it->jogador_peao[JOGADOR2][PEAO3] == WIN) ? SYMBOLS_J2[7] : SYMBOLS_J2[3];
				}
		
				if (it->jogador_peao[JOGADOR2][PEAO4] != 0) 
				{
					symbol4 = (it->jogador_peao[JOGADOR2][PEAO4] == WIN) ? SYMBOLS_J2[8] : SYMBOLS_J2[4];
				}
		
				printf("| %c%c%c%c |", symbol1, symbol2, symbol3, symbol4);
			}
			break;
			case TAIL:
				printf("+------+");
			break;
	}
}

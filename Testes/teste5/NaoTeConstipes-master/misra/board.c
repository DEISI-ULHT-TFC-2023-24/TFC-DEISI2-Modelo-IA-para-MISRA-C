#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "board.h"

#define PEAO1 ((uint8_t)0U)
#define PEAO2 ((uint8_t)1U)
#define PEAO3 ((uint8_t)2U)
#define PEAO4 ((uint8_t)3U)
#define DICE_SIZE ((uint8_t)6U)

/**
 * Nomeia cada linha quando uma casa e desenhada
 * o topo da casa é o HEADER, e o fundo da casa desenhada é o TAIL
 */
typedef enum {
	HEADER = 0,
	OCCUPANCY_1 = 1,
	SAFE_HOUSE = 2,
	OCCUPANCY_2 = 3,
	TAIL = 4
} line_rendering;

typedef struct casa casa;
typedef struct list list;

/**
 * Obtem uma determinada casa do tabuleiro que está definido na lista 
 * localizada pela sua posicao
 *
 * @param[in] theBoard - Lista de casas do tabuleiro
 * @param[in] idx - Numero de posicao da casa
 * @return Pointer to the casa at index idx in theBoard
 */
casa *listCasaAt(list *theBoard, int idx);

/**
 * Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
 * Incluindo peoes presentes na casa e simbolo das casas seguras
 *
 * @param[in] line - linha da casa a imprimir
 * @param[in] pos - Numero de posicao da casa a imprimir
 * @param[in] theBoard - Lista contendo o tabuleiro
 */
void printCasaLine(line_rendering line, int pos, list *theBoard);

#endif /* BOARD_H */

/**
	Simula o dado do jogo
	
	numberOfDices - Numero de dados a jogar
*/

#define DICE_SIZE 6  // Assuming a standard 6-sided dice

int rolldice(int numberOfDices)
{
	if (numberOfDices <= 0 || numberOfDices > (INT_MAX / DICE_SIZE)) {
		// Return -1 or handle the error appropriately
		return -1;
	}

	int i = 0; 
	int sum = 0;

	for (i = 0; i < numberOfDices; i++) {
		int roll = rand() % DICE_SIZE + 1;
		sum += roll;
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

/**/

void boardPrint(const unsigned int rows, const unsigned int cols, list theBoard, const int modo)
{
	typedef char line_rendering;

	extern const char SYMBOLS_J1[];
	extern const char SYMBOLS_J2[];

	unsigned int i, k, pos, right_pos, left_pos, pos_l, pos_r;
	line_rendering line;
	node *t;
	casa *it;

	const int Ncasas = (2U * (cols + rows - 2U)); // Rule 10.3 and Rule 10.4

	// Asserts for validation
	assert((rows >= MIN_ROWS) && ((rows % 2U) != 0U) && "Tabuleiro tem de ter no minimo 3 linhas e impar");
	assert(cols > MIN_COLS && "Numero colunas do tabuleiro tem de ser superior a 4");
	assert(theBoard.length == Ncasas && "Falha na construcao do tabuleiro, demasiado grande");
	assert(theBoard.head != NULL && "Falha na construcao do tabuleiro");

	assert((modo == 0) || (modo == 1)); // Rule 14.3

	if (modo)
	{
		i = 0;
		for (t = theBoard.head; i < Ncasas && t != NULL; t = t->next, i++)
		{
			it = &(t->item);
			printf("%d ", i); 

			if (it->jogador_peao[JOGADOR1][PEAO1] != 0) {
				printf("%c", it->jogador_peao[JOGADOR1][PEAO1] == WIN ? SYMBOLS_J1[5]: SYMBOLS_J1[1]);
			}

			if (it->jogador_peao[JOGADOR1][PEAO2] != 0) {
				printf("%c", it->jogador_peao[JOGADOR1][PEAO2] == WIN ? SYMBOLS_J1[6]: SYMBOLS_J1[2]);
			}

			if (it->jogador_peao[JOGADOR1][PEAO3] != 0) {
				printf("%c", it->jogador_peao[JOGADOR1][PEAO3] == WIN ? SYMBOLS_J1[7]: SYMBOLS_J1[3]);
			}

			if (it->jogador_peao[JOGADOR1][PEAO4] != 0) {
				printf("%c", it->jogador_peao[JOGADOR1][PEAO4] == WIN ? SYMBOLS_J1[8]: SYMBOLS_J1[4]);
			}

			if (it->jogador_peao[JOGADOR2][PEAO1] != 0) {
				printf("%c", it->jogador_peao[JOGADOR2][PEAO1] == WIN ? SYMBOLS_J2[5]: SYMBOLS_J2[1]);
			}

			if (it->jogador_peao[JOGADOR2][PEAO2] != 0) {
				printf("%c", it->jogador_peao[JOGADOR2][PEAO2] == WIN ? SYMBOLS_J2[6]: SYMBOLS_J2[2]);
			}

			if (it->jogador_peao[JOGADOR2][PEAO3] != 0) {
				printf("%c", it->jogador_peao[JOGADOR2][PEAO3] == WIN ? SYMBOLS_J2[7]: SYMBOLS_J2[3]);
			}

			if (it->jogador_peao[JOGADOR2][PEAO4] != 0) {
				printf("%c", it->jogador_peao[JOGADOR2][PEAO4] == WIN ? SYMBOLS_J2[8]: SYMBOLS_J2[4]);
			}

			putchar('.');
		}
		putchar('\n');
		return;
	}

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
	left_pos = (rows / 2U) - 1U;
	right_pos = pos;
	for (i = 0U; i < (rows / 2U); i++, left_pos--, right_pos++) {
		for (line = HEADER; line <= TAIL; line++) {
			pos_l = left_pos;
			pos_r = right_pos;
			for (k = 0U; k < cols; k++) {
				if (k == 0U) {
					printCasaLine(line, pos_l, theBoard);
				} else if (k == (cols - 1U)) {
					printCasaLine(line, pos_r, theBoard);
				} else {
					printf("        ");
				}
			}
			putchar('\n');
		}

	/* print bottom intermediate lines */


	/**/
	left_pos = Ncasas - 1U;
		for (i = 0U; i < ((rows / 2U) - 1U); i++, left_pos--, right_pos++) {
			for (line = HEADER; line <= TAIL; line++) {
				pos_l = left_pos;
				pos_r = right_pos;
				for (k = 0U; k < cols; k++) {
					if (k == 0U) {
						printCasaLine(line, pos_l, theBoard);
					} else if (k == (cols - 1U)) {
						printCasaLine(line, pos_r, theBoard);
					} else {
						printf("        ");
					}
				}
				putchar('\n');
			}
		}
	
	/* print bottom line */
	for (line = HEADER ; line <= TAIL ; line++)
	{
		pos = left_pos;
		for (i = 0U ; i < cols ; i++, pos--)
			printCasaLine(line, pos, theBoard);
		putchar('\n');
	}
	(void)fflush(stdout);
}

/**
	Obtem uma determinada casa do tabuleiro que está definido na lista 
	localizada pela sua posicao
	
	l - Lista de casas do tabuleiro
	idx - Numero de posicao da casa
*/
casa * listCasaAt(list theBoard, int idx)
{
	/* ponteiro para um node da lista */
	Node *t;
	
	/* iterador do ciclo for */
	unsigned int i;

	for (t = theBoard.head, i = 0U ; (t != NULL) && (i < idx) ; t = t-> next, i++)
		;

	return (t != NULL) ? &(t -> item) : NULL;
}

/**
	Imprime o conteudo dentro de uma casa do tabuleiro linha a linha
	Incluindo peoes presentes na casa e simbolo das casas seguras
	
	line - linha da casa a imprimir
	pos - Numero de posicao da casa a imprimir
	theBoard - Lista contendo o tabuleiro
*/


void printCasaLine(line_rendering line, int pos, list theBoard)
{
	/* Valor temporario da casa do tabuleiro que esta a ser processada */
	Casa *it;

	switch((unsigned int)line) {
		case HEADER: /* Print house number on line 0 */
			printf("+--%2d--+", pos);
			break;
		case OCCUPANCY_1: /* Print player 1 pawns present, on line 1 */
			it = listCasaAt(theBoard, (unsigned int)pos);
			assert(it != NULL); // This should be replaced in production code
			printf("| %c%c%c%c |", 
				it->jogador_peao[0][0] ? 
					(it->jogador_peao[0][0] == 'W' ? 
						'A':
						'B'):
					'C',
				it->jogador_peao[0][1] ?
					(it->jogador_peao[0][1] == 'W' ?
						'D':
						'E'):
					'F',
				it->jogador_peao[0][2] ?
					(it->jogador_peao[0][2] == 'W' ?
						'G':
						'H'):
					'I',
				it->jogador_peao[0][3] ?
					(it->jogador_peao[0][3] == 'W' ?
						'J':
						'K'):
					'L');
			break;
		case SAFE_HOUSE: /* Print if the house is safe, on line 2 */
			it = listCasaAt(theBoard, (unsigned int)pos);
			assert(it != NULL); // This should be replaced in production code
			if (it->casaSegura) {
				printf("| **** |");
			} else {
				printf("|      |");
			}
			break;
		case OCCUPANCY_2: /* Print player 2 pawns present, on line 3 */
			it = listCasaAt(theBoard, (unsigned int)pos);
			assert(it != NULL); // This should be replaced in production code
			printf("| %c%c%c%c |", 
				it->jogador_peao[JOGADOR2][PEAO1] ?
					(it->jogador_peao[JOGADOR2][PEAO1] == WIN ?
						SYMBOLS_J2[5]:
						SYMBOLS_J2[1]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO2] ?
					(it->jogador_peao[JOGADOR2][PEAO2] == WIN ?
						SYMBOLS_J2[6]:
						SYMBOLS_J2[2]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO3] ?
					(it->jogador_peao[JOGADOR2][PEAO3] == WIN ?
						SYMBOLS_J2[7]:
						SYMBOLS_J2[3]):
					SYMBOLS_J2[0],
				it->jogador_peao[JOGADOR2][PEAO4] ?
					(it->jogador_peao[JOGADOR2][PEAO4] == WIN ?
						SYMBOLS_J2[8]:
						SYMBOLS_J2[4]):
					SYMBOLS_J2[0]);
			break;
		case TAIL:
			printf("+------+");
			break;
		default:
			/* Add a default case to handle unexpected values */
			break;
	}
}

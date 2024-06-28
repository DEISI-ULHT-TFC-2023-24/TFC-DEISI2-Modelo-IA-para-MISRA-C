#ifndef BOARD_H
#define BOARD_H

#include <stddef.h>  /* Required for NULL */

/* Definitions */
#define SYMBOLS_J1 " abcdABCD"
#define SYMBOLS_J2 " wxyzWXYZ"
#define JOGADOR1 0U
#define JOGADOR2 1U
#define MIN_ROWS 3U
#define MIN_COLS 4U

/* Messages */
#define INVAL_PARAMS "ERRO: Parametros invalidos"
#define INVAL_MOVE "Comando Invalido"
#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "
#define FILE_ERR1 "Ficheiro nao encontrado \n"
#define FILE_ERR2 "Erro na leitura do ficheiro\n"
#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"

/* Enum for state of a pawn */
typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;

/* Structure for a board square */
typedef struct
{
	state jogador_peao[2][4];   /* Player 1 and 2 pawns present */
	state casaSegura;           /* Indicates if the square is safe */
} casa;

/* Node structure for a linked list holding board squares */
typedef struct node_t
{
	casa item;                  /* Information held in a board square */
	struct node_t *next;        /* Pointer to the next node */
} node_t;

/* Linked list structure representing the board */
typedef struct 
{
	node_t *head;               /* Pointer to the first node */
	node_t *tail;               /* Pointer to the last node */
	int length;                 /* Number of nodes in the list */
} list;

/* Function prototypes */
int rolldice(int numberOfDices);
void boardPrint(unsigned int rows, unsigned int cols, list theBoard, int modo);

#endif /* BOARD_H */
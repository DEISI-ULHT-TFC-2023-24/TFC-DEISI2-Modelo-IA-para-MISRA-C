#ifndef __BOARD_H__
#define __BOARD_H__

// Definitions that may or may not be useful:
#define SYMBOLS_J1 " abcdABCD"
#define SYMBOLS_J2 " wxyzWXYZ"
#define JOGADOR1 0
#define JOGADOR2 1
#define MIN_ROWS 3
#define MIN_COLS 4

// Message to be displayed when main parameters are invalid
// The program displays the message and terminates
#define INVAL_PARAMS "ERRO: Parametros invalidos"

// Message displayed whenever the user makes an invalid move or command
#define INVAL_MOVE "Comando Invalido"

#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "

// Message displayed if the file opening fails
#define FILE_ERR1 "Ficheiro nao encontrado \n"
// Message displayed if the file reading fails
#define FILE_ERR2 "Erro na leitura do ficheiro\n"

#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"

/** 
	State of a pawn
	FALSE - Not present in this board square
	TRUE - Present in this board square
	WIN - Pawn has completed a lap and is in the home square
*/
typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;

/**
	Board square
*/
typedef struct
{
	/** player 1 and 2 and their pawns 1 to 4 present TRUE or not FALSE */
	state jogador_peao[2][4];

	/** Indicates whether the square is safe and pawns cannot be taken */
	state casaSegura;
} casa;

/**
	Node of a list, containing a board square
*/
typedef struct _node
{
	/* Information retained in a board square */
	casa item;

	/* Pointer to the next node, the next board square */
	struct _node * next;
} node;

/**
	List of nodes, it is a list of squares, thus a board
*/
typedef struct 
{
	/* Pointer to the first node of the list, the first board square */
	node * head;

	/* Pointer to the last node of the list, the last board square */
	node * tail;

	/* Number of nodes or number of board squares */
	int length;
} list;

/**
	Simulate the game's dice

	numberOfDices - Number of dice to roll
*/
int rolldice(int numberOfDices);

/**
	Print the board on the screen

	rows - Number of rows on the board
	cols - Number of columns on the board
	theBoard - List containing the board squares
	modo - mode of board presentation
*/
void boardPrint(const unsigned int rows, const unsigned int cols, list theBoard, const int modo);

#endif
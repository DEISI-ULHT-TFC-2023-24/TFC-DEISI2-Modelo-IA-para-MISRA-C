#ifndef __BOARD_H__
#define __BOARD_H__

/* To adhere to Rule 5.5, avoid using the same names for different constants */
#define SYMBOLS_PLAYER1 " abcdABCD"
#define SYMBOLS_PLAYER2 " wxyzWXYZ"
#define PLAYER1 0
#define PLAYER2 1
#define MIN_ROWS_BOARD 3
#define MIN_COLS_BOARD 4

#define INVALID_PARAMS_MESSAGE "ERRO: Parametros invalidos"

#define INVALID_MOVE_MESSAGE "Comando Invalido"

#define EXIT_MESSAGE "Fim do jogo"
#define PLAYER1_WINS_MESSAGE "Jogador 1 Ganhou!"
#define PLAYER2_WINS_MESSAGE "Jogador 2 Ganhou!"
#define PLAYER_DICE_MESSAGE "Jogador lancou dados com valor "

#define FILE_ERROR1_MESSAGE "Ficheiro nao encontrado \n"
#define FILE_ERROR2_MESSAGE "Erro na leitura do ficheiro\n"

#define PLAYER1_MOVE_MESSAGE "------ Jogador 1 ------"
#define PLAYER2_MOVE_MESSAGE "------ Jogador 2 ------"


typedef enum {STATE_FALSE = 0, STATE_TRUE = 1, STATE_WIN = 2} pawn_state;

typedef struct
{
	pawn_state player_pawn[2][4];
	pawn_state safe_house;
} House;

typedef struct Node
{
	House item;
	struct Node * next;
} Node;

typedef struct 
{
	Node * head;
	Node * tail;
	int length;
} List;


int roll_dice(int numberOfDices);

void print_board(const unsigned int rows, const unsigned int cols, List theBoard, const int modo);

#endif
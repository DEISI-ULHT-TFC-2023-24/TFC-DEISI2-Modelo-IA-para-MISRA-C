#ifndef __BOARD_H__
#define __BOARD_H__

/* definicoes que podem, ou nao, ser uteis: */
#define SYMBOLS_J1 " abcdABCD"
#define SYMBOLS_J2 " wxyzWXYZ"
#define JOGADOR1 0
#define JOGADOR2 1
#define MIN_ROWS 3
#define MIN_COLS 4

/* mensagem que deve ser apresentada qundo os parametros do main nao sao validos
   o programa apresenta a mensagem e termina */
#define INVAL_PARAMS "ERRO: Parametros invalidos"

/* mensagem apresentada sempre que o utilizador faz uma jogada ou comando invalido */
#define INVAL_MOVE "Comando Invalido"

#define EXIT_MSG "Fim do jogo"
#define PL1_WINS "Jogador 1 Ganhou!"
#define PL2_WINS "Jogador 2 Ganhou!"
#define PL_DICE "Jogador lancou dados com valor "

/* mensagem apresentada se a abertura do ficheiro falhar */
#define FILE_ERR1 "Ficheiro nao encontrado \n"
/* mensagem apresentada se a leitura do ficheiro falhar */
#define FILE_ERR2 "Erro na leitura do ficheiro\n"

#define PL1_MOVE "------ Jogador 1 ------"
#define PL2_MOVE "------ Jogador 2 ------"

typedef enum {FALSE = 0, TRUE = 1, WIN = 2} state;

typedef struct
{
	state jogador_peao[2][4];
	state casaSegura;
} casa;

typedef struct node_t
{
	casa item;
	struct node_t * next;
} Node;

typedef int32_t MyInt;

typedef struct 
{
	Node * head;
	Node * tail;
	MyInt length;
} list;

MyInt rolldice(MyInt numberOfDices);

void boardPrint(const MyInt rows, const MyInt cols, list theBoard, const MyInt modo);

#endif
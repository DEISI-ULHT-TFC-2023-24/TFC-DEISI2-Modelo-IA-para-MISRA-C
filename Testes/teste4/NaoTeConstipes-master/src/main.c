#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "board.h"

#define DIM 1280

#define PRINTMOVE(P) P ? puts(PL2_MOVE) :  puts(PL1_MOVE)

/* list simbolizando o tabuleiro com peoes e toda informacao */
list theList;

/* jogada indicanco para jogador 1 e 2, a casa em que ta peao 1 a 4 */
node * jogada[2][4];
node * casamae[2];
int seguros[100];
char symbols[][10] = {{SYMBOLS_J1}, {SYMBOLS_J2}};

static int mode = 0;

void listInit(list * l)
{
	assert(l != NULL);

	l -> head = l -> tail = NULL;
	l -> length = 0;
}

void listInsert(list * l, casa x)
{
	node * new = malloc(sizeof(node));
	new -> item = x;
	assert(l != NULL);

	new->next = l->head;
	l -> head = new;

	if (l->tail == NULL)
		l->tail = new;

	l -> tail -> next = l -> head;

	l->length ++;
}

casa itemCreate(state b1, state b2, state b3, state b4, state r1, state r2, state r3, state r4, state casaSegura)
{
	casa i = {{{b1, b2, b3, b4}, {r1, r2, r3, r4}}, casaSegura};
	return i;
}

void exitMSG(char *str)
{
	puts(str);
	exit(0);
}

void ultrapassa(int jogador, node * casa)
{
	for (int i = 0; i < 4; i++)
	{
		if ((casa->item.jogador_peao[jogador][i] == TRUE) && (casa->item.casaSegura == FALSE))
		{
			//printf ("Ultrapassa %d\n", i);
			casa->item.jogador_peao[jogador][i] = FALSE;
			casamae[jogador]->item.jogador_peao[jogador][i] = TRUE;
			jogada[jogador][i] = casamae[jogador];
		}
	}	
}

int gameMove(int jogador, int dice, char idPeao)
{
	int iPeao;
	state vitoria = TRUE;
	node * casaPresente = NULL;
	node * proximaCasa = NULL;

	iPeao = idPeao - symbols[jogador][1];

	/* Verifica se o valor do peao e valido */
	if ((iPeao < 0) || (iPeao > 3))
		return 3;
	
	casaPresente = jogada[jogador][iPeao];
	proximaCasa = casaPresente;

	if(casaPresente->item.jogador_peao[jogador][iPeao] == WIN) 
		return 3; 	// Este Peao ja terminou percurso!


	/* Avanca cases definido pelo dice */
	for (int i = 0; i < dice; i++)
	{
		proximaCasa = proximaCasa->next;
		if(proximaCasa != casamae[jogador])
			ultrapassa(!jogador, proximaCasa);
		else
			break; 	/* Chegou ao fim do tabuleiro */
	}

	/* Retira peao da casa presente e poe na proximaCasa */
	casaPresente->item.jogador_peao[jogador][iPeao] = FALSE;
	if (proximaCasa != casamae[jogador])
		proximaCasa->item.jogador_peao[jogador][iPeao] = TRUE;
	else
		/* chegou ao fim do percurso, vitoria para este peao */		
		proximaCasa->item.jogador_peao[jogador][iPeao] = WIN;

	/* Atualiza jogada */
	jogada[jogador][iPeao] = proximaCasa;

	/*Verificacao vitoria */
	for (int i = 0; i < 4; i++)
	{
		if (jogada[jogador][i]->item.jogador_peao[jogador][i] != WIN)
			vitoria = FALSE;
	}

	if (vitoria)
		return jogador+1;

	return 0;
}

int addSafeHouse(int house)
{
	int i = 0;
	
	//verifica se valor de safehouse é invalido
	if(house > theList.length)
	{
		return 0;
	}
	
	// Ir ao fim da lista
	while(seguros[i])
	{
		// verifica se safe house ja existe
		if(seguros[i] == house)
		{
			return -1;
		}
		i++;
		
		// Verifica se esta cheia a lista
		if(i >= theList.length)
		{			
			return 0;
		}
	}
	seguros[i] = house;
	return 1;
}


int readFile(char *fname)
{
	FILE* ptr = NULL;
	int i = 0;
	int casa = 0;
	int status = 1;

	// removing defaults seguros
	seguros[0] = 0;
	seguros[1] = 0;
 
    // Opening file in reading mode
    ptr = fopen(fname, "r");
 
    if (NULL == ptr) {
        printf(FILE_ERR1);
        return 0;
    }
 
    // Printing what is written in file
    // character by character using loop.
    while(status != EOF)
	{
		status = fscanf(ptr, "%d", &casa);
		if (status == 1)
		{
			if(!addSafeHouse(casa))
			{
				printf(FILE_ERR2);
				return 0;
			}
			i++;
		}
		else if (status != EOF)
		{			
			printf(FILE_ERR2);		
			return 0;
		}
	}

	/* Marcando ultimo elemento da lista */
	seguros[i] = 0;
    fclose(ptr);
	return 1;
}

int writeFile(char *fname)
{
	FILE* ptr = NULL;
	int i = 0;
 
    // Opening file in writing mode
    ptr = fopen(fname, "w");
 
    if (NULL == ptr) {
        printf("Erro na abertura do ficheiro");
        return 0;
    }
 
	// printing content of array seguros
 	while(seguros[i])
	{
		fprintf(ptr, "%d\n", seguros[i]);
		i++;
	}
	
    fclose(ptr);
	return 1;
}

int isSafeHouse(int place)
{
	int i = 0;
	while(seguros[i])
	{
		if(place == seguros[i])
			return 1;
		i++;
	}
	return 0;
}

void criaTabuleiro(list *tabuleiro, int rows, int cols)
{
	for (int p = 2*(cols+rows-2)-1 ; p >=0 ; p--)
	{
		/* Adiciona Casa Mae de jogador 1 */
		if (p == 0)
		{			
			listInsert(tabuleiro, itemCreate(TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, TRUE));
			/* indica que na jogada inicial onde  estao os peoes do jogador 1*/
			for (int i = 0; i < 4; i++)
			{
				jogada[JOGADOR1][i] = tabuleiro->head;
			}
			casamae[JOGADOR1] = tabuleiro->head;
		}
		/* Adiciona Casa Mae de jogador 2 */
		else if (p == (2*(cols+rows-2)) / 2)
		{
			listInsert(tabuleiro, itemCreate(FALSE, FALSE, FALSE, FALSE, TRUE, TRUE, TRUE, TRUE, TRUE));
			/* indica que na jogada inicial onde  estao os peoes do jogador 2*/
			for (int i = 0; i < 4; i++)
			{
				jogada[JOGADOR2][i] = tabuleiro->head;
			}
			casamae[JOGADOR2] = tabuleiro->head;
		}
		/* Adiciona casas seguras */
		else if (isSafeHouse(p))
			listInsert(tabuleiro, itemCreate(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, TRUE));
		else
			listInsert(tabuleiro, itemCreate(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE));
	}
}

void apagaTabuleiro (node * casa){
	
	if (casa == NULL)
		return;
	apagaTabuleiro(casa->next);
	
	free(casa);
}


void printMenuInitial()
{
	puts("+--------------------------------------------------------+");
	puts("|         Nao Te Constipes - configs                     |");
	puts("+--------------------------------------------------------+");
	puts("| confadd <numero>    - adicionar casa segura            |");
	puts("| confsave <nome>     - gravar ficheiro de casas seguras |");
	puts("| confboard <numero>  - mostrar o tabuleiro              |");
	puts("| confstart <numero>  - iniciar o jogo                   |");
	puts("| confmenu            - imprimir menu                    |");
	puts("+--------------------------------------------------------+");
	fflush(stdout);
}

void printMenu()
{
	puts("+------------------------------------+");
	puts("|         Nao Te Constipes           |");
	puts("+------------------------------------+");
	puts("| <id do peao> (abcd, xyzw)          |");
	puts("| s - sair                           |");
	puts("| h - imprimir menu                  |");
	puts("+------------------------------------+");
	fflush(stdout);
}

void configuration(int rows, int cols)
{
	char comandos[DIM];
	char cmd[DIM];
	char option[DIM];
	int returnValue;
	
	printMenuInitial();
	while(1)
	{
		// cria tabuleiro com ultimos valores de configuracao
		if(theList.tail != NULL)
			theList.tail->next = NULL;
		apagaTabuleiro(theList.head);
		listInit(&theList);
		criaTabuleiro(&theList, rows, cols);
		
		printf(">");
		fgets(comandos, DIM, stdin);		
		returnValue= sscanf(comandos, "%s%s", cmd, option);
		fflush(stdout);
		if (cmd[5] == 'd') //confadd
		{
			if (returnValue == 1)
			{				
				puts(INVAL_PARAMS);
				cmd[5] ='e';
			}
			else		
				if(!addSafeHouse(atoi(option)))
					puts(INVAL_PARAMS);
				
		}
		if (cmd[5] == 'a') //confsave
		{	
			if (returnValue == 1)
			{				
				puts(INVAL_PARAMS);
				cmd[5] ='e';
			}
			else
				writeFile(option);
		}
		if (cmd[5] == 'o') //confboard
		{
			if (returnValue == 1)
				boardPrint(rows, cols, theList, mode);
			else
			if (atoi(option) > 1)
			{				
				puts(INVAL_PARAMS);
				cmd[5] ='e';
			}
			else
				boardPrint(rows, cols, theList, atoi(option));
		}
		if (cmd[5] == 't') //confstart
		{			
			if (returnValue != 1)
				if(atoi(option) >= 0)
					srand(atoi(option));
			return;
		}			
		if (cmd[5] == 'e') //confmenu
		{
			printMenuInitial();
			continue;
		}
	}
}

void game(int rows, int cols)
{
	int dice;
	int nextMove = JOGADOR1;
	char comandos[DIM];
	char option;
	int returnValue = 0;

	boardPrint(rows, cols, theList, mode);
	printMenu();
	dice = rolldice(2);

	while(1)
	{
		PRINTMOVE(nextMove);
		printf(PL_DICE);
		printf ("%d \n", dice);

		printf(">");
		fgets(comandos, DIM, stdin);		
		sscanf(comandos, "%c", &option);

		if (option == 's')
			exitMSG(EXIT_MSG);
		
		if (option == 'h')
		{
			printMenu();
			continue;

		}
		returnValue = gameMove(nextMove, dice, option);

		switch(returnValue)
		{
		case 0:
			// normal move
			break;
		case 1:
			boardPrint(rows, cols, theList, mode);
			puts(PL1_WINS);
			return;
			break;

		case 2:
			boardPrint(rows, cols, theList, mode);
			puts(PL2_WINS);
			return;
			break;

		case 3:
			puts(INVAL_MOVE);
			fflush(stdout);
			continue;  // volta a esperar pelo input sem mostrar o menu novamente
		}

		nextMove = !nextMove;

		boardPrint(rows, cols, theList, mode);
		dice = rolldice(2);
	}
}


int main(int argc, char *argv[])
{
	int seed = 1;
	int rows = 3, cols = 7;

	// default safe house
	seguros[0] = 0;
	seguros[1] = 0;
	seguros[2] = 0;


	if (argc >=2)
	{
		if (sscanf(argv[1], "%d", &seed) != 1)
			exitMSG(INVAL_PARAMS);
	}

	if (argc >=3)
	{
		if (sscanf(argv[2], "%d", &mode) != 1)
			exitMSG(INVAL_PARAMS);
	}

	if (argc >=4)
	{
		if (sscanf(argv[3], "%d", &rows) != 1)
			exitMSG(INVAL_PARAMS);
		
		if (rows < MIN_ROWS || rows % 2 == 0)
			exitMSG(INVAL_PARAMS);
	}

	if (argc >=5)
	{
		if (sscanf(argv[4], "%d", &cols) != 1)
			exitMSG(INVAL_PARAMS);

		if (cols < MIN_COLS)
			exitMSG(INVAL_PARAMS);
	}

	listInit(&theList);
	criaTabuleiro(&theList, rows, cols);

	if (argc >= 6)
	{
		if (!readFile(argv[5]))
			exit(0);
	}

	srand(seed); // initialize seed
	configuration(rows, cols);
	game(rows, cols);

	puts(EXIT_MSG);
	exit(0);
}

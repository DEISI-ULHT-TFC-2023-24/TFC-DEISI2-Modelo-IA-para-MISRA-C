# NaoTeConstipes

## Instrucoes para jogar

Não Te Constipes é um jogo de tabuleiro para dois jogadores, em que cada jogador tem uma família de 4 peões:
   - O jogador 1 é dono dos peões identificados pelas letras `a`, `b`, `c` e `d`.
   - O jogador 2 é dono dos peões identificados pelas letras `x`, `y`, `z` e `w`.

No início do jogo, os 4 peões de cada jogador estão na sua casa de partida, em pontas opostas do tabuleiro (casas 0 e 8). A cada jogada, os jogadores lançam os dados alternadamente e escolhem um dos seus peões para se movimentar. O peão escolhido, avança o número de casas que saiu no lançamento dos dados. 

O objectivo de cada jogador é que os seus 4 peões completem uma volta ao tabuleiro. Ganha o primeiro jogador a conseguir esse feito.

No entanto, se um peão for ultrapassado por um peão da equipa adversária, fica _constipado_ e tem de voltar para a sua casa de partida.

Ao correr o programa será criado o tabuleiro inicial, com o seguinte formato:

```
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      ||      ||      ||      ||      |
|      || **** || **** ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
| abcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      ||      ||      ||      ||      |
|      ||      || **** ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
```

E irá aparecer o seguinte menu:

```
+------------------------------------+
|         Nao Te Constipes           |
+------------------------------------+
| <id do peao> (abcd, xyzw)          |
| s - sair                           |
| h - imprimir menu                  |
+------------------------------------+
```

Para jogador basta selecionar o peão, o valor do dado é automaticamente gerado.
  
Assim para jogar o peão 'a', basta pressionar a tecla 'a' seguido de 'enter', e pode acontecer o seguinte (depende do valor do dado, aqui dado deu valor 12):

```
 +------------------------------------+
|         Nao Te Constipes           |
+------------------------------------+
| <id do peao> (abcd, xyzw)          |
| s - sair                           |
| h - imprimir menu                  |
+------------------------------------+
a
------ Jogador 1 ------
Dados: 12
>Game move

Jogando jogador 0, peao 0, dado 12
+-- 1--++-- 2--++-- 3--++-- 4--++-- 5--++-- 6--++-- 7--+
|      ||      ||      ||      ||      ||      ||      |
|      || **** || **** ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
+-- 0--+                                        +-- 8--+
|  bcd |                                        |      |
| **** |                                        | **** |
|      |                                        | wxyz |
+------+                                        +------+
+--15--++--14--++--13--++--12--++--11--++--10--++-- 9--+
|      ||      ||      || a    ||      ||      ||      |
|      ||      || **** ||      ||      ||      ||      |
|      ||      ||      ||      ||      ||      ||      |
+------++------++------++------++------++------++------+
```

 O peão 'a' foi para a casa 12.

As casa com asteriscos sao casas seguras em que os peoes nao conseguem _comer_ os outros quando ultrapassam.
Ganha quando 4 peoes dao a volta ao circuito.
 
 Existe um ficheiro de configuracao para definir casas seguras, ver config.txt
 
  Enjoy!
  

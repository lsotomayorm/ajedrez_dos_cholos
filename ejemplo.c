#include "chess.h"
#include "figures.h"
#include<stdlib.h>
#include<stdio.h>

void display(){

  /*char*** board2 = (char***)malloc(sizeof(char**) * 8);
  for(int i = 0; i < 8; i++){
    board2[i] = pawn;
    }*/

  char** row = repeatH(whiteSquare, 8);
  char** board = repeatV(row, 8);

  char** pawnTest = reverse(pawn);
  *board = *pawnTest;
  //board = superImpose(pawnTest, board);

  char** whiteSquareTest = whiteSquare;
  printf("Marca 1\n");
  printf("Direccion del puntero char a puntero: %p\n", (void*)&whiteSquareTest);
  printf("Direccion del puntero char a puntero: %p\n", (void*)whiteSquareTest);
  printf("Direccion del puntero char a puntero: %p\n", (void*)*whiteSquareTest);
  printf("Contenido: %c\n", **whiteSquareTest);
  printf("Marca 2\n");
  interpreter(board);
}

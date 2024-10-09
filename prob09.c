#include "chess.h"
#include "figures.h"
#include <stdio.h>

#define SIZE 9

struct Piezas{
  char** piece;
  int fila;
  int columna;
};

void display(){
  struct Piezas piezas[SIZE] = {
    {reverse(queen), 0, 5},
    {reverse(king), 0, 7},
    {reverse(rook), 1, 0},
    {reverse(rook), 1, 4},
    {pawn, 2, 4},
    {queen, 2, 7},
    {reverse(pawn), 3, 1},
    {reverse(pawn), 3, 2},
    {rook, 3, 5}
  };
  char** blackSquare = reverse(whiteSquare);
  char** squareStart = whiteSquare;
  char** row = NULL;
  char** board = NULL;
  char** piezaTemp = NULL;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      squareStart = reverse(squareStart);
      piezaTemp = squareStart;
      for(int k=0; k < SIZE; k++){
        if(piezas[k].fila == i && piezas[k].columna == j){
          squareStart = superImpose(piezas[k].piece, squareStart);
        }
      }
      if(row == NULL)
        row = squareStart;
      else
        row = join(row, squareStart);
      squareStart = piezaTemp;
    }
    if(board == NULL) board = row;
    else board = up(board, row);
    row = NULL;
    squareStart = reverse(squareStart);
  }
  interpreter(board);
}

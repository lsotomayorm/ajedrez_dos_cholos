#include "chess.h"
#include "figures.h"
#include <stdio.h>

struct Piezas{
  char** piece;
  int fila;
  int columna;
};

void display(){
  struct Piezas piezas[16] = {
    {reverse(queen), 0, 5},
    {reverse(king), 0, 7},
    {reverse(rook), 1, 2},
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
      for(int k=0; k < 16; k++){
        if(piezas[k].fila == i && piezas[k].columna == j){
          squareStart = superImpose(piezas[k].piece, squareStart);
        }
      }
      row = join(row, squareStart);
      squareStart = piezaTemp;
    }
    if(board == NULL) board = row;
    else board = up(board, row);
  }
  interpreter(board);
}

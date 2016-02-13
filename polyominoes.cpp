#include <stdio.h>
#include "polyominoes.h"

void Square::print(){
    printf("Square is (%d,%d)\n", x, y);
};

void Polyomino::print(){
  printf("Polynomino:\n");
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    it->print();
  }
  printf("\n");
};

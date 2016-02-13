#include <stdio.h>
#include <math.h>
#include "polyominoes.h"

#ifndef M_PI
#define M_PI 3.14159
#endif

void Square::print(){
    printf("Square is (%.2f,%.2f)\n", x, y);
};

void Polyomino::print(){
  printf("Polynomino:\n");
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    it->print();
  }
  printf("\n");
};

void Polyomino::translate(const int x, const int y){
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    it->x += x;
    it->y += y;
  }
}

void Polyomino::rotate(const double d){
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    const double x_orig = it->x;
    const double y_orig = it->y;
    it->x = x_orig * cos(d * M_PI / 180) - y_orig * sin(d * M_PI / 180);
    it->y = x_orig * sin(d * M_PI / 180) + y_orig * cos(d * M_PI / 180);
  }
}



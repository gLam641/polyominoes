#include <stdio.h>
#include <algorithm>
#include <math.h>
#include "polyominos.h"

#ifndef M_PI
#define M_PI 3.14159
#endif

void Square::print(){
  printf("Square is (%d,%d)\n", x, y);
}

void Square::translate(const int x, const int y){
  this->x += x;
  this->y += y;
}

bool Polyomino::isEqual(Polyomino& p){
  for(int i = 0; i < 4; i++){
    bool isExact = true;
    for(unsigned int i = 0; i < p.getSquares().size(); ++i){
      if(p.getSquares()[i].x != vSquares[i].x ||
         p.getSquares()[i].y != vSquares[i].y){
        isExact = false;
        break;
      }
    }
    if(isExact) return true;

    this->rotate(90);
    this->normalize();
  }

  return false;
}

void Polyomino::print(){
  printf("Polynomino:\n");
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    it->print();
  }
  printf("\n");
}

void Polyomino::drawASCII(){
  int len = vSquares.size();
  std::vector<std::vector<int>> squareMatrix;
  //int squareMatrix[len][len];
  // Untested
  for(auto &i : squareMatrix){
      std::fill(i.begin(), i.end(), 0);
  }

  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    squareMatrix[it->x][it->y] = 1;
  }

  printf("---------------------------\n");
  for(int row = len - 1; row > -1; --row){
    for(int col = 0; col < len; ++col){
      if(squareMatrix[col][row] == 1)
        printf("x");
      else
        printf("-");
    }
    printf("\n");
  }
  printf("\n---------------------------\n");
}

// Perhaps not the best way to copy vector and insert element
Polyomino Polyomino::generatePolyomino(Square sNew) const{
  bool isAdded = false;
  std::vector<Square> vSquaresNew;
  for(std::vector<Square>::const_iterator it = this->vSquares.begin(); it != this->vSquares.end(); ++it){
    Square sOld = {it->x, it->y};
    if(!isAdded  &&
       (sNew.y < sOld.y || (sNew.y == sOld.y && sNew.x < sOld.x))){
      isAdded = true;
      vSquaresNew.push_back(sNew);
    }
    vSquaresNew.push_back(*it);
  }
  if(!isAdded) vSquaresNew.push_back(sNew);

  return Polyomino(vSquaresNew);
}

void Polyomino::translate(const int x, const int y){
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    it->x += x;
    it->y += y;
  }
}

void Polyomino::rotate(const float d){
  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    const float x_orig = it->x;
    const float y_orig = it->y;
    it->x = floor(x_orig * cos(d * M_PI / 180) - y_orig * sin(d * M_PI / 180) + 0.5);
    it->y = floor(x_orig * sin(d * M_PI / 180) + y_orig * cos(d * M_PI / 180) + 0.5);
  }
}

bool Polyomino::isSquareEmpty (const Square& square) const{
  for(std::vector<Square>::const_iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    if(it->x == square.x && it->y == square.y) return false;
  }
  return true;
}

bool compareSquares(Square s1, Square s2){
  if(s1.y < s2.y || (s1.y == s2.y && s1.x <= s2.x)) return true;
  return false;
}

void Polyomino::normalize(){
  float dX = 0.0;
  float dY = 0.0;

  for(std::vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
    if(dX > it->x) dX = it->x;
    if(dY > it->y) dY = it->y;
  }

  this->translate(-dX, -dY);
  std::sort(vSquares.begin(), vSquares.end(), compareSquares);
}


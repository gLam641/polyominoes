#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

// Squares are defined by the bottom left corner 'coordinates'
struct Square{
  double x;
  double y;

  const static int x_size = 1;
  const static int y_size = 1;
    
  void print();
};

// A std::vector of connected squares
// Connected-ness is not checked here
class Polyomino{

private:
  std::vector<Square> vSquares;

public:
  Polyomino(std::vector<Square> squares){
    vSquares = squares;
  };

  std::vector<Square> getSquares(){ return vSquares; }

  void print();
  void translate(const int x, const int y);
  void rotate(const double d);  // Rotation cc by degree d
};

#endif


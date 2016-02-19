#ifndef POLYOMINO_H
#define POLYOMINO_H

#include <vector>

class QGroupBox;

// Squares are defined by the bottom left corner 'coordinates'
struct Square{
  int x;
  int y;

  const static int x_size = 1;
  const static int y_size = 1;

  void print();

  void translate(const int x, const int y);
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

  // Checks all 4 rotational equivalent
  bool isEqual(Polyomino& p);

  std::vector<Square> getSquares(){ return vSquares; }

  void print();
  void drawASCII();
  void translate(const int x, const int y);
  void rotate(const float d);  // Rotation cc by degree d

  // Check if square is used in this polyomino after transformation
  bool isSquareEmpty (const Square& square) const;

  // Translate Polyomino such that its minimum x value is 0 and minimum y
  // value is 0
  void normalize();

  // Generate new Polyomino by inserting a new square
  Polyomino generatePolyomino(Square sNew) const;
};

#endif // POLYOMINO_H

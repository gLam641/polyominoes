#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

// Squares are defined by the bottom left corner 'coordinates'
// All Squares are of size 1,1
struct Square{
  int x;
  int y;
    
  void print(){
    printf("Square is (%d,%d)\n", x, y);
  }
};

// A vector of connected squares
// Currently, no validation for connectedness
class Polyomino{

private:
  vector<Square> vSquares;

public:
  Polyomino(vector<Square>& squares){
    vSquares = squares;
/*
    for(int i = 0; i < squares.size(); i++)
      vSquares.push_back(squares[i]);
*/
  } 

  ~Polyomino(){
  }

  vector<Square> getSquares(){ return vSquares; }

  void print(){
    printf("Polynomino:\n");
    for(vector<Square>::iterator it = vSquares.begin(); it != vSquares.end(); ++it){
      it->print();
    }
    printf("\n");
  }

};

int main(){
  Square s1 = {1, 1};
  Square s2 = {2, 2};
  Square s3 = {3, 3};
  vector<Square> v;
  v.push_back(s1);
  v.push_back(s2);
  v.push_back(s3);
  Polyomino p(v);
 
  p.print();
}

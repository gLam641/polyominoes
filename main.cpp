#include <stdio.h>
#include <unordered_map>
#include "polyominoes.h"
#include <iostream>

using namespace std;

#ifndef P_MAP

typedef std::unordered_map<size_t, Square> pMap;

#endif

// Compute all Polyomino possible by adding a square to all
// possible 'empty' locations in each of the set of n-1 polyominoes
void computePolyominoes(const unsigned int nSquares, vector<vector<Polyomino>>& vPolyAll){
  // check base case and already computed cases
  if(nSquares == 1 || nSquares == 2) return;
  if(nSquares <= vPolyAll.size()) return;

  // compute the polyominoes for the 1 smaller set if not yet computed
  if(nSquares - 1 > vPolyAll.size()) computePolyominoes(nSquares - 1, vPolyAll);
  

  vector<Square> vSquares;
  vector<Polyomino>* vPolyNLess1 = &vPolyAll[nSquares - 1];
  for(unsigned int i = 0; i < vPolyNLess1->size(); ++i){
    vector<Square>* vSquaresNLess1 = (*vPolyNLess1)[i].getSquares();
    for(unsigned int j = 0; j < vSquaresNLess1->size(); ++i){
      Square s = (*vSquaresNLess1)[j];
      //--s.x;
      return;
    } 
  }
};

void testTranslateRotate(Polyomino p){
  p.print();
  printf("Translating -1, -1\n");
  p.translate(-1, -1);
  p.print();
  printf("Rotating 90%%\n");
  p.rotate(90);
  p.print();
};

int main(){
  Square s1 = {1, 1};
  Square s2 = {1, 2};
/*
  pMap mSquares;

  mSquares.insert(make_pair(1,s1));
  mSquares.insert(make_pair(2,s2));
  mSquares.insert(make_pair(3,s3));
*/

  // vector of all polyominoes 
  vector<vector<Polyomino>> vPolyAll;

  // base cases
  // 1 square
  vector<Square> vSquares1;
  vSquares1.push_back(s1);
  Polyomino p1(vSquares1);
  vector<Polyomino> vPoly1;
  vPoly1.push_back(p1);
  vPolyAll.push_back(vPoly1);

  // 2 squares
  vector<Square> vSquares2;
  vSquares2.push_back(s1);
  vSquares2.push_back(s2);
  Polyomino p2(vSquares2);
  vector<Polyomino> vPoly2;
  vPoly2.push_back(p2);
  vPolyAll.push_back(vPoly2);
 
  int nSquares;
  cout << "Please enter the number of squares" << endl;
  cin >> nSquares;  

  computePolyominoes(nSquares, vPolyAll);

  cout << "Computing ..." << endl
       << "There are " 
       << vPolyAll[nSquares - 1].size()
       << " polyominoes for " 
       << nSquares << " squares" << endl;
 
}



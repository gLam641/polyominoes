#include <stdio.h>
#include <unordered_map>
#include "polyominoes.h"
#include <iostream>

using namespace std;

#ifndef P_MAP

typedef std::unordered_map<size_t, Square> pMap;

#endif

// Check if adding a square at the specified square + transform makes a 
// new polyomino. If yes, store it in table
void FindNewPolyomino(Square& s, const int transX, const int transY,
                      const Polyomino& polyNLess1,
                      vector<Polyomino>& vPolyN){
  s.translate(transX, transY);
  if(polyNLess1.isSquareEmpty(s)){
    // Insert in the appropriate place. 
    // Translate if new square is on the boundary
    Polyomino genP = polyNLess1.generatePolyomino(s);
    genP.translate(s.x < 0 ? -s.x : 0, 
                   s.y < 0 ? -s.y : 0);
    
    bool isNew = true; 

    // Check if polyomino is new. Add if new
    for(vector<Polyomino>::iterator it = vPolyN.begin(); it != vPolyN.end(); ++it){
      if(it->isEqual(genP)){
        isNew = false;
	break;
      }
    }

    if(isNew){ 
      //genP.drawASCII();
      vPolyN.push_back(genP);
    }
  }
  s.translate(-transX, -transY);
}

// Compute all Polyomino possible by adding a square to all
// possible 'empty' locations in each of the set of n-1 polyominoes
void ComputePolyominoes(const unsigned int nSquares, vector<vector<Polyomino>>& vPolyAll){
  // check base case and already computed cases
  if(nSquares == 1 || nSquares == 2) return;
  if(nSquares <= vPolyAll.size()) return;

  // compute the polyominoes for the 1 smaller set if not yet computed
  if(nSquares - 1 > vPolyAll.size()) ComputePolyominoes(nSquares - 1, vPolyAll);

  vector<Polyomino> vPolyN;
  for(unsigned int i = 0; i < vPolyAll[nSquares - 2].size(); ++i){
    Polyomino* polyNLess1 = &vPolyAll[nSquares - 2][i];
    for(unsigned int j = 0; j < polyNLess1->getSquares().size(); ++j){
      Square s = polyNLess1->getSquares()[j];
      FindNewPolyomino(s, 1, 0, *polyNLess1, vPolyN);  // Right 
      FindNewPolyomino(s, 0, 1, *polyNLess1, vPolyN);  // Up
      FindNewPolyomino(s, -1, 0, *polyNLess1, vPolyN);  // Left 
      FindNewPolyomino(s, 0, -1, *polyNLess1, vPolyN);  // Down
    } 
  }
  vPolyAll.push_back(vPolyN);
};

void TestTranslateRotate(Polyomino p){
  p.print();
  printf("Translating -1, -1\n");
  p.translate(-1, -1);
  p.print();
  printf("Rotating 90%%\n");
  p.rotate(90);
  p.print();
};

int main(){
  Square s1 = {0, 0};
  Square s2 = {0, 1};
/*
  pMap mSquares;

  mSquares.insert(make_pair(1,s1));
  mSquares.insert(make_pair(2,s2));
  mSquares.insert(make_pair(3,s3));
*/

  // vector of all polyominoes 
  vector<vector<Polyomino>> vPolyAll;

  // Base cases
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

  while(1){
    int nSquares;
    cout << "Please enter the number of squares" << endl;
    cin >> nSquares;

    cout << "Computing ..." << endl;

    ComputePolyominoes(nSquares, vPolyAll);

    cout << "There are "
	 << vPolyAll[nSquares - 1].size()
	 << " distinct polyominoes for "
	 << nSquares << " squares" << endl;
  }
}



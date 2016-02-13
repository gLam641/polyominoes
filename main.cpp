#include <stdio.h>
#include <unordered_map>
#include "polyominoes.h"

using namespace std;

#ifndef P_MAP

typedef std::unordered_map<size_t, Square> pMap;

#endif

int main(){
  Square s1 = {1, 1};
  Square s2 = {2, 2};
  Square s3 = {3, 3};
/*
  pMap mSquares;

  mSquares.insert(make_pair(1,s1));
  mSquares.insert(make_pair(2,s2));
  mSquares.insert(make_pair(3,s3));
*/
  vector<Square> vSquares;
  vSquares.push_back(s1);
  vSquares.push_back(s2);
  vSquares.push_back(s3);
  Polyomino p(vSquares);
 
  p.print();
}

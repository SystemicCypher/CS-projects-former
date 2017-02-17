//Jake Hickey, Austin Loza
//May 4, 2016
#ifndef SLL_H
#define SLL_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class sll{
  
 public:
  
  sll(sll* next = NULL);
  //mutators
  void link(sll* next);
  void data(pair<string[2], int> info);
 
  //accessors
  sll* glink() const{ return next; }
  pair<string[2],int> gdata() const{ return data_field; }
  bool has_next() const{ return (glink() != NULL); }
  
 private:
  sll* next;
  pair<string[2], int> data_field;
};

#endif

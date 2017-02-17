//Jake Hickey, Austin Loza
//May 4, 2016

#include "bag.h"
#include "sll.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

using namespace std;

Bag::Bag(){
  words_head = NULL;
  many_nodes = 0;
  srand (time(NULL));
}

Bag::~Bag(){
  //semi-sure
  if(words_head == NULL)
    return;
  sll *current = words_head;
  sll *next;
  while (current != NULL){
    next = current->glink();
    delete current;
    current = next;
  }
  words_head = NULL;
  many_nodes = 0;
}

void Bag::insert(const string& word, const string& fileName, int count){
  ifstream parse;
  string store;
  string x, y;
  int counter = 0;
  for (int i = 0; i < word.length();i++){
    x += tolower(word[i]);
  }
  parse.open(fileName, ifstream::in);
  while(getline(parse, store, ' ')){
    for (int i = 0; i < store.length(); i++){
      y += tolower(store[i]);
    }
    if (y == x){
      count++;
    }
  }
  string out[2];
  pair<string[2], int> ex;
  out[0] = x;
  out[1] = fileName;
  //~~~~~~~
  (ex.first)[0] = out[0];
  (ex.first)[1] = out[1];
  ex.second = count;
  //changed
  sll* next = new sll();
  next->data(ex);
  if(words_head == NULL){
    words_head = next;
  }
  else{
    sll* temp;
    temp = words_head;
    while (temp->has_next()) temp = temp->glink();
    temp->link(next);
  }
  many_nodes++;
  //end of changes
  parse.close();
}

pair<string,int> Bag::lookupFirst(const string& word){
  pair<string,int> output;
  string x;
  for (int i =0; i < word.length();i++){
    x += tolower(word[i]);
  }
  //changed
  for(sll *i = words_head; i != NULL; i = i->glink()){
    if ((i->gdata().first)[0] == x){
      output.first = (i->gdata().first)[1];
      output.second = i->gdata().second;
      //end of changes
      return output;
    }
  }
  output.first= "";
  output.second = 0;
  return output;
}

pair<string,int> Bag::lookupRandom(const string& word){
  
  string x;
  pair<string, int> output;
  vector<pair<string,int> > out_v;
  for (int i =0; i < word.length();i++){
    x += tolower(word[i]);
  }
  //changes
  for(sll *i = words_head; i != NULL; i = i->glink()){
    if ((i->gdata().first)[0] == x){
      output.first = (i->gdata().first)[1];
      output.second = i->gdata().second;
      out_v.push_back(output);
    }
  }
  //end of changes
  
  if (out_v.size() >= 1){
    int chaos;
    chaos = (rand()%(out_v.size()));
    return out_v.at(chaos);
  }
  else{
    pair<string,int> fail;
    fail.first = "";
    fail.second = 0;
    return fail;
  }
}

void Bag::lookupAll(const string& word, vector<pair<string,int> >& items){
  pair<string,int> output;
  string x;
  for (int i =0; i < word.length();i++){
    x += tolower(word[i]);
  }
  //changes
  for(sll *i = words_head; i != NULL; i = i->glink()){
    if ((i->gdata().first)[0] == x){
      output.first = (i->gdata().first)[1];
      output.second = i->gdata().second;
      items.push_back(output);
    }
  }
}

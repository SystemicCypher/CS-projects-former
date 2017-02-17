//Jake Hickey, Austin Loza
//April 24, 2016

#include "bag.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

Bag::Bag(int max_num_words){
  words = new pair<string[2],int>[max_num_words];
  size = 0;
}

Bag::~Bag(){
  delete [] words;
  size = 0;
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
  out[0] = x;
  out[1] = fileName;
  (words[size].first)[0] = out[0];
  (words[size].first)[1] = out[1];
  words[size].second = count;
  size++;
  parse.close();
}

pair<string,int> Bag::lookupFirst(const string& word){
  pair<string,int> output;
  string x;
  for (int i =0; i < word.length();i++){
    x += tolower(word[i]);
  }
  for(int i = 0; i < size; i++){
    if ((words[i].first)[0] == x){
      output.first = (words[i].first)[1];
      output.second = words[i].second;
      return output;
    }
  }
  output.first= "";
  output.second = 0;
  return output;
}

pair<string,int> Bag::lookupRandom(const string& word){
  srand (time(NULL));
  string x;
  pair<string, int> output;
  vector<pair<string,int> > out_v;
  for (int i =0; i < word.length();i++){
    x += tolower(word[i]);
  }
  for(int i = 0; i < size; i++){
    if ((words[i].first)[0] == x){
      output.first =(words[i].first)[1];
      output.second = words[i].second;
      out_v.push_back(output);
    }
  }
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
  for(int i = 0; i < size; i++){
    if ((words[i].first)[0] == x){
      output.first =(words[i].first)[1];
      output.second = words[i].second;
      items.push_back(output);
    }
  }
}

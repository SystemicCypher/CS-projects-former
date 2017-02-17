#ifndef BAG_H_
#define BAG_H_
#include "sll.h"
#include <string>
#include <vector>

using namespace std;

class Bag
{
 public:
  Bag ();
  virtual ~Bag ();
  void insert(const string& word, const string& fileName, int count);
  pair<string, int> lookupFirst(const string& word);
  pair<string, int> lookupRandom(const string& word);
  void lookupAll(const string& word, vector<pair<string, int> >& items);

  // don't change anything before here
 private:
  // add your private functions declaration here

 private:
  // add your private members here
  int many_nodes;
  sll* words_head;
};

#endif /* end of include guard: BAG_H_ */

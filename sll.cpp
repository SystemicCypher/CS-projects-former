#include "sll.h"
#include <cstdlib>
#include <utility>

sll::sll(sll* next){
    this->data_field.first[0] = "" ;
    this->data_field.first[1] = "";
    this->data_field.second = 0;
    this->next = next;
  }

void sll::link(sll* next){
  this->next = next;
}

void sll::data(const pair<string[2], int> info){
  this->data_field.first[0] = info.first[0];
  this->data_field.first[1] = info.first[1];
  this->data_field.second = info.second;
}


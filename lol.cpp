//Jake Hickey, Austin Loza
//June 2, 2016

#include "lol.h"
#include <string>

using namespace std;

lol::lol(string word, lol* next, sub_node* head){
	this->word = word;
	this->link_field = next;
	this->list_head = head;
}

void lol::set_link(lol* next){
	this->link_field = next;
}

void lol::set_word(string word){
	this->word = word;
}

void lol::set_sublist(sub_node* list){
	this->list_head = list;
}
 
//subnodes

sub_node::sub_node(int count, string filename, sub_node* next){
	this->count = count;
	this->filename = filename;
	this->next = next;
}

void sub_node::set_link(sub_node* next){
	this->next = next;
}

void sub_node::set_filename(string data){
	this->filename = data;
}

void sub_node::set_count(int& count){
	this->count = count;
}

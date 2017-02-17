//Jake Hickey, Austin Loza
//June 2, 2016
#ifndef LOL_H
#define LOL_H
#include <string>
#include <cstdlib>

using namespace std;
class sub_node{
public:
	//constructor
	sub_node(int count = 0, string filename = "", sub_node* next = NULL);

	//mutators
	void set_link(sub_node* next);
	void set_filename(string data);
	void set_count(int &count);

	//accessors
	string get_filename() const { return filename; }
	sub_node* get_link() const { return next; }
	int get_count() const { return count; }
	bool has_next() const { return (get_link() != NULL); }

private:
	int count;
	string filename;
	sub_node* next;
};

class lol{
public:
	//constructor
	lol(string word = "", lol* next = NULL, sub_node* head = NULL);

	//mutators
	void set_link(lol* next);
	void set_word(string word);
	void set_sublist(sub_node* list);

	//accessors
	lol* get_link() const { return link_field; }
	string get_word() const { return word; }
	sub_node* get_sublist() const { return list_head; }
	bool has_next() const { return (get_link() != NULL); }

private:
	string word;
	lol *link_field;
	sub_node *list_head;
};

//List in the list data



#endif

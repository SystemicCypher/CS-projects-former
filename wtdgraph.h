#ifndef WTDGRAPH_H
#define WTDGRAPH_H

#include <cstdlib>  
#include <set> 
#include <cassert> 
#include <map>
#include "graph.h"

namespace main_savitch_15
{
	template <class Item>
	class wtdgraph : public graph<Item>
	{
	public:
		wtdgraph() : graph<Item>::graph(){
            weights = new std::map<std::size_t,std::size_t> [10];
        }

        wtdgraph(std::size_t initial_allocation);

        wtdgraph(const wtdgraph &source);
        
        //mutators
        void add_edge(std::size_t source, std::size_t target,std::size_t weight=0);
        
        void remove_edge(std::size_t source, std::size_t target);

        void resize(std::size_t new_allocation);

        std::size_t edge_weight(std::size_t source, std::size_t target) const;

      

        //dtor
        ~wtdgraph();

        //assignment
        wtdgraph &operator=(const wtdgraph &source);

    private:
    	std::map<std::size_t,std::size_t>* weights;


	};



   
    template <class Item>
    wtdgraph<Item>::wtdgraph(std::size_t initial_allocation) : graph<Item>::graph(initial_allocation){
    	weights = new std::map<std::size_t,std::size_t> [initial_allocation];
        //graph<Item>::graph(initial_allocation);
        
    }
    
    //copy
    template <class Item>
    wtdgraph<Item>::wtdgraph(const wtdgraph &source) : graph<Item>::graph(source){



        weights = new std::map<std::size_t,std::size_t> [source.allocated_amt()];
        
        for (std::size_t i = 0; i < source.size(); i++ ){
        	for (std::map<std::size_t,std::size_t>::iterator it=source.weights[i].begin(); it!=source.weights[i].end(); ++it){
        		weights[i][it->first]= it->second;
        	}
        }


    }
   
    template <class Item>
    wtdgraph<Item>::~wtdgraph(){
        delete []weights;
       
    }

    template <class Item>
    wtdgraph<Item>& wtdgraph<Item>::operator=(const wtdgraph &source){

        if(&source == this)
            return *this;

        else{


            resize(source.allocated_amt());


            graph<Item>::operator=(source);


           for(std::size_t i=0; i <source.size(); ++i)
                for(std::map<std::size_t,std::size_t>::iterator it=source.weights[i].begin(); it!=source.weights[i].end(); ++it)
                    weights[i][it->first]=it->second;
        
        }

        return *this;
        
    }

    template <class Item>
    void wtdgraph<Item>::add_edge(std::size_t source, std::size_t target,std::size_t weight){
    	weights[source][target] = weight;
        graph<Item>::add_edge(source,target);
    }

    template <class Item>
    void wtdgraph<Item>::remove_edge(std::size_t source, std::size_t target){
    	assert(graph<Item>::is_edge(source,target) == true);
    	weights[source].erase(target);
        graph<Item>::remove_edge(source,target);

    }

    template <class Item>
    void wtdgraph<Item>::resize(std::size_t new_allocation){
        std::size_t pie = graph<Item>::allocated_amt();
    	if (new_allocation >= pie){
            std::map<std::size_t,std::size_t> *new_weights = new std::map<std::size_t,std::size_t> [new_allocation];


            for(std::size_t i=0; i < this->size(); i++){
                for (std::size_t j = 0; j < weights[i].size(); j++)
                    new_weights[i][j] = weights[i][j];
            }
            delete [] weights;
            graph<Item>::resize(new_allocation);
            weights = new_weights;

        }
    } 

    template <class Item>
    std::size_t wtdgraph<Item>::edge_weight(std::size_t source, std::size_t target) const{
    	assert(graph<Item>::is_edge(source,target) == true);
    	return weights[source][target];
    }

 

}
#endif
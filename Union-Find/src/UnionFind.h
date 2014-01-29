#ifndef __popup_v2_union_find__UnionFind__
#define __popup_v2_union_find__UnionFind__

#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

namespace unionfind {
    
    class UnionFind {
    public:
        
        void unionSet(std::map<unsigned int, std::set<unsigned int> * > & structure, unsigned int p, unsigned int q) {
            if(structure[p] == structure[q]) {
                return;
            }
            if(structure[p]->size() > structure[q]->size()) {
                unionSet(structure, structure[p], structure[q]);
            } else {
                unionSet(structure, structure[q], structure[p]);
            }
        }
        
        void move(std::map<unsigned int, std::set<unsigned int> * > & structure, unsigned int p, unsigned int q) {
            if(structure[p] == structure[q]) {
                return;
            }
            structure[p]->erase(p);
            structure[q]->insert(p);
            structure[p] = structure[q];
        }
        
    private:
        void unionSet(std::map<unsigned int, std::set<unsigned int> * > & structure, std::set<unsigned int> * newSet, std::set<unsigned int> * oldSet) {
            for(unsigned int e : *oldSet) {
                newSet->insert(e);
                structure[e] = newSet;
            }
        }
    };
}

#endif

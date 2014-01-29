//
//  main.cpp
//  popup-v1-help
//
//  Created by Mathias Lindblom on 2014-01-27.
//  Copyright (c) 2014 Mathias Lindblom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

#include "UnionFind.h"
int main(int argc, const char * argv[])
{
    using namespace unionfind;
    
    UnionFind * uf = new UnionFind();
    
    while(true) {
        std::string line;
        std::getline(std::cin, line);
        if(std::cin.eof()) {
            return 0;
        }
        std::istringstream iss(line);
        std::vector<std::string> nAndM{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        unsigned int n = std::stoi(nAndM[0]);
        unsigned int m = std::stoi(nAndM[1]);
        std::map<unsigned int, std::set<unsigned int> * > structure;
        
        for(unsigned int i = 1; i <= n; i++) {
            structure[i] = new std::set<unsigned int>({i});
        }
        
        for(unsigned int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::vector<std::string> command{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            unsigned int operation = std::stoi(command[0]);
            unsigned int p = std::stoi(command[1]);
            if(operation == 3){
                size_t nrElements = structure[p]->size();
                unsigned int sum = 0;
                for(unsigned int element : *structure[p]) {
                    sum += element;
                }
                std::cout << nrElements << " " << sum << std::endl;
                
            } else {
                unsigned int q = std::stoi(command[2]);
                if(operation == 1) {
                    uf->unionSet(structure, p, q);
                } else if(operation == 2) {
                    uf->move(structure, p, q);
                }
            }
        }
    }
}

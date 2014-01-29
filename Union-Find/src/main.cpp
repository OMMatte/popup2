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
    
    while(!std::cin.eof()) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::vector<std::string> nAndM{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        unsigned int n = std::stoi(nAndM[0]);
        unsigned int m = std::stoi(nAndM[1]);
        std::vector<std::vector<int>> structure;
        
        for(unsigned int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::vector<std::string> command{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            unsigned int operation = std::stoi(command[0]);
            unsigned int p = std::stoi(command[1]);
            if(operation == 3){
                
            } else {
                unsigned int q = std::stoi(command[2]);
                if(operation == 1) {
                    uf.unionSet(structure, p, q);
                } else if(operation == 2) {
                    uf.move(structure, p, q);
                } else {
                    throw new std::invalid_argument("Operation: " + std::to_string(operation) + " not allowed");
                }
            }
        }
        
        
    
    }
    for(int i = 0; i < n; i++){
        std::vector<int> pianoDates[100];
        std::getline(std::cin, line);
        
        int pianos = std::stoi(pianosAndMovers[0]);
        int movers = std::stoi(pianosAndMovers[1]);
        
        for(int p = 0; p < pianos; p++) {
            std::getline (std::cin, line);
            std::istringstream iss(line);
            std::vector<std::string> pianoMove{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            int firstDay = std::stoi(pianoMove[0]);
            int lastDay = std::stoi(pianoMove[1]);
            pianoDates[firstDay-1].push_back(lastDay-1);
        }
        
        if(piano->isFine(pianoDates, movers/2, pianos)) {
            std::cout << "fine" << std::endl;
        } else if(piano->isWeekend(pianoDates, movers/2, pianos)) {
            std::cout << "weekend work" << std::endl;
        } else {
            std::cout << "serious trouble" << std::endl;
        }
        
    }
    return 0;
}

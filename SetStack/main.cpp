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
#include <set>
#include <stack>
#include <map>

int main(int argc, const char * argv[])
{
    std::string line;
    std::getline(std::cin, line);
    unsigned int testCases = std::stoi(line);
    
    unsigned int uniqueVal = 0;
    std::map<std::set<unsigned int>, unsigned int> uniqueValues;
    
    for(unsigned int testcase = 0; testcase < testCases; testcase++){
        std::getline(std::cin, line);
        unsigned int operations = std::stoi(line);
        std::stack<std::set<unsigned int>*> setStack;
        for(int op = 0; op < operations; op++){
            std::getline(std::cin, line);
            if(line == "PUSH") {
                setStack.push(new std::set<unsigned int>());
            } else if(line == "DUP") {
                setStack.push(new std::set<unsigned int>(*(setStack.top())));
            } else {
                std::set<unsigned int> * first = setStack.top();
                setStack.pop();
                std::set<unsigned int> * second = setStack.top();
            
                if(line == "ADD") {
                
                    unsigned int firstUniqueVal;
                    auto foundVal = uniqueValues.find(*first);
                    if(foundVal != uniqueValues.end()) {
                        firstUniqueVal = foundVal->second;
                    } else {
                        //the combined sets val is completely new, add it to our unique map
                        firstUniqueVal = uniqueVal++;
                        uniqueValues[*first] = firstUniqueVal;
                    }
                    
                    second->insert(firstUniqueVal);
                    delete first;
                } else {
                    setStack.pop();
                    std::set<unsigned int> * smallest;
                    std::set<unsigned int> * biggest;
                    
                    if(first->size() > second->size()) {
                        smallest = second;
                        biggest = first;
                    } else {
                        smallest = first;
                        biggest = second;
                    }
                    
                    if(line == "UNION") {

                        for(unsigned int set : *smallest) {
                            biggest->insert(set);
                        }
                        setStack.push(biggest);
                        delete smallest;
                
                    } else if(line == "INTERSECT") {
                        std::set<unsigned int> * newSet =  new std::set<unsigned int>();
                
                        for(unsigned int set : *smallest) {
                            if(biggest->find(set) != biggest->end()){
                                newSet->insert(set);
                            }
                        }
                        delete smallest;
                        delete biggest;
                        setStack.push(newSet);
                    }
                }
            }
            size_t cardinality = setStack.top()->size();
            std::cout << cardinality << std::endl;
            
        }
        std::cout << "***" << std::endl;
    }
}


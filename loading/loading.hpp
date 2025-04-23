#ifndef LOADING_HPP
#define LOADING_HPP
#include "utills.hpp"
#include <vector>
#include <iostream>

using namespace utills;

class loading
{
public:
loading(int size);
void updateSize(float increment);//updates loading bar calls printBar
void printBar();//prints loading bar


private:
int size;
std::vector<char> bar;

};
#endif
#include "loading.hpp"
#include "utills.hpp"
#include <iostream>
using namespace utills;
utills::loading::loading(int size)
{
    this->size = size;
    bar.pushback('[');
  
for (int i = 1; i < SIZE -1; i++)
{
bar.pushback(' ')
}
bar.pushback(']');
printBar();

}
void utills::loading::printBar()
{
    std::cerr << "\r";
for(char section : bar) { std::cerr << section; }
}

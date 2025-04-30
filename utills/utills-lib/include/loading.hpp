//loading.hpp
#ifndef LOADING_HPP
#define LOADING_HPP
#include "utills.hpp"
#include "errorReport.hpp"
#include <vector>
#include <iostream>
#include <optional>
#include <functional>

 namespace utills
  {

class loading
{
public:
    loading(int size, errorReport& error);
    loading(int size);
    void update(int increment = 1);
    void printBar();
    loading(const loading& obj);
    ~loading();
private:
    int size;
    int progress = 0;
    std::vector<char> bar;
   errorReport* er;
   bool erobj = false;
};
  }
#endif
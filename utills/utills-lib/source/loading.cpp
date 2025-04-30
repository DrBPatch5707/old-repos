//loading.cpp
#include "../include/loading.hpp"
#include "../include/utills.hpp"
#include "../include/errorReport.hpp"
#include <iostream>
#include <vector>
#include <functional>

namespace utills
{
    loading::loading(int size, errorReport& error)
        : size(size + 1)
    {
        try
        {
            this->er = &error; //pointers and addresses
            bar.push_back('[');
            for (int i = 1; i < this->size - 1; ++i)
            {
                bar.push_back(' ');
            }
            bar.push_back(']');
        }
        catch (...)
        {
            er->setError("Unknown error in \"loading\" initialization");
            return;
        }
        printBar();
    }
    loading::loading(int size)
        : size(size + 1)
    {
        try
        {
           this->erobj = false;
            bar.push_back('[');
            for (int i = 1; i < this->size - 1; ++i)
            {
                bar.push_back(' ');
            }
            bar.push_back(']');
        }
        catch (...)
        {
            return;
        }
        printBar();
    }

    void loading::update(int increment)
    {
        try
        {
            progress += increment;
            if (progress >= this->size)
            {
                if (erobj)
                {
                    er->setError("Progress overflow(loading progress has exeededthe maximum value)");
                }
                return;
            }
            for (int i = 1; i < progress; ++i)
            {
                bar.at(i) = '#';
            }
        }
        catch (...)
        {
            if (erobj) 
            { 
            er->setError("Unknown error in \"loading::update\"");
            }
        }
        printBar();
    }

    void loading::printBar()
    {
        try
        {
            std::cerr << "\r";
            for (char section : bar)
            {
                std::cerr << section;
            }
        }
        catch (...)
        {
            if(erobj) {er->setError("Unknown error in \"loading::printBar\"");}
        }
    }
  loading::loading(const loading& obj) : bar(obj.bar), progress(obj.progress), size(obj.size), erobj(obj.erobj)
  {
if(erobj) {*er = *(obj.er);}
  }

    loading::~loading()
    {
        delete er;
        
    }
}
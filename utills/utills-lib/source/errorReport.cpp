//errorReport.cpp
#include <iostream>
#include <fstream>
#include <memory>
#include "../include/errorReport.hpp"
#include "../include/utills.hpp"
using namespace std;
namespace utills
{
    errorReport::errorReport(const errorReport &obj) : errorsP(obj.errorsP), errorsF(obj.errorsF), fileName(obj.fileName), writeCalled(false), reset(obj.reset)
    {
       setErrorFile(fileName, reset);
    }
    void errorReport::setError(string error)
    {
        try
        {
            this->errorsP.push_back(error);
            this->errorsF.push_back(error);
        }
        catch (...)
        {
            setError("Unknown error in \"setError\"");
           if (errorOutFile && errorOutFile->is_open())
            {
                writeErrors();
            }
        }
    }
    void errorReport::printErrors()
    {
        cerr << "\nInitialized error report" << "..." << endl;
        if (errorsP.empty())
        {
            cerr << "No errors to report" << "..." << endl;
        }
        for (string error : errorsP)
        {
            cerr << "error: " << error << "..." << endl;
        }
    }

    void errorReport::writeErrors()
    {
        if (!errorOutFile->is_open()) {setError("Please designate an error file with the \"setErrorFile\" function");}
        for (int i = 0; i < 1000000; i++) {*errorOutFile << "." << flush;}
        if (!errorOutFile->is_open())
        {
            setError("Please designate an error file with the \"setErrorFile\" function");
        }
        else
        {
            try
            {
                if (!writeCalled)
                {
                    *errorOutFile << "Initialized error report" << "..." << flush << endl;
                    writeCalled = true;
                }
                if (errorsF.empty())
                {
                    *errorOutFile << "No errors to report" << "..." << flush << endl;
                }
                for (string error : errorsF)
                {
                    *errorOutFile << "error: " << errorsF.back() << "..." << flush << endl;
                    errorsF.pop_back();
                }
                errorsF.shrink_to_fit();
                errorOutFile->flush();
            }
            catch (...)
            {
                setError("Unknown error in \"writeErrors\"");
            }
            *errorOutFile << flush;
        }
    }
    void errorReport::setErrorFile(string fileName, bool reset)
    {
        try
        {
            this->reset = reset;
            this->fileName = fileName;
            errorOutFile = std::make_shared<ofstream>(this->fileName, ios::app); 
          
            if (reset)
            {
                resetFile();
            }
            if (!errorOutFile->is_open())
            {
                setError("The provided error file could not be opened");
            }
        }
        catch (...)
        {
            setError("Unknown error in \"setErrorsFile\"");
            if (errorOutFile->is_open())
            {
                writeErrors();
            }
        }
    }

    vector<string> errorReport::getErrors()
    {
        return this->errorsP;
    }

    void errorReport::resetFile()
    {
        if(!errorOutFile)
        try
        {
            if (!errorOutFile->is_open())
            {
                setError("Can not reset: Please designate an error file with the \"setErrorFile\" function");
            }
            std::ofstream resetF; // Local ofstream object
            resetF.open(this->fileName, std::ios::out | std::ios::trunc);
            if (!resetF.is_open())
            {
                setError("Reset file not opened");
            }
            resetF.close();
        }
        catch (...)
        {
            setError("Unknown error in \"resetFile\"");
            if (errorOutFile->is_open())
            {
                writeErrors();
            }
        }
    }

    errorReport::~errorReport()
    {
        try
        {
        }
        catch (...)
        {
            setError("Unknown error in error report destructor...");
        }
    }

}
#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#ifdef _WIN32
#include <windows.h>
#else
#include <limits.h>
#include <stdlib.h>
#endif
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "errorReport.hpp"
#include "utills.hpp"


using namespace std;
namespace utills
{
class fileManager 
{
    public:
    fileManager(string file, errorReport& erobj) : er(&erobj), valid_er(true), filekey(getCanonicalPath(file))
        {
        if (filekey.empty())
        {er->setError("catastrophic fileStreamManager construction failure / please provide a valid file"); is_valid = false;}
            else
            {
                auto pos = files.find(filekey);
                if (pos != files.end()) {files.at(filekey).amt++;}
                else
                {
                    fileinfo* tmp = ((valid_er) ? (new fileinfo(filekey, *er)) : (new fileinfo(filekey)));
                    files[filekey] = *tmp;
                    delete tmp;
                }
            }
        }

        string getCanonicalPath(const string& path)
        {
            #ifdef _WIN32
                char fullPath[MAX_PATH];
                DWORD result = GetFullPathNameA(path.c_str(), MAX_PATH, fullPath, nullptr);
                if (result == 0 || result > MAX_PATH) {
                if (valid_er) {er->setError("Bad file path / \"file not found\"");}
                    return "";
                }
                return string(fullPath);
            #else
                char resolvedPath[PATH_MAX];
                char* res = realpath(path.c_str(), resolvedPath);
                if (res == nullptr) {
                    if (valid_er) {er->setError("Bad file path / \"file not found\"");}
                    return "";
                }
                return string(resolvedPath);
            #endif
            }

        fstream* call()
        {
            if (is_valid) {return (files.at(filekey).file);}
        }

        friend ostream& operator<<(ostream& out,const fileManager& obj);

        friend istream& operator>>(istream& in,const fileManager& obj);

        ~fileManager()
        {
        if (is_valid) {
            files.at(filekey).amt--;
            if ( files.at(filekey).amt == 0) { files.at(filekey).file->close();}
        }
        }
    private:
        struct fileinfo
        {
            fileinfo() : file(nullptr) {}
            fileinfo(string file, errorReport& er)
            {
                this->file->open(file);
                if (!this->file->is_open()) {er.setError(("fileStreamManager: could not open provided file\"" + file + "\""));}
            }
            fileinfo(string file)
            {
                this->file->open(file);
            }
                fstream* file = new fstream;
                int amt = 0;
                ~fileinfo() {delete file; file = nullptr;}
        };
        bool is_valid = true;
        errorReport* er;
        bool valid_er;
        string filekey;
        inline static map<string, fileinfo> files;  //file name, ifstream obj, ofstream obj, objs using file
};

inline ostream& operator<<(ostream& out,const fileManager& obj)
{
    obj.files.at(obj.filekey).file->seekg(0);
            out <<  obj.files.at(obj.filekey).file->rdbuf();
            obj.files.at(obj.filekey).file->clear();
    return out;
}

inline istream& operator>>(istream& in,const fileManager& obj)
{
    std::string data_to_write;
    in >> data_to_write; 
    *obj.files.at(obj.filekey).file << data_to_write << std::endl;
    obj.files.at(obj.filekey).file->flush();
    return in;
}






}
#endif
#include iostream
#include <vector>
#include <string>
#include <algorithm>
#include Files.h
using namespace std;

class BaseFile {
    string name;

public:
    BaseFile(string name){name = name;}
    string getName() const{
        return name;
    }
    void setName(string newName){
        name = newName;
    }
    virtual int getSize() = 0;

};

class File : public BaseFile {
private:
    int size;

public:
    File(string name, int size):BaseFile(name){
        this->size=size;
    }
    int  getSize() override{
        return size;
    }

};

class Directory : public BaseFile {
private:
    vector<BaseFile*> children;
    Directory *parent;
    bool compSize(const BaseFile* f1, const BaseFile* f2){
        return  f1->getName()< f2->getName();
    }
public:
    Directory(string name, Directory *parent):BaseFile(name){
        this->parent=parent;
       // children=new vector<BaseFile*> ();
    } // Constructor

    Directory *getParent() const{
        return parent;
    } // Return a pointer to the parent of this directory

    void setParent(Directory *newParent){
        this->parent=parent;
    } // Change the parent of this directory

    void addFile(BaseFile* file){
        children.push_back(file);
        sortByName();
    } // Add the file to children

    void removeFile(string name){
        //children.erase(std::remove(children.begin(),children.end(),name),children.end());

    }// Remove the file with the specified name from children
    void removeFile(BaseFile* file){
        children.erase(std::remove(children.begin(),children.end(),file),children.end());
    }// Remove the file from children

    void sortByName(){
        std:: sort(children.begin(), children.end(), compSize());
    } // Sort children by name alphabetically (not recursively)

    void sortBySize(); // Sort children by size (not recursively)
    vector<BaseFile*> getChildren(); // Return children
    int getSize(); // Return the size of the directory (recursively)
    string getAbsolutePath();  //Return the path from the root to this

};




//
// Created by barvak on 11/13/17.
//


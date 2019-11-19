//
// Created by avihu on 13/11/2019.
//

#ifndef EX1_DOCUMENT_H
#define EX1_DOCUMENT_H

#endif //EX1_DOCUMENT_H


#include <iostream>
#include <vector>
#include <list>

using namespace std ;


class Document
{
private:
    vector <string> data ;
    vector<string>::iterator it ;
    int currentLine;
    int lastSearch ;
    string lastSearchStr ;
    list<string> dataList ;


public:
    Document();

    void increaseLineNumber() ;
    void insertToList(string line);
    void changeCurrentLine(string newLine) ;
    void changeCurrentLineNumber(int newLine) ;
    void resetIterator() ;
    void insertBefore(string newLine);
    void deleteCurrentLine() ;
    void setCurrentLine( int newLine) ;
    void lastSearchText() ;
    int vectorSize() ;
    int getCurrentLine() ;

    void forwardSearch(string text , int index);
    void backwardSearch(string text , int index);
    void itToCurrentLine() ;
    void itToLastSearch() ;
    void oldToNew(vector<string>) ;
    string printLineText(int index) ;

    vector<string> getVectorList() ;
    vector<string>::iterator getIterator();


};

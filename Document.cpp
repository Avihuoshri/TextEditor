//
// Created by avihu on 13/11/2019.
//

#include <iostream>
#include "Document.h"

using namespace std ;



Document::Document()
{
    currentLine = 0 ;
    data.push_back("") ;
    lastSearch = -1 ;
    lastSearchStr = "" ;
    it = data.begin() ;

}

void Document::increaseLineNumber()
{
    currentLine++ ;
}
void Document::insertToList(string line) { data.push_back(line) ; }

int Document::vectorSize() { return data.size() ;}

int Document::getCurrentLine() {return currentLine ;}

void Document::setCurrentLine(int newLine)
{
    currentLine = newLine ;
   // cout <<  " currentLine has changed to " << currentLine << endl ;
}

vector<string> Document::getVectorList() {return data ;}

vector<string>::iterator Document::getIterator() {return it ;}

void Document::resetIterator()
{
    it = data.begin() ;
}

string Document::printLineText(int index)
{

    return data.at(index) ;
}

void Document::changeCurrentLine(string newLine)
{
    resetIterator() ;
    advance(it , currentLine) ;
    *it = newLine ;
}

void Document::insertBefore(string newLine)
{
    resetIterator() ;
    advance(it , currentLine) ;
    data.insert(it , newLine);
    currentLine++ ;

}

void Document::deleteCurrentLine()
{
    resetIterator() ;
    advance(it , currentLine);
    data.erase(it);
    currentLine--;
}
void Document::itToCurrentLine()
{
    resetIterator() ;
    for (int i = 0; i < currentLine ; ++i) // לבדוק שלא עושה בעיות כש - currentLine=-1
    {
        it++ ;
    }
}
void Document::forwardSearch(string text , int index)
{
    bool isExist = false ;
    int i = index ;
    lastSearchStr = text ;

    resetIterator() ;
    if(index == currentLine)
        itToCurrentLine() ;
    else if(index == lastSearch)
        itToLastSearch() ;

    while(it != data.end() && isExist == false )
    {

        if((*it).find(lastSearchStr) != string::npos) {
            isExist = true;
            lastSearch = ++i ;
            //currentLine = lastSearch-1 ;
            cout << *it << endl;
        }
        if( isExist == false)
        {
            ++it ;
            ++i ;
        }

    }
    if(isExist ==false) {
        it = data.begin();
        for (int j = 0; j < lastSearch; ++j) {
            if ((*it).find(lastSearchStr) != string::npos) {
                isExist = true;
                lastSearch = ++j;
                cout << "found it!! : " << *it << endl;
            }
            ++it;
            ++j;

        }
    }

}

void Document::backwardSearch(string text , int index)
{
    bool isExist = false ;
    lastSearchStr = text ;

    resetIterator() ;
    if(index == currentLine)
        itToCurrentLine() ;
    else if(index == lastSearch)
        itToLastSearch() ;

    int i = index ;

    while(it != data.begin() && isExist == false )
    {


        if((*it).find(lastSearchStr) != string::npos) {
            isExist = true;
            lastSearch = --i ;
            cout <<  *it << endl;
        }
        --it ;
        --i ;
    }
    if((*it).find(text) != string::npos) {
        lastSearch = --i ;
        cout << *it << endl;
    }

}

void Document::lastSearchText()
{
    forwardSearch(lastSearchStr , lastSearch ) ;


}

void Document::itToLastSearch()
{
    resetIterator() ;
    for (int i = 0; i < lastSearch ; ++i) // לבדוק שלא עושה בעיות כש - currentLine=-1
    {
        it++ ;
    }
}

void Document:: oldToNew(vector<string> vector)
{
   string oldText = vector[0] ;
   int b_old ;
   int e_old ;

    resetIterator() ;
    itToCurrentLine() ;
    if((*it).find(oldText) != string::npos)
    {
        b_old = (*it).find(oldText) ;
        (*it).replace(b_old , vector[0].length() , vector[1]  ) ;
    }
}




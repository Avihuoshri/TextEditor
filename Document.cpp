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
void Document::insertToList(string line)
{

    data.insert(data.begin() + currentLine  , line) ;
}

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
    it = data.begin() + currentLine ;
}
void Document::forwardSearch(string text , int index)
{
    bool isExist = false ;
    int lastCurrentLine ;
    int counter = 0 ;
    lastSearchStr = text ;
    resetIterator() ;
    if(currentLine == index)
    {
        if(currentLine + 1 >= data.size())
        {
            currentLine = 1 ;
            lastCurrentLine = currentLine ;
        }
        else
        {
            currentLine++;
            lastCurrentLine = currentLine ;
        }
        itToCurrentLine() ;
    }
    else if(lastSearch == index)
    {
        itToLastSearch() ;
    }

    while(currentLine < data.size() && isExist == false)
    {
        counter++ ;

        if((*it).find(text) != string::npos )
        {
            isExist = true ;
            lastSearch = currentLine ;
            cout << *it << endl ;
            break ;
        }
        currentLine++ ;
        it++ ;
    }

    if(isExist == false)
    {
        currentLine = 1 ;
        advance(it , currentLine);

        while(currentLine <= lastCurrentLine &&  isExist == false)
        {
            if((*it).find(text) != string::npos )
            {
                isExist = true ;
                cout << *it << endl ;
            }
            
        }
    }
}

void Document::backwardSearch(string text , int index)
{
    bool isExist = false ;
    int lastCurrentLine ;
    int counter = 0 ;
    lastSearchStr = text ;
    resetIterator() ;
    if(currentLine == index)
    {
        if(currentLine - 1 < 1)
        {
            currentLine = data.size()-1 ;
            lastCurrentLine = currentLine ;
        }
        else
        {
            currentLine--;
            lastCurrentLine = currentLine ;
        }
        itToCurrentLine() ;
    }
    else if(lastSearch == index)
    {
        itToLastSearch() ;
    }

    while(currentLine > 0 && isExist == false)
    {
        counter++ ;

        if((*it).find(text) != string::npos )
        {
            isExist = true ;
            lastSearch = currentLine ;
            cout << *it << endl ;
            break ;
        }
        currentLine-- ;
        it-- ;
    }

    if(isExist == false)
    {
        currentLine = currentLine = data.size()-1 ;
        advance(it , currentLine);

        while(currentLine >= lastCurrentLine &&  isExist == false)
        {
            if((*it).find(text) != string::npos )
            {
                isExist = true ;
                cout << *it << endl ;
            }
        }
    }

}

void Document::lastSearchText()
{
    forwardSearch(lastSearchStr , lastSearch ) ;


}

void Document::itToLastSearch()
{
    resetIterator() ;
   it = data.begin() + lastSearch ;
}

void Document:: oldToNew(vector<string> vector)
{
    string oldText = vector[0];
    int b_old;

    resetIterator();
    it = data.begin() + currentLine;
    while (it != data.end())
    {
        if ((*it).find(oldText) != string::npos)
        {
            b_old = (*it).find(oldText);
            (*it).replace(b_old, vector[0].length(), vector[1]);
        }
        it++;
    }
    it = data.begin();
    while (it != data.begin() + currentLine)
    {
        if ((*it).find(oldText) != string::npos)
        {
            b_old = (*it).find(oldText);
            (*it).replace(b_old, vector[0].length(), vector[1]);
        }
        it++;
    }

}



#include <iostream>
#include "Editor.h"

using namespace std ;

Editor::Editor()
{
    line = "" ;
    lastSearch = "";
    stopEdit = false ;
    Document text ;

}

void Editor::loop() {
    cout << "Enter new line" << endl;
    while (!stopEdit) {
        getline(cin, line);

        if (line == "a")
        {
            getline(cin, line);
            while (line != ".")
            {
                text.increaseLineNumber();
                text.insertToList(line);
                getline(cin, line);
            }
           // cout << "exited while loop , size of list is " << text.vectorSize() << endl;
        }

        else if (isdigit(line[0]) == 1 )
        {
            bool isNumber = true ;

            for (int i = 0; i < line.length() ; ++i)
            {
                if(isdigit(line[i]) != 1)  { isNumber = false ; }
            }

            if(isNumber == true)
            {
                if(stoi(line) >= 0 && stoi(line) < text.vectorSize())
                {
                    int newLine = stoi(line) ;
                    text.setCurrentLine(newLine);
                }
            }
        }
        else if (line == "n")
        {
            int cLine = text.getCurrentLine() ;
            cout << cLine << "  " << text.getVectorList()[cLine] << endl ;
        }

        else if (line == "%p")
        {
//            list<string>::iterator it = text.getIterator();
//            list<string> dataList = text.getDataList();
            for (int i = 0 ; i < text.vectorSize() ; ++i)
            {
                cout << text.getVectorList()[i] << endl;
            }
        }

        else if (line == "p") {
            if (text.vectorSize()> 0) {
                cout << text.printLineText(text.getCurrentLine()) << endl;
                text.resetIterator();
            } else
                cerr << "problem in (line == \"p\" )  ";

        } else if (line == "i") {
            string newLine;
            getline(cin, newLine);
            text.insertBefore(newLine);
            text.resetIterator();

        } else if (line == "c") {
            string newLine;
            getline(cin, newLine);
            text.changeCurrentLine(newLine);
            text.resetIterator();

        } else if (line == "d") {
            text.deleteCurrentLine();
            text.resetIterator();
        } else if (line[0] == '/')
        {
            if (line.size() == 1) {
                text.lastSearchText() ;
            }

            if (line.size() >= 2)
            {
                text.forwardSearch(line.substr(1, line.size() - 1) , text.getCurrentLine());
            }
        }
        else if (line[0] == '?')
        {
            lastSearch = line.substr(1);
            text.backwardSearch(lastSearch , text.getCurrentLine());
            text.resetIterator();
        }


        else if(line[0] == 's' && line[1] == '/' )
        {
            line =  line.substr(2) ;
            string newstr = "";
            vector<string> results ;

            for (int i = 0; i < line.length() ; ++i)
            {
                if(line[i] != '/')
                { newstr+= line[i] ; }
                else
                {
                    results.push_back(newstr) ;
                    newstr = "" ;
                }
            }
            results.push_back(newstr) ;
            text.oldToNew(results) ;
        }

        else if(line == "q" )
        {
            stopEdit = true ;
        }
    }
}


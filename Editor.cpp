
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
    //cout << "Enter new line" << endl;
    while (!stopEdit) {
        getline(cin, line);

        if (line == "a")
        {
            cout << "a" << endl;
            getline(cin, line);
            while (line != ".")
            {
                cout << line << endl;
                text.increaseLineNumber();
                text.insertToList(line);
                getline(cin, line);
            }


//            for (int i = 0 ; i < text.vectorSize() ; ++i)
//            {
//                if(text.getVectorList()[i] != "")
//                cout << text.getVectorList()[i] << endl;
//            }
            cout << "." << endl;
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
                if(stoi(line) > 0 && stoi(line) < text.vectorSize())
                {
                    int newLine = stoi(line) ;
                    cout << newLine << endl ;
                    text.setCurrentLine(newLine);

                    if(text.getVectorList()[newLine] == "" )
                        cout << "?" << endl ;
                    else
                    cout << text.printLineText(text.getCurrentLine()) << endl;

                }
                else
                    cout << "?" << endl ;
            }
        }
        else if (line == "n")
        {
            cout << "n" << endl;
            int cLine = text.getCurrentLine() ;
            cout << cLine << "  " << text.getVectorList()[cLine] << endl ;
        }

        else if (line == "%p")
        {
            cout << "%p" << endl;
//            list<string>::iterator it = text.getIterator();
//            list<string> dataList = text.getDataList();
            for (int i = 0 ; i < text.vectorSize() ; ++i)
            {
                cout << text.getVectorList()[i] << endl;
            }
        }

        else if (line == "p")
        {
            cout << "p" << endl;
            if (text.vectorSize()> 0) {
                cout << text.printLineText(text.getCurrentLine()) << endl;
                text.resetIterator();
            } else
                cerr << "?" << endl;

        }
        else if (line == "i")
        {
            cout << "i" << endl;
            string newLine;
            int numOfLines = 0 ;
            getline(cin, newLine);
            while (newLine != ".")
            {
                cout << newLine << endl ;
                text.insertBefore(newLine);
                getline(cin, newLine);
                numOfLines++ ;

            }
//            text.setCurrentLine(text.getCurrentLine() + numOfLines) ;
            text.resetIterator();

        }
        else if (line == "c")
        {
            cout << "c" << endl;
            string newLine;
            getline(cin, newLine);
            while(newLine != ".")
            {
                cout << newLine << endl ;
                text.changeCurrentLine(newLine);
                text.increaseLineNumber() ;
                getline(cin, newLine);
            }
//            for (int i = 0 ; i < text.vectorSize() ; ++i)
//            {
//                cout << text.getVectorList()[i] << endl;
//            }
        cout << "." << endl ;

        } else if (line == "d")
        {
            cout << "d" << endl ;
            text.deleteCurrentLine();
            text.resetIterator();
        }
        else if (line[0] == '/')
        {
            if (line.size() == 1)
            {
                cout<< "/" << endl ;
                text.lastSearchText() ;
            }

            if (line.size() >= 2)
            {
                cout << line << endl ;
                text.forwardSearch(line.substr(1, line.size() - 1) , text.getCurrentLine());
            }
        }
        else if (line[0] == '?' && line.length() >= 2)
        {
            cout<< line << endl ;
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
            cout<<"s/" << results[0] << "/" << results[1] << "/" << endl ;
        }

        else if(line == "Q" )
        {
            cout << "Q" << endl ;
            stopEdit = true ;
        }
        else
        {
            cout <<"?" << endl ;
        }

    }
}


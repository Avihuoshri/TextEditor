//
// Created by Avihu on 13/11/2019.
//
#include "Document.h"
#ifndef EX1_EDITOR_H
#define EX1_EDITOR_H


class Editor
{
    private:
            Document text ;
            bool stopEdit ;
            string line ;
            string lastSearch ;

    public:
            Editor()    ;
            void loop() ;



};


#endif //EX1_EDITOR_H

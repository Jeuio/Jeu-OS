//
// Created by jeuio on 30/11/2021.
//

#pragma once

class String {

    char* content

public:
    String(char* content);


    char* getCharPointer();


    String operator = (char* content);
};
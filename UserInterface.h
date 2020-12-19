#ifndef _USERINTERFACE_H
#define _USERINTERFACE_H

#include ""

class UserInterface{

    public:

        virtual void printInterface() = 0;


        void clearScreen(){
        	std::cout << std::flush;
        	system("clear");
        }






}


#endif
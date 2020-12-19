#include <iostream>
#include <vector>
#include "../HeaderFile/FileConnector.h"

using namespace std;

int main(){

    FileConnector f("test.csv");

    vector<string> vec;
    vec.push_back("12");
    vec.push_back("cat");
    vec.push_back("asdasd");
    vec.push_back("123123");
    f.append(vec);

    vec.clear();

    vec.push_back("12");
    vec.push_back("cat");
    vec.push_back("asdasd");
    vec.push_back("123123");
    f.append(vec);

    vec.push_back("12");
    vec.push_back("cat");
    vec.push_back("asdasd");
    vec.push_back("123123");
    f.append(vec);

}
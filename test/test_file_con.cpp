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

    vec.push_back("22");
    vec.push_back("dog");
    vec.push_back("qwe");
    vec.push_back("12");
    f.append(vec);

    vec.clear();

    //Invalid append
    /*vec.push_back("12");
    vec.push_back("cat");
    vec.push_back("asdasd");
    vec.push_back("123123");
    vec.push_back("123123");
    f.append(vec);*/
    
    cout << "not seg yet!";

    vector<int> searchDog = f.search("id", "22");
    cout << searchDog.size() << endl;
    for(int i : searchDog) cout << i << " ";

}
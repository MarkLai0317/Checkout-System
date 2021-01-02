#ifndef _FILECONNECTOR_H
#define _FILECONNECTOR_H
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <chrono>

class FileConnector{

    public:

        FileConnector(std::string name);

        ~FileConnector();

        void search(std::string from, std::string target);

        std::vector< std::vector<std::string> > getResult();

        //找到那行的那個位置修改其值，如果找不到要回傳錯誤訊息
        void update(std::string from_property, std::string which_is, std::string from_col, std::string change_to);

        //vector裡面要裝有 id name price category
        void append(std::vector<std::string>);

    private:

        void readCsv();
        void write();

        std::vector<int> row_result;
        std::vector< std::vector<std::string> > result;

        std::ifstream input_file;
        std::ofstream output_file; 
        std::string file_name;
        std::vector<std::vector<std::string> > table;
        std::map<std::string, int> column;

};

#endif

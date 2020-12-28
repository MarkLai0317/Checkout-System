#include <iostream>
#include <fstream>
#include <vector>
#include "../HeaderFile/FileConnector.h"

FileConnector::FileConnector(std::string name) : file_name("../data/"+name), input_file("../data/" + name), output_file("../data/" + name + ".tmp"){
    table.clear();
    if(input_file.fail()){
        std::cout << "Fail to open file" << std::endl;
        std::cout << "Creating new file" << std::endl;
        system( ("touch " + file_name).c_str() );
        std::cout << "Create new file successfully! " << std::endl;
    }

    readCsv();
}

void FileConnector::readCsv(){
    std::cout << "Reading csv" << std::endl;
    input_file.seekg(0,std::ios::beg);
    int count = 0;
    char buffer[80];
    input_file.getline(buffer, sizeof(buffer));
    std::vector<std::string> tmp_row;

    for(char *token=strtok(buffer, ","); token; token=strtok(NULL, ",")){
        tmp_row.push_back(token);
        column[token] = count++;
    }
    table.push_back(tmp_row); 
    tmp_row.clear();

    while(input_file.getline(buffer, sizeof(buffer))){
        for(char *token=strtok(buffer, ","); token; token=strtok(NULL, ",")){
            tmp_row.push_back(token);
        }
        table.push_back(tmp_row); tmp_row.clear();
    }

    result = table;

    std::cout << "Finish reading" << std::endl;
}

FileConnector::~FileConnector(){
    write();

    input_file.close();
    output_file.close();

    system( ("rm " + file_name).c_str() );
    system( ("mv " + file_name + ".tmp " + file_name).c_str() );

}

void FileConnector::write(){
    for(int i=0; i<table.size(); i++){
        output_file << table[i][0];
        for(int j=1; j<table[i].size(); j++){
            output_file << "," << table[i][j];
        }
        output_file << std::endl;
    }
}

void FileConnector::search(std::string property, std::string target){
    int which_col = column[property];

    row_result.clear();
    result.clear();
    
    if(which_col){
        int cnt = 0;
        while(cnt++ < table.size()-1){
            if(table[cnt][which_col] == target){
                row_result.push_back(cnt);
                result.push_back(table[cnt]);
            }
        }
    }else{
        row_result.push_back(stoi(target));
        result.push_back(table[stoi(target)]);
    }
}

std::vector< std::vector<std::string> > FileConnector::getResult(){
    std::vector< std::vector<std::string> > tmp = result;
    result = table;
    return tmp;
}

//找到那行的那個位置修改其值，如果找不到要回傳錯誤訊息
void FileConnector::update(std::string from_property, std::string which_is, std::string from_col, std::string change_to){
    search(from_property, which_is);
    std::vector<int> which_row = row_result;
    int which_col = column[from_col];

    for(int i : which_row){
        table[i][which_col] = change_to;
    }
}

//vector裡面要裝有 id name price category (quantity) (time)
void FileConnector::append(std::vector<std::string> vec){
    if(vec.size() != column.size()){
        std::cout << "invaild append (different column size)" << vec.size() << " " << column.size() << std::endl;
        std::cout << "Each of the first row and your input row are belong:\n";
        
        for(std::string s : vec)
            std::cout << s << " ";
        std::cout << std::endl;

        for(std::string s : table[0])
            std::cout << s << " ";
        std::cout << std::endl;

        return ;
    }

    table.push_back(vec);
    std::cout << "Append successfully!" << std::endl;

    result = table;
}

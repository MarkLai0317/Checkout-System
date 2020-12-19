#include <FileConnector.h>

FileConnector::FileConnector(string name) : file_name("data\\"+name+".csv") {
    ifstream file(file_name);
    int count = 0;
    char buffer[80];
    file.getline(buffer, sizeof(buffer));

    for(char *token=strtok(buffer, ","); token; token=strtok(NULL, ",")){
        column[token] = count++;
    }

    file.close();
}

FileConnector::~FileConnector(){
}

// return 哪一行
int FileConnector::search(strng from, string target){
    ifstream file(file_name);
    char buffer[80];
    int from_col = column[from], count = 0;

    while(file.getline(buffer, sizeof(buffer))){
        char *token=strtok(buffer, ",");
        for(int i=0; i<from_col; i++, token=strtok(buffer, ",")){};

        if((std::string)token == target){
            file.close();
            return count;
        }

        count++;
    }
    
    file.close();
    return -1;
}

//找到那行的那個位置修改其值，如果找不到要回傳錯誤訊息
void FileConnector::update(string from, string to_update, string which_col, string to_target){
    ifstream file(file_name);
    ofstream tmp_file(file_name + ".tmp");

    int which_row = search(from, to_update);
    while(which_row--){ 
        file.getline(buffer, sizeof(buffer));
        tmp_file << buffer << std::endl;
    }

    file.getline(buffer, sizeof(buffer));
    int from_col = column[which_col];
    for(char *token=strtok(buffer, ","); token; token=strtok(NULL, ","), count++){
        if((std::string)token == to_update) vec.push_back(to_update);
        else vec.push_back(token);
    }

    file << vec[0];
    for(int i=1; i<vec.size(); i++){
        file << "," << vec[i];
    }
    file << std::endl;

    while(file.getline(buffer, sizeof(buffer)))
        tmp_file << buffer << std::endl;

    file.close();
    tmp_file.close();

    system( ("rm " + file_name).c_str() );
    system( ("mv " + file_name + ".tmp " file_name).c_str() );

}

//vector裡面要裝有 id name price category (quantity) (time)
void FileConnector::append(vector<string> vec){
    ofstream file(file_name);

    file << vec[0];
    for(int i=1; i<vec.size(); i++){
        file << "," << vec[i];
    }
    file << endl;

    file.close();
}

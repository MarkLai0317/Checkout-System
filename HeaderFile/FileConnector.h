class FileConnector{

    public:

        FileConnector(string name);

        ~FileConnector();

        // return 哪一行
        int search(strng from, string target);

        //找到那行的那個位置修改其值，如果找不到要回傳錯誤訊息
        void update(string from, string to_update, string which_col, string to_target);

        //vector裡面要裝有 id name price category
        void append(vector<string>);

    private:
    
        std::string file_name;
        vector<string> result;
        map<string, int> col;

};

enum operation { Activity=0 , Inventory=1 };

class FileConnector{

    public:

        vector<GoodsInventory> searchInventory;

    private:

        fstream fin, fout;

};

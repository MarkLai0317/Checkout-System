class FileConnector{

    public:

        FileConnector(string activity_file, string inventory_file) : activity(activity_file+".csv"), inventory(inventory_file+".csv") {};

        /*
        改變貨物庫存
        要改activity.csv(因為要記錄拿東西出來或拿東西進去的量（增加->quantity>0 和 減少->quantity<0）)
        要改inventory.csv(因為庫存的量會變化)
        記得庫存可能已經有一樣的貨物了 然後檔案要存成csv的格式 不懂找我問 詳細格式之後討論
        */
        void changeGoods(GoodsInventory good, time_t time);

        //find the specific id's goods status in Inventory
        vector<GoodsInventory> searchInventory(int id);

        //find the specific id's
        vector<GoodsActivity> searchActivity(GoodsInventory goods);

        //find the specific time zone
        vector<GoodsActivity> searchActivityByTime(GoodsInventory goods, int month_begin, int month_end);

    private:

        fstream activity, inventory;

};

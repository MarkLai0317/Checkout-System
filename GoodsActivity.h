class GoodsActivity{

    public:
        
        GoodsActivity(int id, int quantity, string name, int yy, int mm, int dd)
            : goods(id, quantity, name),
             year(yy), month(mm), date(dd)
        {}
        
        int getYear() const;

        int getMonth() const;
        
        int getDate() const;



    private:
    
        int year, month, date;
        GoodsInInventory goods; 
};
class GoodsActivity{

    public:
        
        GoodsActivity(int id, int quantity, string name, time_t t)
            : goods(id, quantity, name),
             time(t)
        {}
        
        int getYear() const;

        int getMonth() const;
        
        int getDate() const;



    private:
    
        time_t time;
        GoodsInInventory goods; 
};
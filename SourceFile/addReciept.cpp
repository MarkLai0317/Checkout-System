void addReciept(){
    for(int i=0; i<reciept.size(); ++i) {
        if(reciept[i].id == id_now){
            reciept[i].quantity += quantity_now;
            return; 
        }
    }
    GoodInventory tmp = findInventoryByIdAndSetQuantity(id_now, quantity_now);
    reciept.push_back(tmp);
}





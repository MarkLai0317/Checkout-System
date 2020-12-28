//addReciept in Userinterface
void addReciept(){
    for(int i=0; i<reciept.size(); ++i) {
        if(reciept[i].id == id_now){
            reciept[i].quantity += quantity_now;
            return; 
        }
    }
    reciept.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now));
}

//addReciept in SupplierUI
void addReciept(){
    if(old_new_status == OLD_GOOD_STATUS){
        for (int i = 0; i < reciept.size(); ++i){
            if (reciept[i].id == id_now){
                reciept[i].quantity += quantity_now;
                return;
            }
        }
    }else{
        reciept.push_back(search.findInventoryByIdAndSetQuantity(id_now, quantity_now))
    }
}

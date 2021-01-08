#ifndef _MANAGERUI_H
#define _MANAGERUI_H

class ManagerUI{

    public:
    
        void managerSystem();

    private:

        void exportInventory();

        void exportActivity();

        void exportActivity(time_t begin, time_t end);

}

#endif
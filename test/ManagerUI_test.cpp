#include <unistd.h>
#include "../HeaderFile/ManagerUI.h"


int main(){

    char current_dir[80] = "~/Desktop/oop_final_project/bin";
	//getcwd(current_dir, sizeof(current_dir));
	if( !chdir(current_dir) )
        perror((std::string("Fail to change files directory to ") + current_dir).c_str());
    else perror("Successfully change dir.");
	system("cd ~/Desktop/oop_final_project/bin; pwd");
    system("pwd");
    ManagerUI test;
    test.managerSystem();

}
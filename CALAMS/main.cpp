#include <iostream>
#include "Registration.h"
#include "Login.h"
#include "Menus.h"

int main(){
    int choice;
    do{
        std::cout << "======== CALAMS ========" << std::endl;
        std::cout << "1.Administrator Login" << std::endl;
        std::cout << "2.Student Login" << std::endl;
        std::cout << "3.Register" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                if(adminLogin()){
                    adminMenu();
                }
                break;
            case 2:
                if(studentLogin()){
                    studentMenu();
                }
                break;
            case 3:
                system("cls");
                Register();
                break;
            case 4:
                system("cls");
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                system("cls");
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 4);

    cleanupAccounts();
    return 0;
}
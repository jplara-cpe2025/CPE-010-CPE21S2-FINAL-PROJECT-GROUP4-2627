#include <iostream>
#include "Registration.h"
#include "Login.h"

void studentMenu();
void adminMenu();
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

void studentMenu(){
    int choice;
    do{
        std::cout << "======== CALAMS ========" << std::endl;
        std::cout << "1. Available Lockers" << std::endl;
        std::cout << "2. Request a Locker" << std::endl;
        std::cout << "3. Borrow an Asset" << std::endl;
        std::cout << "4. Return an Asset" << std::endl;
        std::cout << "5. Logout" << std::endl;
        std::cin >> choice;;
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: 
                break;
            default:
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 5);
}

void adminMenu(){
    int choice;
    do{
        std::cout << "======== Admin Menu ========" << std::endl;
        std::cout << "1. Manage Lockers" << std::endl;
        std::cout << "2. Manage Campus Assets" << std::endl;
        std::cout << "3. " << std::endl;
        std::cout << "4. " << std::endl;
        std::cout << "5. Logout" << std::endl;
        std::cin >>choice;
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: 
                break;
            default:
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 5);
}

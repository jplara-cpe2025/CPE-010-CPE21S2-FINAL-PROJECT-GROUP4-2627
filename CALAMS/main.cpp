#include <iostream>
#include "Registration.h"
#include "Login.h"
#include "LockerAssetSort.h"
#include "BorrowReturnHistory.h"
#include "StudentQueue.h"

const int TOTAL_ITEMS = 6;
LockerItem campusLockers[TOTAL_ITEMS] = {
    {305, "Locker 305 - 3rd Flr", "2514137", false},
    {101, "Locker 101 - 1st Flr", "Available", true},
    {502, "Locker 502 - 5th Flr", "2513505", false},
    {204, "Locker 204 - 2nd Flr", "Available", true},
    {102, "Locker 102 - 1st Flr", "Available", true},
    {401, "Locker 401 - 4th Flr", "2513324", false}
};

void studentMenu();
void adminMenu();

int main(){
    int choice;
    do{
        std::cout << std::endl;
        std::cout << "======== CALAMS LOGIN MENU ========" << std::endl;
        std::cout << "1. Administrator Login" << std::endl;
        std::cout << "2. Student Login" << std::endl;
        std::cout << "3. Register" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

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
                clearScreen();
                Register();
                break;
            case 4:
                clearScreen();
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                clearScreen();
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 4);

    cleanupAccounts();
    return 0;
}

StudentQueue studentWaitingQueue;

void studentMenu(){
    int choice;
    do{
        std::cout << std::endl;
        std::cout << "======== CALAMS STUDENT MENU ========" << std::endl;
        std::cout << "1. Available Lockers" << std::endl;
        std::cout << "2. View Lockers by ID" << std::endl;
        std::cout << "3. Request a Locker" << std::endl;
        std::cout << "4. Borrow an Asset" << std::endl;
        std::cout << "5. Return an Asset" << std::endl;
        std::cout << "6. View Waiting Queue" << std::endl;
        std::cout << "7. Logout" << std::endl;
        std::cin >> choice;;
        std::cout << std::endl;
        switch(choice){
            case 1:
                // Calls availability sorting function
                sortByAvailability(campusLockers, TOTAL_ITEMS);
                std::cout << "--- Lockers Sorted by Availability (Available First) ---";
                displayLockerItems(campusLockers, TOTAL_ITEMS);
                break;
            case 2:
                // Calls bubble sort / selection sort by ID
                bubbleSortById(campusLockers, TOTAL_ITEMS);
                std::cout << "--- Lockers Sorted in Ascending Order by ID ---";
                displayLockerItems(campusLockers, TOTAL_ITEMS);
                break;
            case 3:
                studentWaitingQueue.requestLockerFromInput();
                break; 
            case 4:
                std::cout << "[Feature under development: Borrow Asset]\n";
                transactionHistory.recordTransaction(HISTORY_BORROW);
                break;
            case 5:
                std::cout << "[Feature under development: Return Asset]\n";
                transactionHistory.recordTransaction(HISTORY_RETURN);
                break;
            case 6:
                studentWaitingQueue.displayQueue();
                break;
            case 7:
                clearScreen();
                break;
            default:
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 7);
}

void adminMenu(){
    int choice;
    do{
        std::cout << std::endl;
        std::cout << "======== CALAMS ADMIN MENU ========" << std::endl;
        std::cout << "1. Manage Lockers" << std::endl;
        std::cout << "2. Manage Campus Assets" << std::endl;
        std::cout << "3. Asset Inventory" << std::endl;
        std::cout << "4. Transaction History" << std::endl;
        std::cout << "5. Assign/Release Student Locker (1st in queue)" << std::endl;
        std::cout << "6. View Student Waiting Queue" << std::endl;
        std::cout << "7. Logout" << std::endl;
        std::cin >>choice;
        std::cout << std::endl;
        switch(choice){
            case 1:
                selectionSortById(campusLockers, TOTAL_ITEMS);
                std::cout << "[Admin] All Lockers Sorted Numerically via Selection Sort:";
                displayLockerItems(campusLockers, TOTAL_ITEMS);
                break;
            case 2:
                sortByAvailability(campusLockers, TOTAL_ITEMS);
                std::cout << "[Admin] Lockers Sorted by Availability Status:";
                displayLockerItems(campusLockers, TOTAL_ITEMS);
                break;
            case 3:
                std::cout << "[Feature under development: Asset Inventory]\n";
                break;
            case 4:
                transactionHistory.showMenu();
                break;
            case 5:
                studentWaitingQueue.processFrontQueue(campusLockers, TOTAL_ITEMS);
                break;
            case 6:
                studentWaitingQueue.displayQueue();
                break;
            case 7:
                clearScreen();
                break;
            default:
                std::cout << "Invalid Choice." << std::endl;
                break;
        }
    }while(choice != 7);
}
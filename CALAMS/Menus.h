#ifndef Menus_h
#define Menus_h

inline void studentMenu(){
    int choice;
    std::cout << "======== CALAMS ========" << std::endl;
    std::cout << "1. Available Lockers" << std::endl;
    std::cout << "2. Request a Locker" << std::endl;
    std::cout << "3. Borrow an Asset" << std::endl;
    std::cout << "4. Return an Asset" << std::endl;
    std::cout << "5. Logout" << std::endl;
    std::cin >> choice;;
    
}

inline void adminMenu(){
    int choice;
    std::cout << "======== Admin Menu ========" << std::endl;
    std::cout << "1. Manage Lockers" << std::endl;
    std::cout << "2. Manage Campus Assets" << std::endl;
    std::cout << "3. " << std::endl;
    std::cout << "4. " << std::endl;
    std::cout << "5. Logout" << std::endl;
    std::cin >>choice;

}
#endif
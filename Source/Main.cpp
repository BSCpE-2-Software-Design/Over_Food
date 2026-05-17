#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Customer.h"
#include "GameSession.h"
#include "Order.h"
#include "Burger.h"
#include "Pizza.h"
#include "FriedChicken.h"
#include "IceCream.h"
#include "Fries.h"

//IF I SEE THIS MY COMMIT PASS THROUGH
// Function to display continue/exit menu
char displayLevelCompleteMenu(int currentLevel) {
    char choice;
    std::cout << "\n========================================" << std::endl;
    std::cout << "    LEVEL " << currentLevel << " COMPLETE!      " << std::endl;
    std::cout << "========================================" << std::endl;

    if (currentLevel < 3) {
        std::cout << "\n[1] Continue to Level " << (currentLevel + 1) << std::endl;
    }
    std::cout << "[2] Exit Game" << std::endl;
    std::cout << "\nEnter your choice (1 or 2): ";
    std::cin >> choice;
    std::cin.ignore(1000, '\n');
    return choice;
}

// Level 1: 1 Order
Order* createLevel1(const std::vector<Food>& menu, int& orderIdCounter) {
    Customer mainCustomer(1, 1);
    Food mainFood = menu[std::rand() % menu.size()];

    Order* rootOrder = new Order(orderIdCounter++, mainCustomer, mainFood, 1, -1);

    std::cout << "[LEVEL 1 - MAIN ORDER]" << std::endl;
    std::cout << "Customer " << mainCustomer.getCustomerId() << ": Hello! I'd like to have the " << mainFood.getFoodName() << ", please.\n" << std::endl;

    return rootOrder;
}

// Level 2: 2 Orders
Order* createLevel2(const std::vector<Food>& menu, int& orderIdCounter) {
    // Main root order for this level
    Customer mainCustomer(201, 2);
    Food mainFood = menu[std::rand() % menu.size()];
    Order* rootOrder = new Order(orderIdCounter++, mainCustomer, mainFood, 2, -1);

    std::cout << "\n[LEVEL 2 - 2 ORDERS]" << std::endl;
    std::cout << "[CUSTOMER " << mainCustomer.getCustomerId() << "]: Hello! I'd like to have the " << mainFood.getFoodName() << ", please.\n" << std::endl;

    // Second order
    Customer subCustomer(202, 2);
    Food subFood = menu[std::rand() % menu.size()];
    Order* level2Order2 = new Order(orderIdCounter++, subCustomer, subFood, 2, -1);
    rootOrder->addChildOrder(level2Order2);

    std::cout << "[CUSTOMER " << subCustomer.getCustomerId() << "]: I'd like the " << subFood.getFoodName() << " as well!\n" << std::endl;

    return rootOrder;
}

//level 3: 3 orders 
Order* createLevel3(const std::vector<Food>& menu, int& orderIdCounter) {
    //First order
    Customer mainCustomer(301, 3);
    Food mainFood = menu[std::rand() % menu.size()];
    Order* rootOrder = new Order(orderIdCounter++, mainCustomer, mainFood, 3, -1);

    std::cout << "\n[LEVEL 3 - 3 ORDERS]" << std::endl;
    std::cout << "[CUSTOMER " << mainCustomer.getCustomerId() << "]: Hello! I'd like to have the " << mainFood.getFoodName() << ", please.\n" << std::endl;

    // Second order
    Customer subCustomer1(302, 3);
    Food subFood1 = menu[std::rand() % menu.size()];
    Order* level3Order2 = new Order(orderIdCounter++, subCustomer1, subFood1, 3, -1);
    rootOrder->addChildOrder(level3Order2);
    std::cout << "[CUSTOMER " << subCustomer1.getCustomerId() << "]: I'll have the " << subFood1.getFoodName() << "!\n" << std::endl;

    // Third order
    Customer subCustomer2(303, 3);
    Food subFood2 = menu[std::rand() % menu.size()];
    Order* level3Order3 = new Order(orderIdCounter++, subCustomer2, subFood2, 3, -1);
    rootOrder->addChildOrder(level3Order3);
    std::cout << "[CUSTOMER " << subCustomer2.getCustomerId() << "]: I'll take the " << subFood2.getFoodName() << " too!\n" << std::endl;

    return rootOrder;
}

// Display order hierarchy
void displayOrderHierarchy(Order* rootOrder) {
    rootOrder->displayHierarchy(0);
    std::cout << std::endl;
}

// Process a level
void processLevel(Order* levelOrder, int levelNumber) {
    displayOrderHierarchy(levelOrder);
    std::cout << "[SYSTEM]: Chef, the orders are in! Starting the kitchen...\n" << std::endl;

    GameSession session(levelOrder);
    session.processHierarchicalOrder();
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "========================================" << std::endl;
    std::cout << "       WELCOME TO CHEF MODE ON!        " << std::endl;
    std::cout << "========================================\n" << std::endl;

    // Create food items
    Burger burger;
    Pizza pizza;
    FriedChicken chicken;
	Fries fries;
	IceCream icecream;
    std::vector<Food> menu = { burger, pizza, chicken, fries, icecream };

    int orderIdCounter = 1;
    int currentLevel = 1;
    bool gameRunning = true;
    int totalScore = 0;
   

    // ===== LEVEL 1 =====
    if (gameRunning) {
        Order* level1Order = createLevel1(menu, orderIdCounter);

        GameSession session1(level1Order);
        session1.processHierarchicalOrder();

        if (session1.checkFailure()) {
            std::cout << "\n========================================" << std::endl;
            std::cout << "           GAME OVER!                   " << std::endl;
            std::cout << "========================================" << std::endl;
            std::cout << "[SYSTEM]: You ran out of points!\n" << std::endl;
            std::cout << "[SYSTEM]: Thanks for playing Chef Mode On!\n" << std::endl;
            gameRunning = false;

        }
        else{
        totalScore += session1.getPoints();
        char choice = displayLevelCompleteMenu(1);

            if (choice == '1') {
                std::cout << "\n[SYSTEM]: Great! Starting Level 2...\n";
                currentLevel = 2;
            }
            else {
                gameRunning = false;
            }
        }

        delete level1Order;
    }

    // ===== LEVEL 2 =====
    if (gameRunning && currentLevel == 2) {
        Order* level2Order = createLevel2(menu, orderIdCounter);
        GameSession session2(level2Order);
        displayOrderHierarchy(level2Order);
        std::cout << "[SYSTEM]: Chef, the orders are in! Starting the kitchen...\n" << std::endl;
        session2.processHierarchicalOrder();

        if (session2.checkFailure()) {
            std::cout << "\n========================================" << std::endl;
            std::cout << "           GAME OVER!                   " << std::endl;
            std::cout << "========================================" << std::endl;
            std::cout << "[SYSTEM]: You ran out of points!\n" << std::endl;
            std::cout << "[SYSTEM]: Thanks for playing Chef Mode On!\n" << std::endl;
            gameRunning = false;
        } else {
            totalScore += session2.getPoints();
            char choice = displayLevelCompleteMenu(2);
            if (choice == '1') {
                std::cout << "\n[SYSTEM]: Excellent! Starting Level 3...\n" << std::endl;
                currentLevel = 3;
            } else {
                std::cout << "\n[SYSTEM]: Thanks for playing Chef Mode On!\n" << std::endl;
                gameRunning = false;
            }
        }

        delete level2Order;
    }

    // ===== LEVEL 3 =====
    if (gameRunning && currentLevel == 3) {
        Order* level3Order = createLevel3(menu, orderIdCounter);

        GameSession session3(level3Order);

        displayOrderHierarchy(level3Order);

        std::cout << "[SYSTEM]: Chef, the orders are in! Starting the kitchen...\n" << std::endl;

        session3.processHierarchicalOrder();

        if (session3.checkFailure()) {
            std::cout << "\nGAME OVER!\n";
            gameRunning = false;
        }
        else {
            totalScore += session3.getPoints();
        }

        std::cout << "\n========================================" << std::endl;
        std::cout << "    LEVEL 3 COMPLETE - GAME FINISHED!    " << std::endl;
        std::cout << "========================================\n" << std::endl;
     

        std::cout << "[SYSTEM]: Congratulations! You completed all levels!\n" << std::endl;
        std::cout << "[SYSTEM]: Final Score: " << totalScore << "/300\n" << std::endl;
        std::cout << "[SYSTEM]: Thanks for playing Chef Mode On!\n" << std::endl;

        delete level3Order;
    }

    // Final ending message
    std::cout << "\n========================================" << std::endl;
    std::cout << "           Thanks for playing!      " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(1000, '\n');
    std::cin.get();

    return 0;
}

//if this show this chage has been commited

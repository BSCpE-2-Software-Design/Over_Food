#include "doctest.h"


#include "GameSession.h"
#include "Order.h"
#include "Customer.h"
#include "Burger.h"

TEST_CASE("Testing Chef Mode On - Scoring and Points System Logic") {

    Customer testCustomer(999, 1);
    Burger testBurger;


    Order* rootOrder = new Order(1, testCustomer, testBurger, 1, -1);

    // I-initialize ang GameSession gamit ang ginawang order tree
    GameSession session(rootOrder);

    // -------------------------------------------------------------------
    // SUBCASE 1: Verifying of Starting Points (Initial State)
    // -------------------------------------------------------------------
    SUBCASE("Initial Score Validation") {

        int expectedStartingPoints = 100;

        CHECK(session.getPoints() == expectedStartingPoints);

        // At first you should not trigger a failure
        CHECK(session.checkFailure() == false);
    }

    // -------------------------------------------------------------------
    // SUBCASE 2:  (Deduction Logic)
    // -------------------------------------------------------------------
    SUBCASE("Point Deduction and Boundary Limits") {
        int initialPoints = session.getPoints();

 
        session.deductPoints(20);

        CHECK(session.getPoints() == (initialPoints - 20));

        // Dahil may natitira pang puntos, hindi pa dapat Game Over
        CHECK(session.checkFailure() == false);
    }

    // -------------------------------------------------------------------
    // SUBCASE 3:  (Game Over State)
    // -------------------------------------------------------------------
    SUBCASE("Game Over Trigger at Zero Points") {
        int currentPoints = session.getPoints();


        session.deductPoints(currentPoints);

        CHECK(session.getPoints() == 0);


        CHECK(session.checkFailure() == true);
    }

    // === CLEANUP ===
    delete rootOrder;
}
#include "doctest.h"
#include "GameSession.h"


TEST_CASE("GameSession core behavior") {

    Customer c;
    Food f("Pizza");
    Order o(1, c, f, 0, -1);

    SUBCASE("Points initialize correctly") {
        GameSession gs(f, 100);
        CHECK(gs.getPoints() == 100);
    }

    SUBCASE("Order constructor sets root correctly") {
        GameSession gs(&o, 50);

        CHECK(gs.getPoints() == 50);
        CHECK(gs.getRootOrder() != nullptr);
    }

    SUBCASE("Deduct points works") {
        GameSession gs(f, 100);

        gs.deductPoints(30);
        CHECK(gs.getPoints() == 70);
    }

    SUBCASE("Points cannot go below zero") {
        GameSession gs(f, 10);

        gs.deductPoints(100);
        CHECK(gs.getPoints() == 0);
    }

    SUBCASE("Failure condition works") {
        GameSession gs(f, 10);

        gs.deductPoints(10);

        CHECK(gs.checkFailure() == true);
    }

    SUBCASE("Non-failure condition works") {
        GameSession gs(f, 10);

        gs.deductPoints(5);

        CHECK(gs.checkFailure() == false);
    }
}
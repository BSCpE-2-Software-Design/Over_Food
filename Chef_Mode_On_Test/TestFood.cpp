#include "doctest.h"
#include "Food.h"

TEST_CASE("Food class test") {

    SUBCASE("Constructor sets name") {
        Food f("Pizza");
        CHECK(f.getFoodName() == "Pizza");
    }
    SUBCASE("Constructor sets name") {
        Food f("Burger");
        CHECK(f.getFoodName() == "Burger");
    }
    SUBCASE("Constructor sets name") {
        Food f("Fries");
        CHECK(f.getFoodName() == "Fries");
    }
    SUBCASE("Constructor sets name") {
        Food f("FriedChicken");
        CHECK(f.getFoodName() == "FriedChicken");
    }
    SUBCASE("Constructor sets name") {
        Food f("Icecream");
        CHECK(f.getFoodName() == "Icecream");
    }
    
    SUBCASE("addStep stores data") {
        Food f("Burger");

        f.addStep("Q1", { "A","B","C","D" }, 2);

        CHECK(f.questions.size() == 1);
        CHECK(f.choices.size() == 1);
    }
}

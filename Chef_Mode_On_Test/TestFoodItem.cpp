#include "doctest.h"
#include "Food.h"

TEST_CASE("Food objects represent different dishes") {

    SUBCASE("Burger object identity") {
        Food burger("Burger");

        CHECK(burger.getFoodName() == "Burger");
        CHECK_FALSE(burger.isCompleted);
    }

    SUBCASE("FriedChicken object identity") {
        Food friedchicken("FriedChicken");

        CHECK(friedchicken.getFoodName() == "FriedChicken");
        CHECK_FALSE(friedchicken.isCompleted);
    }

    SUBCASE("Fries object identity") {
        Food fries("Fries");

        CHECK(fries.getFoodName() == "Fries");
        CHECK_FALSE(fries.isCompleted);
    }
    SUBCASE("Pizza object identity") {
        Food pizza("Pizza");

        CHECK(pizza.getFoodName() == "Pizza");
        CHECK_FALSE(pizza.isCompleted);
    }

    SUBCASE("IceCream object identity") {
        Food ice("IceCream");

        CHECK(ice.getFoodName() == "IceCream");
        CHECK_FALSE(ice.isCompleted);
    }

    SUBCASE("Each food is independent") {
        Food burger("Burger");
        Food pizza("Pizza");
		Food fries("Fries");
		Food icecream("IceCream");
		Food friedchicken("FriedChicken");

        burger.isCompleted = true;

        CHECK(burger.isCompleted == true);
        CHECK(pizza.isCompleted == false);
        CHECK(friedchicken.isCompleted == false);
    }
}
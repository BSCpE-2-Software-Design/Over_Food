#include "doctest.h"
#include "Order.h"


TEST_CASE("Order class tests") {

    Customer c;
    Food f("Pizza");

    SUBCASE("Constructor initializes correctly") {
        Order o(1, c, f, 0, -1);

        CHECK(o.getOrderId() == 1);
        CHECK(o.getLevel() == 0);
        CHECK(o.getParentOrderId() == -1);
        CHECK(o.getIsCompleted() == false);
    }

    SUBCASE("Food pointer is stored correctly") {
        Order o(2, c, f, 0, -1);

        CHECK(o.getFood() != nullptr);
        CHECK(o.getFood()->getFoodName() == "Pizza");
    }

    SUBCASE("Completion state works") {
        Order o(3, c, f, 0, -1);

        CHECK(o.getIsCompleted() == false);

        o.setCompleted(true);

        CHECK(o.getIsCompleted() == true);
    }

    SUBCASE("Child order system works") {
        Order* parent = new Order(1, c, f, 0, -1);
        Order* child = new Order(2, c, f, 1, 1);

        parent->addChildOrder(child);

        CHECK(parent->getChildOrders().size() == 1);
        CHECK(parent->getChildOrders()[0]->getOrderId() == 2);

        delete parent;
    }

    SUBCASE("Multiple child orders") {
        Order* parent = new Order(1, c, f, 0, -1);

        parent->addChildOrder(new Order(2, c, f, 1, 1));
        parent->addChildOrder(new Order(3, c, f, 1, 1));

        CHECK(parent->getChildOrders().size() == 2);

        delete parent;
    }
}
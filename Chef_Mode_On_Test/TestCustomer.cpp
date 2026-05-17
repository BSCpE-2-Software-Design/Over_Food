#include "Customer.h"
#include "doctest.h"

TEST_CASE("Customer class initialization") {
    SUBCASE("Default constructor creates empty customer") {
        Customer customer;
        CHECK_EQ(customer.getfood().size(), 0);
    }

    SUBCASE("Parameterized constructor sets ID and level") {
        Customer customer(5, 10);
        CHECK_EQ(customer.getCustomerId(), 5);
        CHECK_EQ(customer.getLevel(), 10);
    }
}

TEST_CASE("Customer setters and getters") {
    Customer customer;

    SUBCASE("setCustomerId and getCustomerId work correctly") {
        customer.setCustomerId(42);
        CHECK_EQ(customer.getCustomerId(), 42);
    }

    SUBCASE("setLevel and getLevel work correctly") {
        customer.setLevel(7);
        CHECK_EQ(customer.getLevel(), 7);
    }

    SUBCASE("push_back adds food to the customer's list") {
        Food food1("Pizza");
        Food food2("Burger");

        customer.push_back(food1);
        customer.push_back(food2);

        CHECK_EQ(customer.getfood().size(), 2);
        CHECK_EQ(customer.getfood()[0].getFoodName(), "Pizza");
        CHECK_EQ(customer.getfood()[1].getFoodName(), "Burger");
    }
}
#include "Pizza.h"

Pizza::Pizza() : Food("Pizza") {

    addStep("Step 1",
        { "Prepare dough", "Cut cheese",
          "Heat tray", "Wash bowl" }, 0);

    addStep("Step 2",
        { "Add sauce", "Let dough rise",
          "Cool dough", "Wash tray" }, 1);

    addStep("Step 3",
        { "Cut toppings", "Prepare sauce",
          "Heat cheese", "Check dough" }, 1);

    addStep("Step 4",
        { "Heat tray", "Add cheese",
          "Wash plate", "Spread dough" }, 3);

    addStep("Step 5",
        { "Cool sauce", "Cut dough",
          "Add sauce and toppings", "Wash tray" }, 2);

    addStep("Step 6",
        { "Check pizza", "Bake pizza",
          "Cool oven", "Dry plate" }, 1);

    addStep("Step 7",
        { "Heat slice", "Slice and serve",
          "Wash pizza", "Bake again" }, 1);
}
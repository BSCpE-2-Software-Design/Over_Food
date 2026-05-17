#include "FriedChicken.h"

FriedChicken::FriedChicken() : Food("Fried Chicken") {

    addStep("Step 1",
        { "Heat tray", "Cut chicken",
          "Add spice", "Wash chicken" }, 3);

    addStep("Step 2",
        { "Dry meat", "Marinate chicken",
          "Wash bowl", "Cool flour" }, 1);

    addStep("Step 3",
        { "Add oil", "Check pan",
          "Dry flour", "Prepare flour coating" }, 3);

    addStep("Step 4",
        { "Heat tray", "Coat chicken in flour",
          "Wash flour", "Cool meat" }, 1);

    addStep("Step 5",
        { "Add salt", "Dry pan",
          "Check oil", "Heat oil" }, 3);

    addStep("Step 6",
        { "Cool tray", "Wash bowl",
          "Deep fry chicken", "Dry plate" }, 2);

    addStep("Step 7",
        { "Cook again", "Drain oil and serve",
          "Wash tray", "Cool chicken" }, 1);
}
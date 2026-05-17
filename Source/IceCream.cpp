#include "IceCream.h"

IceCream::IceCream() : Food("IceCream") {

    addStep("Step 1",
        { "Chocolate chips", "Ice and salt",
          "Milk, cream, sugar, and flavoring", "Sprinkles" }, 2);

    addStep("Step 2",
        { "Freeze immediately", "Mix everything in a bowl until smooth",
          "Add toppings first", "Heat the mixture until boiling" }, 1);

    addStep("Step 3",
        { "Add ice cubes", "Boil again",
          "Eat it raw", "Let it rest in the fridge" }, 3);

    addStep("Step 4",
        { "Frying pan", "Baking tray",
          "Freezer-safe container", "Plate" }, 2);

    addStep("Step 5",
        { "Leave it outside", "Freeze until solid",
          "Heat it in microwave", "Stir on stove" }, 1);

    addStep("Step 6",
        { "To melt it faster", "To add air and prevent ice crystals",
          "To cook it", "To make it salty" }, 1);

    addStep("Step 7",
        { "Boil it again", "Mix with water",
          "Freeze longer forever", "Serve with toppings" }, 3);
}
#include "Fries.h"

Fries::Fries() : Food("Fries") {

    addStep("Step 1",
        { "Heat oil", "Cut potatoes",
          "Add salt", "Wash potatoes" }, 3);

    addStep("Step 2",
        { "Dry knife", "Peel potatoes",
          "Heat bowl", "Cut plate" }, 1);

    addStep("Step 3",
        { "Wash tray", "Dry potatoes",
          "Heat pan", "Cut into strips" }, 3);

    addStep("Step 4",
        { "Add salt", "Soak in water",
          "Heat oil", "Skip soak" }, 1);

    addStep("Step 5",
        { "Cool tray", "Check potatoes",
          "Dry potatoes", "Wash bowl" }, 2);

    addStep("Step 6",
        { "Add spice", "Deep fry potatoes",
          "Cool fries", "Dry pan" }, 1);

    addStep("Step 7",
        { "Heat again", "Season and serve",
          "Wash fries", "Cool plate" }, 1);
}
#include "Food.h"
#include <random>


Food::Food(std::string name) {
	foodName = name;
	isCompleted = false;
}




void Food::addStep(const std::string& question,
    const std::vector<std::string>& choiceList,
    int correctIndex)
{
    questions.push_back(question);
    choices.push_back(choiceList);

    // Convert 0-3 index into A-D
    answers.push_back('A' + correctIndex);

    answersText.push_back(choiceList[correctIndex]);
}



std::string Food::getFoodName () const {
    return foodName;
}

bool Food::playFood(int& score) {

    std::cout << "\nCooking: " << foodName << "\n";
    

    for (int i = 0; i < questions.size(); i++) {

        bool correct = false;

        int currentWinningIndex = 0;



        while (!correct) {


            std::vector<std::string> tempChoices = choices[i];
            std::string correctString = answersText[i];

            std::mt19937 g(static_cast<unsigned int>(std::time(0)));
            std::shuffle(tempChoices.begin(), tempChoices.end(), g);

            std::cout << "\n" << questions[i] << "\n";

            char letters[4] = { 'A', 'B', 'C', 'D' };

            for (int j = 0; j < tempChoices.size(); j++) {
                std::cout << letters[j] << ". " << tempChoices[j] << "\n";

                if (tempChoices[j] == correctString) {
                    currentWinningIndex = j;
                }
            }

            char userAnswer;
            std::cout << "Answer: ";
            std::cin >> userAnswer;
            std::cin.ignore(1000, '\n');
            userAnswer = toupper(userAnswer);

            if (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D') {
                score = 0;
                std::cout << "Invalid input \n";
                std::cout << "Score: " << score << "\n";
                return true;
            }
            else if (userAnswer == letters[currentWinningIndex]) {
                std::cout << "Correct!\n";
                correct = true;
            }
            else {
                score -= 10;

                std::cout << "Wrong! -10 points\n";
                std::cout << "Score: " << score << "\n";

                if (score <= 0) {
                    std::cout << "GAME OVER!\n";
                    return false;
                }
            }
        }
    }

    std::cout << "\n" << foodName << " completed successfully!\n";

    return true;
}
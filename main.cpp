#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room" << std::endl;
    std::cout << "You need to enter the correct codes to continue..." << std::endl;
}

bool PlayGame(int Difficulty) {
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntroduction(Difficulty);

    // Print sum and product to the terminal
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The codes add-up to: " << CodeSum << std::endl;
    std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct) {
        std::cout << "*** Well done agent! You have extracted a file! Keep going! ***" << std::endl;
        return true;
    } else {
        std::cout << "*** You entered the wrong code! Careful agent! Try again! ***" << std::endl;
        return false;
    }
}

int main() {
    srand(time(nullptr)); // create a new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }

    std::cout << "*** Great work agent! You got all the files! Now get out of there! ***" << std::endl;
    return 0;
}

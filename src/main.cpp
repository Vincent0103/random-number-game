#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int getRandomSecretNumber() {
  srand(static_cast<unsigned int>(time(0)));
  return rand() % 100 + 1;
}

int getInput() {
  int x{0};
  std::cout << "Guess the number: ";
  std::cin >> x;
  return x;
}
void handleOutput(int guess, int secretNumber) {
  if (guess >= secretNumber + 20) {
    std::cout << "The number is way too high!" << "\n";
  } else if (guess > secretNumber) {
    std::cout << "The number is too high" << "\n";
  } else if (guess == secretNumber) {
    std::cout << "Congratulation, you found the secret number: " << secretNumber << "\n";
  } else if (guess < secretNumber - 20) {
    std::cout << "The number is way too low!" << "\n";
  } else {
    std::cout << "The number is too low" << "\n";
  }
}

int main() {
  const int secretNumber = getRandomSecretNumber();
  int currentGuess{0};

  while (currentGuess != secretNumber) {
    currentGuess = getInput();
    handleOutput(currentGuess, secretNumber);
  }
  return 0;
}

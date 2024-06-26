/* 
Based on the "Rock, Paper, Scissors, Lizard, Spock" assignment from Codecademy
*/

#include <iostream>
#include <string>
#include <stdlib.h>

void help(){

  std::cout << "====================\n";
  std::cout << "rock paper scissors lizard spock!\n";
  std::cout << "====================\n\n";

  std::string help = "Rules:\n\n 1. Paper covers Rock\n 2. Rock crushes Scissors \n 3. Scissors cuts Paper\n 4. Lizard eats Paper\n 5. Scissors decapitates Lizard\n 6. Rock crushes Lizard\n 7. Lizard poisons Spock\n 8. Spock smashes Scissors\n 9. Paper disproves Spock\n 10. Spock vaporizes Rock\n\n";

  std::cout << help;

  std::cout << "Choice 1: ✊\n";
  std::cout << "Choice 2: ✋\n";
  std::cout << "Choice 3: ✌️\n";
  std::cout << "Choice 4: 🦎\n";
  std::cout << "Choice 5: 🖖\n";
}

// Captures whether the player whether or not to play again, stop, or ask for help.
char again(){
  std::cout << "\nPlay again? (y/n/h (for help))\n" << "> ";
  char again;
  std::cin >> again;
  //std::cin.get();
  std::cin.clear();
  return std::tolower(again);
}

// Holds results of 'again()' in various places throughout the program.
char next_action;

int main(){

  // calling 'help' once to start us off
  help();

  const signed char rock = 1;
  const signed char paper = 2;
  const signed char scissors = 3;
  const signed char lizard = 4;
  const signed char spock = 5;

  const std::string you_win = "\n --> You win! 🙌\n";
  const std::string computer_wins = "\n 🖥️  <-- Computer wins! \n";
  

  do{
    
    // player chooses their weapon
    std::cout << "\n🔫 Shoot!\n" << "> ";
    int user;
    std::cin >> user;
    std::cin.clear();
    std::cout << "user = " << user << "\n";
    
    // computer chooses theirs
    srand(time(NULL));
    int computer = rand() % 5 + 1;

    /* !!! Winner determination logic !!! */

    // 0. Tie
    if(user == computer){
      std::cout << "Tie!\n";
    }

    // 1. Paper(2) covers Rock(1)
    else if(user == 2 && computer == 1){
      std::cout << "Paper covers rock!" << you_win;
    }
    else if(computer == 2 && user == 1){
      std::cout << "Paper covers Rock!" << computer_wins;
    }

    //2. Rock(1) crushes Scissors(3)
    else if(user == 1 && computer == 3){
      std::cout << "Rock crushes Scissors!" << you_win;
    }
    else if(computer == 1 && user == 3){
      std::cout << "Rock crushes Scissors!" << computer_wins;
    }

    // 3. Scissors(3) cuts Paper(2)
    else if(user == 3 && computer == 2){
      std::cout << "Scissors cuts Paper!" << you_win;
    }
    else if(computer == 3 && user == 2){
      std::cout << "Scissors cuts Paper!" << computer_wins;
    }

    // 4. Lizard(4) eats Paper(2)
    else if(user == 4 && computer == 2){
      std::cout << "Lizard eats Paper!" << you_win;
    }
    else if(computer == 4 && user == 2){
      std::cout << "Lizard eats Paper!" << computer_wins;
    }

    // 5. Scissors(3) decapitates Lizard(4)
    else if(user == 3 && computer == 4){
      std::cout << "Scissors decapitates Lizard!" << you_win;
    }
    else if(computer == 3 && user == 4){
      std::cout << "Scissors decapitates Lizard!" << computer_wins;
    }

    // 6. Rock(1) crushes Lizard(4)
    else if(user == 1 && computer == 4){
      std::cout << "Rock crushes Lizard!" << you_win;
    }
    else if(computer == 1 && user == 4){
      std::cout << "Rock crushes Lizard!" << computer_wins;
    }

    // 7. Lizard (4) poisons Spock (5)
    else if(user == 4 && computer == 5){
      std::cout << "Lizard poisons Spock!" << you_win;
    }
    else if(computer == 4 && user == 5){
      std::cout << "Lizard poisons Spock!" << computer_wins;
    }

    // 8. Spock(5) smashes Scissors(3)
    else if(user == 5 && computer == 3){
      std::cout << "Spock smashes Scissors!" << you_win;
    }
    else if(computer == 5 && user == 3){
      std::cout << "Spock smashes Scissors!" << computer_wins;
    }

    // 9. Paper(2) disproves Spock(5)
    else if(user == 2 && computer == 5){
      std::cout << "Paper disproves Spock!" << you_win;
    }
    else if(computer == 2 && user == 5){
      std::cout << "Paper disproves Spock!" << computer_wins;
    }

    // 10. Spock(5) vaporizes Rock(1)
    else if(user == 5 && computer == 1){
      std::cout << "Spock vaporizes Rock!" << you_win;
    }
    else if(computer == 5 && user == 1){
      std::cout << "Spock vaporizes Rock!" << computer_wins;
    }
    
    else{
      std::cout << "Invalid choice!  Only choose 1 - 5.\n\n";
    }

    // Does the player want to play again?
    next_action = again();
    
    // The player can request more help here, just in case they forgot the rules
    while(next_action == 'h'){
      help();
      next_action = again();
    }

  } while(next_action == 'y' || next_action == 'h');

  std::cout << "\n\nThanks for playing! 👋 See you next time.\n\n";
}

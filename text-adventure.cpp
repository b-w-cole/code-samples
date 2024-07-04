#include <iostream>
#include <string>
#include <vector>


std::string about = "\n\nThis adventure takes place in a subsection my dystopian Dungeons and Dragons realm, on the planet Gargorath. \n\nThis world has gone through many transformation over the millenia and has eventually settled into provinces dictated by current politics and geography.  Magic is used alongside technology, as the two are inseparable.  Space flight is possible, with space taxis available at 10,000 gp (gold pieces).  There isn't much danger left, except for typical crime, well-guarded ancient secrets, and ... space dragons!\n\n";
std::string options = "Actions are numerical. Refer to above text for available options.";
std::string bad_ending = "\n\nOof, sorry, looks like you got a bad ending. 😨 Good luck next time!\n\n";
std::string good_ending = "\n\nCongrats, you got a good ending!!! 🙌 🙌 🙌\n\n";
std::string average_ending = "\n\nHey, you did pretty alright.  You got the average ending. 👍\n\n";

int gp = 10000;
int path_choice;
bool pub_bequeathed = false;
bool knows_scroll_location = false;
bool knows_dragon_secret = false;
bool found_scroll = false;

/*

Plot - get some quests from local job board

1. Get dwarven scroll
2. Find DRAGON'S LAIR
3. Fetch FRED
4. Open the local pub you inherited, which would be the one where the job postings are nailed onto.

*/

// Takes option choice from user and returns the number
int get_choice(){
  int choice;
  std::cout << "Please select a number.\n> ";  
  std::cin >> choice;
  std::cout << "\n";

  /* TODO: Handling for not-integers */

  return choice;
}

// Prints out a consistent menu of options per situation
void give_options(std::vector<std::string> options){
  std::cout << "\n\n";  
  for(int i = 0; i < options.size(); i++){
    std::cout << i + 1 << ". " << options[i] << "\n";
  }
  std::cout << "\n";
}

void print_gp(){
  std::cout << "============================\n";
  std::cout << "You started with 10,000 gp.\n";
  std::cout << "You now have " << gp << "gp.\n";
  std::cout << "============================\n";
}

int main(){
  std::cout << "============================\n";
  std::cout << "Tiny Adventure Simulator\n";
  std::cout << "============================\n";
  std::cout << about;
  std::cout << "============================\n";
  std::cout << options;

  bool game_runs = true;

  while(game_runs){

    std::cout << "You're a level 1 person with 10,000 gold credits to your name.  It's a misty mid-autumn day on the planet Gargorath, and you find yourself outside of a PUB with plywood nailed over its windows and door.  The door is guarded by a security gate.";
    give_options({"Look", "Move on", "0 to quit"});

    int first_choice = get_choice();

    if(first_choice == 1){
      std::cout << "\nYou see some advertisements for punk bands, tattoo artists, an advert to find a missing scroll, a missing person poster, and a quest to find a DRAGON'S LAIR.";

      bool looking = true;

      while(looking){ 
        give_options({"Seek SCROLL", "Seek FRED", "Seek DRAGON'S LAIR", "0 to go back"});
        int second_choice = get_choice();

        if(second_choice == 1){
          std::cout << "There are 0 clues as to where this slip of paper might be, so it's up to you if you want to call it a night.\n";
        }
        else if(second_choice == 2){

          std::cout << "You take a quick look around, wondering how you might find such an individual.  You take a quick snapshot with your SHINY NEW DEVICE and start looking around the building.  In no time flat, you find a sad, cloaked figure, huddled between a fence and this building.  You peer under the hood and notice that the craggy nose is a perfect match for the illustration.  In fact, you really do think it is FRED.  \"Hey, FRED,\" you say.  He grumbles slightly.";
          bool talking = true;

          while(talking){
            std::cout << "\nFRED looks up, head cocked in impatience, awaiting your question.";
            give_options({"Ask about SCROLL", "Ask about DRAGON'S LAIR", "Ask about PUB", "Ask about WANTED AD", "0 to leave Fred alone" });
            int third_choice = get_choice();

            if(third_choice == 1){
              if(!found_scroll){
                std::cout << "FRED has the scroll in his pocket, but he charges you 10gp for it. He pick-pockets another 490gp.\n\n";
                gp -= 500;
                found_scroll = true;
              }
              else{
                std::cout << "!!! Hey, you already found the scroll.  What do you want to do next?\n\n";
              }
              
              
            }
            else if(third_choice == 2){
              std::cout << "FRED tells you that the dragon owes him 5gp and that he hasn't been able to collect since the only way to get there is via space taxi.  He also grumbles about the SHINY ring he lost.  It appears that the DRAGON is easily distracted by SHINY objects. \n\n";
              knows_dragon_secret = true;
            }
            else if(third_choice == 3){
              std::cout << "\"Oh yeah, that old beaut. Closed down about 2 years ago, when old HILDA passed away, Torm rest her soul.\" He bows his head dramatically.  The name HILDA sounds awfully familiar.  You wonder if you have a great aunt HILDA somewhere in the line.\n\n";
              pub_bequeathed = true;
            }
            else if(third_choice == 4){
              std::cout << "You point out the sign to FRED inquiring to his whereabouts.  He humbly requests that you do not follow up.  You have deciding power, though.\n\n";
            }
            else if(third_choice == 0){
              std::cout << "The conversation has dwindled.  FRED returns to his alley.  Should you sell FRED out?\n\n";
              give_options({"Yes", "No"});
              
              int sellout = get_choice();

              if(sellout == 1){
                std::cout << "You happen to know the person inquiring about FRED.  You track them down in exchange for... .1gp.  In the excitement for an easy question, you failed to notice the reward amount.  There are no noticeable consequences to your actions, otherwise.\n\n";
                gp += 1;
                talking = false;
              }
              else if(sellout == 2){
                std::cout << "You comply with FRED's wishes.  He gave you some great intel, after all.  And besides, you notice the quest reward is for only 1 gp.  Meh.\n\n";
                talking = false;
              }
              else{
                std::cout << "In your confusion, since " << sellout << " isn't a valid option, you wander off in a random direction, which happens to be back towards the pub wall.\n\n";
                talking = false;

              }

              talking = false;
            }
            
            else{
              std::cout << "Please choose a valid option.\n\n";
            }
          }

        }
        else if(second_choice == 3){
          std::cout << "You walk over to the space port and ask about how to get to the closest stop nearest the LAIR.  Tickets cost 10,000, your life savings.  Continue?\n\n";
          give_options({"Yes", "No"});
          int financial_choice = get_choice();
          if(financial_choice == 1){
            std::cout << "Adventure is life.  You spend your hard-earned coin for a ride to the LAIR.  The flight is awesome, by the way.  You hit 2 G's and spawned a pair of AVIATORS somehow.  Looking fabulous, you enter the LAIR.\n\n";
            gp -= 10000;
          }
          else if(financial_choice == 2){
            std::cout << "You decide this isn't for you and walk on back.\n\n";
            looking = false;
          }
          else{
            std::cout << "In your confusion, because obviously " << financial_choice << " isn't a valid choice, you wander on back from whence you came.\n\n";
            looking = false;
          }

          std::vector<std::string> dragon_choices = {"Slay DRAGON", "Escape DRAGON"};
          if(knows_dragon_secret == true){
            dragon_choices.push_back("Throw SHINY NEW DEVICE");
          }
          give_options(dragon_choices);
          std::cout << dragon_choices.size();
          int third_choice = get_choice();

          if(third_choice == 1){
            std::cout << "The only weapon you have on you is pepper spray.  Unfortunately, the dragon really likes spice.  You have died.\n\n";
            print_gp();
            return 0;
          }
          else if(third_choice == 2){
            std::cout << "You crouch low  Dragon notices you and you flee for your life.  Like the common house cat, the dragon appreciates a good chase.  You have died.\n\n";
            print_gp();
            return 0;
          }
          else if(knows_dragon_secret && third_choice == 3){
            std::cout << "You distract the dragon by throwing your SHINY NEW DEVICE.  Your high-school sportsball team experience paid off, and the Dragon chases down your phone with exhuberance.  You jog through the lair, loading your pockets with whatever you can find.\n\nLater, you discover your journey has been reimbursed by the Dragon, as 20000k, some jewelry, a miniature collection of Sherlock Holmes mysteries, and a strange document are in your pockets.\n";
            if(pub_bequeathed){
              std::cout << "\nYou also find a piece of paper.  When back to safety, you notice that it's a will and the name on it sounds awfully familiar.  It's your great aunt's.  That's who FRED was talking about!  You haven't heard that name for years.  Turns out, you've inherited the PUB where you found FRED!  GOOD ENDING 1/1\n\n";
            }
            print_gp();
            return 0;

          }
        }
        else if(second_choice == 0){
          looking = false;
        }
        else{
          std::cout << "\n\nPlease choose a valid option.\n\n";
        }
      }
    }
    else if(first_choice == 2){
      std::cout << "You move on with your day, opening the umbrella you forgot you had and purchasing a warm cup of space-pumpkin chai.  Your life progresses as planned, with a home in the city and a promotion you've been eyeing in the space-pod plant you work at.  Congrats, that's a pretty nice life!\n\n" << average_ending;
      game_runs = false;
    }
    else if(first_choice == 0){
      game_runs = false;
    }
    else{
      std::cout << "Please select a valid choice.\n";
    }
  }

  std::cout << "============================\n";
  std::cout << "THE END" << std::endl;
  std::cout << "============================\n";
  print_gp();
  return 0;
}

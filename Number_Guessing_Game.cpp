#include <iostream>
#include <random>

using namespace std;

int randomNumber();
void Ingame(string diff, int &life, int rand_num);
bool guessCheck(int user_guess, int rand_num);
int main(){

  int choice, life = 0, random_number = randomNumber(), attempt = 0;
  string difficulty;

  cout << "Welcome to the Number Guessing Game!\n";
  cout << "I'm thinking of a number between 1-100\n";
  
  cout << "Please choose the difficulty\n";
  cout << "1. Easy (10 Chances)\n";
  cout << "2. Medium (5 Chances)\n";
  cout << "3. Hard (3 Chances)\n";
  cin >> choice;
  switch (choice)
  {
  case 1:
    life = 10;
    difficulty = "Easy";
    Ingame(difficulty, life, random_number);
    break;
  case 2:
    life = 5;
    difficulty = "Medium";
    Ingame(difficulty, life, random_number);
    break;
  case 3:
    life = 3;
    difficulty = "Hard";
    Ingame(difficulty, life, random_number);
    break;
  default:
    break;
  }
}

int randomNumber(){ 
  random_device rd; 
  mt19937 gen(rd()); 
  uniform_int_distribution<> dis(1, 100); 
  return dis(gen);
}

void Ingame(string diff, int &life, int rand_num){
  std::cout << "You Have Chosen " << diff << " Mode \n";
  char response;
  int guess;
  int attempt = 1;
  while (life > 0){
  cout << "Lives : " << life << '\n';
  cout << "Your Guessing Number : ";
  cin >> guess;
  if(guessCheck(guess, rand_num)){
    std::cout << "You have Guessed the Number!\n";
    cout << "Attempts : " << attempt << '\n';
    cout << "Would You Like To Play Again?(Y/N)\n";
    cin >> response;
    if(response != 'Y' || response != 'y'){
      cout << "Thank You For Playing!\n";
      return;
    }
    else{
      main();
    }
  }
  else{
    life--;
    attempt++;
    if(life == 0){
      cout << "Game Over! You have run out of lives!\n";
      cout << "The correct number is " << rand_num;
      }
    }
  }
}

bool guessCheck(int user_guess, int rand_num){
  if(user_guess == rand_num){
    return true;
  }
  else if(user_guess < rand_num){
    cout << "Number Is Greater Than " << user_guess << "\n";
  }
  else{
    cout << "Number is Less Than " << user_guess << '\n';
  }
  return false;
}
#include <iostream>

/*
From Codecademy's Piggy Bank project for C++
*/

int main() {
  
  double pesos;
  double reais;
  double soles;
  double dollars;
  
  std::cout << "Enter number of Colombian Pesos: ";
  std::cin >> pesos;

  std::cout << "Enter number of Brazilian Reais: ";
  std::cin >> reais;

  std::cout << "Enter number of Peruvian Soles: ";
  std::cin >> soles;
  
  /*
  Conversion rate for:
    * Peso: 4,090.00
    * Real: 5.45
    * Nuevo Sole: 3.80

  as of 4/25/2024
  */

  pesos *= 4090;
  reais *= 5.45;
  soles *= 3.80;

  std::cout << "US Dollars = $" << pesos + reais + soles << std::endl;
  

}

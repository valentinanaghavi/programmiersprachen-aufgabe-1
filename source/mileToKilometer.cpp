#include <iostream>
#include <string>
#include <cmath>

    double mileToKilometer(double zahl){
      if (zahl>0){
      return (zahl/0.62137);
      }
      else{
        return 0;
      }
    }

int main() {

    std::cout << "Bitte gebe die Zahl, die von Meile zu Kilometer umgerechnet werden soll, ein: \n";
    double zahl = 0;
    std::cin >> zahl ;
    std::cout << zahl << " Meile(n) ist/sind " <<mileToKilometer(zahl) <<" Kilometer. \n" ;
    
    return 0;
}
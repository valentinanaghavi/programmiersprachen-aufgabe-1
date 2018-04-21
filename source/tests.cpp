#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include "catch.hpp"
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}


    int gemeinsamerTeiler (){

        bool gesZahl = false;
        int zaehler = 0;

        for (int i=1; gesZahl!=true; i++){
            for (int j=1; j<=20; j++){
               if( i % j == 0){
                   zaehler +=1;
                   if (zaehler == 20){
                       gesZahl = true;
                       std::cout << i <<std::endl;
                   }
               }

            }
            zaehler = 0;
        }
        return 0;
    }

    TEST_CASE ( " gemeinsamerTeiler " , " [gemeinsamerTeiler] " ){
      REQUIRE ( gemeinsamerTeiler() == 0);
    }

    int gcd(int a, int b){
      if(a==b){
        return a;
      }
      else{
        if (a>b){
          return(gcd(a-b,b));
        }
        else{
          return(gcd(b-a,a));
        }
      }
      return 1;
    }

    TEST_CASE("describe_gcd", "[gcd]"){
      REQUIRE(gcd(2,4) == 2);
      REQUIRE(gcd(9,6) == 3);
      REQUIRE(gcd(3,7) == 1);
    }

    int checksum(int zahl){
      int summe=0;
      if(zahl<=0){  // ausgabe der 0 fungiert als u.a. fehlermeldung
        return 0;
      }
      while(zahl != 0){
        summe += (zahl%10);
        zahl /= 10;
      }
      return summe;
    }

    TEST_CASE("quersumme", "[checksum]"){
      REQUIRE(checksum(-1) == 0); 
      REQUIRE(checksum(99423) == 27);
      REQUIRE(checksum(345) == 12);

    }

    int sumMulitples(){
      int summe=0;
      for(int i=1; i<=1000;i++){
        if (i%3==0 || i%5==0){
          summe+=i;
        }
      }
      std::cout << summe <<std::endl;
      return 1;
    }

    TEST_CASE("sumMultiples", "[sumMultiples]"){
      REQUIRE(sumMulitples() ==1);
    }

    
    double fract (double zahl){
      return (zahl -(int) zahl);
    }

    TEST_CASE("fract", "[fract]"){
      REQUIRE(fract(1.234) == Approx(0.234));
      REQUIRE(fract(155.634) == Approx(0.634));
      REQUIRE(fract(1.0) == Approx(0.0)); 
    }


    int zylinder(int r, int h){
      if(r>0 && h>0){
      float volumen = M_PI*(r*r)*h;
      float oberflaeche = (2*M_PI*(r*r))+(2*M_PI*r*h);

      std::cout <<"Volumen:" <<volumen << " Oberflaeche:"<< oberflaeche <<std::endl;

      return 1;
      }
      else{
        return 0; // ausgabe der 0 fungiert als u.a. fehlermeldung
      }
    }

    TEST_CASE("zylinder", "[zylinder]"){
      REQUIRE(zylinder(5,10) == 1);
      REQUIRE(zylinder(-5,10) == 0);

    }

    int factorial (int zahl){
      int produkt = 1;
      if (zahl<=0){
        return 0;
      }
      else {
        while (zahl != 0){
          produkt*=zahl;
          zahl--;
        }
        return produkt;
      }
    }

    TEST_CASE("factorial", "[factorial]"){
       REQUIRE(factorial(5)== 120);
       REQUIRE(factorial(-5)== 0);
       REQUIRE(factorial(10)== 3628800);


    }

    float binomial(int b, int a){ //a=k ,b=n mit n ueber k
    
      if(0<=a<=b){
        if((factorial(a) != 0 && factorial(b) != 0 && factorial(b-a)) != 0){
          float ergebnis = factorial(b) / (factorial(a) * factorial(b-a));
          return ergebnis;
        }
        else{ 
          return 0;
          }

      }
      else{
        return 0;
      }
    }

    TEST_CASE("binomial", "[binomial]"){
      REQUIRE(binomial(0,-2) == Approx(0.0));
      REQUIRE(binomial(10,6) == Approx(210.0));
      REQUIRE(binomial(6,4) == Approx(15.0));
    }


//bool is_prime(int zahk){
  //bool prim=false;
  //if(zahl<2 || zahl%2=0){
    //return prim;
  //}
  //else{

  //}

//}


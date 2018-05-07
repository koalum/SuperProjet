#ifndef CASE_H
#define CASE_H
#include <string>
#include "Individu.h"
using namespace std;

class Case {
   
   private :

   protected : 

   //Attributs

      int x_;
      int y_;
      Individu indi_; 
      vector<Metabolite> cExtra_; //vecteur des concentration des métabolites, c[0]=A, c[1]=B, c[2]=C

   public :

   //Constructors
      Case(int x, int y, Individu indi, float cExtra);

   //Destructors
      ~Case();

   //Getters

   //Setters

   //Methods
      void voie();
 
};

#endif

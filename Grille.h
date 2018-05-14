#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include<vector>
#include "Case.h"
using namespace std;

class Grille {
   
   private :

   protected : 

   //Attributs

      static const int W_;
      static const int H_;
      vector<vector<Case>>myGrid_;
      int nbS_; //nombre d'individus S
      int nbL_;

   public :

   //Constructors
      Grille();

   //Getters

   //Setters

   //Methods
      void afficheGrille();
 
};

#endif

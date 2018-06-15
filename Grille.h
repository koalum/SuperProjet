#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include<vector>
#include<map>
#include<iterator>
#include "Case.h"
#include <algorithm>
using namespace std;

class Grille {
   
   private :

   protected : 

   //Attributs

      static const int W_;
      static const int H_;
      static const float D;
      vector<vector<Case>>myGrid_;
      int nbS_; //nombre d'individus S
      int nbL_;
      int nbMorts_;
      float Ainit_;
      struct celluleMorte_{
         int x;
         int y;
      };

   public :

   //Constructors
      Grille(float Ainit);

   //Getters
      int nbS();
      int nbL();
      int nbMorts();

   //Setters

   //Methods
      void afficheGrille();
      void diffusionGenerale();
      void diffusion(int x,int y);
      void pasDeTemps();
      void mortAleatoireGenerale();
      void competitionGenerale();
      void competition(int x, int y);
      void reseauMetaboliqueGenerale();
      void count();
      void reinitialisationGenerale();
      void simulation(int T);
 
};

#endif

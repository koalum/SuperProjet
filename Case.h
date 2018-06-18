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
      bool vivant_; //false si l'individu meurt
      Individu indi_; 
      vector<Metabolite> cExtra_; //vecteur des concentration des métabolites, c[0]=A, c[1]=B, c[2]=C

   public :

   //Constructors
      Case(int x, int y, Individu indi, vector<Metabolite> cExtra);

   //Destructors
      //~Case();

   //Getters
      vector<Metabolite> cExtra();
      Individu indi();
      bool vivant();

   //Setters
      void vivant(bool viv);
      void individu(Individu indi);
      void cExtra(vector<Metabolite> cExt);

   //Methods
      void voie();
      void mortAleatoire();
      void deversement(Individu indi);
      void reinitialisation(float Ainit);
 
};

#endif

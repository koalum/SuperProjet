#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <string>
#include"Metabolite.h"
#include <vector>
using namespace std;

class Individu {
   
   private :

   protected : 

   //Attributs

      static const float pDeath;
      static const float pMut;
      static const float fitnessMIN;
      float fitness_;
      string genotype_;
      vector<Metabolite>phenotype_;


   public :

   //Constructors
      Individu();
      Individu(float fitness,string genotype,vector<Metabolite>phenotype_);

   //Destructors
      ~Individu();

   //Getters

   //Setters

   //Methods
      void mutation();
 
};

#endif

#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <string>
#include"Metabolite.h"
#include <vector>
using namespace std;

class Individu {

//commentaire Kaodi
   
   private :

   protected : 

   //Attributs

      static const float Raa_;
      static const float Rab_;
      static const float Rbb_;
      static const float Rbc_;
      static const float pDeath;
      static const float pMut;
      static const float fitnessMIN;
      float fitness_;
      string genotype_;
      vector<Metabolite>phenotype_;


   public :

   //Constructors
      Individu();
      Individu(string genotype,vector<Metabolite>phenotype_);

   //Destructors
      //~Individu();

   //Getters
      string genotype();
      vector<Metabolite> phenotype();
      float Raa() const;
      float Rab() const;
      float Rbb() const;
      float Rbc() const;
      float fitness();

   //Setters
      void setFitness(float w);      

   //Methods
      void mutation();
      void reseauMetabolite(float out);
      void seuilMinimum();
 
};

#endif

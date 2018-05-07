#include"Individu.h"
#include <iostream>
#include <time.h>
using namespace std;

const float Individu::pDeath=0.2;
const float Individu::pMut=0.1;
const float Individu::fitnessMIN=1;

//Constructors
Individu::Individu(float fitness,string genotype,vector<Metabolite>phenotype):fitness_(fitness),genotype_(genotype),phenotype_(phenotype){
}

//Destructors

//Méthodes
void Individu::mutation(){
   float nbAleatoire = 0;
   srand(time(NULL));
   nbAleatoire = (float)rand() / (float)RAND_MAX;
   if (nbAleatoire<pMut){
      if (genotype_=="Ga"){
         genotype_=="Gb";
      }
      else {
         genotype_=="Ga";
      }
   }
}

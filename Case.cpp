#include"Case.h"
#include <iostream>
#include <time.h>
using namespace std;


//Constructors
Case::Case(int x, int y, Individu indi, vector<Metabolite> cExtra):x_(x),y_(y),indi_(indi),cExtra_(cExtra){
  vivant_ = true;
}

//Getters
vector<Metabolite> Case::cExtra(){
   return cExtra_;
}

Individu Case::indi(){
   return indi_;
}

bool Case::vivant(){
   return vivant_;
}

//Setters

void Case::vivant(bool viv){
   vivant_ = viv;
}

void Case::individu(Individu indi){
   indi_=indi;
}

//Méthodes

void Case::voie(){
   if (indi_.genotype()=="Ga"){
      indi_.reseauMetabolite(cExtra_[0].concentration());
      cExtra_[0].concentration(-cExtra_[0].concentration()*indi_.Raa());
   } 
   else if(indi_.genotype()=="Gb") {
      indi_.reseauMetabolite(cExtra_[1].concentration());
      cExtra_[1].concentration(-cExtra_[1].concentration()*indi_.Rab());
   }
}

void Case::mortAleatoire(){
   float nbAleatoire = 0;
   nbAleatoire = (float)rand() / (float)RAND_MAX;
   if (nbAleatoire<indi_.pDeath()){
      vivant_ = false;
      deversement(indi_);//déversement
   }
}

void Case::deversement(Individu indi){
   Metabolite meta1 = Metabolite();
   Metabolite meta2 = Metabolite(0.1,'B',0.0);
   Metabolite meta3 = Metabolite(0.1,'C',0.0);
   vector<Metabolite>newExtra = {meta1, meta2, meta3};
   vector<Metabolite>phen = indi.phenotype();
   newExtra[0].concentration(phen[0].concentration() + cExtra_[0].concentration());
   newExtra[1].concentration(phen[1].concentration() + cExtra_[1].concentration());
   newExtra[2].concentration(phen[2].concentration() + cExtra_[2].concentration());
   cExtra_ =newExtra;
}


      

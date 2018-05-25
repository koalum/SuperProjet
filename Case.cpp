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
   srand(time(NULL));
   nbAleatoire = (float)rand() / (float)RAND_MAX;
   if (nbAleatoire<indi_.pDeath()){
      vivant_ = false;
      //MÉTHODE QUI FAIT QUE le contenu se déverse dans la case
   }
}


      

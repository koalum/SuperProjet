#include"Case.h"
#include <iostream>
using namespace std;


//Constructors
Case::Case(int x, int y, Individu indi, vector<Metabolite> cExtra):x_(x),y_(y),indi_(indi),cExtra_(cExtra){
}

//Destructors

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

      

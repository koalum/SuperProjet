#include"Grille.h"
#include <iostream>
#include <time.h>
using namespace std;

const int Grille::W_=4;
const int Grille::H_=4;

//Constructors

Grille::Grille () {
   nbS_=int((H_*W_)/2);
   nbL_=int((H_*W_)/2);
   Metabolite metA(0.1,'A',.0);
   Metabolite metB(0.1,'B',.0);
   Metabolite metC(0.1,'C',.0);
   vector<Metabolite>vec1 = {metA, metB, metC};
   Metabolite metA2(0.1,'A',20.0);
   Metabolite metB2(0.1,'B',.0);
   Metabolite metC2(0.1,'C',.0);
   vector<Metabolite>vecExtra = {metA2,metB2,metC2};
   Individu indi;
   for(int i=0; i<H_; ++i){
      for(int j=0; j<W_; ++j){
         if(nbS_==0){   
            indi=Individu("Ga", vec1);
            nbL_ = nbL_-1;
         } else if(nbL_==0){
            indi=Individu("Gb", vec1);
            nbS_ = nbS_-1;
         } else {
            float nbAleatoire = 0;
            srand(time(NULL));
            nbAleatoire = (float)rand() / (float)RAND_MAX;
            if (nbAleatoire >0.5){
               indi=Individu("Ga", vec1);
               nbL_ = nbL_-1;
            } else {
               indi=Individu("Gb", vec1);
               nbS_ = nbS_-1;
            }
         }
         myGrid_[i][j] = Case(i,j,indi,vecExtra);
      }
   }  
}

//Méthodes
void Grille::afficheGrille(){
   for(int i=0; i<H_; ++i){
      for(int j=0; j<W_; ++j){
         Individu indi = myGrid_[i][j].indi();
         if (indi.genotype()=="Ga"){
            cout<<"L "<<endl;
         } else {
            cout <<"S "<<endl;
         }
      }  
      cout<<" "<<endl;
   }
}



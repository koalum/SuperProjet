#include"Grille.h"
#include <iostream>
#include <time.h>
using namespace std;
//ceci est un commentaire

const int Grille::W_=10;
const int Grille::H_=10;
const float Grille::D=0.1;

//Constructors

Grille::Grille () {
   myGrid_.reserve(W_);
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
   float nbAleatoire = 0;
   srand(time(NULL));
   for(int i=0; i<H_; ++i){
      vector<Case>vecCase; 
      for(int j=0; j<W_; ++j){
         if(nbS_==0){   
            indi=Individu("Ga", vec1);
            nbL_ = nbL_-1;
         } else if(nbL_==0){
            indi=Individu("Gb", vec1);
            nbS_ = nbS_-1;
         } else {
            nbAleatoire = (float)rand() / (float)RAND_MAX;
            if (nbAleatoire >0.5){
               indi=Individu("Ga", vec1);
               nbL_ = nbL_-1;
            } else {
               indi=Individu("Gb", vec1);
               nbS_ = nbS_-1;
            }
         }
         vecCase.push_back(Case(i,j,indi,vecExtra));
      }
      myGrid_.push_back(vecCase);
   }  
}

//Méthodes
void Grille::afficheGrille(){
   Individu indi;
   for(int i=0; i<H_; ++i){
      for(int j=0; j<W_; ++j){
         indi = myGrid_[i][j].indi();
         if (myGrid_[i][j].vivant()){
            if (indi.genotype()=="Ga"){
               cout<<"L ";
            } else {
               cout <<"S ";
            }
         }
         else{
            cout<<" ";
         }
      }  
      cout<<" "<<endl;
   }
}

   //AUTRE SOLUTION AVEC ITERATEUR
   /*int iter;
   for(int i=0; i<H_; ++i){
      for (vector<Case>::const_iterator iter = myGrid_[i].begin(); iter != myGrid_[i].end(); ++iter){
         Case macase = *iter;
         Individu indi = macase.indi();
         string gen = indi.genotype();
         cout<<gen<<endl;
         cout<<"OK"<<endl;
         cout<<i<<endl;
      }  
   }*/

void Grille::diffusionGenerale(){
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){
         diffusion(i,j);
      }
   }
}

void Grille::diffusion(int x,int y){
   vector<Metabolite>meta = myGrid_[x][y].cExtra();
   vector<Metabolite>metanew = meta;
   vector<Metabolite>meta2;
   for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
         for (int k=0; k<3; k++){
            int a = x+i-1;
            int b = y=j-1;
            if (a<0){
              a = H_-1;
            }
            else if (a>(H_-1)){
              a=0;
            }
            if (b<0){
              b = W_-1;
            }
            else if (b>(W_-1)){
              b=0;
            }
            meta2 = myGrid_[a][b].cExtra();
            metanew[k].concentration(metanew[k].concentration()+D*meta2[k].concentration());
         }
      }
   }
   for (int k=0; k<3; k++){
      metanew[k].concentration(metanew[k].concentration()-9*D*meta[k].concentration());
   }
}

void Grille::pasDeTemps(){
  diffusionGenerale(); 
  mortAleatoireGenerale();
  competitionGenerale();
  reseauMetaboliqueGenerale(); 
}
   
void Grille::mortAleatoireGenerale(){ 
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){
         myGrid_[i][j].mortAleatoire();
      }
   }
}
   
void Grille::competitionGenerale(){ 
map<int,int>cellulesMortes;
int n=0;
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){ 
         Case maCase = myGrid_[i][j];  
         if (maCase.vivant()==false){
            cellulesMortes.insert(pair<int,int>(i,j));
         }
      }
   }
   map<int,int>::iterator item = cellulesMortes.begin();
   int randNum = rand()%(cellulesMortes.size() + 1);
   advance( item, randNum );
}

void Grille::competition(int x, int y){
   float bestFitness = .0;
   int alpha; //coordonnés de l'individu avec la meilleure fitness
   int beta;  //coordonnés de l'individu avec la meilleure fitness
   bool test = false; //bool pour tester si au moins 1 vivant autour
   for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
         int a = x+i-1;
         int b = y=j-1;
         if (a<0){
            a = H_-1;
         }
         else if (a>(H_-1)){
         a=0;
         }
         if (b<0){
            b = W_-1;
         }
         else if (b>(W_-1)){
            b=0;
         }
         Individu indi = myGrid_[a][b].indi();
         if (myGrid_[a][b].vivant()==true && indi.fitness()>bestFitness){
            test = true;
            bestFitness = indi.fitness();
            alpha = a; 
            beta = b;
         }
      }
   }
   if (test){
      Individu indiFille = myGrid_[alpha][beta].indi();
      indiFille.phenotypeFille();
      indiFille.mutation();
      myGrid_[alpha][beta].individu(indiFille); //point vers le même truc
      myGrid_[x][y].individu(indiFille);
      myGrid_[x][y].vivant(true);
   }
}

void Grille::reseauMetaboliqueGenerale(){ 
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){ 
         if (myGrid_[i][j].vivant() == true){
            myGrid_[i][j].voie();
         }
      }
   }
}

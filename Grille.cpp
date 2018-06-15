#include"Grille.h"
#include <iostream>
#include <time.h>
using namespace std;
//ceci est un commentaire

const int Grille::W_=10;
const int Grille::H_=10;
const float Grille::D=0.1;

//Constructors

Grille::Grille (float Ainit) {
   float Ainit_ = Ainit;
   myGrid_.reserve(W_);
   nbS_=int((H_*W_)/2);
   nbL_=int((H_*W_)/2);
   nbMorts_ = 0;
   int nombreS = nbS_ ;
   int nombreL = nbL_ ;
   Metabolite metA(0.1,'A',.0);
   Metabolite metB(0.1,'B',.0);
   Metabolite metC(0.1,'C',.0);
   vector<Metabolite>vec1 = {metA, metB, metC}; //vecteur de métabolite de l'individu de la case
   Metabolite metA2(0.1,'A',Ainit);
   Metabolite metB2(0.1,'B',.0);
   Metabolite metC2(0.1,'C',.0);
   vector<Metabolite>vecExtra = {metA2,metB2,metC2}; //vecteur de metabolites dans la case au temps 0
   Individu indi;
   float nbAleatoire = 0;
   srand(time(NULL));
   for(int i=0; i<H_; ++i){
      vector<Case>vecCase; 
      for(int j=0; j<W_; ++j){
         if(nbS_==0){   
            indi=Individu("Ga", vec1);
            nombreL = nombreL-1;
         } else if(nbL_==0){
            indi=Individu("Gb", vec1);
            nombreS = nombreS-1;
         } else {
            nbAleatoire = (float)rand() / (float)RAND_MAX;
            if (nbAleatoire >0.5){
               indi=Individu("Ga", vec1);
               nombreL = nombreL-1;
            } else {
               indi=Individu("Gb", vec1);
               nombreS = nombreS-1;
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
            cout<<"X ";
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

int Grille::nbS(){
   return nbS_;
}

int Grille::nbL(){
   return nbL_;
}

int Grille::nbMorts(){
   return nbMorts_;
}

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
   vector<struct celluleMorte_>cellulesMortes;
   struct celluleMorte_ maCelluleMorte;
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){ 
         Case maCase = myGrid_[i][j];  
         if (maCase.vivant()==false){
            maCelluleMorte.x = i;
            maCelluleMorte.y = j;
            cellulesMortes.push_back(maCelluleMorte);
         }
      }
   }
   random_shuffle(cellulesMortes.begin(), cellulesMortes.end());
   for(vector<struct celluleMorte_>::iterator it=cellulesMortes.begin(); it!=cellulesMortes.end(); ++it){
      competition(it->x, it->y);
   }
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
      myGrid_[alpha][beta].individu(indiFille); //pointent vers le même truc
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

void Grille::count(){
   nbS_ = 0;
   nbL_ = 0;
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){ 
         Case maCase = myGrid_[i][j];
         Individu indi = maCase.indi();
            if(maCase.vivant() == false){
               nbMorts_ +=1;
            }
            else {
               if(indi.genotype() == "Ga"){
                  nbL_ +=1;
               }
               else {
                  nbS_ +=1;
               }
            }
      }
   }
}

void Grille::reinitialisationGenerale(){
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){  
         myGrid_[i][j].reinitialisation(Ainit_);
      }
   }
}

void Grille::simulation(int T){
   for (int i=0; i<500; ++i){
      grille1.pasDeTemps();   
   }
}


#include"Individu.h"
#include <iostream>
#include <time.h>
using namespace std;

const float Individu::Raa_=0.1;
const float Individu::Rab_=0.1;
const float Individu::Rbb_=0.1;
const float Individu::Rbc_=0.1;
const float Individu::pDeath_=0.2;
const float Individu::pMut=0.5;
const float Individu::fitnessMIN=0.001;

//Constructors
Individu::Individu(){
   genotype_ = "Ga";
   Metabolite met;
   phenotype_={met, met, met};
}

Individu::Individu(string genotype,vector<Metabolite>phenotype):genotype_(genotype),phenotype_(phenotype){
   if (genotype_ == "Ga"){
      fitness_ = phenotype_[1].concentration();
   }
   else {
      fitness_ = phenotype_[2].concentration();
   }
   seuilMinimum();
}

//Destructors

//Getters

string Individu::genotype(){
   return genotype_;
}

vector<Metabolite> Individu::phenotype(){
   return phenotype_;
}

float Individu::Raa() const{
   return Raa_;
}

float Individu::Rab() const{
   return Rab_;
}

float Individu::Rbb() const{
   return Rbb_;
}

float Individu::Rbc() const{
   return Rbc_;
}

float Individu::pDeath() const{
  return pDeath_;
}

float Individu::fitness(){
   return fitness_;
}

//Setters
void Individu::setFitness(float w){
   fitness_=w;
   seuilMinimum();
}

//Méthodes
void Individu::mutation(){
   float nbAleatoire = 0;
   nbAleatoire = (float)rand() / (float)RAND_MAX;
   cout<<nbAleatoire<<endl;
   if (nbAleatoire<pMut){
      if (genotype_=="Ga"){
         genotype_="Gb";
      }
      else {
         genotype_="Ga";
      }
   }
   resetFitness();
}

void Individu::reseauMetabolite(float out){
  if (genotype_=="Ga"){
      phenotype_[0].concentration(out*Raa_ - phenotype_[0].concentration()*Rab_);
      phenotype_[1].concentration(phenotype_[0].concentration()*Rab_);
   }
   else {
      phenotype_[1].concentration(out*Rbb_ - phenotype_[1].concentration()*Rbc_);
      phenotype_[2].concentration(phenotype_[1].concentration()*Rbc_);
   }
}

void Individu::seuilMinimum(){
   if (fitness_<fitnessMIN){
      fitness_=.0;
   }
}

void Individu::phenotypeFille(){
   for(int i=0; i<3; ++i){
      float concentrationFille = phenotype_[i].concentration()/2;
      phenotype_[i].concentration(concentrationFille);
   }
   resetFitness();
}
 
void Individu::resetFitness(){
   if (genotype_ == "Ga"){
      fitness_ = phenotype_[1].concentration();
   }
   else {
      fitness_ = phenotype_[2].concentration();
   }
   seuilMinimum();
}

   

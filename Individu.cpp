/******************************************************

                  | INCLUDES |

*******************************************************/
#include"Individu.h"
#include <iostream>
#include <time.h>
using namespace std;


/******************************************************

                  | ATTRIBUTS CONSTANTS |

*******************************************************/

//TAUX METABOLIQUES
const float Individu::Raa_=0.1;
const float Individu::Rab_=0.1;
const float Individu::Rbb_=0.1;
const float Individu::Rbc_=0.1;

//PROBABILITÉS
const float Individu::pDeath_=0.02; //Probabilité de mort
const float Individu::pMut=0.0; //Probabilité de mutation

const float Individu::fitnessMIN=0.001;


/******************************************************

                  | CONSTRUCTEURS |

*******************************************************/

//PAR DEFAUT
Individu::Individu(){
   genotype_ = "Ga";
   Metabolite met;
   phenotype_={met, met, met};
   fitness_ = phenotype_[1].concentration();
}

//PAR COPIE
Individu::Individu(string genotype,vector<Metabolite>phenotype):genotype_(genotype),phenotype_(phenotype){
   if (genotype_ == "Ga"){
      fitness_ = phenotype_[1].concentration();
   }
   else {
      fitness_ = phenotype_[2].concentration();
   }
   seuilMinimum();
}


/******************************************************

                  | GETTERS |

*******************************************************/

string Individu::genotype(){
   return genotype_;
}

vector<Metabolite> Individu::phenotype(){
   return phenotype_;
}

//TAUX METABOLIQUES
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


/******************************************************

                  | SETTERS |

*******************************************************/

//FITNESS
void Individu::setFitness(float w){
   fitness_=w;
   seuilMinimum();
}


/******************************************************

                  | METHODES |

*******************************************************/

//SEUIL MINIMUM 

/*Méthode qui permet aux individus avec une fitness tro faible de se reproduire

Préconditions : l'individu doit être vivant
Postconditions : si la fitness de l'individu est inférieure à la fitness minimal, elle est mise à 0
                 l'individu ne pourra pas se reproduire*/

void Individu::seuilMinimum(){
   if (fitness_<fitnessMIN){
      fitness_=.0;
   }
}

//RESET FITNESS

/*Méthode qui permet de mettre à jour la fitness d'un individu

Préconditions : l'individu doit être vivant
Postconditions : on affecte la nouvelle fitness à l'individu, 
                 on applique la méthode seuilMinimum() */
 

void Individu::resetFitness(){
   if (genotype_ == "Ga"){
      fitness_ = phenotype_[1].concentration();
   }
   else {
      fitness_ = phenotype_[2].concentration();
   }
   seuilMinimum();
}


//MUTATION

/*Méthode qui permet aux individus de muter de façon aléatoire avec une probabilité Pmut.
On crée un nombre aleatoire entre 0 et 1, si ce nombre aléatoire est inférieur à la probabilité de mutation, 
l'individu change de génotype (L devient S et vice-versa)

Préconditions : aucune
Postconditions : l'individu change de genotype et da fitness et mise à jour */

void Individu::mutation(){
   float nbAleatoire = 0;
   nbAleatoire = (float)rand() / (float)RAND_MAX;
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

//RESEAU METABOLITE

/*Méthode qui permet de décrire le réseau métabolique et les échanges par les voies métaboliques à l'intérieur d'un individu

Préconditions : l'individu doit être vivant
Postconditions : le phenotype (la concentration de chaque métabolite) de chaque individu change,
                 la fitness est mise à jour*/

void Individu::reseauMetabolite(float out){
  if (genotype_=="Ga"){
      float dA = out*Raa_ - phenotype_[0].concentration()*Rab_;
      float A = phenotype_[0].concentration();
      float dB = phenotype_[0].concentration()*Rab_;
      float B = phenotype_[1].concentration();
      phenotype_[0].concentration(dA + A); //dA + A
      phenotype_[1].concentration(dB + B);  //dB + B
      setFitness(phenotype_[0].concentration());
   }
   else {
      float dB = out*Rbb_ - phenotype_[1].concentration()*Rbc_;
      float B = phenotype_[0].concentration();
      float dC = phenotype_[1].concentration()*Rbc_;
      float C = phenotype_[1].concentration();
      phenotype_[1].concentration(dB + B);
      phenotype_[2].concentration(dC + C);
      setFitness(phenotype_[1].concentration());
   }
}


//PHENOTYPE FILLE

/*Méthode qui permet de calculer le phenotype de l'individu fils aprés division de la bactérie mère

Préconditions : l'individu doit être vivant
Postconditions : la cellule fille a le phénotype de la mère divisé par 2 */

void Individu::phenotypeFille(){
   for(int i=0; i<3; ++i){
      float concentrationFille = phenotype_[i].concentration()/2;
      phenotype_[i].concentration(concentrationFille);
   }
   resetFitness();
}


   

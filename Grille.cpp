/******************************************************

                  | INCLUDES |

*******************************************************/
#include"Grille.h"
#include <iostream>
#include <time.h>
using namespace std;

/******************************************************

                  | ATTRIBUTS CONSTANTS |

*******************************************************/

const int Grille::W_=32;
const int Grille::H_=32;
const float Grille::D=0.1;

/******************************************************

                  | CONSTRUCTEURS|

*******************************************************/

Grille::Grille (float Ainit) {
   Ainit_ = Ainit;
   myGrid_.reserve(W_);
   myGrid_.reserve(H_);
   nbS_=int((H_*W_)/2);
   nbL_=int((H_*W_)/2);
   nbMorts_ = 0;
   int nombreS = nbS_ ;
   int nombreL = nbL_ ;
   Metabolite metA(0.1,'A',.0);
   Metabolite metB(0.1,'B',.0);
   Metabolite metC(0.1,'C',.0);
   vector<Metabolite>vec1 = {metA, metB, metC}; //vecteur de métabolites de l'individu de la case
   Metabolite metA2(0.1,'A',Ainit);
   Metabolite metB2(0.1,'B',.0);
   Metabolite metC2(0.1,'C',.0);
   vector<Metabolite>vecExtra = {metA2,metB2,metC2}; //vecteur de metabolitess dans la case au temps 0
   Individu indi;
   float nbAleatoire = 0; //remplissage aléatoire de la grille
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


/******************************************************

                  | GETTERS |

*******************************************************/

int Grille::nbS(){
   return nbS_;
}

int Grille::nbL(){
   return nbL_;
}

int Grille::nbMorts(){
   return nbMorts_;
}

vector<vector<Case>> Grille::myGrid(){
   return myGrid_;
}

float Grille::Ainit(){
   return Ainit_;
}

int Grille::resultats(){
   return resultats_;
}


/******************************************************

                  | METHODES |

*******************************************************/

//AFFICHE GRILLE

/*Méthode d'affichage de la grille*/
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


//DIFFUSION GENERALE

/*Méthode qui parcourt la grille et applique la méthode diffusion*/


void Grille::diffusionGenerale(){
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){
         diffusion(i,j);
      }
   }
}

//DIFFUSION

/*Méthode qui décrit le processus de diffusion selon l'algorithme donné

Préconditions : la diffusion doit être D<0.1
Postconditions : les métabolites se diffusent dans la case*/

void Grille::diffusion(int x,int y){
   vector<Metabolite>meta = myGrid_[x][y].cExtra();
   vector<Metabolite>metanew = meta;
   vector<Metabolite>meta2;
   for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
         for (int k=0; k<3; k++){
            int a = x+i-1;
            int b = y+j-1;
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
   myGrid_[x][y].cExtra(metanew);
}

//MORT ALEATOIRE GENERALE

/*Méthode qui parcourt la grille et applique la méthode mortAleatoire à chaque Case*/


void Grille::mortAleatoireGenerale(){ 
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){
         myGrid_[i][j].mortAleatoire();
      }
   }
}

//COMPETITION

/*Méthode qui décrit la compétition entre individus lorsqu'au moins un individu d'une case voisine meurt

Préconditions : un individu doit mourir pour que la méthode soit appliquée
Postconditions : l'individu avec la meilleure fitness occupe la case libre et se divise en deux cellules filles */

void Grille::competition(int x, int y){
   float bestFitness = .0;
   int alpha; //coordonnés de l'individu avec la meilleure fitness
   int beta;  //coordonnés de l'individu avec la meilleure fitness
   bool test = false; //bool pour tester si au moins 1 vivant autour
   for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
         int a = x+i-1;
         int b = y+j-1;
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
   if (test){ //Si il y a au moins 1 vivant autour
      Individu indiFille = myGrid_[alpha][beta].indi();
      indiFille.phenotypeFille();
      indiFille.mutation();
      myGrid_[alpha][beta].individu(indiFille); 
      myGrid_[x][y].individu(indiFille);
      myGrid_[x][y].vivant(true);
   }
}
//COMPETITION GENERALE

/*Méthode qui parcourt la grille et applique la méthode de competition à chaque case*/
   
void Grille::competitionGenerale(){ 
   vector<struct celluleMorte_>cellulesMortes; //Vector de coordonnées des cellules mortes
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

//RESEAU METABOLIQUE GENERALE

/*Méthode qui parcourt la grille et applique la méthode voie()*/

void Grille::reseauMetaboliqueGenerale(){ 
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){ 
         if (myGrid_[i][j].vivant() == true){
            myGrid_[i][j].voie();
         }
      }
   }
}


//COUNT

/*Méthode qui compte le nombre d'individus L et S et qui renvoie l'état d'équilibre du système

Préconditions : un individu doit mourir pour que la méthode soit appliquée
Postconditions : l'individu avec la meilleure fitness occupe la case libre et se divise en deux cellules filles */

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
   if(nbS_ == 0 && nbL_ == 0){
      cout<<"Extinction"<<endl;
      resultats_ = 0; //Il ne reste ni de L ni de S
   }
   else if (nbS_ == 0 ){
      cout<<"Exclusion S"<<endl;
      resultats_ = 1; //Il ne reste que des L
   }
   else if (nbL_ == 0 ){
      cout<<"Exclusion L"<<endl;
      resultats_ = 2; //Il ne reste que des S
   }
   else {
      cout<<"Cohabitation"<<endl;
      resultats_ = 3; //Il reste des individus S et L
   }

}

//REINITIALISATION GENERALE

/*Méthode qui parcourt la grille et applique la méthode de réinitialisation à chaque case

Préconditions : aucune
Postconditions : la grille est reinitialisée avec une concentration Ainit*/

void Grille::reinitialisationGenerale(){
   for(int i=0; i<H_; i++){
      for(int j=0; j<W_; j++){  
         myGrid_[i][j].reinitialisation(Ainit_);
      }
   }
}

//PAS DE TEMPS

/*Méthode qui décrit l'algorithme évolutif à chaque pas de temps de la simulation

Préconditions : aucune
Postconditions : on applique les 4 méthodes à la suite*/

void Grille::pasDeTemps(){
  diffusionGenerale(); 
  mortAleatoireGenerale();
  competitionGenerale();
  reseauMetaboliqueGenerale(); 
}
   
//SIMULATION

/*Méthode qui reinitialise le système à chaque pas de temps

Préconditions : aucune
Postconditions : une simulation dure 5000 itérations*/

void Grille::simulation(int T){
   int i = 0;
   while (i<5000){ 
      pasDeTemps();
      if(i%T==0){
         reinitialisationGenerale();  
      }
      i++;

   }
}




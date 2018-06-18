#include <iostream>
#include "Metabolite.h"
#include "Individu.h"
#include "Case.h"
#include "Grille.h"
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {   
   srand(time(NULL));
   //TESTS

   //TEST INDIVIDU
   cout<<"notre super projet avance !"<<endl;
   Metabolite metA(0.1,'A',25.0);
   Metabolite metB(0.1,'B',-20.0);
   Metabolite metC(0.1,'C',0.0);
   vector<Metabolite>vec1 = {metA, metB, metC};
   Individu bac1=Individu("Ga",vec1);
   cout<<bac1.genotype()<<endl;
   cout<<"w : " << bac1.fitness()<<endl;
   //bac1.mutation();
   cout<<bac1.genotype()<<endl;
 
   /*//TEST CASE
   Case case1 = Case(1,1,bac1,vec1);
   vector<Metabolite>monVec = case1.cExtra();
   cout<<"A : "<< monVec[0].concentration()<<endl;
   cout<<"B : "<< monVec[1].concentration()<<endl;
   cout<<"C : "<< monVec[2].concentration()<<endl;

   vector<Metabolite>monVecPhen = bac1.phenotype();
   cout <<"A dans indi : "<<monVecPhen[0].concentration()<<endl;
   cout <<"B dans indi : "<<monVecPhen[1].concentration()<<endl;
   cout <<"C dans indi : "<<monVecPhen[2].concentration()<<endl;

   case1.voie();
   vector<Metabolite>monVec2 = case1.cExtra();
   cout<<"A : "<< monVec2[0].concentration()<<endl;
   cout<<"B : "<< monVec2[1].concentration()<<endl;
   cout<<"C : "<< monVec2[2].concentration()<<endl;

   vector<Metabolite>monVecPhen2 = bac1.phenotype();
   cout <<"A dans indi : "<<monVecPhen2[0].concentration()<<endl;
   cout <<"B dans indi : "<<monVecPhen2[1].concentration()<<endl;
   cout <<"C dans indi : "<<monVecPhen2[2].concentration()<<endl;*/

/*

   //TEST GRILLE
   cout <<"TEST GRILLE: "<< endl;
   Grille grille1 = Grille(50.0);
   grille1.afficheGrille();

   //TEST DIFFUSION
   
   grille1.simulation(1000);
   cout <<" "<< endl;
   grille1.afficheGrille();
   grille1.count();
   cout<<"S : " <<grille1.nbS()<<endl;
   cout<<"L : "<<grille1.nbL()<<endl;
   cout<<"X : "<<grille1.nbMorts()<<endl;

   /*A FAIRE :
   Commenter le code
   Le rendre beau
   Interface graphique
   timer
   récupération données

   */

//TEST RUN
   cout <<"TEST RUN: "<< endl;
   float Ainit = 50.0;
   int T = 1500;
   ofstream myfile;
   myfile.open ("test.txt");
   for (int i=0; i<=Ainit; i=i+50){
      for(int j=1; j<=T; j=j+1499){
         Grille grille1 = Grille((float)(i));
         grille1.simulation(j);

         cout<<"Ainit = "<<i<<endl;
         cout<<"Changement tous les :" <<j<<endl;
         grille1.count();
         cout<<"S : " <<grille1.nbS()<<endl;
         cout<<"L : "<<grille1.nbL()<<endl;
         cout<<"X : "<<grille1.nbMorts()<<endl;
         myfile << left <<"\t"<< setw(10) << i << left <<"\t"<< setw(10) << j << left <<"\t"<< setw(10) <<grille1.resultats()<<endl;
      }
   }
   myfile.close();

/*Grille grille1 = Grille(30.0);
    float temps;
    clock_t t1, t2;
 
    t1 = clock();
grille1.simulation(200);
grille1.count();
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);*/



   
   
   return 0;
}


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

   cout<<"notre super projet est fini !"<<endl;

 

//TEST RUN
   cout <<"TEST RUN: "<< endl;
   float Ainit = 50.0;
   int T = 1500;
   ofstream myfile;
   myfile.open ("T4.txt"); //T1 pmut=0, T2 pmut=0.1, T3 et T4 augm pas de temps
   for (int i=0; i<=Ainit; ++i){
      for(int j=1; j<=T; j=j+10){ //pas de temps = 10
         Grille grille1 = Grille((float)(i));
         grille1.simulation(j);
         grille1.count();
         /*cout<<"Ainit = "<<i<<endl;
         cout<<"Changement tous les :" <<j<<endl;
         grille1.count();
         cout<<"S : " <<grille1.nbS()<<endl;
         cout<<"L : "<<grille1.nbL()<<endl;
         cout<<"X : "<<grille1.nbMorts()<<endl;*/

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


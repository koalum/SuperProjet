/******************************************************

                  | INCLUDES |

*******************************************************/
#include <iostream>
#include "Metabolite.h"
#include "Individu.h"
#include "Case.h"
#include "Grille.h"
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

/******************************************************

                  | MAIN |

*******************************************************/

   int main() {   

      srand(time(NULL));   //Pour l'utilisation des nombre aléatoires

      cout<<"Projet Developpement Logiciel"<<endl;
      cout<<"Auteurs : J. Holland, K. Alum "<<endl;

  

   //RUN
      cout <<"TEST RUN: "<< endl;
      float Ainit = 50.0;
      int T = 1500;
      ofstream myfile;
      myfile.open ("simulation.txt"); //recuperation des données dans un fichier texte 

      for (int i=0; i<=Ainit; ++i){ //la concentration Ainit change de 10 en 10
         for(int j=1; j<=T; j=j+100){ //on reinitialise la grille tous les 100 pas de temps
          Grille grille1 = Grille((float)(i));
            grille1.simulation(j);
            grille1.count();

         myfile << left <<"\t"<< setw(10) << i << left <<"\t"<< setw(10) << j << left <<"\t"<< setw(10) <<grille1.resultats()<<endl;
      }
   }
   myfile.close();

    //CALCUL DU TEMPS DE SIMULATION

      /*Grille grille1 = Grille(30.0);
        float temps;
        clock_t t1, t2;
        t1 = clock();
        grille1.simulation(5000);
        grille1.count();
        t2 = clock();
        temps = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("temps = %f\n", temps);*/


   
   return 0;
}


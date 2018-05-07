#include <iostream>
#include "Metabolite.h"
#include "Individu.h"
#include "Case.h"
#include "Grille.h"


using namespace std;

int main() {

   //TESTS
   cout<<"notre super projet avance trop bien!"<<endl;
   Metabolite metA(0.1,'A',25.0);
   Metabolite metB(0.1,'B',0.0);
   Metabolite metC(0.1,'C',0.0);
   vector<Metabolite>vec1 = {metA, metB, metC};
   Individu bac1=Individu(0.2,"Ga",vec1);
   cout<<bac1.genotype()<<endl;
   bac1.mutation();
   cout<<bac1.genotype()<<endl;
   
   Case case1 = Case(1,1,bac1,vec1);
   return 0;
}


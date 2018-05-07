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
   Metabolite metB(0.1,'B',20.0);
   Metabolite metC(0.1,'C',0.0);
   vector<Metabolite>vec1 = {metA, metB, metC};
   Individu bac1=Individu(0.2,"Ga",vec1);
   cout<<bac1.genotype()<<endl;
   //bac1.mutation();
   cout<<bac1.genotype()<<endl;
   
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
   cout <<"C dans indi : "<<monVecPhen2[2].concentration()<<endl;


   return 0;
}


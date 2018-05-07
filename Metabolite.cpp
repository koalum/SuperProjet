#include"Metabolite.h"
#include <iostream>
using namespace std;

//Constructors
Metabolite::Metabolite(float D, char type, float concentration):D_(D),type_(type), concentration_(concentration){
}

Metabolite::Metabolite(){
   D_ = 0.1;
   type_ = 'A';
   concentration_ = 20.0;
}

//Getters
float Metabolite::concentration(){
   return concentration_;
}

//Setters
void Metabolite::concentration(float concentration){
   concentration_=concentration;
}


//Destructors
//Méthodes

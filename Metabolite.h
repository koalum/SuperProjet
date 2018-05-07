#ifndef METABOLITE_H
#define METABOLITE_H
#include <string>
using namespace std;

class Metabolite {
   
   private :

   protected : 

   //Attributs

      float D_;
      char type_;
      float concentration_;

   public :

   //Constructors
      Metabolite(float D, char type, float concentration);
      Metabolite();

   //Destructors
      //~Metabolite();

   //Getters
      float concentration();
   //Setters
      void concentration(float concentration);

   //Methods
 
};

#endif

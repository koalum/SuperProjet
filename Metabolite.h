/******************************************************

                  | INCLUDES |

*******************************************************/

#ifndef METABOLITE_H
#define METABOLITE_H
#include <string>
using namespace std;

/******************************************************

                  | METABOLITE |

*******************************************************/

class Metabolite {
   
   private :

   protected : 

   //ATTRIBUTS

      float D_; //Coefficient de diffusivité
      char type_; //Type de métabolite diffusé. A : Glucose, B : acétate, C : éthanol.
      float concentration_; 

   public :

   //CONSTRUCTEURS
      Metabolite();
      Metabolite(float D, char type, float concentration);


   //GETTERS
      float concentration();

   //SETTERS
      void concentration(float concentration);
 
};

#endif

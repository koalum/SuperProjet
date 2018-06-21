/******************************************************

                  | INCLUDES |

*******************************************************/

#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <string>
#include"Metabolite.h"
#include <vector>
using namespace std;


/******************************************************

                  | INDIVIDU |

*******************************************************/


class Individu {
   
   private :

   protected : 


/******************************************************

                  | ATTRIBUTS |

*******************************************************/

      static const float Raa_;
      static const float Rab_;
      static const float Rbb_;
      static const float Rbc_;
      static const float pDeath_;
      static const float pMut;
      static const float fitnessMIN;
      float fitness_;
      string genotype_;
      vector<Metabolite>phenotype_;


   public :

/******************************************************

                  | CONSTRUCTEURS|

*******************************************************/

      //PAR DEFAUT
      Individu();

      //PAR COPIE
      Individu(string genotype,vector<Metabolite>phenotype_);



/******************************************************

                  | GETTERS |

*******************************************************/
      
      string genotype();
      vector<Metabolite> phenotype();

      //TAUX METABOLIQUES
      float Raa() const;
      float Rab() const;
      float Rbb() const;
      float Rbc() const;

      float fitness();
      float pDeath() const;


/******************************************************

                  | SETTERS |

*******************************************************/
      
      void setFitness(float w);     


/******************************************************

                  | METHODES |

*******************************************************/
      
      void mutation();
      void reseauMetabolite(float out);
      void seuilMinimum();
      void phenotypeFille();
      void resetFitness();
 
};

#endif

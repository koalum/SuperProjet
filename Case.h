/******************************************************

                  | INCLUDES |

*******************************************************/

#ifndef CASE_H
#define CASE_H
#include <string>
#include "Individu.h"
using namespace std;

/******************************************************

                  | CASE |

*******************************************************/

class Case {
   
   private :

   protected : 

/******************************************************

                  | ATTRIBUTS |

*******************************************************/

      int x_;
      int y_;
      bool vivant_; //boolean qui est false si l'individu est mort
      Individu indi_; 
      vector<Metabolite> cExtra_; //vecteur des concentration des métabolites dans une case, c[0]=A : concentration en glucose, c[1]=B : concentration en acétate, c[2]=C : concentration en éthanol

   public :

/******************************************************

                  | CONSTRUCTEURS |

*******************************************************/

     //PAR DEFAUT
     Case(int x, int y, Individu indi, vector<Metabolite> cExtra);


/******************************************************

                  | GETTERS |

*******************************************************/

      vector<Metabolite> cExtra(); 
      Individu indi();
      bool vivant();


/******************************************************

                  | SETTERS |

*******************************************************/

      void vivant(bool viv);
      void individu(Individu indi);
      void cExtra(vector<Metabolite> cExt);

/******************************************************

                  | METHODES |

*******************************************************/
      void voie();
      void mortAleatoire();
      void deversement(Individu indi);
      void reinitialisation(float Ainit);
 
};

#endif

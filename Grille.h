/******************************************************

                  | INCLUDES |

*******************************************************/
#ifndef GRILLE_H
#define GRILLE_H
#include <string>
#include<vector>
#include<map>
#include<iterator>
#include "Case.h"
#include <algorithm>
using namespace std;

/******************************************************

                  | GRILLE |

*******************************************************/
class Grille {
   
   private :

   protected : 

/******************************************************

                  | ATTRIBUTS |

*******************************************************/

      static const int W_; //largeur grille
      static const int H_; //hauteur grille
      static const float D; //constante de diffusivité
      vector<vector<Case>>myGrid_;
      int nbS_; //nombre d'individus S
      int nbL_; //nombre d'individus L
      int nbMorts_;
      float Ainit_;
      struct celluleMorte_{ //Coordonées des cellules mortes
         int x;
         int y;
      };
      int resultats_; //variable pour la récupération des données

   public :

/******************************************************

                  | CONSTRUCTEURS |

*******************************************************/

      Grille(float Ainit);

/******************************************************

                  | GETTERS |

*******************************************************/
      int nbS();
      int nbL();
      int nbMorts();
      vector<vector<Case>>myGrid(); //recuperer une case
      float Ainit();
      int resultats();

/******************************************************

                  | SETTERS |

*******************************************************/

/******************************************************

                  | METHODES |

*******************************************************/

      void afficheGrille();
      void diffusionGenerale();
      void diffusion(int x,int y);
      void pasDeTemps();
      void mortAleatoireGenerale();
      void competitionGenerale();
      void competition(int x, int y);
      void reseauMetaboliqueGenerale();
      void count();
      void reinitialisationGenerale();
      void simulation(int T);
 
};

#endif

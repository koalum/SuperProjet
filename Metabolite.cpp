/******************************************************

                  | INCLUDES |

*******************************************************/

#include"Metabolite.h"
#include <iostream>
using namespace std;

/*******************************************************

                 | CONSTRUCTEURS |

********************************************************/

//CONSTRUCTEUR PAR DEFAUT
Metabolite::Metabolite(){
   D_ = 0.1;
   type_ = 'A';
   concentration_ = 20.0;
}

//CONSTRUCTEUR PAR COPIE
Metabolite::Metabolite(float D, char type, float concentration):D_(D),type_(type), concentration_(concentration){
}

/*******************************************************

                 | GETTERS |

********************************************************/

float Metabolite::concentration(){
   return concentration_;
}

/*******************************************************

                 | SETTERS |

********************************************************/

//CONCENTRATION
void Metabolite::concentration(float concentration){
   concentration_=concentration;
}


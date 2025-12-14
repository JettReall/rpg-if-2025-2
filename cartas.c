#include "structs.h"

CARTA magico1={"Disparo Magico","Dispara um pequeno projetil magico",ATAQUEMAG,5};
CARTA magico2={"Missel Magico","Dispara um missel magico",ATAQUEMAG,10};
CARTA magico3={"BOMBA MAGICA","Dispara uma BOMBA de magia",ATAQUEMAG,15};

CARTA fisico1={"Soco Rapido","Profere rapido soco",ATAQUEFIS,5};
CARTA fisico2={"Corte leve","Profere um leve corte",ATAQUEFIS,10};
CARTA fisico3={"VOADORA","Profere UMA VOADORA COM OS DOIS PE",ATAQUEFIS,15};

CARTA cura1={"Cura Inferior","realiza um ritual fraco de cura",CURA,5};
CARTA cura2={"Cura Media","realiza um ritual normal de cura",CURA,10};
CARTA cura3={"Cura SUPERIOR","realiza um ritual de cura SUPERIOR",CURA,15};

CARTA CatalogoCartas[3][3]={ //primeiro indico=classe, segundo=forca;
    {fisico1,fisico2,fisico3},
    {magico1,magico2,magico3},
    {cura1,cura2,cura3}
};
#include "structs.h"

CARTA CatalogoCartas[3][3] = {
    // Linha 0: Físicos
    {
        {"Soco Rapido","Profere rapido soco",ATAQUEFIS,5},
        {"Corte leve","Profere um leve corte",ATAQUEFIS,10},
        {"VOADORA","Profere UMA VOADORA COM OS DOIS PE",ATAQUEFIS,15}
    },
    // Linha 1: Mágicos
    {
        {"Disparo Magico","Dispara um pequeno projetil magico",ATAQUEMAG,5},
        {"Missel Magico","Dispara um missel magico",ATAQUEMAG,10},
        {"BOMBA MAGICA","Dispara uma BOMBA de magia",ATAQUEMAG,15}
    },
    // Linha 2: Cura
    {
        {"Cura Inferior","realiza um ritual fraco de cura",CURA,5},
        {"Cura Media","realiza um ritual normal de cura",CURA,10},
        {"Cura SUPERIOR","realiza um ritual de cura SUPERIOR",CURA,15}
    }
};
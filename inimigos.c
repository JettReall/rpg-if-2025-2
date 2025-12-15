#include "inimigos.h"

INIMIGOS inimigo[max_inimigo_sala] = {0}; 
const INIMIGOS Inimigo_Nulo = {
    .Nome = "Dummy",
    .Xp =0,
    .Stat = {0},
    .Habilidades[0] = {.Nome = "Nula",.Tipo = NULO,.Valor = NULO},
    .Habilidades[1] = {.Nome = "Nula",.Tipo = NULO,.Valor = NULO},
};


//Inimigo_Nulo;

INIMIGOS CatalogoVento[max_inimigo_Dungeon] = {
    [BOSS] = {
        .Nome = "Grande Harpia",
        .Xp = 1500,
        .Stat = {50,15,15,10,25,25}, //Hp, Def fis, Def Mag, Speed, Atk fis, Atk Mag
        .HpAtual = 50,
        .Habilidades[0] = {.Nome = "Dilacerar",.Tipo = ATAQUEFIS,.Valor = 20},
        .Habilidades[1] = {.Nome = "Hipoxia",.Tipo = ATAQUEMAG,.Valor = 30},
    },
    [FACIL] = {
        .Nome = "Falcão",
        .Xp = 100,
        .Stat = {10,5,5,5,10,0}, //Hp, Def fis, Def Mag, Speed, Atk fis, Atk Mag
        .HpAtual = 10,
        .Habilidades[0] = {.Nome = "Bicar",.Tipo = ATAQUEFIS,.Valor = 5},
        .Habilidades[1] = {.Nome = "Rasgar",.Tipo = ATAQUEFIS,.Valor = 10},  
    },
    [MEDIO] = {
        .Nome = "Elemental de Vento",
        .Xp = 250,
        .Stat = {20,10,10,0,5,20}, //Hp, Def fis, Def Mag, Speed, Atk fis, Atk Mag
        .HpAtual = 20,
        .Habilidades[0] = {.Nome = "Gume de vento",.Tipo = ATAQUEMAG,.Valor = 10},
        .Habilidades[1] = {.Nome = "Asfixiar",.Tipo = ATAQUEFIS,.Valor = 10},  
    },
    [DIFICIL] = {
        .Nome = "Hipogrifo",
        .Xp = 500,
        .Stat = {20,10,15,10,10,10}, //Hp, Def fis, Def Mag, Speed, Atk fis, Atk Mag
        .HpAtual = 20,
        .Habilidades[0] = {.Nome = "Bicar",.Tipo = ATAQUEFIS,.Valor = 10},
        .Habilidades[1] = {.Nome = "Coice",.Tipo = ATAQUEFIS,.Valor = 15}, 
    }
};

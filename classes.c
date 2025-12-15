#include "structs.h"
#include <string.h>


PERSONAGEM DadosClasses[MAX_CLASSES] = {
    [GUERREIRO] = {.Stat = {150,10,10,5,10,5},.HpAtual=150,.Classe=GUERREIRO},
    [MAGO] = {.Stat = {100,5,10,5,5,15}, .HpAtual=100, .Classe = MAGO},
    [SACERDOTE] = {.Stat = {125,10,10,0,10,10},.HpAtual = 125, .Classe = SACERDOTE},
};


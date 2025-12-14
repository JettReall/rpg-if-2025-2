#ifndef INIMIGOS_H
#define INIMIGOS_H
#include "structs.h"

// Declara o array global
extern INIMIGOS inimigo[4];
extern INIMIGOS Inimigo_Nulo[1];
// Declara a função que preenche os inimigos
void criar_ini_vento();
void criar_ini_bosque();
void criar_ini_agua();
void criar_ini_fogo();
void criar_ini_final();
void criar_ini_nulo();

#endif

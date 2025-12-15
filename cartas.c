#include "structs.h"


CARTA CatalogoCartas[DIFICULDADES][MAX_TIPO_CARTA][CARTAS_CADA_CAT] = {
    [FACIL-1] = {
        [ATAQUEFIS] = {
            [0] = {.Nome ="Soco Rapido", .Descricao ="Profere rapido soco", .Tipo = ATAQUEFIS, .Valor = 5},
            [1] = {.Nome = "Tabefe", .Descricao = "Dá um tapa no inimigo",.Tipo = ATAQUEFIS, .Valor = 5},
        },
        [ATAQUEMAG] = {
            [0] = {.Nome = "Disparo Magico", .Descricao = "Dispara um pequeno projetil magico", .Tipo = ATAQUEMAG, .Valor = 5},
            [1] = {.Nome = "Zap",.Descricao = "Um choquinho, que mal dói, mas asssusta.",.Tipo = ATAQUEMAG,.Valor = 5},
        },
        [CURA] = {
            [0] = {.Nome = "Cura Inferior", .Descricao = "realiza um ritual fraco de cura", .Tipo = CURA, .Valor = 5},
            [1] = {.Nome = "Bandaid",.Descricao = "Uma pequena e rápida cura.",.Tipo = CURA, .Valor = 5},
        }
    },
    [MEDIO-1] = {
        // ATAQUE FISICO: Slot [0]
        [ATAQUEFIS] = {
            [0] = {.Nome = "Corte leve", .Descricao = "Profere um leve corte", .Tipo = ATAQUEFIS, .Valor = 10},
            [1] = {.Nome = "Barruada",.Descricao="Você bate com tudo no seu oponente, como um ariete.",.Tipo = ATAQUEFIS,.Valor=10}
        },
        
        // ATAQUE MÁGICO: Slot [0]
        [ATAQUEMAG] = {
            [0] = {.Nome = "Missel Magico", .Descricao = "Dispara um missel magico", .Tipo = ATAQUEMAG, .Valor = 10},
            [1] = {.Nome = "Granizo",.Descricao= "Faz uma pedra de granizo cair do céu.",.Tipo = ATAQUEMAG,.Valor = 10},
        },
        
        // CURA: Slot [0]
        [CURA] = {
            [0] = {.Nome = "Cura Media", .Descricao = "realiza um ritual normal de cura", .Tipo = CURA, .Valor = 10},
            [1] = {.Nome = "Magia Herbal",.Descricao = "Regenera vida com poder da erva. (Pense qual preferir)",.Tipo = CURA,.Valor = 10},
        },
    },
    [DIFICIL-1] = {
        // ATAQUE FISICO: Slot [0]
        [ATAQUEFIS] = {
            [0] = {.Nome = "VOADORA", .Descricao = "Profere UMA VOADORA COM OS DOIS PE", .Tipo = ATAQUEFIS, .Valor = 15},
            [1] = {.Nome = "Kickflip",.Descricao = "Dá um BAITA chute forte no seu oponente",.Tipo = ATAQUEFIS,.Valor = 15}
        },
        
        // ATAQUE MÁGICO: Slot [0]
        [ATAQUEMAG] = {
            [0] = {.Nome = "BOMBA MAGICA", .Descricao = "Dispara uma BOMBA de magia", .Tipo = ATAQUEMAG, .Valor = 15},
            [1] = {.Nome = "BOLA DE FOGO", .Descricao = "Que bom RPG não teria uma bola de fogo?",.Tipo=ATAQUEMAG,.Valor = 15},
        },
        
        // CURA: Slot [0]
        [CURA] = {
            [0] = {.Nome ="Cura SUPERIOR", .Descricao = "realiza um ritual de cura SUPERIOR", .Tipo = CURA, .Valor = 15},
            [1] = {.Nome = "Grande poção",.Descricao = "Lembra um Biotônico Fontoura.",.Tipo = CURA, .Valor = 15}
        }

    }
};


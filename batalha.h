#define MAX_TAM_DECK_PLAYER 30
#define MAX_CARTAS_EM_MAO 5
enum Tipos {
     ESPADA,
     MAGIA,
     CURA
};

typedef struct {
     int Valor;
     int Tipo;
     int ID;
     char Naipe; //Escrita do tipo. Ex.: Tipo 0 tem o naipe E (Espada), já o 2 tem C (Cura)
     char NaipePorExtenso[20];
} CARTA;

CARTA DeckDoPlayer[MAX_TAM_DECK_PLAYER];
CARTA *CartaPtr = NULL;
CARTA MaoDoPlayer[MAX_CARTAS_EM_MAO];


void PreencherBaralho(CARTA *Deck);
void PreencherMao(CARTA *Mao, CARTA *Deck);



#ifndef TIPOPALAVRA_H
#define TIPOPALAVRA_H
#include <string>

using namespace std;

typedef string TipoChave; //TipoChave é uma string;

class TipoPalavra {
    public:
        TipoPalavra();
        TipoPalavra(TipoChave p);
        void SetPalavra(TipoChave p);
        TipoChave GetPalavra();
        void Imprime();
    private:
        TipoChave palavra;
};

#endif //TIPOPALAVRA_H
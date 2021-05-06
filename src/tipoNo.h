#ifndef TIPONO_H
#define TIPONO_H
#include "tipoPalavra.h"

class TipoNo {
    public:
        TipoNo();
    private:
        TipoPalavra palavra;
        TipoNo *esq;
        TipoNo *dir;
    friend class ArvoreBinariaDeCriptografia;
};

#endif //TIPONO_H
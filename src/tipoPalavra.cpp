#include "tipoPalavra.h"
#include <iostream>
#include <string>

using namespace std;

TipoPalavra::TipoPalavra() {
    palavra = "-1";
}
TipoPalavra::TipoPalavra(TipoChave p) {
    palavra = p;
}
void TipoPalavra::SetPalavra(TipoChave p) {
    palavra = p;
}
TipoChave TipoPalavra::GetPalavra() {
    return palavra;
}
void TipoPalavra::Imprime(){
    cout << palavra;
}
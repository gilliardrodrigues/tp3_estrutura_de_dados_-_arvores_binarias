#ifndef ARVOREBINARIADECRIPTOGRAFIA_H
#define ARVOREBINARIADECRIPTOGRAFIA_H
#include "tipoNo.h"

class ArvoreBinariaDeCriptografia {
    public:
        ArvoreBinariaDeCriptografia();
        ~ArvoreBinariaDeCriptografia();
        void Insere(TipoPalavra chave);
        void Encripta(TipoChave mensagem);
        void Desencripta(int mensagem_criptografada);
        void Remove(TipoChave chave);
        void Limpa();
    private:
        void InsereRecursivo(TipoNo* &p, TipoPalavra chave);
        void LimpaRecursivo(TipoNo* p);
        void RemoveRecursivo(TipoNo* &p, TipoChave chave);
        void Antecessor(TipoNo* q, TipoNo* &r);
        void EncriptaRecursivo(TipoNo* p, TipoChave mensagem, int *posicao);
        void DesencriptaRecursivo(TipoNo* p, int mensagem_criptografada, int *posicao);
        TipoNo *raiz;
};

#endif //ARVOREBINARIADECRIPTOGRAFIA_H

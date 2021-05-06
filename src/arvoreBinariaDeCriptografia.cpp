#include "arvoreBinariaDeCriptografia.h"
#include <iostream>

using namespace std;

ArvoreBinariaDeCriptografia::ArvoreBinariaDeCriptografia() {
    raiz = NULL;
}
void ArvoreBinariaDeCriptografia::InsereRecursivo(TipoNo *&p, TipoPalavra palavra) {
    if(p == NULL){
        p = new TipoNo();
        p->palavra = palavra;
    }
    else {
        if(palavra.GetPalavra() < p->palavra.GetPalavra()) //Se a palavra a ser inserida é anterior à do nó, insere na subárvore da esquerda;
            InsereRecursivo(p->esq, palavra);
        else
            InsereRecursivo(p->dir, palavra); //Caso contrário, insere na subárvore da direita;
    } 
}
void ArvoreBinariaDeCriptografia::Insere(TipoPalavra palavra) {
    InsereRecursivo(raiz,palavra);
}
void ArvoreBinariaDeCriptografia::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != NULL) { //Enquanto for true, significa que este ainda não é o filho mais à direita na subárvore da esquerda;
        Antecessor(q, r->dir);
        return;
    }
    //Coloca no lugar do nó a ser removido e remove o nó que deveria ser removido;
    q->palavra = r->palavra;
    q = r;
    r = r->esq;
    delete(q);
}
void ArvoreBinariaDeCriptografia::RemoveRecursivo(TipoNo *&no, TipoChave chave) {
    TipoNo *aux;
    if (no == NULL) //Se isso for verdadeiro, a palavra não está presente na árvore; 
        throw("palavra nao esta presente");
    if (chave < no->palavra.GetPalavra()) //Se a palavra a ser removida é anterior à do nó, chama o método recursivamente para a subárvore da esquerda;
        return RemoveRecursivo(no->esq, chave);
    else if (chave>no->palavra.GetPalavra()) //Caso contrário, chama o método para a subárvore da direita;
        return RemoveRecursivo(no->dir, chave);
    else {
    if (no->dir == NULL) { //Se o filho da direita é nulo, então o nó passa a ser o seu filho da esquerda;
        aux = no;
        no = no->esq;
        delete(aux);
    }
    else if(no->esq == NULL) { //Se o filho da esquerda é nulo, então o nó passa a ser o seu filho da direita;
        aux = no;
        no = no->dir;
        delete(aux);
    }
    else //Achou a chave procurada e ela tem 2 nós filhos;
        Antecessor(no, no->esq); //Substitui o nó pelo seu antecessor;
    } 
}
void ArvoreBinariaDeCriptografia::Remove(TipoChave chave) {
    return RemoveRecursivo(raiz, chave);
}
void ArvoreBinariaDeCriptografia::LimpaRecursivo(TipoNo *p) { //Delete todos os nós da árvore;
    if(p != NULL) {
        LimpaRecursivo(p->esq);
        LimpaRecursivo(p->dir);
        delete p;
    }
}
void ArvoreBinariaDeCriptografia::Limpa() {
    LimpaRecursivo(raiz);
    raiz = NULL;
}
ArvoreBinariaDeCriptografia::~ArvoreBinariaDeCriptografia() {
    Limpa();
}
void ArvoreBinariaDeCriptografia::EncriptaRecursivo(TipoNo *p, TipoChave mensagem, int *posicao) {
    if(p != NULL){
        *posicao += 1; //Incrementa o contador que representa a posição segundo o caminhamento pré-ordem;
        if(p->palavra.GetPalavra() == mensagem) //Se a palavra do nó atual for igual à i-ésima palavra da mensagem, imprime a posição dessa palavra na árvore;
            cout << *posicao;
        EncriptaRecursivo(p->esq, mensagem, posicao); 
        EncriptaRecursivo(p->dir, mensagem, posicao);
    }
}
void ArvoreBinariaDeCriptografia::Encripta(TipoChave mensagem) {
    int posicao = 0; //Contador para saber a posição segundo o caminhamento pré-ordem;
    EncriptaRecursivo(raiz, mensagem, &posicao);
}
void ArvoreBinariaDeCriptografia::DesencriptaRecursivo(TipoNo *p, int mensagem_criptografada, int *posicao) {
    if(p != NULL){
        *posicao += 1; //Incrementa o contador que representa a posição segundo o caminhamento pré-ordem;
        if(*posicao == mensagem_criptografada) //Se o valor do contador de posições do nó atual for igual ao i-ésimo nº da mensagem criptografada, imprime a palavra do nó atual;
            p->palavra.Imprime();
        DesencriptaRecursivo(p->esq, mensagem_criptografada, posicao);
        DesencriptaRecursivo(p->dir, mensagem_criptografada, posicao);
    }
}
void ArvoreBinariaDeCriptografia::Desencripta(int mensagem_criptografada) {
    int posicao = 0; //Contador para saber a posição segundo o caminhamento pré-ordem;
    DesencriptaRecursivo(raiz, mensagem_criptografada, &posicao);
}
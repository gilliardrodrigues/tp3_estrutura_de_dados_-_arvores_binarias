#include <iostream>
#include <string>
#include "arvoreBinariaDeCriptografia.h"
#include "tipoPalavra.h"

using namespace std;

int main(){
    ArvoreBinariaDeCriptografia arvore;
    TipoPalavra p;
    char operacao;
    int num_palavras, mensagem_criptografada;  
    TipoChave palavra_a_ser_inserida, palavra_a_ser_substituida, mensagem;
    while (cin >> operacao) {
        switch(operacao){
            case 'i': //Inserção de palavra na árvore;
                cin >> palavra_a_ser_inserida;
                p.SetPalavra(palavra_a_ser_inserida);
                arvore.Insere(p);
                break;
            case 's': //Substituição de palavra na árvore;
                cin >> palavra_a_ser_substituida;
                arvore.Remove(palavra_a_ser_substituida);
                cin >> palavra_a_ser_inserida;
                p.SetPalavra(palavra_a_ser_inserida);
                arvore.Insere(p);
                break;
            case 'e': //Encriptação de palavra na árvore;
                cin >> num_palavras;
                for(int i = 0; i < num_palavras; i++){ //O programa vai criptografar uma palavra da mensagem por vez;
                    cin >> mensagem; //i-ésima palavra da mensagem;
                    arvore.Encripta(mensagem); //Criptografa a mensagem;
                    cout << " ";
                }
                cout << endl;
                break;
            case 'd':
                cin >> num_palavras;
                for(int i = 0; i < num_palavras; i++){ //O programa vai descriptografar uma palavra da mensagem por vez;
                    cin >> mensagem_criptografada; //i-ésimo número da mensagem criptografada;
                    arvore.Desencripta(mensagem_criptografada); //Descriptografa a mensagem;
                    cout << " ";
                }
                cout << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
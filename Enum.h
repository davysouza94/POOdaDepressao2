#ifndef ENUM_H
#define ENUM_H


class Enum
{
    private:
        int qtdIngressos;
        int qtdMeia;
        int preco;
    public:
        enum ingressos
        {
            MEIA,
            INTEIRA
        };
        enum formaPagMentO
        {
            DINHEIRO,
            CARTAO
        };
        void ingressos(int x){
            if(x == INTEIRA)qtdIngressos++;
            if(x == MEIA)qtdMeia++;
        }

        void inicPreco(int x,float precInt){
            float precoInt =precInt,precoMeia=(precInt)/2;
            if(x == INTEIRA)preco = precoMeia;
            if(x == MEIA)preco = precoInt;
        }
};

#endif // ENUM_H

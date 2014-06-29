#ifndef GERENCIAR_SESSAO_H
#define GERENCIAR_SESSAO_H


class gerenciarSessao {
private:

public:
	gerenciarSessao();
	void inserirSessao();
	void exibeSessoes();
	void situacao();
	No<Sessao>* buscarSessao(int chave);
};

gerenciarSessao::gerenciarSessao(){
}

#endif

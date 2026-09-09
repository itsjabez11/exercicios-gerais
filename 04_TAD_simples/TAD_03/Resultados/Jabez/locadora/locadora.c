#include "filme.h"
#include <string.h>
#include <stdio.h>
#include "locadora.h"
#include <stdlib.h>


/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora (){

    tLocadora l;
    l.numFilmes = 0;
    l.lucro = 0;

    return l;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo){
    int i =0;
    for(i = 0; i<locadora.numFilmes; i++){
        if(ehMesmoCodigoFilme(locadora.filme[i],codigo)){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme){
    
    int cod = obterCodigoFilme(filme);
    if(!verificarFilmeCadastrado(locadora,cod)){
            locadora.filme[locadora.numFilmes++] = filme;
            printf("Filme cadastrado %d - ",cod);
            imprimirNomeFilme(filme);
            printf("\n");
        }else{
            printf("Filme ja cadastrado no estoque\n");
        }
    

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora){
    int codigo = 0;

    char c = '#';

    while(scanf(" %d,",&codigo)==1){

        tFilme f;
        f = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora,f);
        
    }
    if(scanf(" %c ",&c)!=1 || c!='#'){
        exit(1);
    }
    
    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i = 0,j;

    int totalAlugados = 0;
    int totalValor = 0;
    for(i = 0; i<quantidadeCodigos; i++){

        int cadastrou = 0;

        for(j = 0; j<locadora.numFilmes; j++){

            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i])){
                
                if(obterQtdEstoqueFilme(locadora.filme[j])>0){
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    totalAlugados++;
                    totalValor+=obterValorFilme(locadora.filme[j]);
                    cadastrou = 1;
                }else{
                    printf("Filme %d - ",locadora.filme[j].codigo);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    cadastrou = 1;
                }
                cadastrou = 1;
            }

            
        }
        if(!cadastrou){
                printf("Filme %d nao cadastrado.\n",codigos[i]);
        }
    }
    if(totalAlugados>0){
        printf("Total de filmes alugados: %d com custo de R$%d\n",totalAlugados,totalValor);
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora){

    int qtd_cod = 0;
    int codigo = 0;
    int vet[MAX_FILMES];
    char c = '#';
    while(scanf(" %d ",&codigo)==1){
        vet[qtd_cod] = codigo;
        qtd_cod++;
    }
    if(scanf(" %c ",&c)!=1 || c!='#'){
        exit(1);
    }
    locadora = alugarFilmesLocadora(locadora,vet,qtd_cod);
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos){
    int i = 0, j = 0;
    for(i = 0; i<quantidadeCodigos; i++){

        int cadastrou = 0;
        for(j = 0; j<locadora.numFilmes; j++){

            if(ehMesmoCodigoFilme(locadora.filme[j],codigos[i])){

                cadastrou = 1;
                if(locadora.filme[j].qtdAlugada > 0){

                    locadora.filme[j] = devolverFilme(locadora.filme[j]);
                    printf("Filme %d - ",obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" Devolvido!\n");
                    locadora.lucro+=obterValorFilme(locadora.filme[j]);
                    
                }else{

                    printf("Nao e possivel devolver o filme %d - ",codigos[i]);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }
                cadastrou = 1;

            }
        }

        if(!cadastrou){
            printf("Filme %d nao cadastrado.\n",codigos[i]);
        }
    }
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora){
    char c = '#';
    int qtd_cod = 0;
    int codigo = 0;
    int vet[MAX_FILMES];
    while(scanf(" %d",&codigo)==1){

        vet[qtd_cod] = codigo;
        qtd_cod++;
    }
    if(scanf(" %c ",&c)!=1 || c!='#'){
        exit(1);
    }
    locadora = devolverFilmesLocadora(locadora,vet,qtd_cod);
    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora){
    int i = 0,j =0;

    tFilme aux;

    for(i = 0; i<locadora.numFilmes-1; i++){
        
        for(j = 0; j<locadora.numFilmes-i-1;j++){
            if(compararNomesFilmes(locadora.filme[j],locadora.filme[j+1])>0){
                aux = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j+1];
                locadora.filme[j+1] = aux;
                
            }
            
            
        }
    }
    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora){
    printf("~ESTOQUE~\n");
    int i = 0;
    
    for(i = 0; i < locadora.numFilmes; i++){
        printf("%d - ",obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n",obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora){
    if(locadora.lucro>0){
        printf("Lucro total R$%d\n",locadora.lucro);
    }
    
}


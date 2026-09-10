#include "loja.h"
#include <stdio.h>
#include "vendedor.h"


int main(){

    int qtd_lojas = 0;
    scanf("%d",&qtd_lojas);

    int choose = -1;

    tLoja l[qtd_lojas];

    int n = 0;

    while(choose!=0){

        scanf("%d",&choose);

        if(choose==1){
            int id;
            float aluguel;
            scanf("%d %f",&id,&aluguel);
            l[n] = AbreLoja(id,aluguel);
            n++;

        }else if(choose==2){

            char nome[50];
            float salario;
            float prct_comissao;
            int id;
            scanf(" %[^ ]",nome);
            scanf("%f %f %d ",&salario,&prct_comissao,&id);
            tVendedor v = RegistraVendedor(nome,salario,prct_comissao);
        
            for(int i = 0; i< n; i++){
                if(VerificaIdLoja(l[i],id)){
                    l[i] = ContrataVendedor(l[i],v);
                    
                    break;
                }
            }
            

        }else if(choose==3){
            int id;
            char nome[50];
            float valor;
            scanf("%d %[^ ] %f ",&id,nome,&valor);
            for(int i = 0; i< n; i++){
                
                for(int j = 0; j<l[i].totalVendedores; j++){
                    if(VerificaNomeVendedor(l[i].vendedores[j],nome)){

                    l[i] = RegistraVenda(l[i],nome,valor);

                }
                }
                
            }

        }else if(choose==4){
            
            for(int i = 0; i< n ;i++){
                l[i] = CalculaLucro(l[i]);
                

            }
            for(int i = 0; i< n ; i++){

                ImprimeRelatorioLoja(l[i]);
            }

        }else if(choose==0){
            break;
            
        }else{
            printf("Operacao invalida\n");
            return 0;
        }
    }
    return 0;
}
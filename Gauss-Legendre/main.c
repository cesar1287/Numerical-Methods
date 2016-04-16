#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FUNCAO (cos(x))
#define FUNCAO_EXIBIR "cos(x)"

// calculo da funcao fx sobre um dado x
float f(float x){
    return(FUNCAO); //inserir a funcao desejada para o calculo
}

double gaussLegendre(double a, double b, int pontos){
    double resultado=0;
    double vet1[5];  // Vetor com os valores numericos dos pontos de "k".
    double vet2[5]; // Vetor com os valores dos pesos.
    double xk;
    double fxk;
    int i;
    switch(pontos){
        case 1:{
            vet1[0] = 0;
            vet2[0] = 2;
            break;
        }
        case 2:{
            vet1[0] = -0.577350269;
            vet1[1] =  0.577350269;
            vet2[0] = 1,
            vet2[1] = 1;
            break;
        }
        case 3:{
            vet1[0] = -0.774596669;
            vet1[1] =  0;
            vet1[2] =  0.774596669;
            vet2[0] = 0.555555555;
            vet2[1] = 0.888888888;
            vet2[2] = 0.555555555;
            break;
        }
        case 4:{
            vet1[0] = -0.861136311;
            vet1[1] = -0.339981043;
            vet1[2] = 0.339981043;
            vet1[3] = 0.861136311;
            vet2[0] = 0.347854845;
            vet2[1] = 0.652145154;
            vet2[2] = 0.652145154;
            vet2[3] = 0.347854845;
            break;
        }
        case 5:{
            vet1[0] = -0.906179845;
            vet1[1] = -0.538469310;
            vet1[2] =  0.000000000;
            vet1[3] =  0.538469310;
            vet1[4] =  0.906179845;
            vet2[0] =  0.236926885;
            vet2[1] =  0.478628670;
            vet2[2] =  0.568888888;
            vet2[3] =  0.478628670;
            vet2[4] =  0.236926885;
            break;
        }
    }
    for (i=0 ; i<pontos ; i++){
        xk = (b+a+(b-a)*vet1[i])/2;// em relacao a x de s (oriunda do vetor 1)
        fxk = f(xk);
        resultado += vet2[i]*fxk;
    }
    resultado *= (b-a)/2.0;
    return(resultado);
}

int main(void){
int opcao = 1,pontos;
    float a,b,erro;
    while(opcao!=0){
        printf("\nImplementacao do metodo de Gauss Legendre\n\n");
        printf("Funcao: f(x) = %s\n\n", FUNCAO_EXIBIR);
        printf("Escolha uma opcao\n\n");
        printf("(1) Inserir o intervalo e a tolerância ao erro permitida e calcule: \n\n");
        printf("(0) Sair do programa\n\n");
        printf("Digite sua opcao:");
        scanf("%d", &opcao);
        if(opcao==1){
            printf("\nInsira o intervalo\n\n");
            printf("Insira um valor para a:\n");
            scanf("%f",&a);
            printf("Insira um valor para b:\n");
            scanf("%f",&b);
            printf("Insira a tolerancia ao erro permitida:\n");
            scanf("%f",&erro);
            erro:
            fflush(stdin);
            printf("Insira o numero de pontos para a resolucao:\n");
            scanf("%d",&pontos);
            printf("\nO resultado da funcao para %d ponto(s) eh: %.10f\n\n",pontos,gaussLegendre(a,b,pontos));
        }
		if(opcao==0)
			break;
        printf("Deseja continuar executando? 1-Sim, 0-Nao:");
        scanf("%d",&opcao);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FUNCAO (cos(x))
#define FUNCAO_EXIBIR "cos(x)"

// calculo da funcao fx sobre um dado x
double f(double x){
    return(FUNCAO); //inserir a funcao desejada para o calculo
}

double gaussHermite(int pontos){
    double resultado=0;
    double vet1[6];// Vetor com os valores numericos dos pontos de "xk".
    double vet2[6];// Vetor com os valores dos pesos totais.
    double fxk;
    int i;
    switch(pontos){
        case 1:{
            vet1[0] = 0;
            vet2[0] = 1.77245;
            break;
        }
        case 2:{
            vet1[0] = -0.70710678;
            vet1[1] =  0.70710678;
            vet2[0] =  0.88622692;
            vet2[1] =  0.88622692;
            break;
        }
        case 3:{
            vet1[0] = -1.22474487;
            vet1[1] =  0;
            vet1[2] =  1.22474487;
            vet2[0] =  0.29540897;
            vet2[1] =  1.18163590;
            vet2[2] =  0.29540897;
            break;
        }
        case 4:{
            vet1[0] = -1.65068012;
            vet1[1] = -0.52464762;
            vet1[2] =  0.52464762;
            vet1[3] =  1.65068012;
            vet2[0] =  0.08131283;
            vet2[1] =  0.80491409;
            vet2[2] =  0.80491409;
            vet2[3] =  0.08131283;
            break;
        }
        case 5:{
            vet1[0] = -2.02018287;
            vet1[1] = -0.95857246;
            vet1[2] =  0;
            vet1[3] =  0.95857246;
            vet1[4] =  2.02018287;
            vet2[0] =  0.01995324;
            vet2[1] =  0.39361932;
            vet2[2] =  0.94530872;
            vet2[3] =  0.39361932;
            vet2[4] =  0.01995324;
            break;
        }
        case 6:{
            vet1[0] = -2.35060497;
            vet1[1] = -1.33584907;
            vet1[2] = -0.43607741;
            vet1[3] =  0.43607741;
            vet1[4] =  1.33584907;
            vet1[5] =  2.35060497;
            vet2[0] =  0.00453001;
            vet2[1] =  0.15706732;
            vet2[2] =  0.72462959;
            vet2[3] =  0.72462959;
            vet2[4] =  0.15706732;
            vet2[5] =  0.00453001;
            break;
        }
    }
    for (i=0 ; i<pontos ; i++){
        fxk = f(vet1[i]);
        resultado += vet2[i]*fxk;
    }
    return(resultado);
}

int main(void){
int opcao = 1,pontos;
    float a,b,erro;
    while(opcao!=0){
        printf("\nImplementacao do metodo de Gauss Hermite\n\n");
        printf("Funcao: f(x) = %s\n\n", FUNCAO_EXIBIR);
        printf("Escolha uma opcao\n\n");
        printf("(1) Inserir o numero de pontos no somatorio e calcular: \n\n");
        printf("(0) Sair do programa\n\n");
        printf("Digite sua opcao:");
        scanf("%d", &opcao);
        if(opcao==1){
            printf("\nInsira o numero de pontos para a resolucao:\n");
            scanf("%d",&pontos);
            printf("\nO resultado da funcao para %d ponto(s) eh: %.10lf\n\n",pontos,gaussHermite(pontos));
        }
		if(opcao==0)
			break;
        printf("Deseja continuar executando? 1-Sim, 0-Nao:");
        scanf("%d",&opcao);
	}
}

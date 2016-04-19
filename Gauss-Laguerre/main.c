#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FUNCAO (1/(1+pow(x,2)))
#define FUNCAO_EXIBIR "1/(1+x^2)"

// calculo da funcao fx sobre um dado x
double f(double x){
    return(FUNCAO); //inserir a funcao desejada para o calculo
}

double gaussLaguerre(int pontos){
    double resultado=0;
    double vet1[6];// Vetor com os valores numericos dos pontos de "xk".
    double vet2[6];// Vetor com os valores dos pesos totais.
    double fxk;
    int i;
    switch(pontos){
        case 1:{
            vet1[0] = 1;
            vet2[0] = 1;
            resultado += vet2[0]*f(vet1[0]);
            break;
        }
        case 2:{
            vet1[0] =  0.58578643;
            vet1[1] =  3.41421356;
            vet2[0] =  0.85355339;
            vet2[1] =  0.14644660;
            resultado += vet2[0]*f(vet1[0]);
            resultado += vet2[1]*f(vet1[1]);
            break;
        }
        case 3:{
            vet1[0] =  0.41577455;
            vet1[1] =  2.29428036;
            vet1[2] =  6.28994508;
            vet2[0] =  0.71109300;
            vet2[1] =  0.27851773;
            vet2[2] =  0.01038925;
            resultado += vet2[0]*f(vet1[0]);
            resultado += vet2[1]*f(vet1[1]);
            resultado += vet2[2]*f(vet1[2]);
            break;
        }
        case 4:{
            vet1[0] =  0.32254768;
            vet1[1] =  1.74576110;
            vet1[2] =  4.53662029;
            vet1[3] =  9.39507091;
            vet2[0] =  0.60315410;
            vet2[1] =  0.35741869;
            vet2[2] =  0.03888790;
            vet2[3] =  0.00053929;
            resultado += vet2[0]*f(vet1[0]);
            resultado += vet2[1]*f(vet1[1]);
            resultado += vet2[2]*f(vet1[2]);
            resultado += vet2[3]*f(vet1[3]);
            break;
        }
        case 5:{
            vet1[0] =  0.26356031;
            vet1[1] =  1.41340305;
            vet1[2] =  3.59642577;
            vet1[3] =  7.08581000;
            vet1[4] = 12.64080084;
            vet2[0] =  0.52175561;
            vet2[1] =  0.39866681;
            vet2[2] =  0.07594244;
            vet2[3] =  0.00361175;
            vet2[4] =  0.00002336;
            resultado += vet2[0]*f(vet1[0]);
            resultado += vet2[1]*f(vet1[1]);
            resultado += vet2[2]*f(vet1[2]);
            resultado += vet2[3]*f(vet1[3]);
            resultado += vet2[4]*f(vet1[4]);
            break;
        }
        case 6:{
            vet1[0] =  0.22284660;
            vet1[1] =  1.18893210;
            vet1[2] =  2.99273632;
            vet1[3] =  5.77514356;
            vet1[4] =  9.83746741;
            vet1[5] = 15.98287398;
            vet2[0] =  0.45896467;
            vet2[1] =  0.41700083;
            vet2[2] =  0.11337338;
            vet2[3] =  0.01039919;
            vet2[4] =  0.00026101;
            vet2[5] =  0.00000089;
            resultado += vet2[0]*f(vet1[0]);
            resultado += vet2[1]*f(vet1[1]);
            resultado += vet2[2]*f(vet1[2]);
            resultado += vet2[3]*f(vet1[3]);
            resultado += vet2[4]*f(vet1[4]);
            resultado += vet2[5]*f(vet1[5]);
            break;
        }
    }
    return(resultado);
}

int main(void){
int opcao = 1,pontos;
    while(opcao!=0){
        printf("\nImplementacao do metodo de Gauss Laguerre\n\n");
        printf("Funcao: f(x) = %s\n\n", FUNCAO_EXIBIR);
        printf("Escolha uma opcao\n\n");
        printf("(1) Inserir o numero de pontos no somatorio e calcular: \n\n");
        printf("(0) Sair do programa\n\n");
        printf("Digite sua opcao:");
        scanf("%d", &opcao);
        if(opcao==1){
            printf("\nInsira o numero de pontos para a resolucao:\n");
            scanf("%d",&pontos);
            printf("\nO resultado da funcao para %d ponto(s) eh: %.10lf\n\n",pontos,gaussLaguerre(pontos));
        }
		if(opcao==0)
			break;
        printf("Deseja continuar executando? 1-Sim, 0-Nao:");
        scanf("%d",&opcao);
	}
}

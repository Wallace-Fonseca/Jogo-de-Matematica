#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;
int multiplicadorPontos;

int main(){

    srand(time(NULL)); //Deve ser chamado apenas uma vez.

    jogar();

    return 0;
}

void jogar(){
    Calcular calc;

    printf("Informe o nivel de Dificuldade(1 - 2 - 3 - 4): ");
    scanf("%d", &calc.dificuldade);
    printf("\n\n");

    //Gera um  inteiro randomico entre 0 e 2:
    //0 = somar, 1 = diminuir, 2 = multiplicar.
    calc.operacao = rand() % 3; //randomico de 0 a 2.

    if(calc.dificuldade == 1){
        //facil
        calc.valor1 = rand() % 11; //randomico de 0 a 10.
        calc.valor2 = rand() % 11; //randomico de 0 a 10.
    } else if(calc.dificuldade == 2){
        calc.valor1 = rand() % 101; //randomico de 0 a 100.
        calc.valor2 = rand() % 101; //randomico de 0 a 100.
    } else if(calc.dificuldade == 3){
        calc.valor1 = rand() % 1001; //randomico de 0 a 1000.
        calc.valor2 = rand() % 1001; //randomico de 0 a 1000.
    } else if(calc.dificuldade == 4){
        calc.valor1 = rand () % 10001; //randomico de 0 a 10000.
        calc.valor2 = rand () % 10001; //randomico de 0 a 10000.
    } else{
        calc.valor1 = rand () % 100001; //randomico de 0 a 100000.
        calc.valor2 = rand () % 100001; //randomico de 0 a 100000.
    }

    int resposta;

    printf("Informe o resultado para a seguinte operacao:\n\n");

    if(calc.operacao == 0){ //Somar
        printf("Adicao: %d + %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        printf("\n\n");

        if(somar(resposta, calc)){
            pontos += 1 * calc.dificuldade;
            printf("Pontuacao: %d\n\n", pontos);
        }
    } else if(calc.operacao == 1){ //Subtracao
        printf("Subtracao: %d - %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        printf("\n\n");

        if(diminuir(resposta, calc)){
            pontos += 1 * calc.dificuldade;
            printf("Pontuacao: %d\n\n", pontos);
        }
    } else if(calc.operacao == 2){ //Multiplicacao.
        printf("Multiplicacao: %d * %d = ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        printf("\n\n");

        if(multiplicar(resposta, calc)){
            pontos += 1 * calc.dificuldade;
            printf("Pontuacao: %d\n\n", pontos);
        }
    } else{
        printf("Operacao invalida... Digito que foi informado na operacao %d\n\n", calc.operacao);
    }

    //Recomeçar o jogo:

    mostrarInfo(calc);

    char continuar;

    do{
        fflush(stdin);
        printf("Deseja continuar o jogo? [ y: Sim e n: nao ]: ");
        scanf("%c", &continuar);

        if(continuar == 'y'){
            system("cls");
            jogar();
        } else if(continuar == 'n'){
            system("cls");
            printf("Voce finalizou com %d pontos.\n", pontos);
            printf("Ate a proxima!");
            exit(0);
        } else{
            printf("Opcao invalida. Tente Novamente\n\n.");
        }
    }while ((continuar != 'y') || (continuar != 'n'));

}

void mostrarInfo(Calcular calc){
    char op[25];

    if(calc.operacao == 0){ //0 == somar
        sprintf(op, "Adicao"); // a varoiavel "op" vai receber "Somar"
    } else if(calc.operacao == 1){
        sprintf(op, "Subtracao");
    } else if(calc.operacao == 2){
        sprintf(op, "Multiplicar");
    } else {
        sprintf(op, "Operacao Desconhecida");
    }
    printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOperacao: %s. \n\n", calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc){
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou; 1 == acertou.

    if(resposta == calc.resultado){
        printf("Resposta Correta!\n");
        certo = 1;
    } else {
        printf("Resposta errada!\n");
    }

    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int diminuir(int resposta, Calcular calc){
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou; 1 == acertou.

    if(resposta == calc.resultado){
        printf("Resposta Correta!\n");
        certo = 1;
    } else {
        printf("Resposta errada!\n");
    }

    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

int multiplicar(int resposta, Calcular calc){
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; //0 == errou; 1 == acertou.

    if(resposta == calc.resultado){
        printf("Resposta Correta!\n");
        certo = 1;
    } else {
        printf("Resposta errada!\n");
    }

    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);

    return certo;
}

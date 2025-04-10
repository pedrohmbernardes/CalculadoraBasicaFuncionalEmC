/*
Disciplina  : [Introducao a Logica de Programacao]
Professor   : Rogerio Mandelli
Descricao   : Atividade Avaliativa 1 - Calculadora Basica Funcional
Autor(a)    : Grupo 3
Alunos(as)  : Pedro Henrique de Moura Bernardes; Ygor Trindade Maia; Kaio Eduardo de Oliveira Barbosa; Felipe Gabriel Pereira Alves Cruz
*/

/*
        1. OBJETIVO: Criar uma calculadora interativa que permita ao usuario realizar operacoes aritmeticas basicas,
        garantindo a validacao das entradas e a robustez da interface.
*/

// Definindo as principais bibliotecas a serem utilizadas nesse projeto.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

// Funcao definida para melhoria da experiencia do usuario.
void printing_result_divider()
{
    for (int i = 0; i <= 75; i++)
    {
        printf("-");
    }
    printf("\n");
}

// Funcao definica para limpeza do buffer de entrada do teclado, evitando caracteres desnecessarios ou 'lixo' de memoria.
void buffer_Input_Cleaner()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/*
    As 3 funcoes de validacao abaixo estao definidas para receberem um valor em formato de string(char[x]) para garantir
    que cada caracter digitado se trata de um numero valido, de acordo com os parametros de cada funcao.

*/

// A funcao entry_Validation esta definida para garantir que o usuario insira um numero real.
int entry_Validation(char *entry)
{
    int i = 0;
    int dotFounded = 0;
    int digitsFound = 0;

    // Se a entrada na posicao zero for vazia, retorna false. Ou seja, entrada invalida.
    if (entry[0] == '\0')
    {
        return 0;
    }

    // Percorrendo a entrada que o usuario digitou ate encontrar o caractere '\0' - esse caractere indica o final da string em C.
    while (entry[i] != '\0')
    {
        if (isdigit(entry[i])) // A Funcao isdigit percorre a string caractere por caractere para confirmar se efetivamente e um numero.
        {
            digitsFound = 1;
        }
        else if (entry[i] == '+' || entry[i] == '-') // Caso encontre um sinal positivo ou negativo, o if abaixo entra em trabalho.
        {
            if (i != 0) // O sinal encontrado na condicao acima, precisa estar diferente da posicao zero. Ou seja, o primeiro digito precisa aparecer como primeiro digito.
            {
                return 0; // Retornando false, ou seja, entrada invalida.
            }
        }
        else if (entry[i] == ',' || entry[i] == '.') // Se uma virgula, ou ponto for encontrado.
        {
            if (dotFounded || i == 0) // Se ja tiver encontrado uma virgula ou ponto ou eles forem o primeiro caractere.
            {
                return 0; // Retorna false.
            }
            dotFounded = 1; // Marcacao para indicar que ja foi encontrado um ponto ou virgula.
        }
        else // Caso seja qualquer outro caractere.
        {
            return 0; // Retorna false, ou seja, entrada invalida.
        }
        i++; // Aumenta o contador em 1 para validar o proximo caractere da string.
    }

    // Retorna 1 (true) se pelo menos 1 numero foi encontra, caso nao, retorna 0 (false).
    return digitsFound;
}

// A funcao entry_Validation_Integer esta definida para garantir que o usuario insira um numero inteiro entre 1 e 6, somente.
int entry_Validation_Integer(char *entryToInteger)
{

    // Se a entrada como string nao esta associada a nenhum objeto ou a entrada for vazia, retorna false.
    if (entryToInteger == NULL || strlen(entryToInteger) == 0)
    {
        return -1;
    }

    // Para cada elemento do vetor da string da entrada(entry) que for diferente de zero.
    for (int i = 0; entryToInteger[i] != '\0'; i++)
    {
        // Se para cada elemento, for diferente de um digito/numero.
        if (!isdigit(entryToInteger[i]))
        {
            // Retorna false.
            return -1;
        }
    }

    // Variavel number recebe a conversao da entrada string para numero, se atender os criterios acima.
    int number = atoi(entryToInteger);

    if (number > 0 && number < 7)
    {
        return number;
    }
    else
    {
        return -1;
    }
}

// A funcao entry_Validation_Continue_Program esta definida para garantir que o usuario insira um numero entre 1 e 2, somente.
// A funcao abaixo eh extremamente similar a anterior, porem ela so pode receber 1 ou 2.
int entry_Validation_Continue_Program(char *entryToInteger)
{

    if (entryToInteger == NULL || strlen(entryToInteger) == 0)
    {
        return -1;
    }

    for (int i = 0; entryToInteger[i] != '\0'; i++)
    {
        if (!isdigit(entryToInteger[i]))
        {
            return -1;
        }
    }

    int number = atoi(entryToInteger);

    if (number > 0 && number < 3)
    {
        return number;
    }
    else
    {
        return -1;
    }
}

// Funcao para calcular a Soma.
float calculating_Sum(float x, float y)
{
    return x + y;
}

// Funcao para calcular a Subtracao.
float calculating_Subtraction(float x, float y)
{
    return x - y;
}

// Funcao para calcular a Multiplicacao.
float calculating_Multiplication(float x, float y)
{
    return x * y;
}

// Tratamento do divisor zero. Enquanto o divisor for zero, o programa apresenta a mensagem de erro e solicita uma nova entrada ao usuario.
float treatment_Divisor_Zero(float dividerZero)
{
    float newDivider = dividerZero;

    while (newDivider == 0)
    {
        printf("\n\tO Divisor não pode ser zero. Por favor insira outro valor.\n\n>> ");
        scanf("%f", &newDivider);
    }

    return newDivider;
}

// Funcao para calcular a Divisao.
float calculating_Division(float x, float y)
{
    return (x / y);
}

// Funcao para calcular a Potencia.
double calculating_PowerOf(double base, double expoent)
{
    double powerOfResult = pow(base, expoent);
    return powerOfResult;
}

// Funcao definida para apresentar a cara do programa e garantir a assertividade da operacao escolhida pelo usuario.
int operation_To_Do()
{
    int operationToDoInteger;   // Definindo variavel que vai indicar qual operacao sera escolhida pelo usuario.
    char operationToDoChar[25]; // Variavel criada para armazenar a opcao do usuario como string e validar a entrada.
    // int validation = 0;         // Contador validador para o while principal da funcao

    while (1) // Enquanto a validacao nao for 1, a estrutura de repeticao se mantem.
    {
        // validation = 1; // Admitindo que a validacao seja 1, para que em caso de sucesso, basta percorrer o loop 1x.

        printf("\n\t***********  ----  CALCULADORA BÁSICA FUNCIONAL  ----   ***********\t\n\n\t\t- Selecione uma opção:\n\n");
        printf("\t\t(1) Soma\n\t\t(2) Subtração\n\t\t(3) Multiplicação\n\t\t(4) Divisão\n\t\t(5) Potenciação\n\t\t(6) Finalizar\n\n>> ");

        fgets(operationToDoChar, sizeof(operationToDoChar), stdin);

        operationToDoChar[strcspn(operationToDoChar, "\n")] = '\0';

        if (strlen(operationToDoChar) == 0)
        {
            printf("\n\t");
            printing_result_divider();
            printf("\tEntrada Vazia! Por favor selecione uma opção de 1 a 6.");
            printf("\n\t");
            printing_result_divider();
            continue;
        }

        if (entry_Validation_Integer(operationToDoChar) != -1)
        {
            break;
        }
        else
        {
            printf("\n\t");
            printing_result_divider();
            printf("\tEntrada Inválida! Por favor selecione uma opção de 1 a 6.");
            printf("\n\t");
            printing_result_divider();
        }
    }

    char *pointerValidation;
    operationToDoInteger = strtod(operationToDoChar, &pointerValidation);

    // Dependendo da operacao escolhida pelo usuario, retorne os dados abaixo.
    switch (operationToDoInteger)
    {
    case 1:
        printf("\n\t");
        printing_result_divider();
        printf("\t>> Você selecionou a soma.");
        printf("\n\t");
        printing_result_divider();
        break;
    case 2:
        printf("\n\t");
        printing_result_divider();
        printf("\t>> Você selecionou a subtração.");
        printf("\n\t");
        printing_result_divider();
        break;
    case 3:
        printf("\n\t");
        printing_result_divider();
        printf("\t>> Você selecionou a multiplicação.");
        printf("\n\t");
        printing_result_divider();
        break;
    case 4:
        printf("\n\t");
        printing_result_divider();
        printf("\t>> Você selecionou a divisão.");
        printf("\n\t");
        printing_result_divider();
        break;
    case 5:
        printf("\n\t");
        printing_result_divider();
        printf("\t>> Você selecionou a potenciação.");
        printf("\n\t");
        printing_result_divider();
        break;
    case 6:
        printf("\n\t");
        printing_result_divider();
        printf("\tFinalizando o programa...");
        printf("\n\t");
        printing_result_divider();
        exit(0); // Funcao exit(0) termina completamente o programa a pedido do usuario.
    }

    // Retornando a funcao com o valor da operacao a fazer, para que la no int main, esse valor seja atrituido a variavel operationChosen.
    return operationToDoInteger;
}

// Funcao definida para questionar o usuario, ao final da interacao com o programa, se ele deseja continuar no programa.
int continue_Program()
{
    char option[20];

    printf("\n\tDeseja realizar mais operações?\n\t[1] - Sim  |  [2] - Não\n\n>> ");
    scanf("%s", option);

    int optionResult = entry_Validation_Continue_Program(option);

    while (optionResult != 1 && optionResult != 2)
    {
        printf("\n\tOpção inválida. Insira [1] para continuar ou [2] para finalizar o programa.\n\n>> ");
        scanf("%s", option);
        optionResult = entry_Validation_Continue_Program(option);
    }

    return optionResult;
}

int main()
{
    // Eu sei que a funcao abaixo funciona somente no windows, porem estou trabalhando para melhor atender a todos os OSs.
    SetConsoleOutputCP(65001);

    int continueOption = 1; // Contador para garantir se o usuario deseja continuar no programa.

    // Enquanto for diferente de 2, esse programa fica se repetindo. A opcao 2 indica o programa que o usuario deseja sair do programa apos a primeira operacao.
    while (continueOption != 2)
    {
        int operationChosen = operation_To_Do(); // A variavel recebe o retorno da funcao que indica qual operacao sera realizada.
        float number1, number2, result;          // Declaracao das variaveis referentes aos numeros de input e output.
        double num1Base, num2Expoent, resultPowerOf;

        // Variavel para armazenar a entrada do usuario. Definida em 50 posicoes (sei que tem como melhorar, porem acredito que para este programa, funciona bem).
        char entryDigited[50];
        char entryDigited2[50];

        // buffer_Input_Cleaner();

        // Loop para recebimento do primeiro numero.
        while (1)
        {
            if (operationChosen != 5) // Se a operacao escolhida for diferente de 5 (potenciacao).
            {
                printf("\n\tDigite o primeiro valor: \n\n>> ");
            }
            else if (operationChosen == 5) // Se a operacao escolhida for igual a 5 (potenciacao), o output para o usuario e diferente, melhorando o entendimento para o usuario.
            {
                printf("\n\tDigite a base: \n\n>> ");
            }

            // Capta a entrada do usuario em formato de string.
            fgets(entryDigited, sizeof(entryDigited), stdin);

            // Remove o caractere de nova linha para impedir erros de memoria e calculo.
            entryDigited[strcspn(entryDigited, "\n")] = '\0';

            // Chama a funcao strlen para garantir que o tamanho da string nao seja vazia.
            if (strlen(entryDigited) == 0)
            {
                printf("\n\tEntrada vazia. Por favor digite um número real.\n\n");
                continue;
            }

            // Chama a funcao entry_Validation para validar a entrada do usuario e garantir que nao possua caracteres indesejados.
            if (entry_Validation(entryDigited))
            {
                break;
            }
            else
            {
                printf("\n\tEntrada inválida. Por favor digite um número real.\n\n");
            }
        }

        // Conversao da string para um numero real (float).
        // Ponteiro para armazenar o resto da string apos a conversao.
        char *pointer;

        // Condicao para atribuir a variavel correta os numeros, dependendo de qual operacao foi escolhida. // Aplicado para o number1 e number2.
        if (operationChosen != 5)
        {
            number1 = strtod(entryDigited, &pointer); // A funcao strtod recebe a string (%s) e o ponteiro como argumentos e os converte para numero real, armazenando esse numero na variavel.
        }
        else if (operationChosen == 5)
        {
            num1Base = strtod(entryDigited, &pointer); // A funcao strtod recebe a string (%s) e o ponteiro como argumentos e os converte para numero real, armazenando esse numero na variavel.
        }

        // Mesmo loop acima, porem para o segundo numero.
        while (1)
        {
            if (operationChosen != 5)
            {
                printf("\n\tDigite o segundo valor: \n\n>> ");
            }
            else if (operationChosen == 5)
            {
                printf("\n\tDigite o expoente: \n\n>> ");
            }

            fgets(entryDigited2, sizeof(entryDigited2), stdin);

            entryDigited2[strcspn(entryDigited2, "\n")] = '\0';

            if (entry_Validation(entryDigited2))
            {
                break;
            }
            else
            {
                printf("\n\tEntrada inválida. Por favor digite um número real.\n\n");
            }
        }

        char *pointer2;
        if (operationChosen != 5)
        {
            number2 = strtod(entryDigited2, &pointer2);
        }
        else if (operationChosen == 5)
        {
            num2Expoent = strtod(entryDigited2, &pointer2);
        }

        // Estrutura de Switch para retornar o resultado final para o usuario conforme a escolha da operacao.
        switch (operationChosen)
        {
        case 1:
            // Chamando a funcao de soma para calcular.
            result = calculating_Sum(number1, number2);
            // Chamando a funcao para imprimir na tela uns tracos para melhorar a experiencia do usuario.
            printf("\n\t");
            printing_result_divider();
            printf("\tO resultado da soma entre %.2f e %.2f é: %.2f.", number1, number2, result); // Devolvendo o resultado na tela para o usuario.
            printf("\n\t");
            printing_result_divider();
            break;

        case 2:
            result = calculating_Subtraction(number1, number2);
            printf("\n\t");
            printing_result_divider();
            printf("\tO resultado da subtração entre %.2f e %.2f é: %.2f.", number1, number2, result);
            printf("\n\t");
            printing_result_divider();
            break;

        case 3:
            result = calculating_Multiplication(number1, number2);
            printf("\n\t");
            printing_result_divider();
            printf("\tO resultado da multiplicação entre %.2f e %.2f é: %.2f.", number1, number2, result);
            printf("\n\t");
            printing_result_divider();
            break;

        case 4:
            // Caso o divisor seja zero, chama a funcao para devolver um novo valor a esta variavel.
            if (number2 == 0)
            {
                number2 = treatment_Divisor_Zero(number2);
            }
            result = calculating_Division(number1, number2);
            printf("\n\t");
            printing_result_divider();
            printf("\tO resultado da divisão entre %.2f e %.2f é: %.2f.", number1, number2, result);
            printf("\n\t");
            printing_result_divider();
            break;

        case 5:
            resultPowerOf = calculating_PowerOf(num1Base, num2Expoent);
            printf("\n\t");
            printing_result_divider();
            printf("\tO resultado da potenciação entre %.4f e %.4f é: %.8f.", num1Base, num2Expoent, resultPowerOf);
            printf("\n\t");
            printing_result_divider();
            break;

        default:
            printf("\n\t");
            printing_result_divider();
            printf("\tResultado não encontrado. Tente novamente.");
            printf("\n\t");
            printing_result_divider();
            break;
        }

        // A variavel continueOption recebe o resultado da funcao continueProgram, sendo 1 para continuar ou 2 para sair.
        continueOption = continue_Program();

        // Caso a opcao seja a 2, finaliza o programa.
        if (continueOption == 2)
        {
            printf("\n");
            printf("-------- Finalizando o programa...\n");
            exit(0);
        }

        buffer_Input_Cleaner();

        // Caso a opcao escolhida seja a 1, eh ignorado a estrutura if acima, e se mantem dentro deste While repetindo as operacoes novamente.
    }

    return 0;
}
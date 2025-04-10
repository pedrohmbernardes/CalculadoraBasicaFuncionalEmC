## --> Esse é meu primeiro projeto desenvolvido através da Tarefa da faculdade (denominada: Atividade Avaliativa).

### --> Mais abaixo estarei apresentando detalhes conforme a versão.

#### TAREFA-1: Calculadora com menu de operações (2,0 pontos)

    • 1. Objetivo > Criar uma calculadora interativa que permita ao usuário realizar operações aritméticas básicas, garantindo a validação das entradas e a robustez da interface.

    • 2. Interface e menu
        2.1. Exibição do menu (apresentar um menu interativo com as seguintes opções):
            ▪ (1) Soma
            ▪ (2) Subtração
            ▪ (3) Multiplicação
            ▪ (4) Divisão
            ▪ (5) Potenciação
            ▪ (6) Finalizar
        2.2. Validação da opção selecionada
            ▪ Garantir que o usuário insira uma opção válida.
            ▪ Em caso de opção inválida, exibir uma mensagem de erro e solicitar uma nova opção.

    • 3. Entrada de dados e validação
        > Solicitar que o usuário insira dois números reais para a operação escolhida.
        > Validar que as entradas sejam numéricas.
        > Tratamento especial para divisão:
            - Verificar se o divisor é diferente de zero.
            - Se o divisor for zero, exibir uma mensagem de erro e solicitar nova entrada.

    • 4. Execução das operações
        > Implementar cada uma das operações (soma, subtração, multiplicação, divisão e potenciação) conforme selecionado pelo usuário.
        > O programa deve operar em loop, permitindo múltiplas operações até que o usuário escolha a opção “Finalizar”.

    • 5. Saída e exibição dos resultados
        > Exibir o resultado da operação com precisão de 3 casas decimais.

---

### V1.1

#### Foram adicionadas 2 novas funções ao código principal para garantir que as entradas do usuário funcionem corretamente.

1. Função: entry_Validation_Integer:

   > Garante que o usuário insira um valor correto dentre as opções mostradas no menu (de 1 a 6). Anteriormente, essa validação não existia, então ao digitar "3,5" por exemplo, o programa entendia o 3 e ia para o cálculo de operação selecionada (no caso do 3, a multiplicação). Agora é apresentado o erro, e pede que o usuário digite corretamente 1 das opções apresentadas.

2. Função: entry_Validation_Continue_Program:
   > Garante que o usuário insira um valor correto dentre as opções mostradas para continuar no programa ou não (1 ou 2). Anteriormente, essa validação não existia, então ao digitar "1,5" por exemplo, o programa entendia o 1 e se mantinha no programa. Agora é apresentado o erro, e pede que o usuário digite corretamente entre as opções 1 ou 2.

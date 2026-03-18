# Projeto-estrutura-de-dados
Este projeto foi desenvolvido como parte de um trabalho acadêmico para a disciplina de Estrutura de Dados. O objetivo é gerenciar uma rotina de tarefas utilizando uma Lista Encadeada Simples com Alocação Dinâmica de Memória utilizando a linguagem de programação C

💻 Conceitos Aplicados
O projeto demonstra o domínio dos seguintes conceitos de baixo nível em C: \n
Structs e Tipos Abstratos de Dados (TAD).
Ponteiros: Manipulação de endereços de memória para encadeamento.
Gestão de Memória: Uso de malloc() para crescimento dinâmico e free() para evitar memory leaks.
Lógica de Busca e Remoção: Algoritmos de travessia de lista linear.

📝 Sistema de Gerenciamento de Tarefas (Lista Encadeada em C)
Este projeto foi desenvolvido como parte de um trabalho acadêmico para a disciplina de Estrutura de Dados. O objetivo é gerenciar uma rotina de tarefas utilizando uma Lista Encadeada Simples com Alocação Dinâmica de Memória.

🚀 Funcionalidades
O sistema permite organizar a rotina acadêmica/pessoal com as seguintes operações:

Incluir Tarefa: Adiciona uma nova tarefa ao início da lista (Alocação com malloc).
Mostrar Todos: Percorre a lista e exibe todos os dados formatados.
Buscar: Localiza uma tarefa específica através do seu ID único.
Retirar: Remove uma tarefa da lista e libera o espaço na memória (free).
Liberar Lista: Limpa toda a memória alocada antes de encerrar o programa.

🛠️ Estrutura do Objeto (Tarefa)
Cada nó da lista armazena um objeto Tarefa com 6 campos distintos:

int id: Identificador único.
char descricao[50]: O que deve ser feito.
char disciplina[30]: Contexto ou matéria relacionada.
int prioridade: Escala de importância (1 a 5).
float horasEstimadas: Tempo previsto para conclusão.
bool concluida: Status atual da tarefa.

📋 Como Executar
1. Clone o repositório:

git clone https://github.com/mfajunior/Projeto-estrutura-de-dados

2. Compile o código (usando GCC):
gcc main.c -o sistema_tarefas

3. Execute o programa:
./sistema_tarefas

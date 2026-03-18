# Projeto-estrutura-de-dados
Este projeto foi desenvolvido como parte de um trabalho acadêmico para a disciplina de Estrutura de Dados. O objetivo é gerenciar uma rotina de tarefas utilizando uma Lista Encadeada Simples com Alocação Dinâmica de Memória utilizando a linguagem de programação C

💻 Conceitos Aplicados<br>
O projeto demonstra o domínio dos seguintes conceitos de baixo nível em C: <br>
Structs e Tipos Abstratos de Dados (TAD).<br>
Ponteiros: Manipulação de endereços de memória para encadeamento.<br>
Gestão de Memória: Uso de malloc() para crescimento dinâmico e free() para evitar memory leaks.<br>
Lógica de Busca e Remoção: Algoritmos de travessia de lista linear.<br>

📝 Sistema de Gerenciamento de Tarefas (Lista Encadeada em C)<br>
Este projeto foi desenvolvido como parte de um trabalho acadêmico para a disciplina de Estrutura de Dados. O objetivo é gerenciar uma rotina de tarefas utilizando uma Lista Encadeada Simples com Alocação Dinâmica de Memória.<br>

🚀 Funcionalidades<br>
O sistema permite organizar a rotina acadêmica/pessoal com as seguintes operações:<br>

Incluir Tarefa: Adiciona uma nova tarefa ao início da lista (Alocação com malloc).<br>
Mostrar Todos: Percorre a lista e exibe todos os dados formatados.<br>
Buscar: Localiza uma tarefa específica através do seu ID único.<br>
Retirar: Remove uma tarefa da lista e libera o espaço na memória (free).<br>
Liberar Lista: Limpa toda a memória alocada antes de encerrar o programa.<br>

🛠️ Estrutura do Objeto (Tarefa)<br>
Cada nó da lista armazena um objeto Tarefa com 6 campos distintos:<br>

int id: Identificador único.<br>
char descricao[50]: O que deve ser feito.<br>
char disciplina[30]: Contexto ou matéria relacionada.<br>
int prioridade: Escala de importância (1 a 5).<br>
float horasEstimadas: Tempo previsto para conclusão.<br>
bool concluida: Status atual da tarefa.<br>

📋 Como Executar
1. Clone o repositório:

git clone https://github.com/mfajunior/Projeto-estrutura-de-dados

2. Compile o código (usando GCC):
gcc main.c -o sistema_tarefas

3. Execute o programa:
./sistema_tarefas

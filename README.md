# AnalizadorSintatico
# Compilando e Executando o Trabalho de Compiladores
Este guia tem como objetivo fornecer instruções para compilar e executar o trabalho de compiladores desenvolvido pelo aluno. Certifique-se de seguir os pré-requisitos e os passos corretamente para garantir uma compilação e execução bem-sucedidas.
## Pré-requisitos
Antes de compilar o trabalho, verifique se você possui os seguintes pré-requisitos instalados em seu sistema:
- **Atualização do Sistema**:
  ```bash
  sudo apt update
  sudo apt upgrade
- **Compilador C++ (g++) e Debugger (gdb)**:
  ```bash
  sudo apt install g++ gdb
- **Ferramentas de Compilação (make e cmake):**:
  ```bash
  sudo apt install make cmake
- **Flex e Biblioteca Flex (libfl-dev):**:
  ```bash
  sudo apt install flex libfl-dev
- **Bison e Biblioteca Bison (libbison-dev):**:
  ```bash
  sudo apt install bison libbison-dev
- ### ASiga os passos abaixo para compilar e executar o trabalho:
  1. Gerar o arquivo do analisador léxico com o flex:
         flex lexer.l
  2. Gerar o arquivo do analisador sintático com o bison:
  Este passo gera o analisador sintático e o arquivo de cabeçalho sint.tab.h a partir do arquivo sint.y.
  
	     bison -d sint.y 
  3. Compilar tudo em no executavel do projeto:
	     g++ lex.yy.c sint.tab.c -o sample -std=c++17
  4. Executar o programa
  
	     ./sample teste.txt
## Observação sobre Erros Sintáticos
Durante a execução, o terminal pode gerar mensagens de erro sintático no seguinte formato:
Essas mensagens indicam um erro sintático no arquivo de entrada. Caso contrário, se o programa for compilado com sucesso e sem erros, nenhuma mensagem de erro será gerada.
```cpp
ERRO SINTÁTICO: símbolo "<símbolo>" (linha <número> do arquivo)
```

## Observação sobre Análise Semântica
### Precedencia dos OPeradores
- Desde a análise sintática já havia sido tratado o problema de ordem de operadores incorretas, entendendo que sempre que um EquivalentTo viesse anteriormente ao SubClassOf ele seria reconhecido como uma classe indefinida
<img src="https://raw.githubusercontent.com/Arthur-Peixoto/Assets/main/Captura%20de%20tela%20de%202024-04-24%2000-25-37.png" alt="Texto Alternativo">
Imagem do código do analisador sintártico

### Axioma de fechamento
- Foi utilizado dentro da classe semanticAnalyzer uma função "onlyCheck" para garantir que axiomas de fechamento só podem aparecer depois de declarações existenciais de
propriedades, pois não tem como fechar as imagens das propriedades sem tê-las declaradoantes explicitamente.
<img src="https://raw.githubusercontent.com/Arthur-Peixoto/Assets/main/Captura%20de%20tela%20de%202024-04-24%2000-11-22.png" alt="Texto Alternativo">

### VERIFICAÇÃO ESTÁTICA DE TIPOS POR COERÇÃO
- Foi criada uma função no Analizador Sintático para tratar usos de Min, Max, Exactly, apontando erros com o intuito de "forçar" o ontologista a indicar um número entre o operador.
- Além de uma função específica para tratar integer e floats de maneira separada
<img src="https://raw.githubusercontent.com/Arthur-Peixoto/Assets/main/Captura%20de%20tela%20de%202024-04-24%2000-11-44.png" alt="Texto Alternativo">

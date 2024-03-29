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

```cpp
ERRO SINTÁTICO: símbolo "<símbolo>" (linha <número> do arquivo)

Essas mensagens indicam um erro sintático no arquivo de entrada. Caso contrário, se o programa for compilado com sucesso e sem erros, nenhuma mensagem de erro será gerada.



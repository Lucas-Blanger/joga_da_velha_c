# Projeto: Jogo da Velha em C

Disciplina: Laboratório de Programação I

Curso: Ciência da Computação

Universidade Federal de Santa Maria (UFSM)

# Descrição

Este projeto consiste em um jogo da velha  desenvolvido em linguagem C, como parte da disciplina de Laboratório de Programação I. O jogo é jogado por dois jogadores, onde um usa o símbolo "X" e o outro "O", e eles alternam suas jogadas em um tabuleiro 3x3. O objetivo é alinhar três símbolos iguais em uma linha, coluna ou diagonal.

O desenvolvimento deste projeto visa a aplicação de conceitos de estruturas de dados, controle de fluxo e interação com uma tela gráfica.

# Funcionalidades

  Interface gráfica
  Jogo para dois jogadores (um contra o outro)
  Verificação automática de vitória ou empate
  Reinício do jogo ao final de cada partida
  Controle de turno para alternar entre os jogadores
  Representação visual do tabuleiro utilizando caracteres ASCII

# Como executar o jogo

Pré-requisitos

  Compilador C (ex: GCC)
  Sistema operacional compatível com compiladores C (Linux, Windows, macOS)

# Passos para compilar e executar:

  Clone o repositório ou baixe os arquivos do projeto.
  Abra o terminal na pasta onde estão os arquivos do projeto.
  Compile o código com o seguinte comando:

    bash

    gcc -o jogo_da_velha jogo_da_velha.c

 Execute o jogo com o comando:

    bash

    ./jogo_da_velha

# Como jogar

  O jogo é jogado em um tabuleiro 3x3, onde os jogadores se alternam para marcar "X" ou "O".
  O jogador 1 utiliza o símbolo "X" e o jogador 2 utiliza o símbolo "O".
  Cada jogador deve escolher a posição (de 1 a 9) onde deseja marcar no tabuleiro.
  O jogo verifica automaticamente se há um vencedor ou se o jogo terminou em empate.
  Ao término da partida, o jogador pode optar por jogar novamente.

# Estrutura do Projeto

  jogo_da_velha.c: Arquivo principal contendo toda a lógica do jogo.
  tela.h: Cabeçalho contendo declarações de funções e estruturas usadas.
  README.md: Documento explicativo com as instruções sobre o projeto.

# Regras do Jogo

  Dois jogadores se revezam para marcar "X" e "O" em um tabuleiro 3x3.
  O objetivo é alinhar três símbolos iguais em uma linha, coluna ou diagonal.
  O jogo termina quando um dos jogadores vence ou quando todas as posições do tabuleiro estão preenchidas, resultando em empate.

# Autor

    Nome do(a) aluno(a): Lucas Blanger

Licença

Este projeto foi desenvolvido exclusivamente para fins acadêmicos e pode ser utilizado livremente com fins educacionais.

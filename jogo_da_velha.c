#include "telag.h"
#include <stdio.h>
#include <stdbool.h>

// Inicialização das variáveis que representam o estado do jogo
char tabuleiro[3][3]; // Matriz do tabuleiro
int jogador_atual; // 0 para 'X' e 1 para 'O'
int pos_x, pos_y; // Posição no tabuleiro
bool jogo_terminado; // Status do jogo
char vencedor; // Vencedor do jogo

// Funções auxiliares
void inicializa_jogo(void);
void processa_entrada(char tecla);
void atualiza_estado(void);
void desenha_tela(void);
bool verifica_vencedor(void);
bool tabuleiro_cheio(void);

// Inicializa o estado do jogo
void inicializa_jogo(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' ';
    }
  }
  jogador_atual = 0; // 'X' começa
  pos_x = 1;
  pos_y = 1;
  jogo_terminado = false;
  vencedor = ' ';
}

// Processa a entrada do usuário
void processa_entrada(char tecla) {
  if (tecla == 'w' && pos_y > 0){ 
    pos_y--;
  }
  if (tecla == 's' && pos_y < 2){
   pos_y++;
  }
  if (tecla == 'a' && pos_x > 0){
    pos_x--;
  }
  if (tecla == 'd' && pos_x < 2){
    pos_x++;
  }
  if (tecla == ' ') {
  if (tabuleiro[pos_y][pos_x] == ' ') {
      if (jogador_atual) {
          tabuleiro[pos_y][pos_x] = 'O';
      } else {
          tabuleiro[pos_y][pos_x] = 'X';
      }
      jogador_atual = !jogador_atual;
  }

  }
}

// Atualiza o estado do jogo
void atualiza_estado(void) {
  if (verifica_vencedor()) {
    jogo_terminado = true;
  } else if (tabuleiro_cheio()) {
    jogo_terminado = true;
    vencedor = ' ';
  }
}

// Verifica se há um vencedor
bool verifica_vencedor(void) {
  for (int i = 0; i < 3; i++) {
    if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
      vencedor = tabuleiro[i][0];
      return true;
    }
    if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
      vencedor = tabuleiro[0][i];
      return true;
    }
  }
  if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
    vencedor = tabuleiro[0][0];
    return true;
  }
  if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
    vencedor = tabuleiro[0][2];
    return true;
  }
  return false;
}

// Verifica se o tabuleiro está cheio
bool tabuleiro_cheio(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

// Desenha a tela com base no estado do jogo
void desenha_tela(void) {
  tela_retangulo(50, 50, 450, 450, 2, verde, preto);
  for (int i = 1; i < 3; i++) {
    tela_linha(50, 50 + i * 133, 450, 50 + i * 133, 2, verde);
    tela_linha(50 + i * 133, 50, 50 + i * 133, 450, 2, verde);
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tabuleiro[i][j] != ' ') {
        tela_texto(50 + j * 133 + 66, 50 + i * 133 + 66, 100, amarelo, (tabuleiro[i][j] == 'X') ? "X" : "O");
      }
    }
  }
  tela_retangulo(50 + pos_x * 133, 50 + pos_y * 133, 50 + (pos_x + 1) * 133, 50 + (pos_y + 1) * 133, 3, amarelo, transparente);
  char status[50];
  sprintf(status, "Jogador atual: %c", jogador_atual ? 'O' : 'X');
  tela_texto(250, 475, 20, amarelo, status);
  if (jogo_terminado) {
    if (vencedor == ' ') {
      tela_texto(250, 20, 40, branco, "Empate!");
    } else {
      char msg[50];
      sprintf(msg, "Vencedor: %c", vencedor);
      tela_texto(250, 20, 40, vermelho, msg);
    }
  }
}

// Função principal
int main(void) {
  // Inicialização do programa
  tela_inicio(500, 500, "Jogo da Velha do Lucas");
  inicializa_jogo();

  // Laço principal, onde uma partida é jogada
  while (!jogo_terminado) {
    // Processamento de entradas
    char tecla = tela_tecla();
    if (tecla != '\0') {
      processa_entrada(tecla);
    }

    // Alterações das entradas
    atualiza_estado();

    // Desenho da tela à partir do estado
    desenha_tela();

    // Atualiza a tela
    tela_atualiza();
  }

  // Finalização do programa
  tela_fim();
  return 0;
}



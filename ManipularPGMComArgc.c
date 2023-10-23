#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int h, w;   // Altura(linhas) e Largura(colunas)
  int cinza;  // Tons de cinza
  int *pixel; // Elementos da Matriz(pixels)
} imgb;

// Função para leitura do arquivo
imgb read_img(FILE *fimg) {
  imgb I;

  // Tipo de imagem. Vamos utilizar P2
  char ver[5];

  // Dimensões da imagem(Matriz I)
  fscanf(fimg, "%s", ver);
  fscanf(fimg, "%d", &I.h);
  fscanf(fimg, "%d", &I.w);
  fscanf(fimg, "%d", &I.cinza);

  // Alocação da memória
  I.pixel = malloc(I.h * I.w * sizeof(int));
  if (I.pixel != NULL) {
    for (int i = 0; i < I.h; i++)
      for (int j = 0; j < I.w; j++) {
        fscanf(fimg, "%d", &I.pixel[i * I.w + j]);
      }
  } else {
    printf("Erro na Alocação.");
  }
  return I;
}

// Libera a alocação de memória
void free_imgb(imgb *I) {
  if (I->pixel != NULL) {
    free(I->pixel);
    I->pixel = NULL;
  }
}

// Cria a imagem limiarizada
void limiar(imgb *I, int lim) {
  // Verificando se não é NULL
  if ((*I).pixel != NULL) {
    for (int i = 0; i < (*I).h; i++) {
      for (int j = 0; j < (*I).w; j++) {
        // Se o elemento (i,j) .pixel for menor que lim,
        // o pixel da nova img receberá 0
        if ((*I).pixel[i * (*I).w + j] < lim) {
          (*I).pixel[i * (*I).w + j] = 0;
        }
        // Caso contrário, recebe a quantd. de cinza
        else {
          (*I).pixel[i * (*I).w + j] = (*I).cinza;
        }
      }
    }
  } else {
    printf("Erro na Alocação.");
    return;
  }
}

// Desenha a imagem
void write_imgb(char *filename, imgb *I) {
  FILE *resp = fopen(filename, "w");
  if (resp != NULL) {
    fprintf(resp, "%s ", "P2");
    fprintf(resp, "%d ", I->h);
    fprintf(resp, "%d ", I->w);
    fprintf(resp, "%d ", I->cinza);
    for (int i = 0; i < I->h; i++) {
      for (int j = 0; j < I->w; j++) {
        fprintf(resp, "%d ", I->pixel[i * I->w + j]);
      }
    }
    fclose(resp);
  } else {
    printf("Resp é NULL\n");
  }
}

// -------- Funções de negativo/inversa

// Inverte as cores da imagem
void inversa(imgb *I) {
  // Verificando se não é NULL
  if ((*I).pixel != NULL) {
    for (int i = 0; i < (*I).h; i++) {
      for (int j = 0; j < (*I).w; j++) {
        // Substitui a cor do pixel pela quantd. de cinza - sua cor original
        (*I).pixel[i * (*I).w + j] = (*I).cinza - (*I).pixel[i * (*I).w + j];
      }
    }
  } else {
    printf("Erro na Alocação.");
    return;
  }
}

// CMD invalido
void cmd_invalido() { 
  printf("Comando inválido. Digite help para ajuda.\n"); 
}

// Helper
void helper() {
  printf("--- Manipular imagens PMG --- \n");
  printf("  a) Limiarizacao \n");
  printf("    Ex.: nomeArquivoCompilado imagemEntrada.pgm limiar "
         "imagemSaida.pgm \n");
  printf("  b) Inversa / Negativo \n");
  printf("    Ex.: nomeArquivoCompilado imagemEntrada.pgm inversa "
         "imagemSaida.pgm \n");
  printf("-----------------------------\n");
}

int main(int argc, char *argv[]) {
  // Deixa o programa em português
  setlocale(LC_ALL, "Portuguese");

  // Caso seja digitado 4 argumentos indica que vai manipular a imagem
  if (argc == 4) {

    // Abre o arquivo e confere se ele é nulo
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("O arquivo não foi encontrado\n");
    } else {
      imgb I = read_img(fp);
      // Confere se o usuário que limiarizar ou inverter a imagem
      if (strcmp(argv[2], "limiar") == 0 || strcmp(argv[2], "LIMIAR") == 0) {
        printf("Digite o coeficiente de limiarização: \n");
        int lim;
        scanf("%d", &lim);
        // Chama a função de limiar e desenha a imagem
        limiar(&I, lim);
        write_imgb(argv[3], &I);
      } else if (strcmp(argv[2], "inversa") == 0 ||
                 strcmp(argv[2], "INVERSA") == 0) {
        // Chama a função de inversa e desenha a imagem
        inversa(&I);
        write_imgb(argv[3], &I);
      } else {
        cmd_invalido();
      }
      // Fecha o arquivo e libera o espaço na memória
      fclose(fp);
      free_imgb(&I);
    }
  } 
  // Caso passe apenas 2 argumentos, provavelmente está requerindo ajuda
  else if (argc == 2) {
    // Confere se digitou "help" ou um comando inválido
    if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "HELP") == 0) {
      helper();
      return 0;
    }
    cmd_invalido();
  } else {
    cmd_invalido();
  }
  return 0;
}

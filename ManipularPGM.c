#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

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

int main() {
  setlocale(LC_ALL, "Portuguese");

  FILE *fp = fopen("barbara.pgm", "r");

  if (fp == NULL) {
    printf("O arquivo não foi encontrado\n");
  } else {
    int lim;
    printf("Digite o coeficiente de limiarização: \n");
    scanf("%d", &lim);

    imgb I = read_img(fp);

    limiar(&I, lim);
    write_imgb("barbara_lim.pgm", &I);
    fclose(fp);
    free_imgb(&I);
  }
  return 0;
}

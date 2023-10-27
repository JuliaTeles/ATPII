typedef struct {
  float *coef; // ponteiro para alocação dos coeficientes
  int n;       // grau do polinômio
} polinomio;

// --- Funções do polinomios.c
polinomio readFile(char *filename);
void coeficientes(polinomio poli);
polinomio novoPolinomio(int n);
void freePoli(polinomio *p);

// --- Funções do operacoes.c
float resolver(polinomio poli, float x);
polinomio derivada(polinomio poli);
polinomio integral(polinomio poli, float k);
float integralDef(polinomio poli, float a, float b);

polinomio soma(polinomio um, polinomio dois);
polinomio subtracao(polinomio um, polinomio dois);
polinomio multiplicacao(polinomio um, polinomio dois);
polinomio maiorPoli(polinomio um, polinomio dois);
polinomio menorPoli(polinomio um, polinomio dois);

float newtonRaphson(polinomio poli, float x, float epsilon, int iterar);

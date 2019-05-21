#include <stdio.h>
#include <stdlib.h>

void verificaAmpuletas(int t_miojo, int t_amp1, int t_amp2);

int main(int argc, char *argv[]){
  /*
   Recebe três parametros da linha de comando
   O primeiro é o tempo que o miojo leva para ficar pronto
   O segundo é o tempo da primeira ampuleta
   O terceiro é o tempo da segunda ampuleta
  */
  verificaAmpuletas(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
  return 0;
}


void verificaAmpuletas(int t_miojo, int t_amp1, int t_amp2){
  // Variaveis auxiliares para fazer a combinação entre as ampuletas
  int t_aux1 = t_amp1, t_aux2 = t_amp2;

  // Tempo gasto para fazer o miojo
  int tempo_gasto = 0;

  // Verifica se o tempo do miojo é igual ao tempo da ampuleta
  if(t_amp1 == t_miojo || t_amp2 == t_miojo) {
    printf("Tempo de preparo do miojo: %d\n",t_miojo);
    return;
  }

  while(t_aux1 != t_aux2){
    /*
    Verifica qual ampuleta tem o menor tempo restante. Subtrai o maior tempo do
    menor, atualiza o contador de tempo com a ampuleta de menor quantia restante.
    Depois "reseta a ampuleta de menor quantia(seu tempo vira o inicial).
    */
    if(t_aux1 < t_aux2){
      t_aux2 = t_aux2 - t_aux1;
      tempo_gasto += t_aux1;
      t_aux1 = t_amp1;
    } else {
      t_aux1 = t_aux1 - t_aux2;
      tempo_gasto += t_aux2;
      t_aux2 = t_amp2;
    }
    // Verifica se alguma das ampuletas esta marcando o tempo do miojo
    if(t_aux1 == t_miojo || t_aux2 == t_miojo){
      if(t_aux1 != t_amp1) tempo_gasto += t_aux1;
      if(t_aux2 != t_amp2) tempo_gasto += t_aux2;
      printf("Tempo de preparo do miojo: %d\n",tempo_gasto);
      return;
    }
  }
  puts("Não é possivel encontrar uma configuração");
}

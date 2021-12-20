#include <iostream>
using namespace std;
#include "methods.hpp"
#include <vector>


//A = matriz triangular superior
//b=vetor constante

vector<float> eliminacaoGauss(vector<vector<float>> A, vector<float> b){
  int n = A.size(); //ordem de A

  for(int k = 0; k < n-1; k++){ //para cada etapa K
    printf("\nEtapa %d",k+1);
    
    for(int i = k+1; i < n; i++){ //para cada linha i
      //fator m
      float m = - A[i][k] / A[k][k];
    
      //atualizar a linha i da matriz, pecorrendo todas as colunas J
      for(int j = k+1; j < n; j++){ //para cada coluna j
        A[i][j] = m * A[k][j] + A[i][j];
      }
      printf("\nFator m: %f", m);
      b[i] = m * b[k] + b[i]; //atualiza o vetor B na linha i

      //zerar o elemento A[i][k]
      A[i][k] = 0;
      mostrarVetor(b);
      mostrarVetor(A);
    }}
  printf("\n");
  return substituicoes_retroativas(A,b);
}

bool escolhe_pivot(int k, vector<vector<float>> A, vector<float> b){
  int n = A.size(), linha_pivot = k;
  
  bool houve_troca = false; //indica se houve troca de linha ao final da função
  
  float pivot = A[k][k]; //setta o primeiro pivot
  
  //indenfica o elemento de maior valor absoluto e a linha onde ele está
  for(int i = k+1; i < n; i++){
    
    if( abs(A[i][k]) > abs(pivot) ){ //achou um novo pivot, então deve atualizar as variáveis utilizadas
      pivot = A[i][k];
      linha_pivot = i;
    }
  }

  if(k!=linha_pivot){ //se a linha inicial que "entrou" na função for diferente da linha do pivot que foi encontrado, indica que deverá haver uma troca
    A[k],A[linha_pivot] = A[linha_pivot], A[k];
    b[k],b[linha_pivot] = b[linha_pivot], b[k];
    
    houve_troca = true;
  }
  return houve_troca;
}
vector<float> gaussParcial(vector<vector<float>> A, vector<float> b){
  int n = A.size(); //ordem de A

  for(int k = 0; k < n-1; k++){ //para cada etapa K
    printf("\nEtapa %d",k+1);
    
    for(int i = k+1; i < n; i++){ //para cada linha i
    //escolhe o pivot
    escolhe_pivot(k,A,b);
    //fator m
    float m = - A[i][k] / A[k][k];
    
    //atualizar a linha i da matriz, pecorrendo todas as colunas J
    for(int j = k+1; j < n; j++){ //para cada coluna j
      A[i][j] = m * A[k][j] + A[i][j];
    }

    printf("\nFator m: %f", m);
    b[i] = m * b[k] + b[i]; //atualiza o vetor B na linha i

    //zerar o elemento A[i][k]
    A[i][k] = 0;
    mostrarVetor(b);
    mostrarVetor(A);
  }}
  printf("\n");
  return substituicoes_retroativas(A,b);
}


vector<vector<vector<float>>> fatoracaoLU(vector<vector<float>> A){
  int n = A.size();

  vector<vector<float>> L = identidade(n);

  for(int k = 0; k < n-1; k++){ //para cada etapa K
    printf("\nEtapa %d",k+1);
    
    for(int i = k+1; i < n; i++){ //para cada linha i
      //fator m
      float m = - A[i][k] / A[k][k];

      L[i][k] = -m;

      //atualizar a linha i da matriz, pecorrendo todas as colunas J
      for(int j = k+1; j < n; j++){ //para cada coluna j
        A[i][j] = m * A[k][j] + A[i][j];
      }
      printf("\nFator m: %f", m);

      //zerar o elemento A[i][k]
      A[i][k] = 0;
      printf("\nMatriz L:");
      mostrarVetor(L);
      printf("Matriz U:");
      mostrarVetor(A);
    }}

  vector<vector<vector<float>>> r{L,A};
  return r;
}

vector<float> resolverLUx(vector<vector<float>> L, vector<vector<float>> U, vector<float> b){ //resolver o sistema LUx = b
  vector<float> y = substituicoes_sucessivas(L,b);
  vector<float> x = substituicoes_retroativas(U,y);

  return x;
}


vector<float> gaussJordan(vector<vector<float>> A, vector<float> b){
  int n = A.size();
  
  for(int k = 0; k < n; k++){ //para cada etapa K
    printf("\nEtapa %d",k+1);
    //transformar o pivot em 1
    for(int j = k+1; j < n; j++){//para cada coluna j
      A[k][j] = A[k][j] / A[k][k];
    }
    b[k] = b[k] / A[k][k];
    A[k][k] = 1;
    
    for(int i = 0; i < n; i++){ //para cada linha i
      //fator m

      if(i!=k){ //só fará a eliminação se a linha não for a do pivot
        float m = - A[i][k] / A[k][k];
      
        //atualizar a linha i da matriz, pecorrendo todas as colunas J
        for(int j = k+1; j < n; j++){ //para cada coluna j
          A[i][j] = m * A[k][j] + A[i][j];
        }
      
        b[i] = m * b[k] + b[i]; //atualiza o vetor B na linha i
        A[i][k] = 0; //zerar o elemento A[i][k]

        printf("\nFator m: %f\n", m);
        mostrarVetor(b);
        mostrarVetor(A);
      }
    }}
  return b;
}
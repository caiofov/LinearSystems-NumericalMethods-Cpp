#include "methods.hpp"
#include <vector>
#include <iostream>
using namespace std;

void showVector(vector<float> v){
  printf("{");
  for(int i = 0; i < v.size();i++){
    printf("%f,", v[i]);
  }
  printf("}\n");
}

void showVector(vector<vector<float>> v){
  printf("{");
  for(int i = 0; i < v.size();i++){
    printf("{");
    for(int j =0; j < v[i].size();j++){
      cout << v[i][j] << ",";
    }
    printf("},");
  }
  printf("}\n");
}


vector<float> substituicoes_retroativas(vector<vector<float>> A, vector<float> b){
  int n = A.size(); //ordem de A
  vector<float> x(n,0);
  //inicializa o vetor x com tamanho n e elemento iguais a 0

  for(int i = n-1; i > -1; i--){
    float S = 0;
    for(int j = i+1; j < n; j++){
      S = S + A[i][j] * x[j];
    }
    x[i] = (b[i] - S) / A[i][i];
  }

  return x;
}

vector<float> substituicoes_sucessivas(vector<vector<float>>A, vector<float> b){
  int n = A.size(); //ordem de A
  vector<float> x(n,0);
  //inicializa o vetor x com tamanho n e elemento iguais a 0

  for(int i = 0; i < n; i++){
    int S = 0; 
    for(int j = 0; j < i; j++){
      S = S + A[i][j] * x[j];
    }
    x[i] = (b[i] - S) / A[i][i];
  }
  return x;
}

vector<vector<float>> identidade(int n){ //cria uma matriz de identidade de ordem N

  vector<vector<float>> id(n, vector<float>(n,0)); //inicializa a matriz com 0's

  for(int i = 0; i < n; i++){
    id[i][i] = 1;
  }

  return id;
}
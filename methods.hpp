using namespace std;
#include <vector>

//auxiliares
void mostrarVetor(vector<float> v);
void mostrarVetor(vector<vector<float>> v);

vector<float> substituicoes_retroativas(vector<vector<float>> A, vector<float> b);
vector<float> substituicoes_sucessivas(vector<vector<float>>A, vector<float> b);
vector<vector<float>> identidade(int n);

//Questão 1
vector<float> eliminacaoGauss(vector<vector<float>> A, vector<float> b);
bool escolhe_pivot(int k, vector<vector<float>> A, vector<float> b);
vector<float> gaussParcial(vector<vector<float>> A, vector<float> b);

//Questão 2
vector<vector<vector<float>>> fatoracaoLU(vector<vector<float>> A);
vector<float> resolverLUx(vector<vector<float>> L, vector<vector<float>> U, vector<float> b);

//Questão 3
vector<float> gaussJordan(vector<vector<float>> A, vector<float> b);
vector<vector<float>> gaussJordan_matrizInversa(vector<vector<float>> A);
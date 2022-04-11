// Aplicações e Serviços Web
// Cifra de Vernam
// João Pedro B. Dias -
// Marcos Cotta -
// Paulo Lima -

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <cstdlib>

int *func_xor(char *p_chave, char *p_mensagem, int tamanho) // essa função retornara a mensagem codificada
{
  int mensagem_decimal[100], chave_decimal[100], i; // declaração de variaveis
  static int mensagem_criptografada[100];

  for (i = 0; i < 100; i++)
  { // inicialização dos vetores inteiros
    chave_decimal[i] = NULL;
    mensagem_decimal[i] = NULL;
    mensagem_criptografada[i] = NULL;
  }
  for (i = 0; i < tamanho; i++)
  { // armazenando a mensagem e a chave nos vetores inteiros em decimal ASCII
    mensagem_decimal[i] = *p_mensagem;
    chave_decimal[i] = *p_chave;
    p_mensagem++;
    p_chave++;
  }
  // fazer a comparação usando a regra xor entre a mensagem em int e a chave em int

  for (i = 0; i < tamanho; i++)
  {
    mensagem_criptografada[i] = mensagem_decimal[i] ^ chave_decimal[i];
  }

  std::cout << std::endl
            << "Mensagem Cifrada em decimal: ";
  for (i = 0; i < tamanho; i++)
  {
    std::cout << mensagem_criptografada[i];
  }

  std::cout << std::endl;
  return mensagem_criptografada;

  // pegar o vetor em binario ja criptografado e transformar para um vetor em ASCII
  // retornar na função o vetor inteiro em ASCII contendo a mensagem criptografada
};

int *func_xor_inv(char *p_chave, int *p_mensagem, int tamanho) // essa função retornara a mensagem descodificada
{
  int mensagem_decimal[100], chave_decimal[100], i; // declaração de variaveis
  static int mensagem_criptografada[100];

  for (i = 0; i < 100; i++)
  { // inicialização dos vetores inteiros
    chave_decimal[i] = NULL;
    mensagem_decimal[i] = NULL;
    mensagem_criptografada[i] = NULL;
  }
  for (i = 0; i < tamanho; i++)
  { // armazenando a mensagem e a chave nos vetores inteiros em decimal ASCII
    mensagem_decimal[i] = *p_mensagem;
    chave_decimal[i] = *p_chave;
    p_mensagem++;
    p_chave++;
  }
  // fazer a comparação usando a regra xor entre a mensagem em int e a chave em int

  for (i = 0; i < tamanho; i++)
  {
    mensagem_criptografada[i] = mensagem_decimal[i] ^ chave_decimal[i];
  }

  std::cout << std::endl
            << "Mensagem Descifrada em decimal: ";
  for (i = 0; i < tamanho; i++)
  {
    std::cout << mensagem_criptografada[i];
  }

  std::cout << std::endl;
  return mensagem_criptografada;

  // pegar o vetor em binario ja criptografado e transformar para um vetor em ASCII
  // retornar na função o vetor inteiro em ASCII contendo a mensagem criptografada
};

int main(int argc, char const *argv[])
{
  char mensagem[100], chave[100];
  int diferenca, i, tamanho;
  int *mensagem_codificada;

  for (i = 0; i < 100; i++)
  {
    mensagem[i] = NULL;
    chave[i] = NULL;
  }

  printf("Entre a mensagem que gostaria de utilizar: ");
  std::cin.getline(mensagem, 100);
  printf("Entre a chave que gostaria de utilizar: ");
  std::cin.getline(chave, 100);

  tamanho = strlen(mensagem);
  diferenca = tamanho - strlen(chave);

  if (diferenca == 0)
    mensagem_codificada = func_xor(chave, mensagem, tamanho);

  else if (diferenca > 0)
  {
    for (i = 0; i < diferenca; i++)
      chave[strlen(chave)] = chave[i];
    mensagem_codificada = func_xor(chave, mensagem, tamanho);
  }
  else
  {
    std::cout << "\nseu jumento!!!!!"; // mudar isso pela mor de Deus
    return 1;
  }

  // Imprime a mensagem codificada e pede a chave para decifração
  std::cout << "Mensagem Cifrada: ";
  for (i = 0; i < tamanho; i++)
    std::cout << (char)*(mensagem_codificada + i);
  std::cout << std::endl;

  std::cout << "\nInsira a chave para decifrar a mensagem\n";
  std::cin.getline(chave, 100);
  diferenca = tamanho - strlen(chave);

  // Iguala o tamanho da chave inserida a mensagem codificada e realiza a cifra inversa
  if (diferenca == 0)
    mensagem_codificada = func_xor_inv(chave, mensagem_codificada, strlen(mensagem));
  else if (diferenca > 0)
  {
    for (i = 0; i < diferenca; i++)
      chave[strlen(chave)] = chave[i];
    mensagem_codificada = func_xor_inv(chave, mensagem_codificada, strlen(mensagem));
  }
  else
  {
    std::cout << "\nseu jumento!!!!!"; // mudar isso pela mor de Deus
    return 1;
  }
  std::cout << "Mensagem Decifrada: ";
  for (i = 0; i < strlen(mensagem); i++)
  {
    std::cout << (char)*(mensagem_codificada + i);
  }
  std::cout << std::endl;

  return 0;
}

/*for(i=0;i<100;i++){                                   // Percorre todas as posições dos vetores de mensagem binarios
    for(j=0;j<6;j++){                                 // Percorre as casas decimais dos ints no vetor
      digito_mensagem = (mensagem[i]/pow(10,j)) % 10;
      digito_chave = (chave[i]/pow(10,j)) % 10;

      if((digito_mensagem + digito_chave)== 1 ){      // Operação XOR
          digito_mensagem = 1;
      }else{
          digito_mensagem = 0;
      }
      mensagem_cript[i] += digito_mensagem * pow(10,j);
    }
}*/

/*
// transformar de decimal ASCII para binario
for (i = 0; i < 100; i++)
{                          // transformar mensagem de ASCII para binario
  if (mensagem[i] == NULL) // quando a mensagem chegar no final
    break;
  else
  { // começa a transformação
    var_aux = 0;
    var_aux2 = 0;
    for (var_ele = 0; mensagem[i] > 1; var_ele++)
    { // passa de inteiro por inteiro transformando em binario e salvando no proprio vetor mensagem ao final
      var_aux = mensagem[i] % 2;
      var_aux2 = var_aux2 + var_aux * pow(10, var_ele);
      mensagem[i] = mensagem[i] / 2;
    }
    var_aux2 = mensagem[i] * pow(10, var_ele); // a ultima transformação para salvar o most significant bit
    mensagem[i] = var_aux2;                    // armazena no vetor mensagem agora a mensagem em binario
  }
}
for (i = 0; i < 100; i++)
{                       // transformar chave de ASCII para binario
  if (chave[i] == NULL) // quando a chave chegar no final
    break;
  else
  { // começa a transformação
    var_aux = 0;
    var_aux2 = 0;
    for (var_ele = 0; chave[i] > 1; var_ele++)
    { // passa de inteiro por inteiro transformando em binario e salvando no proprio vetor mensagem ao final
      var_aux = chave[i] % 2;
      var_aux2 = var_aux2 + var_aux * pow(10, var_ele);
      chave[i] = chave[i] / 2;
    }
    var_aux2 = chave[i] * pow(10, var_ele); // a ultima transformação para salvar o most significant bit
    chave[i] = var_aux2;                    // armazena no vetor chave agora a chava em binario
  }
}
*/
int main() {

      // Há alocação de memória Estática e Dinânimca (estática é reservada com a inicialização do programa)

      int x1 = 125;
      float A = 135.4, B = 89.3;
      char frase[10] = "kkkkkk";
      char c = 'A';
      // Não há Boolean em C (tem que usar um Integer
      // (0->False e !0->True)) -> Ex.: if(10) -> True

      // A alocação na memória é de resposabilidade do OS (lugares não definidos e aleatórios)

      // Atribuição:
      x1 = 345; // = -> é um operador (não comando) entre as variáveis
      int x2 = x1 = 345; // A expressão resultante do operador (=) retorna o valor (345) que pode ser reutilizado

      // Operadores aritméticos:
      // '+', '-', '*', '/'
      // '%' (mod) -> resto de divisão
      // '/' -> divisão inteira (se numerador e denominador são inteiros)

      // Operadores lógicos:
      // && (and), || (or), ! (not)
      
      // Operadores relacionais:
      // ==, !=, >, <, >=, <=

      // pow() -> potenciação

      // Nomes de variáveis:
      // Inicia com letra ou underline
      // Evitar usar underline no início (coincide com nomes de bibliotecas)

      // Tipos de dados:
      // char -> caratere ASCII (1 byte)
      // int -> valor númerico inteiro (4 bytes) (-32768 - 32767)
      // short -> valor numérico inteiro (2 bytes)
      // long -> valor numérico inteiro (8 bytes)
      // float -> valor numérico real (4 bytes)
      // double -> valor numérico real (8 bytes)
      // -> Pode-se usar a palavra unsigned antes da variável para retirar o sinal do número
      //    Se for atribuído um número com sinal, ele é gravado como positivo (pelo seu valor interno), não lendo como negativo (por ignorar o bit do sinal como sendo tal)

      // Caracteres:
      // ASCII + Caracteres especiais
      // Ex.: \0 (nulo),
      //      \n (nova linha),
      //      \t (tabulção),
      //      \\ (barra invertida),
      //      \' (aspa simples),
      //      \xnnn (byte em hexadecimal (0 -> 255)),
      //      \x1b (escape)

      // Escopos:
      // Globais -> fora do main()
      // Locais -> dentro de main() ou de outra instância

      // Operadores de incremento:
      // i++ -> i = i + 1 (e retorna i + 1) (pós-incremento)
      // ++i -> i = i + 1 (e retorna i) (pré-incremento)
      // i-- -> i = i - 1 (e retorna i - 1) (pós-decremento)
      // --i -> i = i - 1 (e retorna i) (pré-decremento)

      return 0;
}

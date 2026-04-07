# Projeto: Transporte Coletivo Municipal

## Descrição

Este projeto consiste em uma aplicação desenvolvida em C++ com o objetivo de organizar uma empresa de transporte
coletivo municipal.

A estrutura do projeto foi organizada de forma modular, separando arquivos de código-fonte, cabeçalhos e testes, a fim de facilitar a manutenção, legibilidade e escalabilidade.

---

## Estrutura do Projeto

```
meu-projeto/
│
├── src/        # Implementações (.cpp)
├── include/    # Arquivos de cabeçalho (.h)
├── tests/      # Testes do projeto
├── main.cpp    # Arquivo principal
└── README.md   # Documentação
```

---

## Requisitos

Para compilar e executar este projeto, é necessário:

* Compilador GCC versão 10 ou superior
* Sistema operacional compatível (Windows, Linux ou macOS)
* Editor ou IDE (recomendado: Visual Studio Code com extensão C/C++)

---

## Compilação e Execução

### Compilação do programa principal

No terminal, na raiz do projeto, execute:

```bash
g++ main.cpp -o programa
```

Caso o projeto utilize arquivos dentro de `src/` e `include/`, utilize:

```bash
g++ main.cpp src/*.cpp -Iinclude -o programa
```

### Execução

No Linux/macOS:

```bash
./programa
```

No Windows:

```bash
programa.exe
```

---

## Testes

### Compilação dos testes

```bash
g++ tests/teste.cpp src/*.cpp -Iinclude -o teste
```

### Execução dos testes

No Linux/macOS:

```bash
./teste
```

No Windows:

```bash
teste.exe
```

---

## Observações

* Certifique-se de que o compilador GCC esteja corretamente instalado e configurado no PATH do sistema.
* Caso utilize o Visual Studio Code, recomenda-se instalar a extensão oficial de C/C++ para melhor suporte ao desenvolvimento.

---

## Análise e Justificativa

### 1. Qual variação de lista foi escolhida?
Foi utilizada uma lista duplamente encadeada.

### 2. Por que essa é a estrutura mais adequada?
A lista duplamente encadeada é mais adequada pois permite:
* Navegação em ambos os sentidos (ida e volta), essencial para mostrar a rota normal e inversa
* Remoção eficiente tanto no início quanto no final da lista
* Inserções mais flexíveis no meio da estrutura
Como o sistema exige operações como mostrar rota inversa e manipular tanto início quanto fim da lista, essa estrutura se torna mais eficiente que uma lista simplesmente encadeada

### 3. Existe cenário onde outra lista seria melhor?
Sim. Em um cenário como linhas circulares de ônibus, uma lista circular seria mais vantajosa.
Visto que:
* O último elemento se conecta ao primeiro
* Permite percorrer a rota continuamente sem precisar reiniciar manualmente
* Representa melhor sistemas onde não há início e fim definidos
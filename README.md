# Turing Machine Sum

Programa em C que simula uma Máquina de Turing para incrementar um número binário em 1. Lê uma sequência de `0`s e `1`s, processa da direita para a esquerda na fita e imprime o resultado.

## Arquivos do projeto

```
turing-machine-sum/
├── main.c                      # Código-fonte
├── turing_machine_sum.cbp      # Projeto Code::Blocks
├── turing_machine_sum.depend   # Dependências do Code::Blocks
├── turing_machine_sum.layout   # Layout do editor no Code::Blocks
├── LICENSE                     # GNU GPL v2
├── .gitignore                  # Ignora bin/, obj/ e artefatos de compilação
└── README.md
```

Saídas de compilação (ignoradas pelo Git):

- `bin/Debug/turing_machine_sum`
- `bin/Release/turing_machine_sum`
- `obj/`

## Comportamento

1. Exibe o prompt: `Input the binary number: `
2. Lê o número binário digitado pelo usuário
3. Coloca os dígitos na fita a partir da posição 50
4. Incrementa o número em 1 (da direita para a esquerda)
5. Imprime o resultado na stdout

| Entrada | Saída |
|---------|-------|
| `0` | `1` |
| `1` | `10` |
| `101` | `110` |
| `111` | `1000` |

## Constantes (`main.c`)

| Constante | Valor | Uso |
|-----------|-------|-----|
| `START_TAPE` | 50 | Índice inicial onde o número é armazenado na fita |
| `SIZE_WORD` | 100 | Tamanho do array que representa a fita |

## Funções (`main.c`)

### `get_input(char* input)`

Lê a entrada do usuário com `gets()`, conta os caracteres e copia os dígitos para `input[START_TAPE + i]`.

### `search_null(char* input)`

Percorre a fita a partir de `START_TAPE` até encontrar `\0`. Retorna o índice dessa posição.

### `sum(char* input, int point_null)`

Incrementa o número binário in-place, começando em `point_null - 1` e indo para a esquerda:

| Valor em `input[i]` | Escrita |
|---------------------|---------|
| `'1'` | `'0'` (continua) |
| `'0'` | `'1'` (para) |
| `'\0'` | `'1'` (para) |

Retorna o índice onde parou.

### `print_input(char* input, int index_start)`

Imprime os caracteres da fita a partir de `index_start` (ou de `START_TAPE`, se `index_start` for maior). Para no `\0`.

### `main()`

Chama, em sequência: `get_input` → `search_null` → `sum` → `print_input`.

## Compilação

### GCC

```bash
gcc -Wall -g -o turing_machine_sum main.c
./turing_machine_sum
```

### Code::Blocks

Abrir `turing_machine_sum.cbp`. Targets disponíveis:

| Target | Flags | Executável |
|--------|-------|------------|
| Debug | `-Wall`, `-g` | `bin/Debug/turing_machine_sum` |
| Release | `-Wall`, `-O2`, linker `-s` | `bin/Release/turing_machine_sum` |

## Dependências

- `stdio.h`, `stdlib.h`, `string.h`
- Compilador GCC

## Licença

GNU General Public License v2.0 — ver [LICENSE](LICENSE).

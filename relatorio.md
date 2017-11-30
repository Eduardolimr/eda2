## Projeto 2 - Estuturas de Dados e Algoritmos I

## Grupo

| Nome               | Email                          | Github    |
| ------------------ | ------------------------------ | --------- |
| Eduardo Lima Ribeiro     | eduardolimrib@gmail.com | [@Eduardolimr](https://github.com/eduardolimr)             |
| Samuel Barros Borges     | samuelmordred@gmail.com          | [@SamuelMordred](https://github.com/SamuelMordred)  |

## Diário
| Dia               | Atividade                          | Observações    |
| ------------------ | ------------------------------ | --------- |
| 23/11/2017    | Commit inicial do projeto, iniciação da pesquisa.|   Criação da estutura de árvore AVL e de hash. |
| 25/11/2017     |  Implementação das funções de hash e de árvore AVL. | Função de comparação AVL ainda incompleta, hash possui colisões.  |
| 26/11/2017    | Segunda tentativa para auto balanceamento da AVL e primeira versão funcional do código da AVL atingido na terceira tentativa. |  - |
| 28/11/2017 | Começo da implementação da estutura AVL no código de corretor ortográfico. | Colisões no código hash ainda presentes.|
| 29/11/2017 | Término da implementacao da AVL no corretor ortografico e hash. | |

## Objetivo
   O objetivo deste projeto é utilizar de duas formas de estuturas de dados diferentes (Árvores AVL e Hashtables) para duas implementações de um corretor ortográfico em C.

## Requisitos

* Árvores
* Árvores de busca
* Alocação dinâmica
* Ponteiros
* Manuseio de arquivos
* Hashtables
* Manuseio de strings


## Projeto
   Foram implementadas ambas as soluções tanto em árvores AVL como em hash table, havendo uma diferença de perfomance entre as duas,a ser destacada à seguir.

![alice.txt](https://i.imgur.com/Wzy7hCh.png)
![shakespeare.txt](https://i.imgur.com/aAlugCK.png)

  Como pode-se perceber, o programa utilizando hastables tem uma perfomance bem melhor, o que já era esperado pois ele não precisa fazer busca alguma durante a sua execução, enquanto a árvore AVL se torna menos eficiente bem mais rápido quanto maior que a hashtable.

## Explicações
   Para a solução utilizando AVL foi utilizada uma função de comparação alfabética para a inserção das palavras do dicionário na estrutura, e para a busca de possíveis palavras da estrutura. A AVL por ser uma estrutura que necessita de alocação dinâmica necessitou de uma função recursiva para a liberação de memória ao fim do programa.

  Já para a solução ótima foi utilizada uma função hash personalizada para eliminar as colisões, tornando assim a busca extremamente eficiente. Foi utilizado um vetor de ponteiros tipo char para armazenar as palavras e portanto, não foi necessário desalocar a memoria no final do programa.

## Falhas/Limitações
   A principal limitacao encontrada foi no tratamento de colisoes encontradas nas funções hash oferecidas, o que culminou na falta de uma implementacao funcional que utilizasse uma dessas funções. Sobretudo, foi enviada uma versão que usa outra função de hash que proporciona muitas poucas colisões para contrapor isso.

## Opiniões

   O trabalho foi importante para o aprendizado dessas estruturas de dados e para a formação de uma nova perspectiva sobre a eficiência que elas proporcionam, além de dar uma ótima lição em trabalho em grupo e divisão de tarefas para um projeto.

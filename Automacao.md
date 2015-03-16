# Automação do Processo de Tecelagem de Eletrodos Multifilares #

A necessidade de automação resultou em um  projeto de mecatrônica onde um programa executado em um microcomputador envia sinais pela porta paralela para um circuito eletrônico que controla motores e sensores que fazem a mecânica funcionar da forma desejada.

A tarefa de operação consiste simplesmente em posicionar o fio no suporte e soldar sua ponta em uma das arestas do cubo. Feito isso, basta acionar um botão na tela do microcomputador e o processo de tecelagem ocorre com precisão, confiabilidade e segurança.

## Sistema Mecânico ##

Para automatizar este sistema foram adaptados motores, sensores, polias, correias e  rolamentos de forma a obter sincronismo durante  processo.  Utilizamos 3 motores:
- Dois motores de passo (um para movimento do cubo e outro para o movimento do fuso).
- Um motor DC (para controle de tensão do fio).
Para controlar e proteger o sistema e permitir um movimento sincronizado foram incorporados sensores ópticos e sensores mecânicos:
- Dois sensores ópticos :  um para sinalizar o rompimento do fio (figura 5) e outro para contagem de voltas do cubo (figura 8).
- Dois sensores mecânicos para detectar fim de curso (figura 6)

## Monitoramento e alinhamento do fio ##

Um sistema de polias foi projetado para guiar e manter o alinhamento do fio, que é monitorado por um sensor óptico ativado em caso de rompimento. A bobina do fio foi acoplada a um motor DC, de modo que o fio é mantido sob tensão durante todo o processo de tecelagem. A disposição do motor DC é esboçada na figura 6.

No conjunto de polias mostrado na figura 5 pode-se observar que uma delas é acoplada a um pêndulo, e fica suspensa durante o processo de tecelagem. Se o fio se romper a polia é solta fazendo com que o pêndulo passe pelo sensor óptico, que quando ativo envia um sinal ao computador que interrompe o movimento dos motores.

## Movimento dos planos de fios ##

Um motor de passo foi acoplado à lateral de uma das hastes que sustentam o cubo. Através de uma correia e duas polias sincronizadas este motor  faz a estrutura cúbica girar  (figura 7).

O sensor óptico de contagem foi fixado na mesma haste e é acionado por um pino adaptado a uma das arestas do cubo, de modo que a cada giro completo o sensor é ativado, enviando um sinal para o microcomputador fazer um outro motor avançar o suporte em um número de passos programados (figura 8).

## Movimento do suporte do fio ##

Para movimentar o suporte do fio foi utilizado um motor de passo com o eixo acoplado
diretamente ao fuso (figura9)

## Especificações ##

O fuso utilizado tem passo de 1mm (∆X =1mm), para avançar este valor o motor precisa dar um giro completo (∆θ = 360º). Para isso é necessário avançar 200 passos  ou  400 1/2 passos conforme tabela abaixo.
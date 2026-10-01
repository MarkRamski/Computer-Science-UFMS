"""
# QUESTÃO 1

As capivaras da UFMS sofreram algumas mutações recentes, e passaram a ter a capacidade de levitação. Além disso, fizeram um curso de programação e, desde então, não conseguem mais se organizar em outro formato que não seja o formato mostrado na figura abaixo:
Escreva um código que recebe um número inteiro n que representa uma quantidade de capivaras levitando em uma floresta mágica da UFMS. A partir dessa quantidade, responda dois números inteiros (1 por linha):
1 - A quantidade de fileiras necessárias para colocar as n capivaras no formato descrito na imagem;
2 - A quantidade máximo de capivaras que caberiam nessas fileiras (ao todo).
Orientação principal:
Seu exercício DEVE utilizar estruturas de repetição para chegar nas duas respostas. Cálculos automáticos utilizando fórmulas não serão considerados.

n = int(input())

fileira = total = 0

while total < n:
    fileira += 1
    total += fileira

maximo = fileira * (fileira + 1) // 2

print(fileira)
print(maximo)

------------------------------------------

# QUESTÃO 3

Um determinado dono de cartório sofre de um problema complexo, e só permite o registro de nomes que não despertem nele uma estranha agonia que ele desenvolveu. Observe o quadrinho abaixo:
Como ele precisa registar muitas crianças todos os dias, ele precisa de sua ajuda para construir um software que detecte se o nome a ser registrado despertará nele a agonia ou não.
Construa um algoritmo que recebe uma palavra que representa um nome em letras maiúsculas (apenas uma palavra, sem espaços e acentos), e retorna ACEITO se o nome em questão NÃO despertar agonia no dono do cartório. Caso contrário, seu algoritmo deve retornar REJEITADO.

nome = str(input())

invertido = ''

for c in range(len(nome) -1, -1, -1):
    invertido += nome[c]

if nome == invertido:
    print('REJEITADO')

else:
    print('ACEITO')

"""
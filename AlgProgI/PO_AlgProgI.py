"""
# QUESTÃO 1

Leia três números com casas decimais (A, B e C) representando os lados de um triângulo e organize esses lados em ordem decrescente, de tal maneira que A contenha o maior dos três lados. Logo após, determine o tipo do triângulo que esses lados formam, baseado nos seguintes casos:
Se A >= B + C, escreva a mensagem: não forma triângulo;
Se A2 = B2 + C2, escreva a mensagem: triângulo retângulo;
Se A2 > B2 + C2, escreva a mensagem: triângulo obtusângulo;
Se A2 < B2 + C2, escreva a mensagem: triângulo acutângulo;
Se os três lados são iguais, escreva a mensagem: triângulo equilátero;
Se dois dos três lados são iguais, escreva a mensagem: triângulo isósceles;
Se os três lados são diferentes, escreva a mensagem: triângulo escaleno.
Note que as condições 1, 2, 3 e 4 são independentes em relação às condições 5, 6, e 7.

a = float(input())
b = float(input())
c = float(input())

if a < b:
    a, b = b, a

if a < c:
    a, c = c, a

if b < c:
    b, c = c, b

if a >= b + c:
    print('não forma triângulo')

else:
    if (a ** 2) == (b ** 2) + (c ** 2):
        print('triângulo retângulo')

    elif (a ** 2) > (b ** 2) + (c ** 2):
        print('triângulo obtusângulo')

    elif (a ** 2) < (b ** 2) + (c ** 2):
        print('triângulo acutângulo')

    if a == b == c:
        print('triângulo equilátero')

    elif a == b or b == c or a == c:
        print('triângulo isósceles')

    elif a != b != c:
        print('triângulo escaleno')

---------------------------------------

# QUESTÃO 2

Escreva um programa que leia uma sequência de números inteiros positivos (um por linha), e imprima somente os ímpares, até que seja lido um número múltiplo de 7. Assim que for lido um número múltiplo de 7, o programa deve encerrar imediatamente sem imprimi-lo.

Você não deve utilizar estruturas de repetição com contadores fixos (for), apenas while. Neste exercício, você deve utilizar pelo menos um dos comandos vistos em sala de aula: break, continue ou pass.

while True:
    number = int(input())
    
    if number % 7 == 0:
        break

    elif number % 2 == 1:
        print(number)

----------------------------------------

# QUESTÃO 3

Tentando verificar se um dado de seis faces apresenta vício, o proprietário de um cassino realizou n lançamentos consecutivos. Cada resultado foi registrado em uma linha separada.
Você deve escrever um programa que:
Leia um valor inteiro n, indicando a quantidade de lançamentos.
Leia n valores inteiros, cada um representando o resultado de um lançamento do dado (valores de 1 a 6), um por linha.
Após a leitura, o programa deve contar quantas vezes cada uma das faces (1, 2, 3, 4, 5 e 6) ocorreu.
Ao final, o programa deve imprimir exatamente seis valores, correspondendo às quantidades de ocorrências das faces 1, 2, 3, 4, 5 e 6, nesta ordem, separados por vírgulas e um espaço após cada vírgula.
Observação: nesse exercício, você deve utilizar pelo menos um vetor para solucionar o problema. 

contador_1 = contador_2 = contador_3 = contador_4 = contador_5 = contador_6 = 0
n = int(input())

lista = []

def sequencia(vetor):
    for c in range(n):
        valores = int(input())
        lista.append(valores)
    return(lista)

for item in sequencia(lista):
    if item == 1:
        contador_1 += 1

    elif item == 2:
        contador_2 += 1

    elif item == 3:
        contador_3 += 1

    elif item == 4:
        contador_4 += 1

    elif item == 5:
        contador_5 += 1

    elif item == 6:
        contador_6 += 1


print(f'{contador_1}, {contador_2}, {contador_3}, {contador_4}, {contador_5}, {contador_6}')

"""
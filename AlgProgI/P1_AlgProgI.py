"""
# QUESTÃO 1
Crie um programa em Python que leia dois números inteiros e um operador matemático (+, -, *, /).
As informações devem ser lidas de forma direta, utilizando apenas input (sem mensagens auxiliares de print) para pedir os valores. As entradas serão fornecidas uma após a outra, cada uma em uma linha.
O programa deve realizar a operação indicada e imprimir apenas o resultado inteiro da operação (corte as casas decimais do resultado antes de imprimi-lo).

a = int(input())
b = int(input())

operacao = str(input())

if operacao == '+':
    print(f'{a + b}')

if operacao == '-':
    print(f'{a - b}')

if operacao == '*':
    print(f'{a * b}')

if operacao == '/':
    print(f'{int(a / b)}')

---------------------------------------

# QUESTÃO 2
O Clube da Produtividade descobriu que o nível de procrastinação de uma pessoa depende do IP (Índice de Procrastinação), do nível de energia e do time de futebol do indivíduo.
Crie um programa que leia uma entrada por linha, na seguinte ordem:
Nome da pessoa
Horas produtivas por dia (inteiro)
Horas de procrastinação por dia (inteiro)
Nível de energia (0 a 10, float)
Time do coração (string) – Flamengo ou Palmeiras
Calcule o IP do indivíduo seguindo a seguinte fórmula:
 P = horas de procrastinação / horas produtivas ** 2
A classificação final do indivíduo segue as seguintes regras:
Se torce para Flamengo:
Se possui IP menor que dois e tem energia maior ou igual a 6 → Produtivo, Filipe Luís aprova
Caso contrário → Procrastinador do Mengão
Se torce para Palmeiras:
Se possui IP menor que três e energia maior ou igual a 5 → Distraído, mas ainda sem mundial
Caso contrário → Procrastinador sem mundial
Uma vez classificado o indivíduo, imprima o seu nome e sua classificação final (uma impressão por linha).

nome = str(input())
produtivo = int(input())
procastina = int(input())
energia = float(input())
time = str(input())

ip = procastina / (produtivo ** 2)

print(nome)

if time == 'Flamengo':
    if ip < 2 and energia >= 6:
        print('Produtivo, Filipe Luís aprova')
    
    else:
        print('Procrastinador do Mengão')

if time == 'Palmeiras':
    if ip < 3 and energia >= 5:
        print('Distraído, mas ainda sem mundial')
    
    else:
        print('Procrastinador sem mundial')

---------------------------------------

# QUESTÃO 3
Você é um detetive e precisa descobrir a idade exata de uma pessoa.
O programa deve ler uma entrada por linha, na seguinte ordem:
Dia de nascimento (inteiro)
Mês de nascimento (inteiro)
Ano de nascimento (inteiro)
Dia atual (inteiro)
Mês atual (inteiro)
Ano atual (inteiro)
O programa deve calcular a idade em anos completos, e imprimir apenas essa informação (valor inteiro).  

dia_nascimento = int(input())
mes_nascimento = int(input())
ano_nascimento = int(input())

dia_atual = int(input())
mes_atual = int(input())
ano_atual = int(input())

idade_anos = ano_atual - ano_nascimento

if mes_atual < mes_nascimento:
    idade_anos -= 1

if mes_atual == mes_nascimento:
    if dia_atual < dia_nascimento:
        idade_anos -= 1
    
print(idade_anos)

"""
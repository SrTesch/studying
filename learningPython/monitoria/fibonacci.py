n = int(input("Digite um número para o tamanho da sequencia de fibonacci desejada: "))

def fibonacci(n):
    termo1 = 0
    termo2 = 1
    Lista = [termo1, termo2]
    if n != 0 and n != 1:
        for i in range(n-2):
            termoGeral = termo1 + termo2
            termo1 = termo2
            termo2 = termoGeral
            Lista.append(termoGeral)
        return Lista

Fibonacci1 = fibonacci(n)

def imprimir(lista):
    for i in range(len(lista)):
        for j in range(i + 1):
            print(f'{lista[j]} ', end ="")
        print()


imprimir(Fibonacci1)

def imprimirInvertido (lista):
    for i in range(len(lista)-1, -1, -1):
        for j in range(i):
            print(f'{lista[j]} ', end ="")
        print()

imprimirInvertido(Fibonacci1)
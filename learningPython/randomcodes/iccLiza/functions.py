def verifica ():
    print("Quando quiser parar, digite 'sair'.")
    vet = []
    while True:
        x = input("Digite uma letra: ")
        if x == "sair":
            break
        else:
            vet.append(x)
            anterior = len(vet)-2
            if x == vet[anterior]:
                print("Essa letra é igual a anterior")

def main():
    verifica()
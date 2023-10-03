n = "486432132"

n1 = int(n)

nomesCentenas = [" ", "cento", "duzentos" , "trezentos", "quatrocentos"]
nomesDezenas = [" ", "dez" , "vinte", "trinta"]
for i in range(len(n)):
    if len(n) > 6:
        if len(n) == 9:
            print(nomesCentenas[n[i]], end = " e")
        elif len(n) == 8:
            print("dezenas de milhoes")
        else:
            print(nomesUnidades, end = " milhões")
    elif len(n) > 3:
        print("casa dos milhares")
    else:
        print("casa das centenas")
##O seu desafio é criar um programa que Basicamente o usuario tem que digitar um valor e o programa tem que printar um quadrado de asterísticos daquele tamanho...
# Ex.: input: 2
# output:
# **
# **

num = int(input("Insira um valor qualquer para que seja retornado um quadrado com asteríscos: "))
y = num

# while y!=0:
#     x = num
#     while x!=0:
#         print("*", end= "")
#         x-=1
#     print("")
#     y-=1

for a in range(0,num):
    for z in range (0,num):
        print("*", end="")
    print("")
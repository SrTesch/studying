def swap(list1, list2, int1, int2):
    aux=list1[int1]
    list1[int1]=list2[int2]
    list2[int2]=aux


def troca(list1,list2,int1,int2):
    for k in range(int1,int2):
        swap(list1, list2, k, k);

def Opera(list1, list2, list3):
    if(len(list3)%2!=0):
        print('tamanho da lista de pares Ã© impar')
    else:
        for k in range(0,len(lista3)-1,2):
            troca(list1, list2, list3[k], list3[k+1])
    print(list1)
    
list1 = [1, 0, -2]
list2 = [3,4,5]
list3 = [0,2]
Opera(list1, list2, list3)
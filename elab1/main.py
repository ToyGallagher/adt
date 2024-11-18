def mul_matrix(a,b):
    c = []
    for i in range(len(a)): 
        row=[]
        for j in range(len(b[i])):
            tempmul = 0
            for k in range(len(a[i])):
                tempmul+= a[i][k]*b[k][j]
            row.append(tempmul)
        c.append(row)
    return c
def print_matrix(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            print(f"{a[i][j]:^6}",end=' ')
        print()
        
A = [[1,2,3],[4,5,6],[7,8,9]]
B = [[22,13,23],[54,43,21],[23,78,71]]
print_matrix(mul_matrix(A,B))
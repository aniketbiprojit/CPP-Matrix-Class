from random import random,randint,seed
seed(0)

# dim=1,n=100
def create(dim,n,filename):
    with open(filename,'w') as f:
        f.write(str(n)+'\n')
        f.write(str(dim)+'\n')
        for i in range(3):
            d=[str(randint(1,100))+' ' for i in range(n*dim)] #Values in range [1,(n*d)^2]
            f.writelines(d)
            f.write('\n')

# Generate three matrices of dim dimension
# and n size with dim b/w 1 and 2
for nums in range(2,6):
    for dims in range(1,3):
        n=10**nums
        create(dims,n,f'matrix_dim_{dims}_len_{nums}.txt')

create(3,100,'matrix_dim_3_len_2.txt')
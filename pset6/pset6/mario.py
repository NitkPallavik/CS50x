import cs50

while True:
    print("Height: ", end="")
    n = cs50.get_int()+1
    if n > 0 and  n < 23:
        break
i=1
s=n-1
for i  in range(i,n,+1):
    print(" "* (s-i),end="")
    print("#" * (i+1),end="")
    print()
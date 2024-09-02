def balance(i):
    ## return the balance after i months
    if i == 0: 
        return 2000
    else:
        return (1.015)*balance(i-1) + 500
    
def month_range(n):
    res = [f"{i:02d} - $ {balance(i):.02f}" for i in range(n)]
    return "\n".join(res)

print(month_range(10))
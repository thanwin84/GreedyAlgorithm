class Pair:
    def __init__(self, price,stock):
        self.price = price
        self.stock = stock
def maxStock(arr, balance):
    totalStock = 0
    v = []
    for i in range(len(arr)):
        v.append(Pair(arr[i], i + 1))
    v = sorted(v, key=lambda p: p.price)
    for i in range(len(arr)):
        if v[i].stock * v[i].price <= balance:
            totalStock += v[i].stock
            balance -= v[i].stock * v[i].price
        else:
            totalStock += balance//v[i].price
            balance -= (balance//v[i].price) * v[i].price
    return totalStock
arr = [10, 7, 19]
print(maxStock(arr, 45))

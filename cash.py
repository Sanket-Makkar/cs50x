while True:
    x = float(input("Change: "))
    if (x > -1):
        break
y = round(x * 100)
coincount = 0
while (y >= 25):
    y -= 25
    coincount += 1
while (y >= 10):
    y -= 10
    coincount += 1
while (y >= 5):
    y -= 5
    coincount += 1
while (y >= 1):
    y -= 1
    coincount += 1
print(f"{coincount}")
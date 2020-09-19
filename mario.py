from cs50 import get_int
while True:
    x = get_int("Height: ")
    if (x > 0 and x < 9):
        break
if (x > 8 or x < 0):
    exit(1)
y = x + 1
for i in range(x):
    u = x - i - 1
    j = i + 1
    print(" " * u, end="")
    print("#" * j)
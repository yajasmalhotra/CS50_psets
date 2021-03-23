import cs50
import math

while True:
    c = cs50.get_float("Change Owed: ")
    if c >= 0:
        break

c = math.floor(c * 100)
n = 0

while c > 0:
    if c >= 25:
        c = c - 25
        n += 1

    elif c < 25 and c >= 10:
        c = c - 10
        n += 1

    elif c < 10 and c >= 5:
        c = c - 5
        n += 1

    elif c < 5 and c >= 1:
        c = c - 1
        n += 1

print(n)

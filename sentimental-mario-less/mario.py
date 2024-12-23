from cs50 import get_int


def print_space(x):
    for i in range(x):
        print(" ", end="")


def print_hash(y):
    for i in range(y):
        print("#", end="")


while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    print_space(n-1-i)
    print_hash(i+1)
    print()

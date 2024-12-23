from cs50 import get_float


def get_positive_float(prompt):
    while True:
        try:
            value = float(input(prompt))
            if value > 0:
                return value
        except ValueError:
            pass


def main():

    money = get_positive_float("Change: ") * 100

    count_25 = money // 25
    money %= 25

    count_10 = money // 10
    money %= 10

    count_5 = money // 5
    money %= 5

    count_1 = money // 1
    money %= 1

    print(int(count_25 + count_10 + count_5 + count_1))


if __name__ == "__main__":
    main()

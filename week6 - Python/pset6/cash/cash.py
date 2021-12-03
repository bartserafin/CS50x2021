from cs50 import get_float


def main():
    i = get_change()
    j = find_coins(i)
    print(j)


def get_change():
    while True:
        x = get_float("Change owed: ")
        if x > 0:
            break
    return x


def find_coins(change_owed):
    # change dollars to cents
    change = change_owed * 100
    change_left = change
    count_coins = 0
    cash = 0
    count_all_coins = 0
    coins_list = [25, 10, 5, 1]

    while cash < change:
        for coin in range(len(coins_list)):
            while change_left >= coins_list[coin]:
                count_coins = change_left // coins_list[coin]
                cash += count_coins * coins_list[coin]
                count_all_coins += int(count_coins)

                change_left = change - cash

    return count_all_coins


if __name__ == "__main__":
    main()

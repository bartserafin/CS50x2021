
def main():
    i = get_number()
    if valid_number(i):
        which_card(i)


def get_number():
    while True:
        x = input("Number: ")
        if 12 < len(x) < 17:
            break
        elif len(x) < 12:
            print("INVALID\n")
            break
    return x


def valid_number(number):
    # multiply every other digit by 2 starting with second to last digit
    number = number[::-1]
    list_multiplied = []

    for el in range(1, len(number), 2):
        list_multiplied.append(int(number[el]) * 2)

    # add those product's digits together
    added_products = 0

    for el in list_multiplied:
        if int(el) >= 10:
            x = int(el) % 10 + 1
            added_products += x
        else:
            added_products += int(el)

    # add the sum to the sum of the digits that were not multiplied by 2
    for el in range(0, len(number), 2):
        added_products += int(number[el])

    # if the total's last digit is 0, number is valid
    if added_products % 10 == 0:
        return True
    else:
        return False


def which_card(number):
    # AMEX (American Express)
    # 15 digits, starts with 34 or 37
    two_digits = number[0] + number[1]
    if len(number) == 15 and (two_digits == "34" or two_digits == "37"):
        print("AMEX\n")

    # MasterCard
    # 16 digits, start with, 51, 52, 53, 54, 55
    elif len(number) == 16 and (two_digits == "51" or two_digits == "52" or
                                two_digits == "53" or two_digits == "54" or two_digits == "55"):
        print("MASTERCARD\n")

    # Visa
    # 13 or 16 digits start with 4
    elif (len(number) == 13 or len(number) == 16) and number[0] == "4":
        print("VISA\n")

    else:
        print("INVALID\n")


if __name__ == "__main__":
    main()
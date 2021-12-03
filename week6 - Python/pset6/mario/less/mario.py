from cs50 import get_int


def main():
    height = get_height()
    print_pyramid(height)


# get height from user
def get_height():
    while True:
        height = get_int("Height: ")
        if height > 0 and height <= 8:
            break
    return height


# print pyramid
def print_pyramid(height):
    i = 0
    for el in range(height):
        i += 1
        print(" " * (height - i) + ("#" * i))


if __name__ == "__main__":
    main()
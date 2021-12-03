# DNA

import sys
import csv


def main():
    
    # Handle command line arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    x = max_repeats()
    y = compare(x)


def max_repeats():
    
    # Open database.csv in read as dict
    database_file = sys.argv[1]
    sequence_file = sys.argv[2]
    with open(database_file, "r") as csv_file:
        reader = csv.DictReader(csv_file)
        dict_list = list(reader)
        # print(dict_list)

    # Open sequences in read as list
    with open(sequence_file, "r") as txt_file:
        sequence = txt_file.read()
        # print(sequence)

# For each STR, compute longest run of consecutive repeats in sequence

    # store counts in a list
    max_counts = []
    for i in range(1, len(reader.fieldnames)):
        # list all possible STRs
        STR = reader.fieldnames[i]
        # print(STR)
        max_counts.append(0)
        # print(max_counts)

    # Loop through sequence to find matching STR
        for j in range(len(sequence)):
            # equals counts to zero so to find maximum number of repeats
            STR_count = 0
            # If match, count how many times it repeats at current position
            if sequence[j:(j + len(STR))] == STR:
                k = 0
                while sequence[(j + k):(j + k + len(STR))] == STR:
                    STR_count += 1
                    k += len(STR)
                # If new maximum of repeats, update max_counts
                if STR_count > max_counts[i - 1]:
                    max_counts[i - 1] = STR_count

    csv_file.close()
    txt_file.close()
    return max_counts


def compare(max_counts):
    
    # Open database.csv in read as dict
    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    with open(database_file, "r") as csv_file:
        reader = csv.DictReader(csv_file)
        dict_list = list(reader)
        # print(dict_list)

    # Open sequences in read as list
    with open(sequence_file, "r") as txt_file:
        sequence = txt_file.read()
        # print(sequence)

 # Compare against data
    for i in range(len(dict_list)):
        matches = 0
        for j in range(1, len(reader.fieldnames)):
            if int(max_counts[j - 1]) == int(dict_list[i][reader.fieldnames[j]]):
                matches += 1
            if matches == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                sys.exit(0)
    print("No match")


if __name__ == '__main__':
    main()
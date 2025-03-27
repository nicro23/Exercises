import csv
import sys


def main():

    # TODO: Check for command-line usage (done)
    if len(sys.argv) != 3:
        print("you no know math?")
        exit()
    # TODO: Read database file into a variable
    database = list(open(sys.argv[1], "r"))
    print(database)
    keys = list(database[0].split(','))
    print(keys)
    di = []
    for i in range(1,(len(database))):
        placeholder = database[i].split(',')
        di.append({keys[0]: placeholder[0], keys[1]: placeholder[1], keys[2]: placeholder[2]})
    print(di)
    # di = [{test[0]: "ahmed", test[1]: 3, test[2]: 4},
    #       {test[0]: "yousof", test[1]: 4, test[2]: 2}]
    # for i in range(2):
    #     if di[i]["name"] == "ahmed":
    #        print(di[i][test[1]])
    # for words in database

    # for words in database:
    #     list(words.split(','))
    #     print(words.split(','), end='\n')
    # TODO: Read DNA sequence file into a variable
    txt = open(sys.argv[2], "r")
    # TODO: Find longest match of each STR in DNA sequence
    count = longest_match(txt,)
    # TODO: Check database for matching profiles

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

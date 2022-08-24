import csv
from sys import argv


def main():

    if len(argv) < 3:
        print("Usage: python3 dna.py *.csv *.txt")
        exit()

    database = []

    with open (argv[1], "r") as file:
        reader = csv.DictReader(file)

        for name in reader:
            database.append(name)
    
    with open(argv[2], "r") as file:
        dna_sequence = file.read()

    longest_run = {}
    subsequences = list(database[0].keys())[1:]

    for subsequence in subsequences:
        longest_run[subsequence] = longest_match(dna_sequence, subsequence)

    for profile in database:
        match_counter = 0
        
        for subsequence in subsequences:

            if int(profile[subsequence]) == longest_run[subsequence]:
                match_counter += 1

        if match_counter == len(subsequences):
            print(profile["name"])

            return

    print("No match")

    return


def longest_match(sequence, subsequence):

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        
        longest_run = max(longest_run, count)

    return longest_run

main()

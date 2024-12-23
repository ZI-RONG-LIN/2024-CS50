import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    # Read database file into a variable
    database = read_database(database_file)

    # Read DNA sequence file into a variable
    sequence = read_sequence(sequence_file)

    # Find longest match of each STR in DNA sequence
    strs = list(database[0].keys())[1:]  # Extract STR names (skip 'name' column)
    sequence_strs = {s: longest_match(sequence, s) for s in strs}

    # Check database for matching profiles
    match = find_match(database, sequence_strs)
    print(match)

def read_database(file_path):
    """Reads the DNA database and returns a list of dictionaries representing each person."""
    with open(file_path, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        database = [row for row in reader]
    return database

def read_sequence(file_path):
    """Reads the sequence file and returns the DNA sequence as a string."""
    with open(file_path) as file:
        sequence = file.read().strip()
    return sequence

def find_match(database, sequence_strs):
    """Finds the person whose DNA profile matches the sequence."""
    for person in database:
        name = person['name']
        match = True
        for s in sequence_strs:
            if int(person[s]) != sequence_strs[s]:
                match = False
                break
        if match:
            return name
    return "No match"

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

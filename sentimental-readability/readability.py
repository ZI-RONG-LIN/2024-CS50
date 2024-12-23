from cs50 import get_string


def count_letter(text):
    letter = 0
    for char in text:
        if char.isalpha():
            letter += 1
    return letter


def count_space(text):
    space = 0
    for char in text:
        if char.isspace():
            space += 1
    return space


def count_sentence(text):
    sentence = 0
    for char in text:
        if char in '.!?':
            sentence += 1
    return sentence


def main():
    input_text = get_string("Text: ")
    letter = count_letter(input_text)
    words = count_space(input_text) + 1
    sentence = count_sentence(input_text)
    L = (letter / words) * 100
    S = (sentence / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()

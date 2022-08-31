def main():
    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    average_letters = (float(letters) / float(words)) * 100
    average_sentences = (float(sentences) / float(words)) * 100
    grade = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print("Grade: " + str(grade))

def count_letters(text: str) -> int:

    return len([letter for letter in text if letter.isalpha()])

def count_words(text: str) -> int:

    return len(text.split())

def count_sentences(text: str) -> int:

    text = text.replace("!", ".")
    text = text.replace("?", ".")
    
    return len(text.split(". "))

if __name__ == "__main__":
    main()

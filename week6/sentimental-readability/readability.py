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

def count_letters(text):
    number_of_letters = 0

    for i in range(len(text)):
        if text[i].isalpha():
            number_of_letters += 1
    
    return number_of_letters

def count_words(text):
    number_of_words = 1

    for i in range(len(text)):
        if text[i] == ' ':
            number_of_words += 1
    
    return number_of_words

def count_sentences(text):
    number_of_sentences = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            number_of_sentences += 1

    return  number_of_sentences

main()
def random_word_count(text:str) -> dict:                                                        # counter roznych slov 
    words = {}
    for word in text.lower().split():
        if word in words:
            words[word] += 1
        else:
            words[word] = 1

    return words



def vowel_counter(text:str) -> int:                                                             # counter samohlasok 
    vow = ["a","e","i","y","o","u"]
    vowcounter = 0
    for symbol in text:
        if symbol in vow:
            vowcounter += 1
    return vowcounter


        
def nospace(text:str) -> int:                                                                   # counter medzier
    space = text.count(" ")
    return space



def letter_counter(text:str) -> int:                                                            # counter pismen
    lett_count = 0
    for letter in text:
        if letter != " ":
            lett_count +=1
        else:
            lett_count += 0
    return lett_count



def sentence_counter(text: str) -> int:                                                         # counter viet
    sentences = 0
    for char in text:
        if char == ".":
            sentences += 1
    return sentences



def numcount(text:str) -> int:                                                                  # counter cisiel
    numcounter = 0
    for num in text:
        if num in "0123456789":
            numcounter += 1
    return numcounter



def count(text:str) -> int:                                                                     # counter slov
    return len(text.split())



def main() -> None:                                                 
    print("Hello, welcome to this program called text summary!")
    print("ENJOY!")

    while True:
        choice = input("Do you want to load text from file? (yes/no): ").lower()

        if choice == "yes":
            filename = input("Enter the filename: ")

            try:
                with open(filename, "r", encoding="utf-8") as sub:
                    text = sub.read()
                print("File was loaded")

            except FileNotFoundError:
                print("File not found, try again.")
                continue

        else:
            text = input("Type some text here: ")


        text = text.replace("\n", " ").replace("\t", " ")

        if not text.strip():
            print("Error, no input was entered. Try again please: ")
            continue
        break


    print(f"The count of characters in your text is: {len(text)}")                              # character count
    print(f"The count of letters in your text is: {letter_counter(text)}")                      # letter count
    print(f"The count of spacebars in your text is: {nospace(text)}")                           # spacebar count
    print(f"The count of words in your text is: {count(text)}")                                 # word count
    print(f"The count of vowels in your text is: {vowel_counter(text)}")                        # vowel count
    print(f"The count of numbers is: {numcount(text)}")                                         # number count  
    print(f"The count of sentences in your text is: {sentence_counter(text)}")                  # sentence counter
    print("Unique words:")                                                                      # unique word count
    unique_words = random_word_count(text)
    for word, cnt in unique_words.items():
        print(f"{word}: {cnt}")


if __name__ == '__main__':
    main()



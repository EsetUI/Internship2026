
import string


def clean_word(word: str) -> str:                                                                # cisti slovo  
    return word.strip(string.punctuation).lower()


def unique_word_count(text: str) -> dict:                                                        # counter roznych slov 
    words = {}
    for word in text.split():
        word = clean_word(word)
        if word == "":
            continue
        if word in words:
            words[word] += 1
        else:
            words[word] = 1

    return words


def vowel_counter(text: str) -> int:                                                             # counter samohlasok 
    vow = set("aeiouyAEIOUY")
    vowcounter = 0
    for symbol in text:
        if symbol in vow:
            vowcounter += 1
    return vowcounter

def nospace(text: str) -> int:                                                                   # counter medzier
    space = text.count(" ")
    return space

def letter_counter(text: str) -> int:                                                            # counter pismen
    lett_count = 0
    for letter in text:
        if letter not in string.whitespace:
            lett_count += 1
    return lett_count

def sentence_counter(text: str) -> int:                                                         # counter viet
    sentences = 0
    for char in text:
        if char == ".":
            sentences += 1
    return sentences

def numcount(text: str) -> int:                                                                  # counter cisiel
    numcounter = 0
    for num in text:
        if num in "0123456789":
            numcounter += 1
    return numcounter

def count(text: str) -> int:                                                                     # counter slov
    return len([clean_word(w) for w in text.split() if clean_word(w) != ""])



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


    print(f"The count of characters in your text is: {len(text)}")
    print(f"The count of letters in your text is: {letter_counter(text)}")
    print(f"The count of spacebars in your text is: {nospace(text)}")
    print(f"The count of words in your text is: {count(text)}")
    print(f"The count of vowels in your text is: {vowel_counter(text)}")
    print(f"The count of numbers is: {numcount(text)}")
    print(f"The count of sentences in your text is: {sentence_counter(text)}")
    print("Unique words:")
    
    unique_words = unique_word_count(text)
    for word, cnt in unique_words.items():
        print(f"{word}: {cnt}")

    magic_letter = input("Enter a letter to highlight in green: ")                                         # zafarbi piseno
    

    if magic_letter:                                    
        target = magic_letter[0]
        colored_text = ""
        
        for char in text:

            if char.lower() == target.lower():
                colored_text += f"\033[32m{char}\033[0m"
            else:
                colored_text += char
                
        print("Your highlighted text is:")
        print(colored_text)


if __name__ == '__main__':
    main()






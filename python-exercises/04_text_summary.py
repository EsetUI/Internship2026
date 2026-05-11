def count_words(text: str) -> int:
    return len(text.split())


def count_vowels(text: str) -> int:
    vowels = {"a", "e", "i", "o", "u"}
    return sum(1 for character in text.lower() if character in vowels)


def main() -> None:
    print("Text summary")
    text = input("Enter a sentence or short paragraph: ").strip()

    if not text:
        print("No text entered.")
        return

    print(f"Characters: {len(text)}")
    print(f"Words: {count_words(text)}")
    print(f"Vowels: {count_vowels(text)}")


if __name__ == "__main__":
    main()

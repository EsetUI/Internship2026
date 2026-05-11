from collections import Counter
import string


def normalize_words(text: str) -> list[str]:
    translation_table = str.maketrans("", "", string.punctuation)
    cleaned_text = text.lower().translate(translation_table)
    return [word for word in cleaned_text.split() if word]


def summarize_text(text: str) -> dict[str, object]:
    words = normalize_words(text)
    counts = Counter(words)

    return {
        "characters": len(text),
        "word_count": len(words),
        "unique_words": len(counts),
        "top_words": counts.most_common(3),
    }


def main() -> None:
    print("Word counter")
    text = input("Enter a sentence or short paragraph: ").strip()

    if not text:
        print("No text entered.")
        return

    summary = summarize_text(text)
    print(f"Characters: {summary['characters']}")
    print(f"Words: {summary['word_count']}")
    print(f"Unique words: {summary['unique_words']}")

    print("Most common words:")
    for word, count in summary["top_words"]:
        print(f"- {word}: {count}")


if __name__ == "__main__":
    main()

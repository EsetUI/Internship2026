def build_welcome_message(name: str) -> str:
    clean_name = name.strip().title() or "Student"
    return f"Hello, {clean_name}! Welcome to the internship."


def main() -> None:
    print("Internship welcome program")
    name = input("Enter your name: ").strip()
    favorite_topic = input("What do you want to practice most? ").strip()

    if not favorite_topic:
        favorite_topic = "Python and C++"

    print()
    print(build_welcome_message(name))
    print(f"Your focus for the internship is: {favorite_topic}.")
    print("Small steps, clean commits, and clear questions matter.")
    print("vela stastia")


if __name__ == "__main__":
    main()

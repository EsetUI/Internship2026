def print_menu() -> None:
    print()
    print("Mini-project menu")
    print("1. Run main feature")
    print("2. Show help")
    print("3. Exit")


def run_main_feature() -> None:
    print("Replace this function with the core logic of your project.")


def show_help() -> None:
    print("Describe what your project does and how a user should interact with it.")


def main() -> None:
    while True:
        print_menu()
        choice = input("Choose an option: ").strip()

        if choice == "1":
            run_main_feature()
        elif choice == "2":
            show_help()
        elif choice == "3":
            print("Goodbye.")
            break
        else:
            print("Unknown option. Try again.")


if __name__ == "__main__":
    main()

import argparse


def parse_numbers(text: str) -> list[float]:
    normalized = text.replace(";", ",")
    return [float(i.strip()) for i in normalized.split(",") if i.strip()]


def print_output(numbers: list[float]) -> None:
    if not numbers:
        print("No numbers provided.")
        return

    total = sum(numbers)

    print(f"Sum: {total}")
    print(f"Count: {len(numbers)}")
    print(f"\033[31mMin: {min(numbers)}\033[0m")
    print(f"\033[32mMax: {max(numbers)}\033[0m")
    print(f"Average: {total / len(numbers)}")

def main() -> None:
    parser = argparse.ArgumentParser(
        prog="MatusNumberStats",
        description="provides sum of numbers",
        epilog="Text at the bottom of help",
    )
    parser.add_argument("filename", nargs="?")
    args = parser.parse_args()

    print(args.filename)

    if args.filename:
        with open(args.filename, "r", encoding="utf-8") as file:
            num_list = parse_numbers(file.read())

        print_output(num_list)

    else:
        try:
            numnum = input("Numbers (separated by a coma (, ;)): ")
            numbe = parse_numbers(numnum)

            print_output(numbe)

        except ValueError:
            print("Sorry, wrong input try again!")


if __name__ == "__main__":
    main()
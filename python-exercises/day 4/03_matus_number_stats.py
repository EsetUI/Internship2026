


import argparse

def parse_numbers(text: str) -> list[float]:
    normalized = text.replace(";", ",")
    return [float(i.strip()) for i in normalized.split(",") if i.strip()]
    # return [float(i.strip()) for i in str.split(',;') if i.strip()]         nefunguje


def num_desc(numbers: list[float]) -> dict[str, float]:
    sumnum = sum(numbers)
    return {"sum": sumnum}


def main() -> None:
    parser = argparse.ArgumentParser(
        prog="MatusNumberStats",
        description="provides sum of numbers",
        epilog="Text at the bottom of help",
    )
    parser.add_argument("filename", nargs="?")
    args = parser.parse_args()

    print(args.filename)
    name = input("Name: ")
    print(f"Hello {name}, welcome!")
    print("This is a program called number stats")
    print("ENJOY")

    if args.filename:
        with open(args.filename, "r") as sub:
            numnum = sub.read().replace(";", ",").split(",")
        

        num_list = [float(line.strip()) for line in numnum if line.strip()]
        numholder = sum(num_list)

        print(f"Sum of the numbers used in your text file is: {numholder}")
        print(f"The number count in your file is: {len(num_list)}")
        print(f"\033[31mThe min number in your file is: {min(num_list)}\033[0m")
        print(f"\033[32The max number in your file is: {max(num_list)}\033[0m")
        print(f"The average number in your file is: {numholder / len(num_list)}")

    else:
        try:
            numnum = input("Numbers (separated by a coma (, ;)): ")
            numbe = parse_numbers(numnum)
            endstat = num_desc(numbe)
            
            print(f"Sum of the numbers used is: {endstat['sum']}")
            print(f"The number count is: {len(numbe)}")
            print(f"\033[31mThe min number is: {min(numbe)}\033[0m")
            print(f"\033[32mThe max number is: {max(numbe)}\033[0m")
            print(f"The average number is: {endstat['sum'] / len(numbe)}")
            
        except ValueError:
            print("Sorry, wrong input try again!")


if __name__ == "__main__":
    main()



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
    print("This is a program called number stats")
    print("ENJOY")

    if args.filename:
        with open(args.filename, "r") as sub:
            num_list = parse_numbers(sub.read())
        
        numholder = sum(num_list)

        print(f"Sum: {numholder}")
        print(f"Count: {len(num_list)}")
        print(f"\033[31mMin: {min(num_list)}\033[0m")
        print(f"\033[32mMax: {max(num_list)}\033[0m")
        print(f"Average: {numholder / len(num_list)}")

    else:
        try:
            numnum = input("Numbers (separated by a coma (, ;)): ")
            numbe = parse_numbers(numnum)
            endstat = num_desc(numbe)
            
            print(f"Sum: {endstat['sum']}")
            print(f"Count: {len(numbe)}")
            print(f"\033[31mMin: {min(numbe)}\033[0m")
            print(f"\033[32mMax: {max(numbe)}\033[0m")
            print(f"Average: {endstat['sum'] / len(numbe)}")
            
        except ValueError:
            print("Sorry, wrong input try again!")


if __name__ == "__main__":
    main()
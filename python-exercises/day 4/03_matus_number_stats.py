
def parse_numbers(text: str)-> list[float]:
    normalized = text.replace(";", ",")
    return [float(i.strip()) for i in normalized.split(",") if i.strip()]
    # return [float(i.strip()) for i in str.split(',;') if i.strip()]         nefunguje


def num_desc(numbers: list[float]) -> dict[str, float]:
    sumnum = sum(numbers)
    return {"sum": sumnum}



def main() -> None:
    name = input("Name: ")
    print(f"Hello {name}, welcome!")
    print("This is a program called number stats")

    numberss = input("Numbers (separated by a coma (, ;)): ")

    numbe = parse_numbers(numberss)
    endstat = num_desc(numbe)

    print(f"Sum of the numbers used is: {endstat["sum"]}")


if __name__ == "__main__":
    main()
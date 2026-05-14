name = input("Name: ")
print(f"Hello {name}!")
print("This is a program called number stats welcome")



def parse_numbers()-> list[float]:
    zoz = []

    numbers = input("Numbers (separated by a coma (, ;)): ")

    for i in numbers.split(","):
        zoz.append(float(i.strip()))


    return zoz


def describe_numbers(numbers: list[float]) -> dict[str, float]:
    sumnum = sum(numbers)

    print(f"Sum of the numbers is: {sumnum}")

nums = parse_numbers()
describe_numbers(nums)
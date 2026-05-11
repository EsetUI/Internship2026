def celsius_to_fahrenheit(celsius: float) -> float:
    return celsius * 9 / 5 + 32


def fahrenheit_to_celsius(fahrenheit: float) -> float:
    return (fahrenheit - 32) * 5 / 9


def parse_unit(text: str) -> str:
    unit = text.strip().upper()
    if unit not in {"C", "F"}:
        raise ValueError("Unit must be C or F.")
    return unit


def main() -> None:
    print("Temperature converter")

    try:
        value = float(input("Enter the temperature value: ").strip())
        unit = parse_unit(input("Is the value in C or F? ").strip())
    except ValueError as error:
        print(f"Invalid input: {error}")
        return

    if unit == "C":
        converted = celsius_to_fahrenheit(value)
        print(f"{value:.2f} C is {converted:.2f} F")
    else:
        converted = fahrenheit_to_celsius(value)
        print(f"{value:.2f} F is {converted:.2f} C")


if __name__ == "__main__":
    main()

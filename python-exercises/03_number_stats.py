def parse_numbers(text: str) -> list[float]:
    normalized = text.replace(";", ",")
    parts = [part.strip() for part in normalized.split(",") if part.strip()]

    if not parts:
        raise ValueError("Enter at least one number.")

    return [float(part) for part in parts]


def describe_numbers(numbers: list[float]) -> dict[str, float]:
    total = sum(numbers)
    return {
        "count": float(len(numbers)),
        "minimum": min(numbers),
        "maximum": max(numbers),
        "sum": total,
        "average": total / len(numbers),
    }


def main() -> None:
    print("Number statistics")
    raw_input_value = input("Enter numbers separated by commas: ").strip()

    try:
        numbers = parse_numbers(raw_input_value)
    except ValueError as error:
        print(f"Invalid input: {error}")
        return

    stats = describe_numbers(numbers)
    print(f"Count: {int(stats['count'])}")
    print(f"Minimum: {stats['minimum']:.2f}")
    print(f"Maximum: {stats['maximum']:.2f}")
    print(f"Sum: {stats['sum']:.2f}")
    print(f"Average: {stats['average']:.2f}")


if __name__ == "__main__":
    main()


number = int(input("What language do you want to use this converter in? (1 for english, 2 for slovak): "))

if number == 1:
    print("English was chosen")
    temp = float(input("Temperature is (°C): "))
    fahr = (temp * 1.8) + 32

    print(f"The temperature converted to F is {fahr}")

elif number == 2:
    print("Vybraná bola slovenčina")
    temp = float(input("Zadaj teplotu (°C): "))
    fahr = (temp * 1.8) + 32

    print(f"Teplota vo Fahrenheitoch je {fahr}")

else:
    print("Sorry, try again (1 or 2)")
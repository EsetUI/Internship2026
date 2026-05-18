
languages = {
    "sk": {
        'choice': "Bola vybraná slovenčina",

        'from_unit':
        "Zvoľ jednotku Z KTOREJ chceš konvertovať:\n"
        "C - Celsius\n"
        "K - Kelvin\n"
        "F - Fahrenheit\n",

        'to_unit':
        "Zvoľ jednotku NA KTORÚ chceš konvertovať:\n"
        "C - Celsius\n"
        "K - Kelvin\n"
        "F - Fahrenheit\n",

        'inputc': "Zadaj teplotu (°C): ",
        'inputf': "Zadaj teplotu (F): ",
        'inputk': "Zadaj teplotu (K): ",

        'x_to_f': "Teplota premenená na Fahrenheity je {} F",
        'x_to_c': "Teplota premenená na Celsius je {} °C",
        'x_to_k': "Teplota premenená na Kelviny je {} K",

        'error': "Prepáč, skús to znova",
        'errorsame': "Prepáč, nemôžeš konvertovať do rovnakej jednotky",
        'vluerr': "Prepáč, zadaj číslo"
    },

    "en": {
        'choice': "English was chosen",

        'from_unit':
        "Choose the unit you want to convert FROM:\n"
        "C - Celsius\n"
        "K - Kelvin\n"
        "F - Fahrenheit\n",

        'to_unit':
        "Choose the unit you want to convert TO:\n"
        "C - Celsius\n"
        "K - Kelvin\n"
        "F - Fahrenheit\n",

        'inputc': "Enter temperature (°C): ",
        'inputf': "Enter temperature (F): ",
        'inputk': "Enter temperature (K): ",

        'x_to_f': "The temperature converted to F is {} F",
        'x_to_c': "The temperature converted to °C is {} °C",
        'x_to_k': "The temperature converted to K is {} K",

        'error': "Sorry, try again",
        'errorsame': "Sorry, you cannot convert to the same unit",
        'vluerr': "Sorry, enter a number"
    }
}


while True:
    lang = input("Choose a language (sk/en): ").lower()

    try:
        text = languages[lang]
        break

    except KeyError:
        print("Unsupported language")


print("---------------------------------------------------")
print(text['choice'])
print("---------------------------------------------------")


while True:
    from_unit = input(text['from_unit']).upper()

    if from_unit in ["C", "K", "F"]:
        break

    print(text['error'])

print("---------------------------------------------------")

while True:
    to_unit = input(text['to_unit']).upper()

    if to_unit in ["C", "K", "F"]:
        break

    print(text['error'])

print("---------------------------------------------------")

def f_to_c(fahrenheit):
    return (fahrenheit - 32) / (9 / 5)

def f_to_k(fahrenheit):
    return (5 / 9) * (fahrenheit - 32) + 273.15

def k_to_f(kelvin):
    return (9 / 5) * (kelvin - 273.15) + 32

def k_to_c(kelvin):
    return kelvin - 273.15

def c_to_f(celsius):
    return celsius * (9 / 5) + 32

def c_to_k(celsius):
    return celsius + 273.15

def convert_temperature(input_text, output_text, convert_func):

    while True:

        value = input(input_text)

        try:
            number = float(value)
            result = convert_func(number)
            print("---------------------------------------------------")
            print(output_text.format(result))
            break

        except ValueError:
            print(text['vluerr'])


if from_unit == "C" and to_unit == "K":
    convert_temperature(
        text['inputc'],
        text['x_to_k'],
        c_to_k
    )

elif from_unit == "C" and to_unit == "F":
    convert_temperature(
        text['inputc'],
        text['x_to_f'],
        c_to_f
    )

elif from_unit == "K" and to_unit == "C":
    convert_temperature(
        text['inputk'],
        text['x_to_c'],
        k_to_c
    )

elif from_unit == "K" and to_unit == "F":
    convert_temperature(
        text['inputk'],
        text['x_to_f'],
        k_to_f
    )

elif from_unit == "F" and to_unit == "C":
    convert_temperature(
        text['inputf'],
        text['x_to_c'],
        f_to_c
    )

elif from_unit == "F" and to_unit == "K":
    convert_temperature(
        text['inputf'],
        text['x_to_k'],
        f_to_k
    )

else:
    print(text['errorsame'])




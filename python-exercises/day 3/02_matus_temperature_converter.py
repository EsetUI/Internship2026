languages = {
    "sk" : {
        'choice': "Bola vybraná slovenčina",
        'conversion': "Chceš premeniť jednotky ZO stupňov Celzia na stupne fahrenheit (1 (f na c), 2 (f na k), 3 (k na f), 4 (k na c), 5 (c na f), 6 (c na k): ",
        'inputc': "Zadaj teplou (°C): ",
        'inputf': "Zadaj teplotu (F): ",
        'x_to_f': "Teplota premenená na fahrenheity je {} F",
        'x_to_c': "Teplota premenená na stupne Celzia je {} °C",
        'x_to_k': "Teplota zmenená na kelviny je {} K",
        'error': "Prepáč, skús to znova (1 - 6)",
        'vluerr': "Prepáč, vyskytla sa chyba, skús to znova"

    },

    "en" : {
        'choice': "English was chosen",
        'conversion': "Do you want to convert FROM celsius or fahrenheit (1 (f to c), 2 (f to k), 3 (k to f), 4 (k to c), 5 (c to f), 6 (c to k): ",
        'inputc': "The temperature is (°C): ",
        'inputf': "The temperature is (F): ",
        'x_to_f': "The temperature converted to F is {} F",
        'x_to_c': "The temperature converted to °C is {} °C",
        'x_to_k': "The temperature converted to K is {} K",
        'error': "Sorry, try again (1 - 6)",
        'vluerr': "Sorry, an error occured, try again"

    }
}






while True:
    lang = input(f"What language do you want to use this converter in? (sk or en): ")
    try:
        text = languages[lang]
        break
    except KeyError:
        print("Unsupported language, try again please")






print("---------------------------------------------------")

print(text['choice'])

print("---------------------------------------------------")  




while True:
    choose = input(text['conversion'])
    if choose in ["1","2","3","4","5","6"]:
        break
    else:
        print(text['error'])




def f_to_c(fahrenheit):
    return (fahrenheit - 32) /(9/5)


def f_to_k(fahrenheit):
    return (5/9)*(fahrenheit -32) +273.15

def k_to_f(kelvin):
    return (9/5)*(kelvin-273.15) + 32

def k_to_c(kelvin):
    return kelvin - 273.15

def c_to_f(celsius):
    return celsius * (9/5) + 32

def c_to_k(celsius):
    return celsius + 273.15





print("---------------------------------------------------")

if choose == "1":
    while True: 
        fahrenheit = input(text['inputc'])
        try:
            inpt = float(fahrenheit)
            print("---------------------------------------------------")
            celsius = f_to_c(inpt)
            print(text['x_to_c'].format(celsius))
            break
        except ValueError:
            print(text['vluerr'])





elif choose == "2":
    while True:
        fahrenheit = input(text['inputf'])
        try:
            inpt = float(fahrenheit)
            print("---------------------------------------------------")
            kelvin = f_to_k(inpt)
            print(text['x_to_c'].format(kelvin))
            break
        except ValueError:
            print(text['vluerr'])







elif choose == "3":
    while True: 
        kelvin = input(text['inputc'])
        try:
            inpt = float(kelvin)
            print("---------------------------------------------------")
            fahrenheit = k_to_f(inpt)
            print(text['x_to_f'].format(fahrenheit))
            break
        except ValueError:
            print(text['vluerr'])





elif choose == "4":
    while True: 
        kelvin = input(text['inputc'])
        try:
            inpt = float(kelvin)
            print("---------------------------------------------------")
            celsius = k_to_c(inpt)
            print(text['x_to_c'].format(celsius))
            break
        except ValueError:
            print(text['vluerr'])






elif choose == "5":
    while True: 
        celsius = input(text['inputc'])
        try:
            inpt = float(celsius)
            print("---------------------------------------------------")
            fahrenheit = c_to_k(inpt)
            print(text['x_to_f'].format(fahrenheit))
            break
        except ValueError:
            print(text['vluerr'])






elif choose == "6":
    while True: 
        celsius = input(text['inputc'])
        try:
            inpt = float(celsius)
            print("---------------------------------------------------")
            kelvin = c_to_k(inpt)
            print(text['x_to_k'].format(kelvin))
            break
        except ValueError:
            print(text['vluerr'])




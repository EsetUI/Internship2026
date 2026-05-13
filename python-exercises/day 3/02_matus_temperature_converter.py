lang = input("What language do you want to use this converter in? (sk or en): ")



languages = {
    "sk" : {
        'choice': "Bola vybratá slovenčina",
        'conversion': "Chceš premeniť jednotky ZO stupňov Celzia na stupne fahrenheit (1 pre celsius, 2 pre fahrenheit): ",
        'inputc': "Zadaj teplou (°C): ",
        'inputf': "Zadaj teplotu (F): ",
        'c_to_f': "Teplota premenená do Fahrenheitov je ",
        'f_to_c': "Teplota premenená do stupňov Celzia je ",
        'error': "Prepáč, skús to znova (1 alebo 2)"
    },

    "en" : {
        'choice': "English was chosen",
        'conversion': "Do you want to convert FROM celsius or fahrenheit (1 for celsius, 2 for fahrenheit): ",
        'inputc': "The temperature is (°C): ",
        'inputf': "The temperature is (F): ",
        'c_to_f': "The temperature converted to F is ",
        'f_to_c': "The temperature converted to °C is ",
        'error': "Sorry, try again (1 or 2)"
    }
}



text = languages[lang]




print(text['choice'])






choose = input(text['conversion'])

if choose == "1":

    celsius = float(input(text['inputc']))
    fahrenheit = celsius * 1.8 + 32
    print(f"{text['c_to_f']}{fahrenheit}")


elif choose == "2":

    fahrenheit = float(input(text['inputf']))
    celsius = fahrenheit /1.8 - 32
    print(f"{text['f_to_c']}{celsius}")


else:
    print(text['error'])
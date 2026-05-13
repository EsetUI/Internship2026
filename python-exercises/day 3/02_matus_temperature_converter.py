lang = input(f"What language do you want to use this converter in? (sk or en): ")



languages = {
    "sk" : {
        'choice': "Bola vybraná slovenčina",
        'conversion': "Chceš premeniť jednotky ZO stupňov Celzia na stupne fahrenheit (1 pre celsius, 2 pre fahrenheit): ",
        'inputc': "Zadaj teplou (°C): ",
        'inputf': "Zadaj teplotu (F): ",
        'c_to_f': "Teplota premenená do Fahrenheitov je {} F",
        'f_to_c': "Teplota premenená do stupňov Celzia je {} °C",
        'error': "Prepáč, skús to znova (1 alebo 2)"
    },

    "en" : {
        'choice': "English was chosen",
        'conversion': "Do you want to convert FROM celsius or fahrenheit (1 for celsius, 2 for fahrenheit): ",
        'inputc': "The temperature is (°C): ",
        'inputf': "The temperature is (F): ",
        'c_to_f': "The temperature converted to F is {} F",
        'f_to_c': "The temperature converted to °C is {} °C",
        'error': "Sorry, try again (1 or 2)",
        'vluerr': "Sorry, an error occured, try again"
    }
}


text = languages[lang]


print(text['choice'])


print("---------------------------------------------------")



choose = input(text['conversion'])
print("---------------------------------------------------")

if choose == "1":

    celsius = float(input(text['inputc']))
    fahrenheit = celsius * 1.8 + 32
    print(text['c_to_f'].format(fahrenheit))

elif choose == "2":

    fahrenheit = float(input(text['inputf']))
    celsius = (fahrenheit-32) /1.8
    print(text['f_to_c'].format(celsius))


else:
     print(text['error'])
        






languages = {
    "sk" : {
        'choice': "Bola vybraná slovenčina",
        'conversion': "Chceš premeniť jednotky ZO stupňov Celzia na stupne fahrenheit (1 pre celsius, 2 pre fahrenheit): ",
        'inputc': "Zadaj teplou (°C): ",
        'inputf': "Zadaj teplotu (F): ",
        'c_to_f': "Teplota premenená do Fahrenheitov je {} F",
        'f_to_c': "Teplota premenená do stupňov Celzia je {} °C",
        'error': "Prepáč, skús to znova (1 alebo 2)",
        'vluerr': "Prepáč, vyskytla sa chyba, skús to znova"

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
    if choose == "1" or choose == "2":
        break
    else:
        print(text['error'])






print("---------------------------------------------------")

if choose == "1":
    while True: 
        celsius = input(text['inputc'])
        try:
            num2 = float(celsius)
            print("---------------------------------------------------")
            fahrenheit = num2 * 1.8 + 32
            print(text['c_to_f'].format(fahrenheit))
            break
        except ValueError:
            print(text['vluerr'])





elif choose == "2":
    while True:
        fahrenheit = input(text['inputf'])
        try:
            num1 = float(fahrenheit)
            print("---------------------------------------------------")
            celsius = (num1 - 32) / 1.8
            print(text['f_to_c'].format(celsius))
            break
        except ValueError:
            print(text['vluerr'])



# # # # # # # # # # # # # # # # # # # #
# # # # # # # # SKUSKA # # # # # # # # 
# # # # # # # TRY EXCEPT # # # # # # # 
# # # # # # # # # # # # # # # # # # # #


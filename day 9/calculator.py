

m_tokens = []
m_pos = 0



def add(a: int, b: int) -> float:
    return a + b

def subtract(a: int, b: int) -> int:
    return a - b

def multiply(a: int, b: int) -> int:
    return a * b

def divide(a: int, b: int) -> int:
    return a / b

def modulo(a: int, b: int) -> int:
    return a % b

def current():
    if m_pos < len(m_tokens):
        return m_tokens[m_pos]
    return None

def advance():
    global m_pos
    m_pos += 1

def consume(test):
    if current() == test:
        advance()
    else:
        raise ValueError(f"Expected {test}, got {current()}")
    

def split_token(formula:str) -> str:
    number = ""
    tokens = []

    for char in formula:
        if char in "+-*/%()":
            if number != "":
                tokens.append(int(number))
                number = ""
            tokens.append(char)
        else:
            number += char
    if number != "":
        tokens.append(int(number))

    return tokens

def parse_factor():
    if type(current()) == int:
        value = current()
        advance()
        return value
    
    if current() == "-":
        advance()
        return -parse_factor()
    
    if current() == "(":
        advance()
        value = parse_expression()
        consume(")")
        return value
    
    raise ValueError(f"Error")
        


def parse_term():
    value = parse_factor()

    while current() == "*" or current() == "/" or current() == "%":
        operator = current()
        advance()

        right = parse_factor()

        if operator == "*":
            value *= right

        elif operator == "/":
            value /= right

        else:
            value %= right

    return value
    


def parse_expression():
    value = parse_term()

    while current() == "+" or current() == "-":
        operator = current()
        advance()

        right = parse_term()

        if operator == "+":
            value += right
        else:
            value -= right

    return value






def main(): 
    global m_tokens
    global m_pos
    while True:
        # history = []
        # userinput = input("Please choose from calculator (enter) or history (?): ")
        # if userinput == "?":
        #     if not history:
        #         print(f"You do not have a calculations history")
        #     else:
        #         print(history)
        # elif userinput == "":
        formula = input("Please enter a mathematical formula: ")
        try:                
            m_tokens = split_token(formula)
            print(m_tokens)
            # history.append(m_tokens)
            res = parse_expression()
            print(f"The result is: {res}")

        except ZeroDivisionError:
            print("You cannot divide with a zero")
        except ValueError:
            print("Using strings is forbidden")

main()
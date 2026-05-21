# Token-Based Calculator Evaluator Algorithm

This document describes an algorithm for evaluating mathematical expressions using tokens and recursive descent parsing.

Example expression:

```text
5 * 4 - (2 + 3)
```

Expected result:

```text
15
```

---

## 1. Overview

The evaluator has two main phases:

```text
input string -> tokens -> parser -> result
```

First, the input string is converted into tokens.
Then, the parser evaluates those tokens according to operator precedence.

Supported operators:

```text
+
-
*
/
(
)
```

Supported values:

```text
integer numbers
decimal numbers
negative numbers
```

---

## 2. Tokenization

Tokenization converts the input string into a list of meaningful symbols.

Example input:

```text
5 * 4 - (2 + 3)
```

Tokens:

```text
NUMBER(5)
MULTIPLY
NUMBER(4)
MINUS
LEFT_PAREN
NUMBER(2)
PLUS
NUMBER(3)
RIGHT_PAREN
END
```

### Tokenization Algorithm

```text
function tokenize(input):
    tokens = []

    for each character in input:
        if character is whitespace:
            skip it

        else if character is digit:
            read the full number
            add NUMBER token

        else if character is '+':
            add PLUS token

        else if character is '-':
            add MINUS token

        else if character is '*':
            add MULTIPLY token

        else if character is '/':
            add DIVIDE token

        else if character is '(':
            add LEFT_PAREN token

        else if character is ')':
            add RIGHT_PAREN token

        else:
            error: invalid character

    add END token

    return tokens
```

---

## 3. Parser Grammar

The parser uses three levels of precedence.

```text
expression = term ((PLUS | MINUS) term)*
term       = factor ((MULTIPLY | DIVIDE) factor)*
factor     = NUMBER | MINUS factor | LEFT_PAREN expression RIGHT_PAREN
```

### Meaning

```text
expression handles + and -
term       handles * and /
factor     handles numbers, unary minus, and parentheses
```

This gives multiplication and division higher priority than addition and subtraction.

---

## 4. Parser State

The parser keeps:

```text
tokens
current position
current token
```

Useful helper operations:

```text
current()  -> returns the current token
advance()  -> moves to the next token
consume(t) -> checks that the current token is t, then advances
```

---

## 5. parseExpression

`parseExpression` handles addition and subtraction.

```text
function parseExpression():
    value = parseTerm()

    while current token is PLUS or MINUS:
        operator = current token
        advance()

        right = parseTerm()

        if operator is PLUS:
            value = value + right
        else:
            value = value - right

    return value
```

Example:

```text
2 + 3 - 1
```

Evaluation:

```text
2 + 3 = 5
5 - 1 = 4
```

---

## 6. parseTerm

`parseTerm` handles multiplication and division.

```text
function parseTerm():
    value = parseFactor()

    while current token is MULTIPLY or DIVIDE:
        operator = current token
        advance()

        right = parseFactor()

        if operator is MULTIPLY:
            value = value * right
        else:
            if right is 0:
                error: division by zero

            value = value / right

    return value
```

Example:

```text
5 * 4 / 2
```

Evaluation:

```text
5 * 4 = 20
20 / 2 = 10
```

---

## 7. parseFactor

`parseFactor` handles:

```text
numbers
negative numbers
parentheses
```

```text
function parseFactor():
    token = current token

    if token is NUMBER:
        advance()
        return token.value

    if token is MINUS:
        advance()
        return -parseFactor()

    if token is LEFT_PAREN:
        advance()

        value = parseExpression()

        if current token is not RIGHT_PAREN:
            error: missing closing parenthesis

        advance()
        return value

    error: expected number or parenthesis
```

Examples:

```text
5       -> 5
-5      -> -5
(2 + 3) -> 5
```

---

## 8. Final Solve Function

```text
function solve(tokens):
    position = 0

    result = parseExpression()

    if current token is not END:
        error: unexpected token

    return result
```

---

## 9. Full Evaluation Example

Expression:

```text
5 * 4 - (2 + 3)
```

Tokens:

```text
NUMBER(5)
MULTIPLY
NUMBER(4)
MINUS
LEFT_PAREN
NUMBER(2)
PLUS
NUMBER(3)
RIGHT_PAREN
END
```

Evaluation flow:

```text
parseExpression
    parseTerm
        parseFactor -> 5
        sees MULTIPLY
        parseFactor -> 4
        result = 5 * 4 = 20

    sees MINUS

    parseTerm
        parseFactor sees LEFT_PAREN
            parseExpression
                parseTerm
                    parseFactor -> 2

                sees PLUS

                parseTerm
                    parseFactor -> 3

                result = 2 + 3 = 5

    result = 20 - 5 = 15
```

Final result:

```text
15
```

---

## 10. Error Handling

The evaluator should detect these errors:

```text
invalid character
missing closing parenthesis
unexpected token
division by zero
expected number or parenthesis
unexpected token after expression
```

Examples:

```text
5 + * 3      -> unexpected token
(2 + 3       -> missing closing parenthesis
10 / 0       -> division by zero
2 + abc      -> invalid character
```

---

## 11. Key Idea

The parser structure controls operator precedence:

```text
parseExpression calls parseTerm
parseTerm calls parseFactor
parseFactor can call parseExpression again inside parentheses
```

Because `parseTerm` is evaluated before `parseExpression` continues with `+` or `-`, multiplication and division naturally happen before addition and subtraction.


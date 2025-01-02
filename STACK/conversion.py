#Conversion of infix_exp into postfix expression

def convert(infix_exp):
    tokens = list(infix_exp) 
    stack = [] 
    output = [] 
    operators = {
        "(": 0,
        "-": 1,
        "+": 2,
        "*": 3,
        "/": 4,
        "^": 5,
        "$": 6
    }
    for token in tokens:
        if token == "(":
            stack.append(token)
        elif token not in operators and token != ')': # token is an operand
            output.append(token)
        else:
            if len(stack) == 0: 
                stack.append(token) 
            elif token != ')':
                if operators[token] > operators[stack[-1]]: 
                    stack.append(token)
                else:
                    element = stack.pop()
                    stack.append(token)
                    output.append(element)
        if token == ')':

            while stack[-1] != "(":
                element = stack.pop()
                output.append(element)
            stack.pop()

    stack.reverse()

    return ''.join(output)+''.join(stack)


inp = input("Enter your expression: ")

output = convert(inp)
print(output)
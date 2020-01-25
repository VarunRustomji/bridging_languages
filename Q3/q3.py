import sys

def main():
    data = sys.stdin.read()
    output = []
    atom = ""
    operators = ["/","*","-","+"]
    for char in data:
        if char == "(":
            output.append(char)

        elif char == "/":
            output.append("/ ")
            term = atom_to_num(atom)
            atom = ""
            output.append(str(term) + " ")
        elif char == "*":
            output.append("* ")
            term = atom_to_num(atom)
            atom = ""
            output.append(str(term) + " ")
        elif char == "+":
            output.append("+ ")
            term = atom_to_num(atom)
            atom = ""
            output.append(str(term) + " ")
        elif char == "-":
            output.append("- ")
            term = atom_to_num(atom)
            atom = ""
            output.append(str(term) + " ")

        elif char == ")":
            term = atom_to_num(atom)
            atom = ""
            output.append(str(term) + " )")
        else:
            atom += char


    print("(display " + ''.join(output)+ " )")


def atom_to_num(atom):
    ans = float(atom)
    return ans


if __name__ == "__main__":
    main()



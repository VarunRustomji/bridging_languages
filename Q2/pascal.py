import sys

def main():
    data = sys.stdin.read()
    data[0].upper()
    ans = ''
    capflag = False
    for i, char in enumerate(data):
        if (char == '_' or char == '-'):
            capflag = True
        else:
            if capflag:
                ans += str(char).upper()
            else:
                ans += str(char)
            capflag = False

    print(ans[0].upper() + ans[1:])


if __name__ == '__main__':
    main()

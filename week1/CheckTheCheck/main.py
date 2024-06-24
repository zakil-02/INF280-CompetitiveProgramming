import sys

def main(*args):
    values = [int(x) for m in args[1::2] for x in m.split()]
    total = values.pop(-1)
    real_total = 0
    for i in range(0,len(values)-1, 2):
        real_total += values[i]*values[i+1]
    if real_total >= total:
        print("PAY")
    else:
        print("PROTEST")

    return 0

if __name__ == "__main__":
    # Read arguments from standard input (text file)
    lines = sys.stdin.readlines()

    main(*lines)

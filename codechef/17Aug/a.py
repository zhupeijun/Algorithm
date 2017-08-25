def solve ():
    n = int (raw_input())
    a = map (int, raw_input().split())

    m = (n + 1) / 2
    is_rainbow = True
    for i in range (0, m):
        if i == 0 and a[i] != 1:
            is_rainbow = False
            break

        if i == m - 1 and a[i] != 7:
            is_rainbow = False
            break

        if i > 0 and a[i] - a[i - 1] > 1:
            is_rainbow = False
            break

        if i > 0 and a[i] - a[i - 1] < 0:
            is_rainbow = False
            break

        if a[i] != a[n - 1 - i]:
            is_rainbow = False
            break

    print ("yes" if is_rainbow else "no")

def main():
    case_n = int (raw_input ())
    for case_i in range (0, case_n):
        solve ()

main ()


#!/usr/bin/env python3
def simpson(f) -> float:
    return (1/3) * (f[0] + 4 * f[1] + 2 * f[2] + 4 * f[3] + f[4])


def main():
    data = [1, 2, 3, 4, 5]
    print(simpson(data))

if __name__ == "__main__":
    main()

def simpson(f:list, refresh=1/400) -> float:
  return refresh/3 * sum([f[i] if i == 0 or i == len(f) - 1 else 4 * f[i] if i % 2 else 2 * f[i] for i in range(len(f))])

def main():
  print(simpson([float(number) for line in sys.stdin for number in line.split()]))

if __name__ == "__main__":
  main()


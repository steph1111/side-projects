import math
import numpy as np

def simpson(x_0:float, x_n:float, func, n:int=100) -> float:
  """  
  Find the definite integral using the simpson's rule
  Params:
    x_0: Lower limit of integration
    x_n: Upper limit of integration
    func: The integrand as a function of x
    n: Number of sub intervals. Defaults to `n` = 100
  Returns:
    The definite integral of func
  """
  # Cannot use the simpson's rule unless n is a even integer
  if n % 2:
    raise ValueError("n must be devisable by 2")
  h = (x_n - x_0) / n; #  Number of sub intervals
  result = func(x_0) + func(x_n) # First and last value
  # Simpson's rule
  for i, x_i in enumerate(np.arange(x_0 + h, x_n, h)):
    result += 2 * func(x_i) if not i % 2 else 4 * func(x_i)
  return h / 3 * result

def f(x:float) ->float:
  """
  Any math function, helper to simpson()
  """
  return (math.pow(x, 3) / 3.0) + math.sin(2*x)

def main():
  print(simpson(2, 3, f, 10))

if __name__ == "__main__":
  main()
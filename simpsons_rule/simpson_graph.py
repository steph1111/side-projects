# import math
import numpy as np
import matplotlib.pyplot as plt

def simpson(x_0:float, x_n:float, func, n:int=100, plot:bool=True) -> float:
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
  result = h / 3 * result
  if plot:
    plot_f(x_0, x_n, func, result)
  return result

def plot_f(x_0:float, x_n:float, func, result:float, n:int=100):
  """
  Plot the function in a window
  Need to have matplotlib installed
  """
  x = np.linspace(x_0, x_n, n)
  y = func(x)
  plt.plot(x, y, "-b", label="f(x)")
  plt.title(f"$\int^{x_0}_{x_n}f(x)dx={result:.5f}$", loc = 'left')
  plt.legend(loc="upper left")
  plt.fill_between(x, y, color="skyblue", alpha=0.5)
  plt.show()

def f(x:float) ->float:
  """
  Any math function, helper to simpson()
  """
  return np.sin(np.pi*x)+2

def main():
  print(simpson(0, 8, f, 1000))

if __name__ == "__main__":
  main()
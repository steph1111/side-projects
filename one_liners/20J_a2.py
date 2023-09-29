import re 
import sys 
import random

print("\n".join([" ".join(["".join(word[0] + "".join(random.sample(word[1:-2], len(word)-3)) + word[-2:] if bool(re.search('\w+\S*$', word)) and len(word) > 4 else word[0] + "".join(random.sample(word[1:-1], len(word)-2)) + word[-1] if not bool(re.search('\w+\S*$', word)) and len(word) > 3 else word) for word in line.split()]) for line in sys.stdin]))

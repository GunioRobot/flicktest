#!/usr/bin/python
import sys

def findzerosbetter(fact):
  zeros = 0
  j = 5
  for i in range(1, 20):   
    zeros+=(fact)/j
    j*=5
    if j > fact:
      break
    
  print zeros    
  
def main():
  
  l = []

  total = int(raw_input(""))


  for i in range(1, total+1):
    n = int(raw_input(""))
    l.append(n)  
  
  for i in range(1, total+1):
    findzerosbetter(l[i-1])
  
  sys.exit(0)
  
# get main caller
if __name__ == '__main__':
  main()

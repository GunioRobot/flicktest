#!/usr/bin/python

#Basic FizzBuzz code

import sys

def fileread(fname):
  f = open(fname, 'r')
  str = f.read()
  nmbr = int(str.strip())
  printhip(nmbr)
  
      
def printhip(loop):
  for i in range(1,loop+1):
    if i%3 == 0 and i%5 == 0:
      print "Hop"
    elif i%3 == 0:
      print "Hoppity"
    elif i%5 == 0:
      print "Hophop"
 
def main():
  if len(sys.argv) == 2:
    fname = sys.argv[1]
  else:
    sys.exit()
    
  fileread(fname)
  
     
# get main caller
if __name__ == '__main__':
  main()

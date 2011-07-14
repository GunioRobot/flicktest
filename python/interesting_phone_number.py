#!/usr/bin/python -tt

import sys
import re

def main():
  # Get the name from the command line, using 'World' as a fallback.
  if len(sys.argv) >= 2:
    number = sys.argv[1]
  else:
    print "BAD args"	  
    sys.exit(0)

  if len(number)!= 10:
    print "BAD args"	 
    sys.exit(0) 
  else:
    print number	    

  resnumber = [""]  

  x = 0
  while x < 10:
    l = len(number)	  
    if x < l-1 and number[x] == number[x+1]:
      if x+1 < l-1 and number[x+1] == number[x+2]:
        resnumber.append(number[x:x+3])
        x+=3
      else:
        resnumber.append(number[x:x+2])
        x+=2	    	    		      	       	    	  
    else:
      resnumber.append(number[x])	    
      x+=1
      
  nice = 0
  for y in resnumber:
    if len(y) == 3:
      nice+=2
    elif len(y) == 2:
      nice+=1
     
  print resnumber[1:]
  print nice 	      	    	  


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

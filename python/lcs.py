#!/usr/bin/python
import sys
def printlcs(grid, a, b):
  count = 0;

  for i in xrange(1,len(b)+1):
    for j in xrange(1,len(a)+1):
      if (grid[i][j] > count):
        print b[i-1]
        count+=1


def preparegrid(grid, a, b):
  
  for i in xrange(1,len(b)+1):
    for j in xrange(1,len(a)+1):
      #if both character matches	    
      if (b[i-1] == a[j-1]):
        #Make sure that you are not matching previously matched character	      
        #Add one to your left cell of your diagonally left above cell
        #Dont add anything to cell above you
        #Take max out of these three values
        value = max(grid[i-1][j] , max(grid[i][j-1], grid[i-1][j-1])+1)
        grid[i][j]= value
        #If you have just got new match, fill up entire row with that
        if value != grid[i-1][j]:
          for k in xrange(j+1, len(a)+1):
            grid[i][k]=grid[i][j]
          break  
      else:
        #Copy from left or above	      
        grid[i][j]=max(grid[i][j-1], grid[i][j-1])
         
  for i in xrange(1,len(b)+1):       
    print grid[i]
  
  printlcs(grid, a, b)
  

def main():
  a = "abbcddddddddddddddefghijj"
  b = "abbddfhhjjj"
  print a
  print b
  #prepare grid
  grid = []
  for i in xrange(len(b)+1):
    grid.append([])
    for j in xrange(len(a)+1):
      grid[i].append(0)
  
  preparegrid(grid, a, b)  
  
# get main caller
if __name__ == '__main__':
  main()

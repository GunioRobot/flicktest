#Rules for game of life:
#   1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
#   2. Any live cell with two or three live neighbours lives on to the next generation.
#   3. Any live cell with more than three live neighbours dies, as if by overcrowding.
#   4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

def readinput(a):
  f = open('gameoflife_input.txt', 'r')
  numlines = 0
  for line in f:
      a.append(line.split())

def verifyinput(a):
  for i in xrange(len(a)):
    if len(a[i]) == len(a):
      continue
    else:
      return 1
  return 0 

def countneighbour(i, j, a=[]):    
  neighbours = 0
  if i > 0 and a[i-1][j] == "1":
    neighbours+=1
  if j > 0 and a[i][j-1] == "1":
    neighbours+=1
  if i < len(a)-1 and a[i+1][j] == "1":
    neighbours+=1
  if j < len(a)-1 and a[i][j+1] == "1":
    neighbours+=1    
  
  return neighbours  

def changecell( i, j, value, b):
  #print b[i][j]
  b[i][j] = value
    
def gennextgrid(a=[]):  
  b = []
  b = [[] for i in range(0, len(a))]

  
  print b           
  for i in range(0, len(a)):
    for j in range(0, len(a[i])):  
      neighbours = countneighbour(i, j, a)
      if a[i][j] == "1":
        if neighbours > 3:
          print "n1 " +`neighbours`
          print i 
          print j
          changecell(i, j, "0",b)
        elif neighbours > 1:  
          print "n2 " +`neighbours`
          print i 
          print j
          changecell(i, j, "1",b)
        else:
          print "n3 " +`neighbours`
          print i 
          print j
          countneighbour(i, j, a)
          changecell(i, j, "0",b )
      else:
        if neighbours == 3:
          print "n4 " +`neighbours`
          print i 
          print j
          changecell(i, j, "1",b)
          
  print b
            
            
def main():   
  a = []
  readinput(a)
  if (verifyinput(a)):
    exit(0)
    
  gennextgrid(a)  
  
  #print a  
  


  
  
  
  

             
# get main caller
if __name__ == '__main__':
  main()

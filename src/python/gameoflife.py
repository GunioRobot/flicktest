#Rules for game of life:
#   1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
#   2. Any live cell with two or three live neighbours lives on to the next generation.
#   3. Any live cell with more than three live neighbours dies, as if by overcrowding.
#   4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


def readinput(a):
  f = open('gameoflife_input.txt', 'r')
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

def printgrid(a):
  for i in range(0, len(a)):
    print a[i]
  print "\n"  

def calchash(a):
  hash = ""
  for i in range(0, len(a)):
    for j in range (0, len(a)):
      hash+=a[i][j]
  return hash    
            
def gennextgrid(a, iter, gridhash):
  if (iter == 0):
    return
  
  print iter
  
  gridhash[calchash(a)] = iter   
  b = []
  readinput(b)
       
  for i in range(0, len(a)):
    for j in range(0, len(a[i])):  
      neighbours = countneighbour(i, j, a)
      if a[i][j] == "1":
        if neighbours > 3:
          changecell(i, j, "0",b)
        elif neighbours > 1:  
          changecell(i, j, "1",b)
        else:
          changecell(i, j, "0",b )
      else:
        if neighbours == 3:
          changecell(i, j, "1",b)
        else:
          changecell(i, j, "0",b)
                
  printgrid(b)
  iter-=1
  if calchash(b) not in gridhash:
    gennextgrid(b, iter, gridhash)
  else:
    print gridhash[calchash(b)]  
            
            
def main():   
  a = []
  iter = 50
  gridhash = {}
  readinput(a)
  if (verifyinput(a)):
    exit(0)
  printgrid(a)  

  gennextgrid(a, iter, gridhash)  
  
  #print a  
             
# get main caller
if __name__ == '__main__':
  main()

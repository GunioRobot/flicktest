import sys
import random

# Define a main() function that prints a little greeting.
def main():
  # Get the name from the command line, using 'World' as a fallback.
  if len(sys.argv) >= 2:
    name = sys.argv[1]
  else:
    name = 'World'
  print 'Hello', name
  a = []
  gridsize = 5;
  creategrid(gridsize, a)
  changemaze(gridsize, a)
  if (verifymaze(gridsize, a) != countcellinmaze(gridsize,a)):
    print "wrong grid"
  else:
    print "correct grid"  
  print a  
   
def countcellinmaze(gridsize, a=[]):
  validcells = 0
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      if (a[i][j] == 1):
        validcells += 1
  print validcells      
  return validcells      

  
  
  
def verifycellinmaze(gridsize, a, row, col):
  if a[row][col] != 1:
    return 0
  elif row > 0 and  a[row-1][col] != 1:
    return 0
  elif col > 0 and  a[row][col-1] != 1:
    return 0
  elif row < gridsize-1 and  a[row+1][col] != 1:
    return 0
  elif col < gridsize-1 and  a[row][col+1] != 1:
    return 0
  else:
    return 1


def verifymaze(gridsize, a=[]):
  validcell = 0
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      if (verifycellinmaze(gridsize, a, i, j)):
        validcell += 1
  print validcell      
  return validcell      
      

def changemaze(gridsize, a=[]):
  for i in xrange(gridsize):
    for j in xrange(gridsize):
      a[i][j] = random.randint(1,10)
      if (a[i][j] > -1):
        a[i][j] = 1
      else:
        a[i][j] = 0
            
def creategrid(gridsize, a=[]):
  for i in xrange(gridsize):
    a.append([])
    for j in xrange(gridsize):
      a[i].append(i+j)
      #print "a["+`i`+"]["+`j`+"]"
      #print a[i][j]
         
      
# get main caller
if __name__ == '__main__':
  main()

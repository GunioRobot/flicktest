
def main():
  
  y = 0
  a= []

  fin = open("testmaze.txt")
  #generate start and end cell
  for x in range(8):
    a.append(fin.next().strip().split())
    a[x].append('0')
    a[x] = [1 if y == '1' else y for y in a[x]]
    a[x] = [0 if y == '0' else y for y in a[x]]
    a[x] = [2 if y == '2' else y for y in a[x]]
    a[x] = [3 if y == '3' else y for y in a[x]]
    #print a[x]
    
  endx = 7
  endy = 0
  hmap = {}  
  genpath(a, hmap, endx*10+endy)
  
  print hmap 
  print hmap[70][1][0]

def genpath(a, hmap, cell):

  ele_len = []
  ele_len.append(1)
  
  ind_len = []
  ind_len.append(1)
  ind_len.append(0)
  
  ele_len.append(ind_len)
  hmap[cell] = ele_len
  
  expand_path(a, hmap, cell, ele_len)

def expand_path(a, hmap, cell, ele_len):
  print a     
# get main caller
if __name__ == '__main__':
  main()    
    
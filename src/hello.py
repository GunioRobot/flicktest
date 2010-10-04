#!/usr/bin/python -tt
# Copyright 2010 Google Inc.
# Licensed under the Apache License, Version 2.0
# http://www.apache.org/licenses/LICENSE-2.0

# Google's Python Class
# http://code.google.com/edu/languages/google-python-class/

"""A tiny Python program to check that Python is working.
Try running this program from the command line like this:
  python hello.py
  python hello.py Alice
That should print:
  Hello World -or- Hello Alice
Try changing the 'Hello' to 'Howdy' and run again.
Once you have that working, you're ready for class -- you can edit
and run Python code; now you just need to learn Python!
"""

import sys
from operator import itemgetter
import MySQLdb
import re
import twitter

def twInit():
  cl = twitter.Api()


def fastLongestPalindromes(seq):
  seqLen = len(seq)
  l = []
  i = 0
  palLen = 0
  # Loop invariant: seq[(i - palLen):i] is a palindrome.
  # Loop invariant: len(l) >= 2 * i - palLen. The code path that 
  # increments palLen skips the l-filling inner-loop.
  # Loop invariant: len(l) < 2 * i + 1. Any code path that increments
  # i past seqLen - 1 exits the loop early and so skips the
  # l-filling inner loop.
  while i < seqLen:
    # First, see if we can extend the current palindrome.  Note that
    # the center of the palindrome remains fixed.
    if i > palLen and seq[i - palLen - 1] == seq[i]:
      palLen += 2
      i += 1
      continue

    # The current palindrome is as large as it gets, so we append it.
    l.append(palLen)

    # Now to make further progress, we look for a smaller palindrome
    # sharing the right edge with the current palindrome.  If we find
    # one, we can try to expand it and see where that takes us.
    # At the same time, we can fill the values for l that we neglected
    # during the loop above. We make use of our knowledge of the length
    # of the previous palindrome (palLen) and the fact that the values
    # of l for positions on the right half of the palindrome are
    # closely related to the values of the corresponding positions on
    # the left half of the palindrome.
    
    # Traverse backwards starting from the second-to-last index up
    # to the edge of the last palindrome.
    s = len(l) - 2
    e = s - palLen
    for j in xrange(s, e, -1):
      # d is the value l[j] must have in order for the palindrome
      # centered there to share the left edge with the last palindrome.
      # (Drawing it out is helpful to understanding why the - 1
         # is there.)
      d = j - e - 1
      
      # We check to see if the palindrome at l[j] shares a left edge
      # with the last palindrome.  If so, the corresponding palindrome
      # on the right half must share the right edge with the last
      # palindrome, and so we have a new value for palLen.
      if l[j] == d: 
        palLen = d
        # We actually want to go to the beginning of the outer
        # loop, but Python doesn't have loop labels.  Instead,
        # we use an else block corresponding to the inner loop,
        # which gets executed only when the for loop exits normally
        # (i.e., not via break).
        break
      
      # Otherwise, we just copy the value over to the right side.
      # We have to bound l[i] because palindromes on the left side
      # could extend past the left edge of the last palindrome,
      # whereas their counterparts won't extend past the right edge.
      l.append(min(d, l[j]))
    else:
      # This code is executed in two cases: when the for loop
      # isn't taken at all (palLen == 0) or the inner loop was
      # unable to find a palindrome sharing the left edge with the
      # last palindrome.  In either case, we're free to consider
      # the palindrome centered at seq[i].
      palLen = 1
      i += 1
      
  # We know from the loop invariant that len(l) < 2 * seqLen + 1, so we
  # must fill in the remaining values of l.
  
  # Obviously, the last palindrome we're looking at can't grow any more.
  l.append(palLen)

	# Traverse backwards starting from the second-to-last index up until
	# we get l to size 2 * seqLen + 1. We can deduce from the loop invariants
	# we have enough elements.
  lLen = len(l)
  s = lLen - 2
  e = s - (2 * seqLen + 1 - lLen)
  for i in xrange(s, e, -1):
    # The d here uses the same formula as the d in the inner loop above.
    # (Computes distance to left edge of the last palindrome.)
    d = i - e - 1
    # We bound l[i] with min for the same reason as in the inner loop
    # above.
    l.append(min(d, l[i]))
  return l




def DBfunc():
  conn = MySQLdb.connect (host = "localhost",
                          user = "root",
                          passwd = "iiitc_Z01",
                          db = "pytest")
  cursor = conn.cursor ()
  cursor.execute ("SELECT VERSION()")
  row = cursor.fetchone ()
  print "server version:", row[0]

  cursor.execute ("SELECT * FROM pytable")
  while (1):
    row = cursor.fetchone ()
    if row == None:
      break
    print "%s, %s" % (row[0], row[1])
  print "Number of rows returned: %d" % cursor.rowcount

  cursor.close ()
  conn.close ()

def Fileop():
  # for loop is over. Indent back   
  all_words = [" "]
  dct = {" ":1}
  #p = re.compile('\w+\s\w+')
  
  #read file now
  fileHandle = open ( 'word_DB1.txt', 'r' )
  #this will give us array of lines
  fileList = fileHandle.readlines()
  #traverse through all lines
  for fileLine in fileList:
    #print fileHandle.tell()	  
     #words = map(lambda l: l.split(" "), fileLine)
    #traverse each word in line now
    m = re.search("(\s*[^a]+\s+) (\w+)",fileLine)
    if m:
      print m.groups()
      print m.group(1)
      print m.group(2)
      print fileLine

    #n = re.split('the',fileLine)
    #if n:
      #print n
      #print fileLine

    for word in fileLine.split(" "):
      #print word

  
      if word == ' ' or word == '' or word == '\n':
        continue
      else: 
        if word[-1] == "\n":
          str = word[:-1]
        else:
          str = word
        	  
        all_words.append(str)  
        if str in dct:
          dct[str] = dct[str] + 1
        else:
          dct[str] = 1		 	  	
    #print fileLine,
  fileHandle.close() 
  #print sorted(all_words)      	  
  #print sorted(dct.items(), key=itemgetter(1), reverse=True)

def Mathfunc():
  #declare number like this
  num = 10
  #integer treatment
  print num/3 - 2.5
  #FIXME: fix this asap
  num = 10.46
  print num/3 - 2.5
  #power 
  print 3 ** 2
  string = u"This is Charul's program"
  # concat string like this 
  print string + " janak"
  # declare array like this
  list = (10, 16, 14, 34)
  #sort the array
  print sorted(list)
  #upper-case
  print string.upper()
  # what is start address of first 'pro'
  print string.index("pro")
  #last 5 chars
  print string[-5:]
  #total occurance of s
  print string.count('s')
  #total len of string
  print len(string)
  # declare hash
  dict = {1:"one", 2:"two", "abc":"random"}
  print dict[2]
  #change second element
  dict[2] = "TWOOOO"
  print dict[2]
  #print len of hash
  print len(dict)
  #print value of 2 in hash
  print (2 in dict)
  #traverse through all keys
  print dict.keys()
  print dict.items()
  
  # this is how if else works
  if num < 10:
    print num
  else:
    print "Hello" 
     
  x = 1
  for x in range(-11,10,2):
    print x

def stringrev():  
  str = "this is interview question"
  print str
  str1 = str[::-1]

  print str1
  for word in str1.split(" "):
    print word[::-1]

def Prime():
  lst = [2,3,5]
  for x in range (0,10):
    lst.append(30*x + 7)	  
    lst.append(30*x + 11)	  
    lst.append(30*x + 13)	  
    lst.append(30*x + 1)	  
    if (x > 0):
      lst.append(30*x - 7)	  
      lst.append(30*x - 11)	  
      lst.append(30*x - 13)	  
      lst.append(30*x - 1)	  



  print sorted(lst)

# Define a main() function that prints a little greeting.
def main():
  # Get the name from the command line, using 'World' as a fallback.
  if len(sys.argv) >= 2:
    name = sys.argv[1]
  else:
    name = 'World'
  print 'Hello', name 
  #TODO: test

  print "Arpit"
  twInit()

  fastLongestPalindromes("malayalam")

  stringrev()

  Prime()
   
  DBfunc() 
  
  Fileop()
   
  Mathfunc()

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()

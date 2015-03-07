#!/usr/bin/python
#!/bin/env python

# solves the problem from: https://code.google.com/codejam/contest/351101/dashboard#s=p0

from operator import itemgetter
import sys


REQUIRED_NUM_ARGUMENTS = 2 

def printUsage():
  print "Usage: %s <input_file> <output_file>" % (sys.argv[0])

def solve_problem():

  # check the number of input arguments
  if (len(sys.argv) != REQUIRED_NUM_ARGUMENTS):
    printUsage()
    sys.exit(-1)

  inputFileName = sys.argv[1]

  # open the input file
  input_fd = open(inputFileName, 'rb')

  # get the number of test cases
  numTestCases = int(input_fd.readline().strip())

  for testCaseIndex in range(numTestCases): 
    
    # get the amount of store credit
    storeCredit = int(input_fd.readline().strip())

    # get the number of items in the store
    numberItems = int(input_fd.readline().strip())

    # get the items
    itemsStrList = (input_fd.readline().strip()).split(' ')
    items = map(int, itemsStrList)

    # double check the number of found items
    if (len(items) != numberItems):
      print "Read %d items when %d were expected" % (len(items), numberItems)
      sys.exit(-1)

    # convert the list into a list of dictionaries
    itemsDictList = []
    for i in range(numberItems):
      itemsDictList.append( {'value':items[i], 'index':i} ) 

    # now sort the list
    itemsSorted = sorted(itemsDictList, key=itemgetter('value'))    

    itemOneValue = 0
    itemTwoValue = 0
    foundMatch = False

    # go through each of the items in the list
    for itemOne in range(len(items) - 1, 0, -1):

      itemOneValue = itemsSorted[itemOne]['value']
      itemOneIndex = itemsSorted[itemOne]['index']

      # don't bother looking at this value if it is already over the limit
      if itemOneValue > storeCredit:
        continue

      for itemTwo in range(0, itemOne, 1):
        
        itemTwoValue = itemsSorted[itemTwo]['value']
        itemTwoIndex = itemsSorted[itemTwo]['index']

        # must have two distinct items, so continue if the indicies match
        if itemOneIndex == itemTwoIndex:
          continue

        if (itemOneValue + itemTwoValue) == storeCredit:
          foundMatch = True
          break

        elif (itemOneValue + itemTwoValue) > storeCredit:
          break # this itemOne item does not have a match
 
      if foundMatch:

        if itemOneIndex > itemTwoIndex:
          print "Case #%d: %d %d" % (testCaseIndex + 1, itemTwoIndex + 1, itemOneIndex + 1)
        else:
          print "Case #%d: %d %d" % (testCaseIndex + 1, itemOneIndex + 1, itemTwoIndex + 1)

        # done with this test case
        break

 
if __name__ == "__main__":
  solve_problem()


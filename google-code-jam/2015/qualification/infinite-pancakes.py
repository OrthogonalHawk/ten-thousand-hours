#!/usr/bin/python
#!/bin/env python

# solves the problem from https://code.google.com/codejam/contest/6224486/dashboard#s=p1

import sys

DEBUG_ON = True
REQUIRED_NUM_ARGUMENTS = 2

def printUsage():
  print "Usage: %s <inputFile>" % (sys.argv[0])

def solveProblem():

  if len(sys.argv) != REQUIRED_NUM_ARGUMENTS:
    printUsage()
    sys.exit(-1)

  inputFile = sys.argv[1]
  input_fd = open(inputFile, 'rb')

  numberTestCases = int(input_fd.readline().rstrip('\n'))

  for testCaseIndex in range(1, numberTestCases + 1, 1):

    # get the number of diners in this test case
    numDiners = int(input_fd.readline().rstrip('\n'))

    # next, get the pancake distribution
    pancakeDistroStr = input_fd.readline().rstrip('\n')

    pancakes = pancakeDistroStr.split(' ')
    pancakes = map(int, pancakes)

    absMaxMinutes = max(pancakes)

    numMinutes = 0
    pancakesRemaining = True
    
    while pancakesRemaining:

      specialMinute = False

      if DEBUG_ON:
        print " %d" % numMinutes, pancakes

      # find the maximum number of pancakes left
      maxDinerPancakes = max(pancakes)

      # find the number of split candidates
      splitCandidates = []
      for i in range(len(pancakes)):

        if ((pancakes[i] % 2) == 0) and \
            (pancakes[i] >= 2) and \
            (pancakes.count(pancakes[i]) < pancakes[i]):
          splitCandidates.append(pancakes[i])

      almostMaxValExists = False
      if (maxDinerPancakes - 1) in pancakes:
        almostMaxValExists = True
         
      # evaluate whether splitting makes sense
      if len(splitCandidates) > 0 and \
         max(splitCandidates) == maxDinerPancakes and \
         pancakes.count(maxDinerPancakes) <= min(splitCandidates) and \
         pancakes.count(maxDinerPancakes) <= (maxDinerPancakes / 2):

        # we should split the max pancakes
        while maxDinerPancakes in pancakes:
          maxDinerIdx = pancakes.index(maxDinerPancakes)
          pancakes[maxDinerIdx] = maxDinerPancakes / 2
          pancakes.append(maxDinerPancakes / 2) 
          numMinutes += 1
     
          if DEBUG_ON:
            print " SPC %d" % numMinutes, pancakes

      # decrement our pancakes
      for i in range(len(pancakes)):
        if pancakes[i] > 0:
          pancakes[i] -= 1
      numMinutes += 1

      # see if we are done
      pancakesRemaining = (max(pancakes) != 0)

    if (numMinutes > absMaxMinutes):
      print "ERROR - Exceeded max tries!!!"
      #sys.exit(-1)
      # dividing didn't help, use worst case
      #numMinutes = absMaxMinutes

    print "Case #%d: %d" % (testCaseIndex, numMinutes)

if __name__ == "__main__":
  solveProblem()


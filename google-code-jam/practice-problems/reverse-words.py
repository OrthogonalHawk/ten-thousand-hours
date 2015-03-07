#!/usr/bin/python
#!/bin/env python

# solves the problem from: https://code.google.com/codejam/contest/351101/dashboard#s=p1

import sys

REQUIRED_NUM_ARGUMENTS = 2

def printUsage():
  print "Usage: %s <inputFile>" % (sys.argv[0])

def solveProblem():
  
  # check the number of input arguments
  if (len(sys.argv) != REQUIRED_NUM_ARGUMENTS):
    printUsage()
    sys.exit(-1)

  inputFileName = sys.argv[1]

  input_fd = open(inputFileName, 'rb')

  # get the number of test cases
  numberTestCases = int(input_fd.readline().strip())

  for testCaseIndex in range(1, numberTestCases + 1, 1):

    testCaseString = input_fd.readline().strip()
    testCaseList = testCaseString.split(' ')

    outputString = ""
    # now get the rest of the string
    for wordIdx in range(len(testCaseList) - 1, -1, -1):
      outputString = outputString + " %s" % (testCaseList[wordIdx])

    print "Case #%d:%s" % (testCaseIndex, outputString)


if __name__ == "__main__":
  solveProblem()


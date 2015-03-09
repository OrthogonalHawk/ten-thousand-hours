#!/usr/bin/python
#!/bin/env python

# solves the problem from: https://code.google.com/codejam/contest/32016/dashboard#s=p0

import sys


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

    vectorLength = int(input_fd.readline().strip())

    vectorOneStr = input_fd.readline().strip()
    vectorTwoStr = input_fd.readline().strip()

    vectorOneStrList = vectorOneStr.split(' ')
    vectorTwoStrList = vectorTwoStr.split(' ')

    vectorOneInts = map(int, vectorOneStrList)
    vectorTwoInts = map(int, vectorTwoStrList)

    vectorOneInts.sort()
    vectorTwoInts.sort(reverse=True)

    minimumScalarProduct = 0
    for i in range(vectorLength):
      minimumScalarProduct += vectorOneInts[i] * vectorTwoInts[i]

    print "Case #%d: %d" % (testCaseIndex, minimumScalarProduct)

if __name__ == "__main__":
  solveProblem()


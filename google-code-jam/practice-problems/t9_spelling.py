#!/usr/bin/python
#!/bin/env python

# solves the problem from: https://code.google.com/codejam/contest/351101/dashboard#s=p2

import sys


REQUIRED_NUM_ARGUMENTS = 2
t9Dict = {'a': '2', 'b': '22', 'c': '222',
          'd': '3', 'e': '33', 'f': '333',
          'g': '4', 'h': '44', 'i': '444',
          'j': '5', 'k': '55', 'l': '555',
          'm': '6', 'n': '66', 'o': '666',
          'p': '7', 'q': '77', 'r': '777', 's':'7777',
          't': '8', 'u': '88', 'v': '888',
          'w': '9', 'x': '99', 'y': '999', 'z':'9999',
          ' ': '0'}

t9UsesKey = {'a': '2', 'b': '2', 'c': '2',
             'd': '3', 'e': '3', 'f': '3',
             'g': '4', 'h': '4', 'i': '4',
             'j': '5', 'k': '5', 'l': '5',
             'm': '6', 'n': '6', 'o': '6',
             'p': '7', 'q': '7', 'r': '7', 's':'7',
             't': '8', 'u': '8', 'v': '8',
             'w': '9', 'x': '9', 'y': '9', 'z':'9',
             ' ': '0'}

def printUsage():
  print "Usage: %s <input_file>" % (sys.argv[0])

def convertToT9(prevCharacter, curCharacter):
  retVal = ""

  if curCharacter not in t9Dict.keys():
    print "Unable to find %s in the T9 Dict!!!" % (curCharacter)
    return ""

  # see if we need a pause before this next character
  if prevCharacter and t9UsesKey[prevCharacter] == t9UsesKey[curCharacter]:
    retVal += " "

  # now add the button press for the current character
  retVal += t9Dict[curCharacter]

  return retVal

def solveProblem():

  # check for the required number of input arguments
  if (len(sys.argv) != REQUIRED_NUM_ARGUMENTS):
    printUsage()
    sys.exit(-1)

  inputFile = sys.argv[1]
  input_fd = open(inputFile, 'rb')

  numberTestCases = int(input_fd.readline().strip())

  for testCaseIndex in range(1, numberTestCases + 1, 1):

    # retrieve the line that we need to convert
    messageToSend = input_fd.readline().rstrip('\n')

    prevCharacter = None
    buttonPresses = ""
    # go through each character in the message and convert
    #  it to the appropriate T9 button presses
    for i in range(len(messageToSend)):
      buttonPresses += convertToT9(prevCharacter, messageToSend[i])
      prevCharacter = messageToSend[i]

    print "Case #%d: %s" % (testCaseIndex, buttonPresses)

if __name__ == "__main__":
  solveProblem()


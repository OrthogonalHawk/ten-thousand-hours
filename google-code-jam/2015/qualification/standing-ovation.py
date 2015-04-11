#!/usr/bin/python
#!/bin/env python

# solves the problem from https://code.google.com/codejam/contest/6224486/dashboard#s=p0

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

    testCaseStr = input_fd.readline().rstrip('\n')

    # make sure that we can split this line as expected
    if len(testCaseStr.split(' ')) != 2:
      print "ERROR - Unable to split the test case line as expected!!!"
      sys.exit(-1)

    maxShyness = testCaseStr.split(' ')[0]
    audienceStr = testCaseStr.split(' ')[1]

    numFriendsToInvite = 0
    numMembersStanding = 0

    for shynessLevel in range(len(audienceStr)):

      # get the number of audience members with shyness level i
      numMembers = int(audienceStr[shynessLevel])      
    
      # are enough people already standing to get these to stand?
      if (shynessLevel == 0) or (numMembersStanding >= shynessLevel):
        pass
      # not enough standing, add friends
      else:
        friendsToAdd = shynessLevel - numMembersStanding
        numFriendsToInvite += friendsToAdd
        numMembersStanding += friendsToAdd

      # these members will now stand
      numMembersStanding += numMembers

    print "Case #%d: %d" % (testCaseIndex, numFriendsToInvite)

if __name__ == "__main__":
  solveProblem()


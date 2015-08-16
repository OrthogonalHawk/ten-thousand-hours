#!/usr/bin/python
#!/bin/env python

# https://github.com/instructure/contests/tree/master/2012-mebipenny/contest/call-me-maybe

import sys

conversion_dict = {'A':2, 'B':2, 'C':2,
                   'D':3, 'E':3, 'F':3,
                   'G':4, 'H':4, 'I':4,
                   'J':5, 'K':5, 'L':5,
                   'M':6, 'N':6, 'O':6,
                   'P':7, 'Q':7, 'R':7, 'S':7,
                   'T':8, 'U':8, 'V':8,
                   'W':9, 'X':9, 'Y':9, 'Z':9}

def convert_to_numbers(input_str):

  # convert all lower-case characters to upper-case
  in_str = input_str.upper().strip()
  out_str = ""
  
  for idx in range(len(in_str)):
    if in_str[idx] in conversion_dict.keys():
      out_str += str(conversion_dict[in_str[idx]])
    else:
      out_str += in_str[idx]

  return out_str

def main():

  if len(sys.argv) != 2:
    print "Usage: %s <input_file>" % (sys.argv[0])
    sys.exit(-1)

  input_file = open(sys.argv[1], 'rb')

  for line in input_file:

    print convert_to_numbers(line)

if __name__ == "__main__":
  main()


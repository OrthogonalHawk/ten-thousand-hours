#!/usr/bin/python
#!/bin/env python

import argparse
import logging

parser = argparse.ArgumentParser()
parser.add_argument("--log_level", help="sets the logging level", choices=['DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL'], default='CRITICAL')

def main():
    
    args = parser.parse_args()
    if args.log_level:
        logging.basicConfig(format='%(asctime)s - %(levelname)s - %(message)s', level=getattr(logging, args.log_level))
    
    logging.debug("Stupid Comment")

if __name__ == "__main__":
    main()
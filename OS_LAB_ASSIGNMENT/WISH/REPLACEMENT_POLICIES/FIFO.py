import socket               # Import socket module
import threading
import os
import sys
import time

alru=[]
fifo=[]
lfu=[]
rand=[]
window_size=3
def Main():
    print "INSIDE MAIN | "
    print ""
    while True:
        input=raw_input("Enter the access | ");
        LRU(input)
        # approxLRU(input)
        # FIFO(input)
        # LFU(input)
        # random(input)

        if input == 'q':
            exit(0);
lru=[]

def LRU(input):
    print "LRU"
    print "input is |",input
    if inp in lru:
        if inp == input:
            print input," HIT"
            lru.rotate(-1)
        else:
            print input," MISS"
            if(len(lru)< window_size):
                lru.append(input)
            else:
                print "REPLACING |"
                lru[0]=input
    print lru;    

def approxLRU(input):
    print "APPROX LRU"
    print "input is |",input

def FIFO(input):
    print "FIFO"
    print "input is |",input
    fifo.append(input);

def LFU(input):
    print "LFU"
    print "input is |",input
    

def random(input):
    print "RANDOM"
    print "input is |",input
    


if __name__ == '__main__':
	Main()
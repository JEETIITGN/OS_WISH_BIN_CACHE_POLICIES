import socket               # Import socket module
import threading
import os
import sys
import time
import random
import copy
# new_list = copy.copy(old_list)
# hitRate=0;
nhits=0
totalAccesses=0;
lru=[]
alru=[]
fifo=[]
lfu=[]
rand=[]
window_size=3
def LRU(input):
    global lru
    global nhits
    print "LRU"
    print "input is |",input
    if len(lru) !=0:
        # for inp in lru:
        if input in lru:
            print input," HIT"
            nhits=nhits+1
            location=lru.index(input)
            print "LOCATION IS | ",location
            print ""
            if location != 0:
                lru=lru[:location]+lru[location+1:]
                print "LRU after add | ",lru
                lru.append(input)
                print "LRU after concat | ",lru
            else:
                lru=lru[1:window_size]+lru[:1]
        else:
            print input," MISS"
            if(len(lru)< window_size):
                lru.append(input)
            else:
                print "REPLACING |"
                lru[0]=input
                location=lru.index(input)
                # print "LOCATION IS | ",location
                print ""
                if location != 0:
                    lru=lru[:location]+lru[location:]
                    lru.append(input)
                else:
                    lru=lru[1:window_size]+lru[:1]
                # lru=lru[1:window_size]+lru[:1]
    else:
        print "LRU LIST EMPTY ADDING TO THE LIST"
        lru.append(input)
    print lru;    

def approxLRU(input):
    print "APPROX LRU"
    print "input is |",input

def FIFO(input):
    global fifo
    global nhits
    print "FIFO"
    print "input is |",input
    if len(fifo) !=0:
        if input in fifo:
            print input," HIT"
            nhits=nhits+1
        else:
            print input," MISS"
            if(len(fifo)< window_size):
                fifo.append(input)
            else:
                print "REPLACING |"
                fifo=fifo[1:window_size]+fifo[:1]
                fifo[window_size-1]=input
    else:
        print "fifo LIST EMPTY ADDING TO THE LIST"
        fifo.append(input)
    print fifo;
counter=[]
i=0
for i in range(window_size):
    counter.append(1)
def LFU(input):
    global lfu
    global counter
    global nhits
    print "LFU"
    print "input is |",input
    
    if len(lfu) !=0:
        if input in lfu:
            print input," HIT"
            nhits=nhits+1
            for ct in lfu:
                if input==ct:
                    location=lfu.index(ct)
                    print "LOCATION FOR INC IS ",location
                    print "COUNTER BEFORE ",counter
                    temp=int(counter[location])+1
                    counter.pop(location)
                    print "POP LOC | ",location
                    counter.insert(location,temp) #list.insert(index,value)
                    print "COUNTER AFTER ",counter
        else:
            print input," MISS"
            if(len(lfu)< window_size):
                lfu.append(input)
            else:
                print "REPLACING |"
                locpop=counter.index(min(counter))
                lfu.pop(locpop)
                counter.pop(locpop)
                counter.insert(locpop,1)
                lfu.insert(locpop,input)
                print "COUNTER | \t ",counter

                
    else:
        print "lfu LIST EMPTY ADDING TO THE LIST"
        lfu.append(input)
    print lfu;


def rando(input):
    global rand  
    global nhits
    nhits=0  
    print "RANDOM"
    # print random.randrange(2)
    print "input is |",input
    if len(rand) !=0:
        if input in rand:
            print input," HIT"
            nhits=nhits+1
        else:
            print input," MISS"
            if(len(rand)< window_size):
                rand.append(input)
            else:
                print "REPLACING |"
                
                rand[random.randrange(2)]=input
    else:
        print "rand LIST EMPTY ADDING TO THE LIST"
        rand.append(input)
    print rand;



def oracle():
    oracle=[]
    c=[]
    input=[0,1,2,0,1,3,0,3,1,2,1]
    print "ORACLE"
    print "input is |",input
    i=0
    print "LENGTH OF INPUT | ",len(input)
    for val in input:
        # print "VAL is | ",val,type(val)
        if val not in oracle:
            print val," is not in ",oracle
            oracle.append(input[i])
            c.append(input.count(input[i]))
        i=i+1
    
    print "ORACLE IS | ",oracle
    print "COUNTER IS ",c
    # exit()
    lis=[]
    i=0
    nhits=0
    for term in (input):
        cp_oracle=copy.copy(oracle)
        cp_counter=copy.copy(c)
        print "###########################",oracle,c
        if len(lis) !=0:
            if term in lis:
                print term," HIT"
                nhits=nhits+1
            else:
                print term," MISS"
                if(len(lis)< window_size):
                    lis.append(term)
                else:
                    print "REPLACING |"
                    indx=cp_oracle.index(term)
                    print "ftr removing index ",indx
                    print "ftr BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                    cp_oracle.pop(indx)
                    cp_counter.pop(indx)
                    print "ftr BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                    try:
                        try:
                            if input[i+1] in lis:
                                try:
                                    indx=cp_oracle.index(input[i+1])
                                    print "i+1 removing index ",indx
                                    print "i+1 BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                                    cp_oracle.pop(indx)
                                    cp_counter.pop(indx)
                                    print "i+1 AFTER ORACLE | ",cp_oracle," counter | ",cp_counter
                                except:
                                    print "not in list"
                        except:
                            print "i+1"
                        try:
                            if input[i+2] in lis:
                                try:
                                    indx=cp_oracle.index(input[i+2])
                                    print "i+2 removing index ",indx
                                    print "i+2 BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                                    cp_oracle.pop(indx)
                                    cp_counter.pop(indx)
                                    print "i+2 AFTER ORACLE | ",cp_oracle," counter | ",cp_counter
                                except:
                                    print "ALREADY removed"
                        except:
                            print "i+2"
                        while len(cp_counter) != 1:
                                
                            indx=cp_counter.index(max(cp_counter))
                            print "chop removing index ",indx
                            print "chop BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                            cp_oracle.pop(indx)
                            cp_counter.pop(indx)
                            print "chop BEFORE ORACLE | ",cp_oracle," counter | ",cp_counter
                        for selection in lis:
                            if selection == cp_oracle[0]:
                                lis[lis.index(selection)]=term
                    except:
                        print ""    
                        # lis[lisom.lisrange(2)]=term
                    # print lis
        else:
            print term," MISS "
            lis.append(term)
        i=i+1
        indx=oracle.index(term)
        new_count=int(c[indx])-1
        c.pop(indx)
        c.insert(indx,new_count)
        print " ORACLE | ",oracle," NEW COUNT | ",c
        print lis;    
        
    print "HITS COUNT | ",nhits
    # hitRate=float(nhits/11)*100;
    print"HIT RATE IS ",(nhits)*100/11, "%"
        

def Main():
    print "INSIDE MAIN | "
    print ""
    global totalAccesses
    global nhits
    nhits=0
    totalAccesses=0
    while True:
        input=raw_input("Enter the access | ");
        if input == 'q':
            break
        totalAccesses=totalAccesses+1
        # LRU(input)
        # approxLRU(input)
        FIFO(input)
        # LFU(input)
        # rando(input)
        hitRate=nhits*100/totalAccesses
        print "HIT RATE IS | ",hitRate, "%"

    oracle()
if __name__ == '__main__':
	Main()
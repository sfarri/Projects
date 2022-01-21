###############################################################
# Program:
#     Week 13, Geneology
#     Brother Ercanbrack, CS235
# Author:
#     Seth Farr
# Summary:
#     This project was super long and very arduous. I spend a
#     minimum of 25 hours.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: main.o
	g++ -o a.out main.o -g
	tar -cf week13.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week13.o     : the driver program
#      geneologyTree.o   : the spell-check program and driver
##############################################################
main.o: geneologyTree.h person.h superNode.h main.cpp
	g++ -c main.cpp -g

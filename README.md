How To Use Test Cases!!

First you choose how many people will be in the two lists, then you populate those lists with preferences.
I will be using test1 as an example, for this example I will provide the words that will be- 
-displayed on screen with the numbers to input, then below that will be what the test case version-
-of that will look like in the .in file labeled "raw input". 

The output will be the same in both cases!


----input------

How many people will be in each list?: 3

How many preferences will acceptor 0 have?
2
Input preference 0 for acceptor 0 :1
Input preference 1 for acceptor 0 :0

How many preferences will acceptor 1 have?
2
Input preference 0 for acceptor 1 :0
Input preference 1 for acceptor 1 :2

How many preferences will acceptor 2 have?
2
Input preference 0 for acceptor 2 :1
Input preference 1 for acceptor 2 :0

How many preferences will donor 0 have?
3
Input preference 0 for donor 0 :2
Input preference 1 for donor 0 :1
Input preference 2 for donor 0 :0

How many preferences will donor 1 have?
3
Input preference 0 for donor 1 :1
Input preference 1 for donor 1 :2
Input preference 2 for donor 1 :0

How many preferences will donor 2 have?
3
Input preference 0 for donor 2 :0
Input preference 1 for donor 2 :2
Input preference 2 for donor 2 :1


---output-----

Acceptor 0 is matched with Donor 2
Acceptor 1 is matched with Donor 0
Acceptor 2 is matched with Donor 1



---raw input---

3
2
1
0
2
0
2
2
1
0
3
2
1
0
3
1
2
0
3
0
2
1

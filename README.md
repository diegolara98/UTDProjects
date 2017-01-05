# UTDProjects
The projects I've completed while at The University of Texas at Dallas.

These are projects that show off many of the different types of skills I have acquired over the past few months.
They include:
Classes/ Operator Overloading
   -  #1:
      In this assignment you are going to create a calculator that reads in commands from an input file called
      input.txt and performs the actions required by the commands.
      The program needs to consist of multiple functions. You need your main and at least two additional
      functions. You can have more than two if desired. 
   -  #2:
      Write a program that simulates a soft drink machine. The program will need several classes: DrinkItem,
      DrinkMachine and Receipt. For each of the classes you must create the constructors and member
      functions required below. You can, optionally, add additional private member functions that can be used
      for doing implementation work within the class.
   
Linked List and Ordered Linked List
   -  #3:
      In this assignment you are going to create a double linked list and an ordered double linked list.
      The bulk of the work will be building the double linked list. This will be a template classes named
      ListNode<DataType> and DoubleLinkedList<DataType>.
      You will also be building an ordered linked list template class named
      OrderedDoubleLinkedList<DataType>.
      
Stack and Queue
   -  #4:
      In assignment 3 you created a double linked list and an ordered double linked list. You will be using the
      DoubleLinkedList and ListNode classes to implement stack and queue classes. We really only need a
      linked list for this exercise, but we already have a nice double linked list you have written and we are
      going to make use of it. You will once again be using composition and not inheritance to reuse the
      DoubleLinkedList class. 

Binary Search Tree
   -  #5:
      You will be creating a program that allows you to quickly solve Jumble or Scram-lets types of puzzles. To
      do this be using a binary search tree you will be creating. Your application will read in a list of words
      (over 35,000). You will sort the letters of each word to create a key. You will then add the key (and the
      word) to the tree (as one item called Word).
  Example:
      The word you read in from the file is the word “Binary”. You need to create a key from this. The key will
      be the word folded to lower case and ordered by its letters. So the word “Binary” first gets folded to
      lower case (binary) and then ordered by letter order – “abinry”. The key is “abinry” and the word is
      “Binary”. You need to create a class for this item (I will call it Word). The Word contains both the key
      (“abinry”) and the word text (“Binary”). This is added to the binary search tree in key order.
      Once the dictionary of look up words has been build your application will prompt for a jumbed word.
      You will fold the jumbled word to lower case and sort the letters in the word. This will be what you look
      up in your dictionary of lookup words. If it is found you get the word text and that is your word
      unscrambled.
  Example:
      You type in Arbiny. This is folded to lower case (arbiny) and sorted (abinry). You look up the key abinry
      and it finds the word text Binary. So arbiny maps to Binary. 

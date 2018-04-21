*********Assignment Description:*************
A local movie rental store wishes to automate their inventory tracking system. Currently there are three types of movies/videos (in DVD media) to be tracked:
-	Comedy (denoted as ‘F’ for funny)
-	Drama (denoted as ‘D’)
-	Classics (denoted as ‘C’)
Borrows and returns of items by customers are also to be tracked. Four types of actions are desired in the system:
-	Borrow (denoted as ‘B’): (stock – 1) for each item borrowed  
-	Return (denoted as ‘R’): (stock + 1) for each item returned
-	Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
-	History (denoted as ‘H’): outputs all the transactions of a customer 
You will design and implement a program that will initialize the contents of the inventory from a file (data4movies.txt), the customer list from another file (data4customers.txt), and then process an arbitrary sequence of commands from a third file (data4commands.txt).
*********************************************

DEVELOPER'S NOTES
For this assignment, I designed and implemented a movie rental store's inventory tracking system. 

It populates its inventory data (all DVD items, customer information, and customer transactions) from different files. It keeps track of the store's DVD inventory, partitioned into different binary search tree containers according to their genres. It also keeps track of the store's customers by storing it into a hash table container which uses open hashing in order to handle collisions.

Borrow and return transactions are also stored in a vector within a customer object which executed the transaction. When an Inventory transaction is read from the command file, this program sorts and outputs all inventory according to this order:

-	comedy movies (‘F’) sorted by Title, then Year it released 
-	dramas (‘D’) are sorted by Director, then Title 
-	classics (‘C’) are sorted by Release date, then Major actor

The history transaction outputs the transaction history of the specified customer.

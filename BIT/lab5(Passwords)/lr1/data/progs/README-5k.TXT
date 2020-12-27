
Table set SSTIC04-5000
----------------------

INFO:

This table set is made of 4 perfect rainbow tables with an initial
number of 350'000'000 chains. At length 5000 there are about
29'500'000 perfect chains left. Each table has a success rate of
83.9%, resulting in 99.93% of success rate for the table set.

The average number of hash operations needed to recover a password is
4.8 million. The maximum number of operations is 55 million.

The total size of the tables is 719MB. If you have only 512MB of RAM
and many passwords to crack you may want to try the -n 3 option to use
only 3 tables in parallel at a time.

USAGE:

Unzip the files into a directory (e.g. 5000/). Run ophcrack with
following parameters:

./ophcrack -d 5000/ -t 5000 -o 10000 -n 4 -s <hash_file>



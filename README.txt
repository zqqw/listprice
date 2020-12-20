listprice - edits data copy-pasted from London Stock Exchange searches to a nicer list.

Build and install / uninstall using Scons:
Run ./configure to change defaults if required:
$ ./configure --help
usage: configure [-h] [--prefix PREFIX] [--compiler COMPILER] [--no_strip]

optional arguments:
  -h, --help           show this help message and exit
  --prefix PREFIX      Installation prefix (default: /usr/local)
  --compiler COMPILER  Manually set cc compiler (default: DEFAULT)
  --no_strip           Do not strip the listprice binary (default: False)

Build without installing:
$ scons
Install:
# scons --install
Uninstall:
# scons --uninstall

Compile without scons:
$ gcc -Wall -Wextra -o listprice listprice.c

Usage:
$ ./listprice [/path/]inputfile.txt [/path/]outputfile.txt
If you want a list of companies in a sector on the London Stock Exchange, you can go do a search on the site like for example here:
https://www.londonstockexchange.com/live-markets/market-data-dashboard/price-explorer?lang=en&indices=ASX&sectors=301010
Then if you copy and paste the result into a text file (be quick as it deselects after a bit, it may be easier going up from the bottom) you get this:

BGEO    BANK OF GEORGIA GROUP PLC ORD 1P        GBX     596.92  1,174.00        -40.00  -3.29%          Equity  Track
BARC    BARCLAYS PLC ORD 25P    GBX     25,262.49       145.00  -0.54   -0.37%          Equity  Track
CBG     CLOSE BROS GROUP PLC ORD 25P    GBX     2,075.12        1,386.00        9.00    0.65%           Equity  Track

Don't worry if you accidentally copy some additional stuff from the page, it should be ignored. Run it through listprice and it gives this:

BGEO    BANK OF GEORGIA GROUP PLC ORD 1P                   596.92     GBX 1,174.00
BARC    BARCLAYS PLC ORD 25P                               25,262.49  GBX 145.00
CBG     CLOSE BROS GROUP PLC ORD 25P                       2,075.12   GBX 1,386.00

Companies in the indices seem to all be quoted in GBX, which is easily identified. But others on the platform are in a multitude of currencies.
The -a / --all option can be used with these, but a small number have for example EUR in the company name section, so they may not print out quite right, e.g.
BKIE    BANK OF IRELAND(GOVERNOR&CO OF) UTS NON-CUM EUR PREF STK EUR1.27 'A'    EUR     -       -       -       -       -       Equity  Track
BKIE    BANK OF IRELAND(GOVERNOR&CO OF) UTS NON-CUM        PREF       EUR STK 
Although in this case there was no price data anyway.

So you get a handy list showing the code, name, market cap and price, which saves a lot of editing. Now you can add your own notes if you want.
listprice is a simple thing so might break slightly on unexpected input, but seems to work OK generally.
The GBX (or iso4217 code list) is used to identify valid lines and the relative position of other elements in the line.
In case you get the idea I fund my open source software through my investments - er, no.
If you want be sure of making money from the markets, get a job as a stockbroker :).

$ listprice --help
Usage: listprice [OPTION...] INFILE OUTFILE
listprice : edits data copy-pasted from London Stock Exchange searches
Examples of use:
$ listprice infile.txt outfile.txt  :  read infile, write (edited) to outfile 
$ listprice -a infile.txt outfile.txt : use iso4217 list as key, not just GBX

  -a, --all                  use all iso4217 codes to find lines
  -?, --help                 Give this help list
      --usage                Give a short usage message
  -V, --version              Print program version

Report bugs to <www.cxperimental.weebly.com>.

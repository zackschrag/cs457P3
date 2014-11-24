Authors: Zack Schrag and Tanner Moore
Date: 11/23/2014

cs457P3 - DNS Resolver
=======

Usage
=======
./myresolver domain-name [RRTYPE code]

Things to note
=======
When running with 'www.cnn.com', occasionally there will be a "stack smashed" error. Please try running a few times because this error only happens about 50% of the time. We ran out of time to debug this part.

Sometimes the server takes a while to respond. Ctrl-c and try again.

If there are no IPv6 records for the domain, it fails with the 'AAAA' option.

We also noticed a really weird edge case. In the case of www.nlnetlabs.nl, there was a server that had a '0' in it, something like this: 194.0.*.* -- This caused parsing to terminate after 194 because it read the 0 as the null character. We found that if you run into this case, run it a bunch of times and eventually you won't see that error because it will give another IP without the 0 in it. Hopefully when this program is run, there won't be any of those issues.

List of domains we tested to be working for IPv4:
www.cnn.com
www.target.com
www.walmart.com
www.google.com
www.bestbuy.com
www.opensooq.com
www.colostate.edu
www.nlnetlabs.nl

We only got IPv4 working. IPv6 works for some cases:
www.cnn.com
www.google.com
www.nlnetlabs.nl

We didn't get RRSIG working either.




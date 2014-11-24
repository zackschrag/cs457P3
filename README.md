cs457P3 - DNS Resolver
=======

Usage
=======
./myresolver <domainName> [RRTYPE code]

Things to note
=======
When running with 'www.cnn.com', occasionally there will be a "stack smashed" error. Please try running a few times because this error only happens about 50% of the time. We ran out of time to debug this part.

List of domains we tested to be working for IPv4:
www.cnn.com
www.target.com
www.walmart.com
www.google.com
www.bestbuy.com
www.opensooq.com
www.colostate.edu
www.nlnetlabs.nl

We only got IPv4 working flawlessly. IPv6 works for some cases:
www.google.com
www.nlnetlabs.nl




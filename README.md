# SaaS on PHP
This is a SaaS proprietary git.

Using this with the free software, swatchphp/Pipes, is recommended but not required.

-------
Just send a query request in either POST or GET in order to start this up.
You must send at least one parameter with a name that starts with "site"

All preg_match("/site/") variables will be sent to. You may send as many as you wish.
If you wish to, you can send them in an array format.

All preg_match("/session/") variables will be sent too. Accommodating with a token on the end
would suffice to keep user tokens which are in the connection as reusable information when
sending things back to this server. Keeping a log is recommended.

This file can be tripped under one SessionID and given a load-balancing feature. This is
enabled by counting the number of SessionIDs or working with a call-pipe callback function
in Pipes, or even as part of this software. The case would be in order as to skip to the
next generation of incoming requests if a duplicate comes to appear. This would be adequate
as a load-balancer.

An acceptable form is this:

    https://www.localhost.com/?session-guest123=isdfh2892m20&site=foo.bar&site=red.com&siteJ2=blue.com&key=variable

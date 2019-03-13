# SaaS on PHP
This is a SaaS proprietary git.

Using this with the free software, swatchphp/Pipes, is recommended but not required.

-------
Just send a query request in either POST or GET in order to start this up.
You must send at least one parameter with a name that starts with "site"

All preg_match("/site/") variables will be sent to. You may send as many as you wish.
If you wish to, you can send them in an array format.

An acceptable form is this:

    https://www.localhost.com/?site=foo.bar&site=bar.foo&site1=red.com&siteJ2=blue.com&key=variable

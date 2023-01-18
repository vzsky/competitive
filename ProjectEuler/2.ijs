NB. 32 is searched before and injected in, since f32 is the greatest lt 4mil
echo 1&{ (({:,(1&{+(0=2|{:)*{:)),({.+{:))^:32 ] 1 0 1
NB.  1&{                                                take first
NB.        {:, 1&{+(0=2|{:)*{:  , {.+{:                 one iteration
NB.                                      ^:32           do 32 iteration
NB.                                             1 0 1   starting config
NB.        {:                                           last element
NB.            1&{                                      middle element
NB.                 0=2|{:                              last is even
NB.                (0=2|{:)*{:                          last if last is even
NB.                               {.+{:                 sum of first and last

exit''
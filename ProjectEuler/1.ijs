a =: i.1000     NB. all number from zero to 999
b =: 0=3|a      NB. bitmask of if 3 divides
c =: 0=5|a      NB. bitmask of if 5 divides
d =: b>.c       NB. bitmask of if 3 or 5 divides
e =: d # a      NB. filtered list 
f =: +/e        NB. sum of all in the list

NB. which then combines into the following

+/((0=3|i.1000)>.(0=5|i.1000))#i.1000

NB. which then optimizes (golf) to the followings.

+/(((0=3|]) >. (0=5|])) # ]) i.1000

+/(>./@(0=3 5|/[)#]) i.1000 NB. which is hard to read for non

+/((0=3&|<.5&|)#]) i.1000

exit''


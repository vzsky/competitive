tri =: 2%~(*(1+]))
pen =: 2%~(*(1-~3*]))
hex =: *(1-~2*])

tp  =: ((tri e. pen) # ])
tph =: ((tri@:tp e. hex) # tp)

echo tri {: tph i.300000x

exit''
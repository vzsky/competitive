sol =: ((*:@:(+/))-(+/@:*:)) 

NB. *:@:(+/) composes square to sum (sum then square) with rank inf
NB. +/@:*:   composes sum to square (square then sum) with rank inf
NB. the rest is the hook form (sqsum - sumsq) of i.101

echo sol i.101
exit''
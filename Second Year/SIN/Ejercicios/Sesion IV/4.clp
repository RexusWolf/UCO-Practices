(deffacts hechos
  (vector v1 9 8  3 2 1 1 4 2 2 1 3 )
   (vector v2 9 8 3 1 2 1 1 4 2 2 1 3 1 2 3 4)
 )

(defrule regla

?dh <-	(vector $? 3 $?enMedio&:(oddp (length$ $?enMedio)) 4 $?)
	=>
	(printout t  ?dh crlf)
)

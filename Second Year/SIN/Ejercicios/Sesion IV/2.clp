(deffacts hechos
  (datos 2 34 23 1)
  (datos 2 34 23 3)
  
)

(defrule regla 
?dh<-	(datos ?x&:(numberp ?x)&:(evenp ?x) $? ?y&:(<= ?x ?y)) 
	=> 
	(printout t ?dh "   " ?x crlf)
) 


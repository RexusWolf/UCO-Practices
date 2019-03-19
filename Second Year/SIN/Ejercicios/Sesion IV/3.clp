(deffacts hechos
  (datos hola 1 3 nuevo 1 adios))
 )

(defrule regla
	?h <- (datos $?cabeza 1 $?cola)
	=>
	(retract ?h)
	(assert (datos $?cabeza $?cola))
)

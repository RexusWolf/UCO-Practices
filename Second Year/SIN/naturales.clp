; Presentar por pantalla los diez primeros números naturales

(deffacts h1 ;Constructor de hechos
  (n 0) ; Hecho ordenado
  )

(defrule r1
?f<-(n  ?x) ; Elemento condicional patrón (ECP)
            ; A la variable ?x se le ligará valores de los hechos que emparejen
            ; A la variable ?f se le liga la dirección de hecho con el que 
            ; empareje el ECP
            
(test (< ?x 10)); Elemento condicional test
=>
(printout t "n= " ?x crlf) ;Acción de imprimir 
(assert (n (+ ?x 1))); Afirmación de un hecho nuevo (n resultado-de-la-suma)
;(retract ?f) ;Elimina el hecho cuya dirección está en la variable ?f
)


(deffacts h1 ;Constructor de hechos
  (n 0) ; Hecho ordenado
  (suma 0)
  )

(defrule r1
?f1<-(n  ?x) ; Elemento condicional patrón (ECP)
            ; A la variable ?x se le ligará valores de los hechos que emparejen
            ; A la variable ?f se le liga la dirección de hecho con el que 
            ; empareje el ECP
?f2<-(suma ?s)
(test (< ?x 7)); Elemento condicional test

=>
(printout t "n= " ?x crlf) ;Acción de imprimir 
(assert (n (+ ?x 1))); Afirmación de un hecho nuevo (n resultado-de-la-suma)
(retract ?f1) ;Elimina el hecho cuya dirección está en la variable ?f1
(retract ?f2)
(assert (suma (+ ?s ?x)))
)



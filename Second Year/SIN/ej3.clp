(deffacts h1
  (dato 3)
  (dato 6)
  (dato 9)
)
  (defrule r1
    (dato ?x) ; Antecedente
  =>
    (assert( resultado(* ?x 2) )) ; Consecuente
)

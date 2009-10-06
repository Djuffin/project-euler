(define (print-num x)
  (newline)
  (print x))

(define (factorize x min-factor)
   (cond 
     ((or (= x 0)(= x 1)) ())
     ((= (remainder x min-factor) 0) (print-num min-factor) (factorize (/ x min-factor) min-factor))
     (else (factorize x (+ min-factor 1))))) 
     
(factorize 600851475143 2)
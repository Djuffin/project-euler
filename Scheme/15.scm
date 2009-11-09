(define (fact n)
  (if (= n 0) 1 (* n (fact (- n 1))))) 

(define (solve n) (/ (fact (* n 2)) (* (fact n) (fact n))))
(solve 20)



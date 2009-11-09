(define (fold f x list)
  (if (null? list)
      x
      (fold f (f x (car list)) (cdr list))))

(define (sum list)
  (fold + 0 list))

(define (get-digits n)
  (if (= n 0) 
      ()
      (cons (remainder n 10) (get-digits (quotient n 10)))))

(define n (expt 2 1000))
(sum (get-digits n))
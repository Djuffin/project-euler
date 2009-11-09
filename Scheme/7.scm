(define (dividable? primes x)
  (if (or (null? primes) (> (car primes) (sqrt x)))
      #f
      (if (= (remainder x (car primes)) 0)
          #t          
          (dividable? (cdr primes) x))))

(define (find-primes primes n x)
  (if (dividable? primes x)
      (find-primes primes n (+ x 1))
      (let ((new-primes (append primes (list x))))
        (print (length new-primes)) (print " - ") (print x) (newline)
        (if (= (length new-primes) n)
            (car (reverse new-primes))
            (find-primes new-primes n (+ x 1)) ))))
                   
(find-primes '(2) 10001 3)
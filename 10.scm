
(define N 2000000)

(define sieve (make-vector (+ N 1) #t))

(define (fill start step)
      (vector-set! sieve start #f)
      (if (<= (+ step start)  N )
          (fill (+ step start) step) 
          () ))

(define (find-prime start)
  (define (iter n)
    (if (>= n N) 
        () 
        (if (vector-ref sieve n) 
          n
          (iter (+ n 1)))))
  (iter start))

(define (find-primes)
  (define (iter start primes)      
    (let ((prime (find-prime start)))
      (cond 
          ((null? prime)  primes)
          (else (fill prime prime)  (iter prime (cons prime primes) )))))
  (iter 2 ()))

(fill 0 N)
(fill 1 N)

      
(define (fold f x list)
  (if (null? list)
      x
      (fold f (f x (car list)) (cdr list))))

(define (sum list)
  (fold + 0 list))
        
(sum (find-primes))
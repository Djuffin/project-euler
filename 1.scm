(define (make-test-by n)
  (lambda (x) (= (remainder x n) 0)))

(define div-by-3 (make-test-by 3))
(define div-by-5 (make-test-by 5))

(define div-by-3-or-5 
  (lambda (x) (or (div-by-3 x) (div-by-5 x))))

(define (sum-if first last filter)
  (define (iter x acc)
    (if (= x last)
        acc
        (iter (+ x 1) (if (filter x) (+ acc x) acc))))
  (iter first 0))

(define (task up-bound) (sum-if 1 up-bound div-by-3-or-5))
(print (task 1000))
      

(define (create-fib-generator a b)
  (lambda () (list (+ a b) (create-fib-generator b (+ a b)))))
                   
(define (even? x)
  (= (remainder x 2) 0))

(define (fib-sum filter max-n)
  (define (iter generator acc)
    (let* ((gen-result (generator))
          (next (car gen-result))
          (new-generator (car (cdr gen-result)))
          (acc-inc (if (filter next) next 0)))
      (if (> next max-n)
          acc
          (iter new-generator (+ acc acc-inc)))))
  (iter (create-fib-generator 0 1) 0))
          
(define (task n) (fib-sum even? n))
(task 4000000)



        
    
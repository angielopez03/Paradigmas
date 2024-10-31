globals [
  epoch-error   ;; average error in this epoch
  perceptron    ;; a single output-node
  input-node-1  ;; keep the input nodes in globals so we can refer
  input-node-2  ;; to them directly and distinctly
]

;; A perceptron is modeled by input-node and bias-node agents
;; connected to an output-node agent.

;; Connections from input nodes to output nodes
;; in a perceptron.
links-own [ weight ]

;; all nodes an activation
;; input nodes have a value of 1 or -1
;; bias-nodes are always 1
turtles-own [activation]

breed [ input-nodes input-node ]

;; bias nodes are input-nodes whose activation
;; is always 1.
breed [ bias-nodes bias-node ]

;; output nodes compute the weighted some of their
;; inputs and then set their activation to 1 if
;; the sum is greater than their threshold.  An
;; output node can also be the input-node for another
;; perceptron.
breed [ output-nodes output-node ]
output-nodes-own [threshold]

;;
;; Setup Procedures
;;

to setup
  clear-all

  ;; set our background to something more viewable than black
  ask patches [ set pcolor grey ]

  set-default-shape input-nodes "circle"
  set-default-shape bias-nodes "bias-node"
  set-default-shape output-nodes "output-node"

  create-output-nodes 1 [
    set activation random-activation
    set xcor 6
    set size 2
    set threshold 0
    set perceptron self
  ]

  create-bias-nodes 1 [
    set activation 1
    setxy 3 7
    set size 1.5
    my-create-link-to perceptron

  ]

  create-input-nodes 1 [
    setup-input-node
    setxy -6 5
    set input-node-1 self
  ]

  create-input-nodes 1 [
    setup-input-node
    setxy -6 0
    set input-node-2 self
  ]

  ask perceptron [ compute-activation ]
  reset-ticks
end

to setup-input-node
    set activation random-activation
    set size 1.5
    my-create-link-to perceptron
end

;; links an input or bias node to an output node
to my-create-link-to [ anode ] ;; input or bias node procedure
  create-link-to anode [
    set color red + 1
    ;; links start with a random weight
    set weight random-float 0.1 - 0.05
    set shape "small-arrow-shape"

  ]
end

;;
;; Runtime Procedures
;;

;; train sets the input nodes to a random input
;; it then computes the output
;; it determines the correct answer and back propagates the weight changes
to train ;; observer procedure
  set epoch-error 0
  repeat examples-per-epoch
  [
    ;; set the input nodes randomly
    ask input-nodes
      [ set activation random-activation ]

    ;; distribute error
    ask perceptron [
      compute-activation
      update-weights target-answer
      recolor
    ]
  ]

  ;; plot stats
  set epoch-error epoch-error / examples-per-epoch
  set epoch-error epoch-error * 0.5
  tick
  plot-error
  plot-learned-line
end

;; compute activation by summing the inputs * weights \
;; and run through sign function which determines whether
;; the computed value is above or below the threshold
to compute-activation ;; output-node procedure
  set activation sign sum [ [activation] of end1 * weight ] of my-in-links
  recolor
end

to update-weights [ answer ] ;; output-node procedure
  let output-answer activation

  ;; calculate error for output nodes
  let output-error answer - output-answer

  ;; update the epoch-error
  set epoch-error epoch-error + (answer - sign output-answer) ^ 2

  ;; examine input output edges and set their new weight
  ;; increasing or decreasing it by a value determined by the learning-rate
  ask my-in-links [
    set weight weight + learning-rate * output-error * [activation] of end1
  ]
end

;; computes the sign function given an input value
to-report sign [input]  ;; output-node procedure
  ifelse input > threshold
  [ report 1 ]
  [ report -1 ]
end

to-report random-activation ;; observer procedure
  ifelse random 2 = 0
  [ report 1 ]
  [ report -1 ]
end

to-report target-answer ;; observer procedure
  let a [activation] of input-node-1 = 1
  let b [activation] of input-node-2 = 1
  report ifelse-value run-result (word "my-" target-function " a b") [1][-1]
end

to-report my-or [a b];; output-node procedure
  report (a or b)
end

to-report my-xor [a b] ;; output-node procedure
  report (a xor b)
end

to-report my-and [a b] ;; output-node procedure
  report (a and b)
end

to-report my-nor [a b] ;; output-node procedure
  report not (a or b)
end

to-report my-nand [a b] ;; output-node procedure
  report not (a and b)
end

;; test runs one instance and computes the output
to test ;; observer procedure
  ask input-node-1 [ set activation input-1 ]
  ask input-node-2 [ set activation input-2 ]

  ;; compute the correct answer
  let correct-answer target-answer

  ;; color the nodes
  ask perceptron [ compute-activation ]

  ;; compute the answer

  let output-answer [activation] of perceptron

  ;; output the result
  ifelse output-answer = correct-answer
  [
    user-message (word "Output: " output-answer "\nTarget: " correct-answer "\nCorrect Answer!")
  ]
  [
    user-message (word "Output: " output-answer "\nTarget: " correct-answer "\nIncorrect Answer!")
  ]
end


;; Sets the color of the perceptron's nodes appropriately
;; based on activation
to recolor ;; output, input, or bias node procedure
  ifelse activation = 1
    [ set color white ]
    [ set color black ]
  ask in-link-neighbors [ recolor ]

  resize-recolor-links
end

;; resize and recolor the edges
;; resize to indicate weight
;; recolor to indicate positive or negative
to resize-recolor-links
  ask links [
    ifelse show-weights?
    [ set label precision weight 4 ]
    [ set label "" ]
    set thickness 0.2 * abs weight
    ifelse weight > 0
      [ set color [ 255 0 0 196 ] ]   ; transparent red
      [ set color [ 0 0 255 196 ] ] ; transparent light blue
  ]
end

;;
;; Plotting Procedures
;;

;; plot the error from the training
to plot-error ;; observer procedure
  set-current-plot "Error vs. Epochs"
  plotxy ticks epoch-error
end

;; plot the decision line learned
to plot-learned-line ;; observer procedure
  set-current-plot "Rule Learned"
  clear-plot

  run word "plot-" target-function

  ;; cycle through all the x-values and plot the corresponding x-values
  let edge1 [out-link-to perceptron] of input-node-1
  let edge2 [out-link-to perceptron] of input-node-2

  foreach (range -2 3) [ x1 ->
    ;; calculate w0 (the bias weight)
    let w0 sum [[weight] of out-link-to perceptron] of bias-nodes

    ;; put it all together
    let x2 ( (- w0 - [weight] of edge1 * x1) / [weight] of edge2 )

    ;; plot x1, x2
    set-current-plot-pen "rule"
    plotxy x1 x2
  ]
end

to plot-or
  set-current-plot-pen "positives"
  plotxy -1 1
  plotxy 1 1
  plotxy 1 -1
  set-current-plot-pen "negatives"
  plotxy -1 -1
end

to plot-xor
  set-current-plot-pen "positives"
  plotxy -1 1
  plotxy 1 -1
  set-current-plot-pen "negatives"
  plotxy 1 1
  plotxy -1 -1
end

to plot-and
  set-current-plot-pen "positives"
  plotxy 1 1
  set-current-plot-pen "negatives"
  plotxy 1 -1
  plotxy -1 1
  plotxy -1 -1
end

to plot-nor
  set-current-plot-pen "positives"
  plotxy -1 -1
  set-current-plot-pen "negatives"
  plotxy 1 1
  plotxy 1 -1
  plotxy -1 1
end

to plot-nand
  set-current-plot-pen "positives"
  plotxy -1 -1
  plotxy 1 -1
  plotxy -1 1
  set-current-plot-pen "negatives"
  plotxy 1 1
end


; Copyright 2006 Uri Wilensky.
; See Info tab for full copyright and license.

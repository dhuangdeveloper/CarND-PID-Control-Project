# Parameter Optimization for the PID controller
The PID controller in the repo is set with a default parameter of `Kp=0.165`, `Ki=0.001`, and `Kd=1.358`. These parameters are obtained via a manual tuning following mostly the twiddle algorithm.


## Effects of the parameters
I have the following observations from tuning the controller. T
* The `Kp` parameter mainly controls how much the car responds to an error in the position. A larger Kp leads to a more "responsive" steering.
* The `Kd` parameter reduces overshoot in the response. A larger `Kd` leads to less overshoot if there is a overshoot. When the car travels a zig-zag pattern, increasing `Kp` would reduces the amoutn of zig-zag.
* The `Ki` parameter reduces long term drift. If `Ki` is zero, then the car tends to be a bit off-centered for a long time. If `Ki` is large, the car would quickly moves towards the edge.


## Optimization procedure
The optimization mostly follows the twiddle algorithm, except in the case of `Ki`, I use the intuition above to significantly reduces `Ki` from an intermediate value of 0.06 (which does not work) to 0.01 and then 0.001. The optimization procedure is described as follows:

* The error criterion used in the twiddle is defined as follows: If the car has not been able to finish the trip, then it is defined as (minus) the total number of calls to the PID controller before the car touches the shoulders of the road; If the car has finished the whole trip without getting stuck, we define the total criterion as the the average error during the trip until the car has reached the beginning of the bridge the second time.
* We initialize with 0, 0, 0 and use dPp=dPi=dPd=0.01
* We update the parameters following the twiddle procedure.

Below is a list of parameter settings (`[Kp, Ki, Kd]`) that had the **best** error before another parameter settings achieve a better one:
* `[0.1, 0, 0]`
* `[0.1, 0, 0.1]`
* `[0.1, 0, 0.21]`
* `[0.1, 0, 0.331]`
* `[0.1, 0, 0.464]`
* `[0.1, 0, 0.464]` which achieves a full trip
* `[0.1, 0, 0.61]`
* `[0.1, 0, 0.771]`
* `[0.1, 0.001, 0.771]` before this, `dPi` is approximately 0.059. When setting `Ki` to between 0.59 and 1, the car would very quickly go off the road. Therefore, I then decided to significatly reduces the value of `Ki`, first to 0.01 and then to 0.001.
* `[0.165, 0.001, 0.771]`
* `[0.165, 0.001, 0.948]`
* `[0.165, 0.001, 1.143]`

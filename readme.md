# Black-Scholes implied volatility calculator

## Build

`make build`
`./out`

## Test

`make test`
`./test`

## Implementation Details & Assumptions

Some built-in mathematical functions are reimplemented for the sake of learning. Namely:

- [Cumulative Density Function](./src/math.cpp#L5)
- [Standard Error Function](./src/math.cpp#L30)
- [Factorial](./src/math.cpp#L38)

### Initial estimate for IV

(Brenner, Subrahmanyam) [A Simple Formula to Compute the Implied Standard Deviation](https://www-jstor-org.ucc.idm.oclc.org/stable/4479152?seq=3)

### Root-solving

The code defaults to newton-raphson. However, in cases where convergence is impossible, brent's method is used as a fallback.

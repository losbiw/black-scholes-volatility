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

The code will fail for some values, as convergence is not always guaranteed when using

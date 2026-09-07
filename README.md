# Week 3 – Backtesting the Trading Strategy Using C++

## Internship
YuvaIntern Virtual Internship

## Project Title
Backtesting the Quantitative Trading Strategy

## Project Description

This project is part of Week 3 of my YuvaIntern Virtual Internship.

The objective of this project is to backtest the trading strategy developed during Week 2 using historical price data. The strategy combines Simple Moving Average (SMA) and Linear Regression to generate BUY, SELL, and HOLD signals.

The C++ program simulates trades using historical price data and evaluates the performance of the strategy.

## Strategy Used

The trading strategy uses two quantitative indicators:

### 1. Simple Moving Average

The Simple Moving Average calculates the average price over a fixed number of observations.

Formula:

SMA = Sum of Prices / Number of Observations

### 2. Linear Regression

Linear Regression is used to identify the direction of the price trend.

A positive slope indicates an upward trend.

A negative slope indicates a downward trend.

## Trading Rules

### BUY

A BUY signal is generated when:

- Current Price > Moving Average
- Regression Slope > 0

### SELL

A SELL signal is generated when:

- Current Price < Moving Average
- Regression Slope < 0

### HOLD

A HOLD signal is generated when the BUY or SELL conditions are not satisfied.

## Backtesting Methodology

The program performs the following steps:

1. Load historical price data.
2. Set the Moving Average window to 5 observations.
3. Calculate the Moving Average.
4. Calculate the Linear Regression slope.
5. Generate BUY, SELL, or HOLD signals.
6. Simulate buying and selling based on the signals.
7. Calculate profit or loss for each completed trade.
8. Calculate total trades.
9. Calculate winning and losing trades.
10. Calculate win rate and overall return.
11. Display the final backtesting results.

## Performance Metrics

The program calculates:

- Initial Balance
- Final Balance
- Total Trades
- Winning Trades
- Losing Trades
- Total Profit
- Total Loss
- Net Profit/Loss
- Win Rate
- Return Percentage

## Sample Historical Data

The project uses 30 sample historical price observations:

```text
100, 102, 101, 103, 105,
107, 106, 108, 110, 112,
111, 109, 107, 105, 103,
104, 106, 108, 111, 114,
116, 115, 117, 119, 121,
120, 118, 116, 114, 117

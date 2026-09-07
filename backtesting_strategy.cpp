#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Calculate Simple Moving Average
double calculateSMA(double prices[], int start, int window)
{
    double sum = 0;

    for (int i = start; i < start + window; i++)
    {
        sum += prices[i];
    }

    return sum / window;
}

// Calculate Linear Regression Slope
double calculateSlope(double prices[], int start, int window)
{
    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;

    for (int i = 0; i < window; i++)
    {
        double x = i + 1;
        double y = prices[start + i];

        sumX += x;
        sumY += y;
        sumXY += x * y;
        sumX2 += x * x;
    }

    double denominator =
        window * sumX2 - sumX * sumX;

    if (denominator == 0)
    {
        return 0;
    }

    return (window * sumXY - sumX * sumY) /
           denominator;
}

// Generate trading signal
string generateSignal(double currentPrice,
                      double movingAverage,
                      double slope)
{
    if (currentPrice > movingAverage && slope > 0)
    {
        return "BUY";
    }
    else if (currentPrice < movingAverage && slope < 0)
    {
        return "SELL";
    }
    else
    {
        return "HOLD";
    }
}

int main()
{
    const int n = 30;

    // Sample historical price data
    double prices[n] =
    {
        100, 102, 101, 103, 105,
        107, 106, 108, 110, 112,
        111, 109, 107, 105, 103,
        104, 106, 108, 111, 114,
        116, 115, 117, 119, 121,
        120, 118, 116, 114, 117
    };

    // Moving Average window
    int window = 5;

    // Initial trading balance
    double initialBalance = 10000;
    double balance = initialBalance;

    bool holding = false;
    double buyPrice = 0;

    int totalTrades = 0;
    int winningTrades = 0;
    int losingTrades = 0;

    double totalProfit = 0;
    double totalLoss = 0;

    cout << "============================================================\n";
    cout << "        WEEK 3 - TRADING STRATEGY BACKTESTING\n";
    cout << "============================================================\n";

    cout << "\nInitial Balance: Rs. "
         << fixed << setprecision(2)
         << initialBalance << endl;

    cout << "\n------------------------------------------------------------\n";

    cout << left
         << setw(8) << "Day"
         << setw(12) << "Price"
         << setw(15) << "Moving Avg"
         << setw(15) << "Slope"
         << setw(10) << "Signal"
         << endl;

    cout << "------------------------------------------------------------\n";

    // Perform backtesting
    for (int i = window - 1; i < n; i++)
    {
        double movingAverage =
            calculateSMA(
                prices,
                i - window + 1,
                window
            );

        double slope =
            calculateSlope(
                prices,
                i - window + 1,
                window
            );

        string signal =
            generateSignal(
                prices[i],
                movingAverage,
                slope
            );

        cout << left
             << setw(8) << i + 1
             << setw(12) << prices[i]
             << setw(15) << movingAverage
             << setw(15) << slope
             << setw(10) << signal
             << endl;

        // BUY signal
        if (signal == "BUY" && !holding)
        {
            holding = true;
            buyPrice = prices[i];

            cout << "        >>> BUY at Rs. "
                 << buyPrice << endl;
        }

        // SELL signal
        else if (signal == "SELL" && holding)
        {
            double profitLoss =
                prices[i] - buyPrice;

            totalTrades++;

            if (profitLoss > 0)
            {
                winningTrades++;
                totalProfit += profitLoss;
            }
            else
            {
                losingTrades++;
                totalLoss += profitLoss;
            }

            balance += profitLoss;

            cout << "        >>> SELL at Rs. "
                 << prices[i]
                 << " | P/L: Rs. "
                 << profitLoss
                 << endl;

            holding = false;
        }
    }

    // Close remaining position at final price
    if (holding)
    {
        double profitLoss =
            prices[n - 1] - buyPrice;

        totalTrades++;

        if (profitLoss > 0)
        {
            winningTrades++;
            totalProfit += profitLoss;
        }
        else
        {
            losingTrades++;
            totalLoss += profitLoss;
        }

        balance += profitLoss;

        cout << "\n        >>> Final SELL at Rs. "
             << prices[n - 1]
             << " | P/L: Rs. "
             << profitLoss
             << endl;
    }

    // Calculate final performance
    double netProfitLoss =
        balance - initialBalance;

    double winRate = 0;

    if (totalTrades > 0)
    {
        winRate =
            ((double)winningTrades / totalTrades) * 100;
    }

    double returnPercentage =
        (netProfitLoss / initialBalance) * 100;

    // Display final results
    cout << "\n============================================================\n";
    cout << "                 BACKTEST RESULTS\n";
    cout << "============================================================\n";

    cout << "Initial Balance       : Rs. "
         << initialBalance << endl;

    cout << "Final Balance         : Rs. "
         << balance << endl;

    cout << "Total Trades          : "
         << totalTrades << endl;

    cout << "Winning Trades        : "
         << winningTrades << endl;

    cout << "Losing Trades         : "
         << losingTrades << endl;

    cout << "Total Profit          : Rs. "
         << totalProfit << endl;

    cout << "Total Loss            : Rs. "
         << totalLoss << endl;

    cout << "Net Profit/Loss       : Rs. "
         << netProfitLoss << endl;

    cout << "Win Rate              : "
         << winRate << "%" << endl;

    cout << "Return                : "
         << returnPercentage << "%" << endl;

    cout << "============================================================\n";

    cout << "\nNote: This backtest is for educational purposes only.\n";
    cout << "Past or simulated performance does not guarantee future results.\n";

    return 0;
}

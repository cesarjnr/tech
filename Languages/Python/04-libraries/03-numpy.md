# NumPy

NumPy is a library for numerical operations in Python.

## Binomial Distribution

Sometimes you want to simulate a lot of different scenarios. It would be very expensive to run thousands of tests, but it's very cheap to generate thousands of results. <br />
Binomial distributions are very useful for modeling different types of data, from drug treatment effectiveness to stock price trends. <br />
Binomial events always have 2 possible outcomes, which we refer to as *success* and *failure*. The probability of a successful outcome is represented by the parameter `p`. For example, for the event of a coin toss using a fair coin, `p` would be `0.5`. <br />
There are lots of ways to do this. We could flip a coin a bunch of times and write down the results or we could use the `random.binomial()` method from the `numpy` library. <br />
To use the `random.binomial()` method, we have to tell it how many trials we want to simulate (`n`) and the probability of 'success' in a single trial (`p`), and how many experiments to run. <br />
In the example below, there was 1 flip per trial (n), the probability (p) of getting 'success' was .5 (the coin is fair), and we conducted the experiment 2,000 times (size).

```py
print(numpy.random.binomial(n = 1, p = 0.5, size=2000))
```

The output from our simulation is a list of 0's and 1's. This is the number of successes in each experiment. In this case, since we are simulating a single trial, `1` would mean the outcome of the trail was a success and `0` would mean the outcome was a failure. <br />
If we wanted to do 10 flips per experiment, the result would be a list of numbers from 0 to 10 representing the number of successes in each experiment.

```py
print(numpy.random.binomial(n=10, p=0.5, size=2000))
```
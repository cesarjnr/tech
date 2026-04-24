# csv

## Converting JSON to CSV

While JSON is a great universal format for data interchange, it might not be the ideal format in other aspects, such as readability. Instead, having the data in a tabular format (like a CSV) can make it much more human-readable and accessible. Therefore, being able to convert between file types is essential. <br />
There are several libraries in Python to work with different data formats. The built-in `csv` is one of them:

```py
import csv
```

Using the JSON data we get from Census API as an example, it's a list of lists in Python, where each inner list corresponds to a single row of data. To convert from JSON to CSV, we want to write each sublist as a comma-separated row of data to file. We can use the `writerows()` method from the `csv` library:

```py
r = requests.get('https://api.census.gov/data/2020/acs/acs5?get=NAME,B08303_001E,B08303_013E&for=county:*&in=state:36')

with open('census.csv', mode='w', newline='') as file:
  writer = csv.writer(file)
  writer.writerows(r.json())
```

We first make a variable and call it `file`. Then we use `open()` to open a file, since we are going to write that file, we open it with `mode='w'` for writing mode. The `newline=''` ensures that newlines are always interpreted correctly. <br />
Next, we use the `writer()` function from the `csv` library to make a writer object. We then use the `writerows()` method to write each row of data into comma-separated format.
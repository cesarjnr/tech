# requests

The requests library is a popular choice for working with HTTP in Python. <br />
Begin by importing the `requests` library with this command:

```py
import requests
```

Next, we can use the `get()` method to return the data from our desired URL:

```py
r = requests.get('https://api.census.gov/data/2020/acs/acs5?get=NAME,B08303_001E&for=state:*') 
```

The result is a **response object** and we stored it in a variable named `r`. <br />
We can look at that response data by using the `.text` attribute. The `text` attribute turns the data into a string. <br />
We can also use the `.json()` method that can automatically decode JSON data into the appropriate Python object. This is useful when working with JSON data, as in the case of the Census API, to have the data in a more intuitive data structure.

```py
# Access data as JSON string
print(r.text)
 
# Access decoded JSON data as Python object
print(r.json())
```
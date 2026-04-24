# pandas

`pandas` is a powerful library for data manipulation and analysis. <br />
We can start working with it by importing the library using the alias `pd`: 

```py
import pandas as pd
```

## Reading CSV Files

We can use the `read_csv()` method to read the CSV data into a DataFrame object:

```py
import pandas
 
census_df = pandas.read_csv("census.csv")
```

By default, the first row of the CSV file is read in as the header row. We can use the `.head()` method to preview the first few rows of the DataFrame. <br />

```py
# Preview DataFrame
print(census_df.head())
```

Sometimes columns have ambiguous or confusing names (like Census codes). We might also want to rename those columns. We can use the `.columns` attribute to rename the column headings if needed:

```py 
# Rename DataFrame columns
census_df.columns = ['name', 'total_commuters', 'state']
```
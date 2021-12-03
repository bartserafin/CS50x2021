# in SQLite there are 5 data types:
    # BLOB - binary large object
    # INTEGER - int
    # NUMERIC - number like, data, year, time
    # REAL - float
    # TEXT - string

## NOT NULL - cannot be empty
## UNIQUE - values must be unique, cant be repeated

## PRIMARY KEY - a column in a table that uniquely identifies every row, an id
## FOREIGN KEY - can call another key, so let's say show_id will refer back to id
## See image MAP
    ## Say the show "The Office" has id 1.
    ## "The Office" will have 3 genres, each will have show_id of 1
    ## "1" - Comedy
    ## "1" - Drama
    ## "1" - Romance



# Python code for iterating through .csv and create two tables as in the MAP image

import csv

# You may need 3rd party software to link pyhton and SQL, but IDE has a buil-in library for that
from cs50 import SQL

# create an empty file, it opens and closes it
open("shows.db", "w").close()

# open empty files as SQLite database
db = SQL("sqlite:///shows.db")

# combine python and SQL; pass argument into SQL terminal window
# create TABLE shows, with columns id, title, using PRIMARY KEY
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")

# create TABLE genres, with columns show_id, genre, using FOREIGN KEY which will get values from shows(id) - the PRIMARY KEY)
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")


# load .csv file into the SQL database
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()

        #                   into placeholder "?" pluck the "title"
        id = db.execute("INSERT INTO shows (title) VALUEs(?)", title)
        
        # remember that in a .csv file, our genres are a list for each show: [Comdey, Drama, Muscial]
        # so for each element in a row we will .split(", ") the list, after every ",<space>"
        # This why we can pluck each genre int our SQL table
        for genre in row["genres"].split(", "):
            db.execute("INSERT INTO genres (show_id, genre) VALUES(?, ?)", id, genre)
            
# With this set up, let's try to answet some questions by enquirng our database

    # what are the comedy shows?
        # Get id's all shows with Comedy genre
        # sqlite> SELECT show_id FROM genres WHERE genre = "Comedy";
        # we can nest queries
            # SELECT DISTINCT(title) FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Comedy");
            
    # find all genres that are assigned to show "The Office"
        # Get "The Office" id's
        # SELECT id FROM shows WHERE title = "THE OFFICE";
        # nest sub-query
            # SELECT DISTINCT(genre) FROM genres WHERE show_id IN (SELECT id FROM shows WHERE title = "THE OFFICE") ORDER BY genre;





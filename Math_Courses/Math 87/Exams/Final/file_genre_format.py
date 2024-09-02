import csv

#Reads through the influence data to find each artist and genre
def parse_genre(filename):
    data = set() #Use a set to avoid duplicates
    line_count = 0
    with open(filename) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                data.add((row[0], row[2])) 
                data.add((row[4], row[6]))
    return data

data = parse_genre("influence_data.csv")

#creates list where each element is a line from the file
lines = []
with open("artist_test.txt", "r") as f:
    for row in f:
        words = row.split(",")
        lines.append(row.rstrip())


#Appends genre to each item in the list
count = 0
for line in lines:
    words = line.split(",")
    artist_id = words[1] #Gets artist of word
    for t in data: #Loops through set
        if t[0] == artist_id: #If they match, which happens once
            genre = t[1] #Assign genre
            line_temp = lines[count]
            lines[count] = line_temp + "," + genre
    count = count + 1

#Sends list to file. When done, you must change the file type to csv, and add 
#genre to end of first row. I Couldn't write directly to .csv file without 
#causing issues. If running multiple times, change "x" to "a" to avoid crash.
with open("artist_genre.txt", "x") as f:
    for l in lines:
        f.write(l + "\n")

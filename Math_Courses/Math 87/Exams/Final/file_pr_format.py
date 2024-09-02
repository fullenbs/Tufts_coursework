import csv

#Looks through the csv file and gets all artist ids associated w/ Pop/Rock
def parse_pr(filename):
    data = set() #Want set to avoid duplicates so use set
    line_count = 0
    with open(filename) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:
                if row[2] == 'Pop/Rock' or row[6] == 'Pop/Rock':
                    if row[2] == 'Pop/Rock':
                        data.add((row[0], row[3]))
                    if row[6] == 'Pop/Rock':
                        data.add((row[4], row[7]))
    return data
data_pop = parse_pr("influence_data.csv")

#Reads in the artist_text.txt and passes each line to file
lines = []
with open("artist_test.txt", "r") as f:
    for row in f:
        lines.append(row.rstrip())

#Appends year of start to each Pop/Rock artist
count  = 0
for line in lines:
    word = line.split(",")
    artist_id = word[1]
    for t in data_pop:
        if t[0] == artist_id:
            year = t[1]
            line_temp = lines[count]
            lines[count] = line_temp + "," + year
    count = count + 1

#For all artists, if they aren't pop/rock sets updated string to empty
count = 0
for line in lines:
    word = line.split(",")
    try:
        t = word[16]
    except:
        lines[count] = ''
    count = count + 1

#Sends to file, due to nature of .csv files, send as .txt, then can do the
#following prepping: From full_music_data.csv, copy first row w/ column 
#names, then add ".year". Then, convert the file type to .csv
with open("pr_data.txt", 'x') as f:
    for l in lines:
        if l != '':
            f.write(l + "\n")

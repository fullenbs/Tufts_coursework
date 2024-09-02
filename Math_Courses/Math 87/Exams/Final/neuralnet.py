import csv
import numpy as np
import tensorflow as tf
from sklearn.model_selection import train_test_split

#parse_csv times three
def parse_csv(filename, genre):
    data = np.array([])
    line_count = 0
    with open(filename) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count = line_count + 1
            else:
                try: 
                    if (row[16] == genre):
                        row_vec = np.array([])
                        sub_count = 0
                        for t in row: 
                            try:
                                if sub_count != 1:
                                    t = float(t)
                                    row_vec = np.append(row_vec, t)
                            except:
                                count = 0
                            sub_count = sub_count + 1
                        if line_count == 1:
                            data = np.hstack((data, row_vec))
                            line_count = -1
                        else:
                            data = np.vstack((data, row_vec))
                except:
                    count = 0
    return data

#Parses data from file_pr_format.csv to get information
def parse_pr(filename, decade):
    data = np.array([])
    line_count = 0
    with open(filename) as csv_file: #Opens CSV file
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            if line_count == 0:
                line_count += 1
            else:  #First line has genres
                try:
                    if (int(row[16]) == decade):
                        row_vec = np.array([])
                        sub_count = 0
                        for t in row:
                            try: #Add if not decade, ID, or name
                                t = float(t) 
                                if sub_count != 15 and sub_count != 1:
                                    row_vec = np.append(row_vec, t)
                            except:
                                count = 0
                            sub_count = sub_count + 1
                        if line_count == 1: #If on first line need hstack
                            data = np.hstack((data, row_vec))
                            line_count = 3
                        else: #Can use vstack from here on out
                            data = np.vstack((data, row_vec))
                except:
                    count = 0
    return data


#Model used 
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(14, 1)),
  tf.keras.layers.Dense(64, activation='softmax'),
  tf.keras.layers.Dropout(0.25),
  tf.keras.layers.Dense(20)
])


#This gets the data from each genre and then combines them all into a 
#single matrix. There might've been a more line efficient way to do it, but I 
#couldn't think of it. The number in each comment corresponds to the classification 
#score. 
data = np.array([])
latin_data = parse_csv('artist_genre.csv', 'Latin') #18
data = latin_data
elec_data = parse_csv('artist_genre.csv', 'Electronic') #17
data = np.vstack((data, elec_data))
rb_data = parse_csv('artist_genre.csv', 'R&B;') #16
data = np.vstack((data, rb_data))
rel_data = parse_csv('artist_genre.csv', 'Religious') #15
data = np.vstack((data, rel_data))
blue_data = parse_csv('artist_genre.csv', 'Blues') #14
data = np.vstack((data, blue_data))
stage_data = parse_csv('artist_genre.csv', 'Stage & Screen') #13
data = np.vstack((data, stage_data))
jazz_data = parse_csv('artist_genre.csv', 'Jazz') #12
data = np.vstack((data, jazz_data))
voc_data = parse_csv('artist_genre.csv', 'Vocal') #11
data = np.vstack((data, voc_data))
class_data = parse_csv('artist_genre.csv', 'Classical') #10
data = np.vstack((data, class_data))
regg_data = parse_csv('artist_genre.csv', 'Reggae') #9
data = np.vstack((data, regg_data))
int_data = parse_csv('artist_genre.csv', 'International') #8
data = np.vstack((data, int_data))
folk_data = parse_csv('artist_genre.csv', 'Folk') #7
data = np.vstack((data, folk_data))
pr_1950_data = parse_pr('pr_data.csv', 1950) #6
data = np.vstack((data, pr_1950_data))
pr_1960_data = parse_pr('pr_data.csv', 1960) #5
data = np.vstack((data, pr_1960_data))
pr_1970_data = parse_pr('pr_data.csv', 1970) #4
data = np.vstack((data, pr_1970_data))
pr_1980_data = parse_pr('pr_data.csv', 1980) #3
data = np.vstack((data, pr_1980_data))
pr_1990_data = parse_pr('pr_data.csv', 1990) #2
data = np.vstack((data, pr_1990_data))
pr_2000_data = parse_pr('pr_data.csv', 2000) #1
data = np.vstack((data, pr_2000_data))
pr_2010_data = parse_pr('pr_data.csv', 2010) #0
data = np.vstack((data, pr_2010_data))

#Loss function
loss_fn = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)
model.compile(optimizer='adam', loss=loss_fn, metrics=['accuracy'])



res_mat = np.zeros(len(data))

# This is really messy, but it sets up the vector matching each data to the 
# classification score listed above. I couldn't think of a more line efficient way
# to code this. 
for i in range(0, len(latin_data) + 1):
    if i < len(latin_data):
        res_mat[i] = 18
    elif i < len(latin_data) + len(elec_data):
        res_mat[i] = 17
    elif i < len(latin_data) + len(elec_data) + len(rb_data):
        res_mat[i] = 16
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data):
        res_mat[i] = 15
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) \
            + len(blue_data):
            res_mat[i] = 14
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data):
            res_mat[i] = 13
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data):
            res_mat[i] = 12
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data):
            res_mat[i] = 11
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data):
            res_mat[i] = 10
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data):
            res_mat[i] = 9
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data):
            res_mat[i] = 8
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data):
            res_mat[i] = 7
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data):
            res_mat[i] = 6
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data) + len(pr_1960_data):
            res_mat[i] = 5
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data) + len(pr_1960_data) + len(pr_1970_data):
            res_mat[i] = 4
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data) + len(pr_1960_data) + len(pr_1970_data) + \
            len(pr_1980_data):
            res_mat[i] = 3
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data) + len(pr_1960_data) + len(pr_1970_data) + \
            len(pr_1980_data) + len(pr_1990_data):
            res_mat[i] = 2
    elif i < len(latin_data) + len(elec_data) + len(rb_data) + len(rel_data) + \
            len(blue_data) + len(stage_data) + len(jazz_data) + len(voc_data) + \
            len(class_data) + len(regg_data) + len(int_data) + len(folk_data) + \
            + len(pr_1950_data) + len(pr_1960_data) + len(pr_1970_data) + \
            len(pr_1980_data) + len(pr_1990_data) + len(pr_2000_data):
            res_mat[i] = 1

#Gets training and testing data set, using sklearn library 
x_train, x_test, y_train, y_test = train_test_split(data, res_mat)
model.fit(x_train, y_train, epochs = 5)
print("\nTesting data results:")
model.evaluate(x_test, y_test, verbose = 2)


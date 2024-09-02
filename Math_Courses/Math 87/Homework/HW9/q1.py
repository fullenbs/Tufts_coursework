import os
#from tkinter import Y
from matplotlib import pyplot as plt
from os.path import join
import matplotlib.pyplot as plt
from IPython.display import Image, display
import numpy as np
import tensorflow as tf
from tensorflow.keras.applications.resnet50 import preprocess_input
from tensorflow.keras.applications import resnet50
from tensorflow.keras.preprocessing.image import load_img, img_to_array

#FUNCTION PROVIDED
image_size = 224
def read_and_prep_images(img_paths, img_height=image_size, img_width=image_size):
    imgs = [load_img(img_path, target_size = (img_height,img_width)) 
            for img_path in img_paths]
    img_array = np.array([img_to_array(img) for img in imgs])
    output = preprocess_input(img_array)
    return(output)



#Directory paths on my local machine
train_hotdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/train/hot_dog'
train_notdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/train/not_hot_dog'

dog_filenames = os.listdir(train_hotdog_dir)
notdog_filenames = os.listdir(train_notdog_dir)

#Creates the two functions creating the complete paths
hot_dog_paths = hot_dog_paths = [join(train_hotdog_dir,filename) for filename in dog_filenames]
not_hot_dog_paths = [join(train_notdog_dir,filename) for filename in notdog_filenames]

#Converts each image into an array
output_dogs = read_and_prep_images(hot_dog_paths, image_size, image_size)
output_not_dogs = read_and_prep_images(not_hot_dog_paths, image_size, image_size)

dogs = np.ones(len(output_dogs))
notdogs = np.zeros(len(output_not_dogs))


def pair_data(list1,list2):
    A=[]
    for i in np.arange(len(list1)):
        A.append([list1[i],list2[i]])
    return A

out = pair_data(output_dogs, dogs)
out_2 = pair_data(output_not_dogs, notdogs)

hotdog_array = np.asarray(out)
notdog_array = np.asarray(out_2)
data = np.concatenate(out, out_2)
pics = np.concatenate(hotdog_array, notdog_array)
scores = np.concatenate(dogs, notdogs)


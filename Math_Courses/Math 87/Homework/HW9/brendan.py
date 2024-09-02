from asyncore import read
import os
from os.path import join
import tensorflow as tf
import matplotlib.pyplot as plt
from IPython.display import Image, display
import numpy as np
from tensorflow.keras.applications.resnet50 import preprocess_input
from tensorflow.keras.applications import ResNet50
from tensorflow.keras.preprocessing.image import load_img, img_to_array

train_hotdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/train/hot_dog'
train_notdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/train/not_hot_dog'

test_hotdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/test/hot_dog'
test_notdog_dir = '/Users/scott/Desktop/Math_Courses/Math87/HW9/hotdogs/test/not_hot_dog'


image_size = 224
def read_and_prep_images(img_paths, img_height=image_size, img_width=image_size):
    imgs = [load_img(img_path, target_size=(img_height, img_width)) for img_path in img_paths]
    img_array = np.array([img_to_array(img) for img in imgs])
    output = preprocess_input(img_array)
    print(output.shape)
    return(output)

def pair_data(list1,list2):
    A=[]
    for i in np.arange(len(list1)):
        A.append([list1[i],list2[i]])
    return A

hot_dog_arr=os.listdir(train_hotdog_dir)
not_hot_dog_arr=os.listdir(train_notdog_dir)
hot_dog_paths = [join(train_hotdog_dir,filename) for filename in hot_dog_arr]
not_hot_dog_paths = [join(train_notdog_dir,filename) for filename in not_hot_dog_arr]

test_hotdog_arr = os.listdir(test_hotdog_dir)
test_notdog_arr = os.listdir(test_notdog_dir)
test_hotdog_paths = [join(test_hotdog_dir,filename) for filename in test_hotdog_arr]
test_not_hotdog_paths = [join(test_notdog_dir,filename) for filename in test_notdog_arr]




model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(224, 224, 3)),
  tf.keras.layers.Dense(10, activation='relu'),
  tf.keras.layers.Dropout(0.1),
  tf.keras.layers.Dense(500)
])

#loss function
loss_fn = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)

#compiles
model.compile(optimizer='adam',
              loss=loss_fn,
              metrics=['accuracy'])

#preps images and stores them both into arrays
dog_arr=read_and_prep_images(hot_dog_paths)
not_arr=read_and_prep_images(not_hot_dog_paths)

#gets a vector of all ones and zeroes
are_dogs=np.ones(len(dog_arr))
not_dogs=np.zeros(len(not_arr))

#pairs the data properly
hotdogs_train=pair_data(dog_arr,are_dogs)
notdogs_train=pair_data(not_arr,not_dogs)


###############################################################################

test_dog_arr = read_and_prep_images(test_hotdog_paths)
test_notdog_arr = read_and_prep_images(test_not_hotdog_paths)

test_are_dogs=np.ones(len(test_dog_arr))
test_not_dogs=np.zeros(len(test_notdog_arr))

hotdogs_test = pair_data(test_dog_arr, test_are_dogs)
notdogs_test = pair_data(test_notdog_arr, test_not_dogs)
###############################################################################

#conducts the fit
test_dog_arr = np.asarray(test_dog_arr)
test_are_dogs = np.asarray(test_are_dogs)
print(dog_arr)
model.fit(dog_arr, are_dogs, epochs = 5)
model.evaluate(test_dog_arr, test_are_dogs, verbose = 2)
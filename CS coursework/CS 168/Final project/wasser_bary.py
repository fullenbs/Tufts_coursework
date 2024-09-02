

import ot
import numpy as np
import matplotlib.pyplot as plt

from keras.datasets import mnist

#Link to GitHub repo this comes from is in the README
from barycenters.utils import create_digits_image
from barycenters import euclidean
from barycenters import wasserstein
from barycenters import kullback_leibler
import time

digit = 5
grid_size = 64
n_digits = 20
original_size = 20

#Loads images
(train_x, train_y), (test_x, test_y) = mnist.load_data()
images = train_x
labels = train_y

#Normalizes to be distributions
images = images.astype(float).reshape(-1, 28, 28)/255

#Processes images
B = create_digits_image(images, labels, digit=4,
                        grid_size=grid_size,
                        n_digits=n_digits,
                        original_size=original_size,
                        is_distribution=True)
#Displays original pictures of all of them
plt.imshow(sum(B).reshape(64, 64), cmap='gray')
plt.show()
plt.savefig('original_img')
plt.axis('off')

#Creates cost matrix
M = np.zeros([grid_size ** 2, grid_size ** 2])
for i in range(grid_size):
    for j in range(grid_size):
        for k in range(grid_size):
            for l in range(grid_size):
                k1 = i * grid_size + j
                k2 = k * grid_size + l
                M[k1, k2] = (j - l) ** 2 + (i - k) ** 2

#Finds Euclidean average and the Wasserstein baryceter
a_euclidean = euclidean.fixed_support_barycenter(B)
a_wasserstein = wasserstein.fixed_support_barycenter(B, M, verbose=True)

#Displays result
fig, axes = plt.subplots(1, 2, figsize=(12, 4))

axes[0].imshow(a_euclidean.reshape(grid_size, grid_size), cmap='gray')
axes[0].axis('off')
axes[1].imshow(a_wasserstein.reshape(grid_size, grid_size), cmap='gray')
axes[1].axis('off')

plt.show()
plt.savefig('result.png')
plt.clf()
plt.show()
print('total run time: ', time.time())

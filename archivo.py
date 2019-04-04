import numpy as np
import matplotlib.pyplot as plt

datos= np.genfromtxt("data.txt")
plt.hist(datos,bins=100)
plt.savefig("histograma.pdf")
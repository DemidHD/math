from mpl_toolkits.mplot3d import Axes3D

fig = plt.gigure()
ax = fig.addsubplot(111, projection="3d")

x = np.linspace(0, 1, 100)
z = np.linspace(0, 3, 100)
x, z = np.meshgrid(x, z)

y = np.sqrt(2*x)
ax.plot_surface(x, y, z, colors='r')
ax.plot_surface(x, -y, z, colors='r')

ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
pit.show()

import matplotlib.pyplot as plt
import sys

if len(sys.argv) != 3:
    print("Usage: python plot_hull.py <input_file> <hull_file>")
    sys.exit(1)

input_file = sys.argv[1]
hull_file = sys.argv[2]

# Read all points from input file
all_points = []
with open(input_file, 'r') as file:
    for line in file:
        x, y = map(int, line.split())
        all_points.append((x, y))
all_points = all_points[1:]
# Read hull points from hull file
hull_points = []
with open(hull_file, 'r') as file:
    for line in file:
        x, y = map(int, line.split())
        hull_points.append((x, y))

# Separate the x and y coordinates for all points
all_x_coords, all_y_coords = zip(*all_points)

# Separate the x and y coordinates for hull points
hull_x_coords, hull_y_coords = zip(*hull_points)

# Close the convex hull
hull_x_coords = list(hull_x_coords) + [hull_x_coords[0]]
hull_y_coords = list(hull_y_coords) + [hull_y_coords[0]]

# Plotting
plt.figure(figsize=(8, 6))

# Plot all points in red
plt.scatter(all_x_coords, all_y_coords, color='red', label='All Points')

# Plot convex hull in blue
plt.plot(hull_x_coords, hull_y_coords, 'b-', marker='o', label='Convex Hull Points')

# Title and labels
plt.title('Convex Hull')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.legend()

# Show plot
plt.show()
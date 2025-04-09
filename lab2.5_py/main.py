import tkinter as tk
import math
import random

n1, n2, n3, n4 = 4, 2, 3, 0
num_peaks = 10 + n3
width = 800
height = 800

random.seed(f"{n1}{n2}{n3}{n4}")

def directed_matrix():
    k = 1 - n3 * 0.02 - n4 * 0.005 - 0.25
    matrix = []
    for i in range(num_peaks):
        row = []
        for j in range(num_peaks):
            element = random.uniform(0, 2) * k
            element = 0 if element < 1 else 1
            row.append(element)
        matrix.append(row)
    return matrix

def undirected_matrix(directed_matrix):
    undir_matrix = [[0] * num_peaks for _ in range(num_peaks)]
    for i in range(num_peaks):
        for j in range(i, num_peaks):
            if directed_matrix[i][j] == 1 or directed_matrix[j][i] == 1:
                undir_matrix[i][j] = 1
                undir_matrix[j][i] = 1
    return undir_matrix

def print_matrix(matrix):
    for row in matrix:
        print(row)
    print()

def arrow(canvas, lx, ly, rx, ry):
    canvas.create_line(lx, ly, rx, ry, fill="gray", width=2)

    angle = math.atan2(ry - ly, rx - lx)
    arrow_length = 12
    angle1 = angle + math.radians(20)
    angle2 = angle - math.radians(20)

    lx2 = rx - arrow_length * math.cos(angle1)
    ly2 = ry - arrow_length * math.sin(angle1)
    rx2 = rx - arrow_length * math.cos(angle2)
    ry2 = ry - arrow_length * math.sin(angle2)

    canvas.create_line(rx, ry, lx2, ly2, fill="gray", width=2)
    canvas.create_line(rx, ry, rx2, ry2, fill="gray", width=2)

def initialize_window():
    root = tk.Tk()
    root.title("Lab 3 by Mariia Khorunzha IM-42")
    root.geometry(f"{int(width)}x{int(height)}")  # Размер окна
    canvas = tk.Canvas(root, width=width, height=height, bg="white")
    canvas.pack()
    return root, canvas

def draw_graph(canvas, matrix, directed=False):
    big_radius = 250
    center_x = width * 0.5
    center_y = height * 0.5

    nn = [str(i + 1) for i in range(num_peaks)]
    small_radius = 16

    positions = []
    for i in range(num_peaks):
        angle = 2 * math.pi * i / num_peaks
        x = center_x + big_radius * math.cos(angle)
        y = center_y + big_radius * math.sin(angle)
        positions.append((x, y))

        canvas.create_oval(x - small_radius, y - small_radius, x + small_radius, y + small_radius, outline="blue", width=2)
        canvas.create_text(x, y, text=nn[i], font=("Arial", 10, "bold"))

    def fix_len(x1, y1, x2, y2, radius):
        dx, dy = x2 - x1, y2 - y1
        length = math.sqrt(dx ** 2 + dy ** 2)
        if length == 0:
            return x1, y1, x2, y2
        scale = (length - radius) / length
        return x1 + dx * (1 - scale), y1 + dy * (1 - scale), x2 - dx * (1 - scale), y2 - dy * (1 - scale)

    for i in range(num_peaks):
        for j in range(num_peaks):
            if matrix[i][j]:

                x1, y1 = positions[i]
                x2, y2 = positions[j]

                if i == j:
                    angle = 2 * math.pi * i / num_peaks
                    loop_len = 50
                    spread_angle = math.radians(30)

                    x_start, y_start = x1 + math.cos(angle) * small_radius, y1 + math.sin(angle) * small_radius
                    x_first, y_first = x1 + math.cos(angle) * (small_radius + 15), y1 + math.sin(angle) * (
                                small_radius + 15)
                    x_mid, y_mid = x1 + math.cos(angle) * (small_radius + loop_len), y1 + math.sin(angle) * (
                                small_radius + loop_len)
                    x_end, y_end = x1 + math.cos(angle + spread_angle) * (small_radius + loop_len), y1 + math.sin(
                        angle + spread_angle) * (small_radius + loop_len)

                    for (x1, y1, x2, y2) in [(x_start, y_start, x_first, y_first), (x_first, y_first, x_mid, y_mid),
                                             (x_mid, y_mid, x_end, y_end)]:
                        canvas.create_line(x1, y1, x2, y2, fill="gray", width=2)
                    if directed:
                        arrow(canvas, x_end, y_end, x_start, y_start)
                    else:
                        canvas.create_line(x_end, y_end, x_start, y_start, fill="gray", width=2)
                else:
                    x1, y1, x2, y2 = fix_len(x1, y1, x2, y2, small_radius)
                    if directed:
                        arrow(canvas, x1, y1, x2, y2)
                    else:
                        canvas.create_line(x1, y1, x2, y2, fill="gray", width=2)

def main():
    root, canvas = initialize_window()

    matrix_dir = directed_matrix()
    print("The directed graph matrix has form:")
    print_matrix(matrix_dir)

    matrix_undir = undirected_matrix(matrix_dir)
    print("The undirected graph matrix has form:")
    print_matrix(matrix_undir)

    # draw_graph(canvas, matrix_dir, directed=True)
    draw_graph(canvas, matrix_undir, directed=False)

    root.mainloop()

if __name__ == "__main__":
    main()

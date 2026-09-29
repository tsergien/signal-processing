
import csv
import random
import math

with open("data/input.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["sample", "value"])

    for i in range(100):
        clean = math.sin(i * 0.05)
        noise = random.uniform(-0.04, 0.04)

        writer.writerow([i, clean + noise])

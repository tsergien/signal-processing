import pandas as pd
import matplotlib.pyplot as plt

input_data = pd.read_csv("data/input.csv")
output_data_fir = pd.read_csv("data/output_fir.csv")
output_data_iir = pd.read_csv("data/output_iir.csv")


fig, axes = plt.subplots(1, 2, figsize=(15, 4))

axes[0].plot(input_data["sample"], input_data["value"], label="Input", color='grey', alpha=0.8)
axes[0].plot(output_data_iir["sample"], output_data_iir["value"], color='orange', label="IIR", alpha=0.8)

axes[1].plot(input_data["sample"], input_data["value"], label="Input", color='grey', alpha=0.8)
axes[1].plot(output_data_fir["sample"], output_data_fir["value"], color='blue', label="FIR", alpha=0.8)

for ax in axes:
    ax.legend()

plt.show()

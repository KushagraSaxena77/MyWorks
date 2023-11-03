import tkinter as tk

def stage1(input_data):
    processed_data = input_data * 2
    return processed_data

def stage2(input_data):
    processed_data = input_data + 5
    return processed_data

def stage3(input_data):
    processed_data = input_data - 3
    return processed_data

def stage4(input_data):
    processed_data = input_data ** 2
    return processed_data

def four_stage_pipeline(input_data):
    stage1_output = stage1(input_data)
    stage2_output = stage2(stage1_output)
    stage3_output = stage3(stage2_output)
    stage4_output = stage4(stage3_output)
    return stage4_output

def three_stage_pipeline(input_data):
    stage1_output = stage1(input_data)
    stage2_output = stage2(stage1_output)
    stage3_output = stage3(stage2_output)
    return stage3_output

def two_stage_pipeline(input_data):
    stage1_output = stage1(input_data)
    stage2_output = stage2(stage1_output)
    return stage2_output

def calculate_pipeline():
    stage = int(stage_entry.get())
    input_data = int(data_entry.get())

    if stage == 2:
        result = two_stage_pipeline(input_data)
        result_label.config(text=f"2-Stage Pipeline Result: {result}")
    elif stage == 3:
        result = three_stage_pipeline(input_data)
        result_label.config(text=f"3-Stage Pipeline Result: {result}")
    elif stage == 4:
        result = four_stage_pipeline(input_data)
        result_label.config(text=f"4-Stage Pipeline Result: {result}")
    else:
        result_label.config(text="Invalid Choice")

root = tk.Tk()
root.title("Arithmetic Pipeline Calculator")

stage_label = tk.Label(root, text="Enter Stage Number (2-4):")
stage_label.pack()
stage_entry = tk.Entry(root)
stage_entry.pack()

data_label = tk.Label(root, text="Enter a number to perform Arithmetic Pipeline:")
data_label.pack()
data_entry = tk.Entry(root)
data_entry.pack()

calculate_button = tk.Button(root, text="Calculate", command=calculate_pipeline)
calculate_button.pack()

result_label = tk.Label(root, text="")
result_label.pack()

root.mainloop()

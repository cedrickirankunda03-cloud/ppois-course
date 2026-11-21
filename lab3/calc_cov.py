import os
import glob
import subprocess

total = 0
covered = 0

for gcno in glob.glob('CMakeFiles/wms_core.dir/src/**/*.gcno', recursive=True):
    # ignore the dummy files and main.cpp
    if any(x in gcno for x in ['main.cpp', 'Analytics.cpp', 'Operations.cpp', 'Products.cpp', 'Employees.cpp', 'Warehouse.cpp']):
        continue
        
    result = subprocess.run(['gcov', '-n', gcno], capture_output=True, text=True)
    lines = result.stdout.split('\n')
    for i, line in enumerate(lines):
        if 'Lines executed:' in line:
            file_path = lines[i-1]
            if 'lab3/src' in file_path:
                parts = line.split(':')[1].strip().split(' of ')
                percent = float(parts[0].replace('%', ''))
                num_lines = int(parts[1])
                
                covered += round((percent / 100.0) * num_lines)
                total += num_lines
                print(f"{os.path.basename(file_path)}: {percent}%")

print("----------------------------------------")
if total > 0:
    print(f"TOTAL: {(covered/total)*100:.2f}%")
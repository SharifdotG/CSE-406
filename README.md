# CSE-406: Operating Systems Lab

- **University of Asia Pacific** | Department of Computer Science & Engineering
- **Course**: CSE 406 - Operating Systems Lab
- **Student**: Sharif Md. Yousuf (ID: 22101128) | Section: C-2
- **Semester**: 4th Year, 1st Semester | Spring 2025
- **Instructor**: Atia Rahman Orthi (Lecturer)

This repository contains comprehensive implementations of CPU scheduling algorithms, disk scheduling algorithms, and page replacement algorithms, along with detailed LaTeX lab reports documenting theory, implementation, and analysis.

---

## 📚 Table of Contents

- [CPU Scheduling Algorithms](#-cpu-scheduling-algorithms)
- [Disk Scheduling Algorithms](#-disk-scheduling-algorithms)
- [Page Replacement Algorithms](#-page-replacement-algorithms)
- [Lab Exam Solutions](#-lab-exam-solutions)
- [Compilation & Execution](#-compilation--execution)
- [Project Structure](#-project-structure)
- [Key Features](#-key-features)
- [Technologies Used](#-technologies-used)
- [Learning Outcomes](#-learning-outcomes)
- [License](#-license)

---

## 💻 CPU Scheduling Algorithms

### 1. FCFS (First Come First Serve)

**Directory**: `FCFS/`

- **Implementation**:
  - Basic: `FCFS.cpp` - Simple FCFS with manual input
  - Optimized: `FCFS_Optimized.cpp` - Improved version with sorting by arrival time
- **Report**: `FCFS_Lab_Report.tex` (Lab Report 1)
- **Features**:
  - Handles different arrival times
  - Calculates completion time, turnaround time, and waiting time
  - Computes average waiting time and average turnaround time
  - Time complexity: O(n log n) with sorting optimization

### 2. SJF (Shortest Job First - Non-Preemptive)

**Directory**: `SJF/`

- **Implementation**: `SJF.cpp`
- **Report**: `SJF_Lab_Report.tex` (Lab Report 2)
- **Features**:
  - Non-preemptive scheduling based on burst time
  - Handles CPU idle time scenarios
  - Optimal average waiting time for non-preemptive schedulers
  - Prevents starvation considerations

### 3. Round Robin (RR)

**Directory**: `Round Robin/`

- **Implementation**: `Round_Robin.cpp`
- **Report**: `Round_Robin_Lab_Report.tex` (Lab Report 3)
- **Features**:
  - Time quantum-based preemptive scheduling
  - Queue-based implementation with visited tracking
  - Handles context switching and process completion
  - Fair CPU time distribution
  - Dynamic time quantum configuration

### 4. Priority Scheduling (Non-Preemptive)

**Directory**: `Priority Scheduling/`

- **Implementation**: `Priority_Scheduling.cpp`
- **Report**: `Priority_Scheduling_Lab_Report.tex` (Lab Report 4)
- **Features**:
  - Priority-based selection (lower number = higher priority)
  - Deterministic tie-breaking (by arrival time, then PID)
  - Handles CPU idle periods
  - Analyzes starvation risks

---

## 💿 Disk Scheduling Algorithms

### 5. FCFS Disk Scheduling

**Directory**: `FCFS Disk Scheduling/`

- **Implementation**: `FCFS_Disk_Scheduling.cpp`
- **Report**: `FCFS_Disk_Scheduling_Lab_Report.tex` (Lab Report 5)
- **Features**:
  - Serves disk requests in arrival order
  - Calculates total head movement
  - Simple and fair but not optimized
  - **Test Case**: Head at 50, requests: [11, 34, 41, 50, 52, 69, 70, 114]
  - **Result**: Total movement = 208

### 6. SSTF (Shortest Seek Time First)

**Directory**: `SSTF Disk Scheduling/`

- **Implementation**: `SSTF_Disk_Scheduling.cpp`
- **Report**: `SSTF_Disk_Scheduling_Lab_Report.tex` (Lab Report 6)
- **Features**:
  - Greedy algorithm selecting closest request
  - Significantly reduces seek time (30% improvement over FCFS)
  - Potential starvation issue for distant requests
  - **Test Case**: Same as FCFS
  - **Result**: Total movement = 146 (30% better than FCFS)

### 7. SCAN (Elevator Algorithm)

**Directory**: `SCAN Disk Scheduling/`

- **Implementation**: `SCAN_Disk_Scheduling.cpp`
- **Report**: `SCAN_Disk_Scheduling_Lab_Report.tex` (Lab Report 7)
- **Features**:
  - Directional sweep to disk boundaries
  - Eliminates starvation completely
  - More predictable than SSTF
  - Configurable initial direction (left/right)
  - **Disk Size**: 200 cylinders (0-199)
  - **Result**: Total movement = 164

### 8. C-SCAN (Circular SCAN)

**Directory**: `C-SCAN Disk Scheduling/`

- **Implementation**: `C_SCAN_Disk_Scheduling.cpp`
- **Report**: `C_SCAN_Disk_Scheduling_Lab_Report.tex` (Lab Report 8)
- **Features**:
  - Unidirectional circular sweep
  - More uniform wait time than SCAN
  - Better fairness across all disk regions
  - Circular jump from end to beginning
  - **Test Case**: Head at 50, requests: [21, 39, 50, 64, 79, 90, 176]
  - **Result**: Total movement = 243

---

## 📄 Page Replacement Algorithms

### 9. FIFO (First In First Out)

**Directory**: `FIFO Page Replacement Algorithm/`

- **Implementation**: `FIFO_Page_Replacement_Algorithm.cpp`
- **Report**: `FIFO_Page_Replacement_Algorithm_Lab_Report.tex` (Lab Report 9)
- **Features**:
  - Queue-based page replacement
  - Tracks page hits and page faults
  - Calculates hit ratio and fault ratio
  - Visualizes frame status at each step
  - Demonstrates Belady's Anomaly
  - **Test Case**: 3 frames, 15 page references

---

## 🎓 Lab Exam Solutions

**Directory**: `Lab Mid/`

- **Q1.cpp**: Round Robin scheduling implementation (lab exam question 1)
- **Q2.cpp**: SCAN disk scheduling implementation (lab exam question 2)

---

## 🔧 Compilation & Execution

### Compiling C++ Programs

All programs use C++17 standard with STL (`bits/stdc++.h`). Compile using g++:

```bash
# General template
g++ -O2 -std=c++17 -Wall -Wextra -o output_name source_file.cpp

# Examples for each algorithm
g++ -O2 -std=c++17 -o fcfs "FCFS/FCFS_Optimized.cpp"
g++ -O2 -std=c++17 -o sjf "SJF/SJF.cpp"
g++ -O2 -std=c++17 -o rr "Round Robin/Round_Robin.cpp"
g++ -O2 -std=c++17 -o priority "Priority Scheduling/Priority_Scheduling.cpp"
g++ -O2 -std=c++17 -o fcfs_disk "FCFS Disk Scheduling/FCFS_Disk_Scheduling.cpp"
g++ -O2 -std=c++17 -o sstf "SSTF Disk Scheduling/SSTF_Disk_Scheduling.cpp"
g++ -O2 -std=c++17 -o scan "SCAN Disk Scheduling/SCAN_Disk_Scheduling.cpp"
g++ -O2 -std=c++17 -o cscan "C-SCAN Disk Scheduling/C_SCAN_Disk_Scheduling.cpp"
g++ -O2 -std=c++17 -o fifo "FIFO Page Replacement Algorithm/FIFO_Page_Replacement_Algorithm.cpp"
```

### Running Programs

```bash
# CPU Scheduling (requires interactive input)
./fcfs
./sjf
./rr
./priority

# Disk Scheduling (uses predefined test cases)
./fcfs_disk
./sstf
./scan
./cscan

# Page Replacement (requires interactive input)
./fifo
```

### Compiling LaTeX Reports

All lab reports are written in LaTeX. Compile to PDF:

```bash
# General template
pdflatex report_name.tex

# Run twice for proper cross-references
pdflatex "FCFS/FCFS_Lab_Report.tex"
pdflatex "FCFS/FCFS_Lab_Report.tex"

# Or use latexmk for automatic compilation
latexmk -pdf "FCFS/FCFS_Lab_Report.tex"
```

**Note**: LaTeX reports include code screenshots, output screenshots, discussions, and conclusions.

---

## 📁 Project Structure

```js
CSE-406/
├── .vscode/                      # VS Code configuration
│   ├── c_cpp_properties.json     # C++ IntelliSense config
│   └── settings.json             # Workspace settings
├── FCFS/                         # Lab 1: FCFS CPU Scheduling
│   ├── FCFS.cpp
│   ├── FCFS_Optimized.cpp
│   └── FCFS_Lab_Report.tex
├── SJF/                          # Lab 2: SJF CPU Scheduling
│   ├── SJF.cpp
│   └── SJF_Lab_Report.tex
├── Round Robin/                  # Lab 3: Round Robin Scheduling
│   ├── Round_Robin.cpp
│   └── Round_Robin_Lab_Report.tex
├── Priority Scheduling/          # Lab 4: Priority Scheduling
│   ├── Priority_Scheduling.cpp
│   └── Priority_Scheduling_Lab_Report.tex
├── FCFS Disk Scheduling/         # Lab 5: FCFS Disk Scheduling
│   ├── FCFS_Disk_Scheduling.cpp
│   └── FCFS_Disk_Scheduling_Lab_Report.tex
├── SSTF Disk Scheduling/         # Lab 6: SSTF Disk Scheduling
│   ├── SSTF_Disk_Scheduling.cpp
│   └── SSTF_Disk_Scheduling_Lab_Report.tex
├── SCAN Disk Scheduling/         # Lab 7: SCAN Disk Scheduling
│   ├── SCAN_Disk_Scheduling.cpp
│   └── SCAN_Disk_Scheduling_Lab_Report.tex
├── C-SCAN Disk Scheduling/       # Lab 8: C-SCAN Disk Scheduling
│   ├── C_SCAN_Disk_Scheduling.cpp
│   └── C_SCAN_Disk_Scheduling_Lab_Report.tex
├── FIFO Page Replacement Algorithm/  # Lab 9: FIFO Page Replacement
│   ├── FIFO_Page_Replacement_Algorithm.cpp
│   └── FIFO_Page_Replacement_Algorithm_Lab_Report.tex
├── Lab Mid/                      # Lab Midterm Exam Solutions
│   ├── Q1.cpp                    # Round Robin implementation
│   └── Q2.cpp                    # SCAN disk scheduling
├── LICENSE                       # MIT License
└── README.md                     # This file
```

---

## ✨ Key Features

- **Comprehensive Implementations**: All major CPU scheduling, disk scheduling, and page replacement algorithms
- **Well-Documented Code**: Clear variable names, structured code, efficient algorithms
- **Academic Reports**: Detailed LaTeX reports with problem statements, objectives, discussions, and conclusions
- **Performance Analysis**: Comparative analysis between algorithms with metrics
- **Test Cases**: Predefined test cases for disk scheduling algorithms
- **Interactive Input**: User-friendly input/output for CPU scheduling algorithms
- **Visual Feedback**: Frame status visualization for page replacement algorithm

---

## 🛠️ Technologies Used

- **Programming Language**: C++17
- **Compiler**: MinGW g++ (Windows)
- **IDE**: Visual Studio Code
- **Documentation**: LaTeX (pdflatex)
- **Version Control**: Git & GitHub
- **Libraries**: C++ Standard Template Library (STL)

---

## 🎯 Learning Outcomes

Through these implementations, the following concepts were mastered:

1. **CPU Scheduling**:
   - Non-preemptive vs preemptive scheduling
   - Process control blocks and context switching
   - Performance metrics (waiting time, turnaround time, response time)
   - Trade-offs between fairness and efficiency

2. **Disk Scheduling**:
   - Disk I/O optimization techniques
   - Seek time minimization strategies
   - Starvation prevention mechanisms
   - Directional vs greedy algorithms

3. **Memory Management**:
   - Virtual memory concepts
   - Page fault handling
   - Frame allocation strategies
   - Performance evaluation (hit ratio, fault ratio)

4. **Algorithm Design**:
   - Greedy algorithms (SSTF)
   - Queue-based algorithms (FCFS, RR, FIFO)
   - Sorting and selection algorithms
   - Time and space complexity analysis

---

## 📊 Algorithm Comparison Summary

### CPU Scheduling

| Algorithm | Type | Pros | Cons | Best Use Case |
|-----------|------|------|------|---------------|
| FCFS | Non-preemptive | Simple, fair | Convoy effect | Batch systems |
| SJF | Non-preemptive | Optimal avg waiting time | Starvation possible | Known burst times |
| Round Robin | Preemptive | Fair, responsive | Context switching overhead | Time-sharing systems |
| Priority | Non-preemptive | Important tasks first | Starvation risk | Real-time systems |

### Disk Scheduling

| Algorithm | Movement (Test) | Pros | Cons | Starvation |
|-----------|-----------------|------|------|------------|
| FCFS | 208 | Simple, fair | High seek time | No |
| SSTF | 146 | Low seek time | Unfair to distant requests | Yes |
| SCAN | 164 | No starvation, predictable | Unnecessary boundary sweep | No |
| C-SCAN | 243 | Uniform wait time | Higher seek time | No |

---

## 📜 License

This project is licensed under the **MIT License**. See the [`LICENSE`](LICENSE) file for details.

```js
MIT License - Copyright (c) 2025 Sharif Md. Yousuf
```

---

## 👨‍💻 Author

**Sharif Md. Yousuf**
Student ID: 22101128
Department of Computer Science & Engineering
University of Asia Pacific

For questions or collaborations, feel free to reach out!

---

**Note**: This repository is maintained for academic purposes and demonstrates understanding of operating systems concepts through practical implementation.

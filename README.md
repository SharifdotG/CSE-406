# CSE-406

Collection of CSE 406 lab implementations and accompanying LaTeX reports.

## Implemented Scheduling / Disk Algorithms

- FCFS (First Come First Serve)
  - Code: `FCFS/FCFS.cpp` and optimized `FCFS/FCFS_Optimized.cpp`
  - Report: `FCFS/FCFS_Lab_Report.pdf` (source: `FCFS/FCFS_Lab_Report.tex`)
- SJF (Shortest Job First Non-Preemptive)
  - Code: `SJF/SJF.cpp`
  - Report: `SJF/SJF_Lab_Report.pdf` (source: `SJF/SJF_Lab_Report.tex`)
- Round Robin
  - Code: `Round Robin/Round_Robin.cpp`
  - Report: `Round Robin/Round_Robin_Lab_Report.pdf` (source: `Round Robin/Round_Robin_Lab_Report.tex`)
- Priority Scheduling (Non-Preemptive)
  - Code: `Priority Scheduling/Priority_Scheduling.cpp`
  - Report: `Priority Scheduling/Priority_Scheduling_Lab_Report.tex` (compile to PDF)
- Disk Scheduling (SSTF)
  - Code: `Disk Scheduling/Disk_Scheduling.cpp`
  - Report: `Disk Scheduling/Disk_Scheduling_Lab_Report.tex` (compile to PDF)

## Compilation Notes

Use a C++17 compiler (e.g., g++):

```bash
g++ -O2 -std=c++17 -Wall -Wextra -Wshadow -o priority "Priority Scheduling/Priority_Scheduling.cpp"
```

Compile LaTeX (example):

```bash
pdflatex FCFS/FCFS_Lab_Report.tex
```

Run twice if references need updating.

## License

See `LICENSE` file.
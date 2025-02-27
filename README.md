# 104neutrinos

## Description
104neutrinos is a statistical analysis tool designed for nuclear physics research, specifically for studying neutrino particles. The program processes large sets of measurement data in real-time, calculating various statistical metrics crucial for neutrino speed analysis.

## Purpose
The program helps researchers study neutrino behavior by maintaining and updating statistical measurements including:
- Arithmetic mean
- Harmonic mean
- Standard deviation
- Root mean square (RMS)

## Requirements
- A C compiler (gcc recommended)
- Make utility
- Unix-like environment

## Installation
```bash
make        # Compile the program
make re     # Recompile
make clean  # Remove object files
make fclean # Remove object files and binary
```

## Usage
```bash
./104neutrinos n a h sd
```

### Parameters
- `n`: Number of values
- `a`: Arithmetic mean
- `h`: Harmonic mean
- `sd`: Standard deviation

### Example
```bash
./104neutrinos 12000 297514 297912 4363
```

## Input Format
- Enter numerical values one at a time when prompted
- Enter "END" to terminate the program

## Output Format
For each new value entered, the program displays:
- Number of values
- Standard deviation
- Arithmetic mean
- Root mean square
- Harmonic mean

### Example Output
```
Enter next value: 299042
Number of values: 12001
Standard deviation: 4362.84
Arithmetic mean: 297514.13
Root mean square: 297546.11
Harmonic mean: 297912.09
```

## Error Handling
- The program exits with code 84 on error
- Error messages are displayed on the error output
- Returns 0 on successful execution

## Important Notes
- All calculations are performed in real-time
- No external libraries for statistical calculations are used
- The program is designed for handling large datasets efficiently

## Technical Constraints
- All main computations must be implemented manually
- No external statistical libraries are allowed
- Calculations must be optimized for real-time processing

## Contributing
This is an EPITECH student project. No contributions are allowed.

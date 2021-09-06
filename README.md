# Basic Read Mapper

This Basic Read Mapper will map reads to a reference sequence and output an aligned fasta file. 
First, a suffix array is generated from the reference sequence. Next, the starting location of the reads
are found by doing a binary search of the suffix array. Then, the reference sequence and reads are 
output to a fasta file using "-" as a leading and trailing spacer for the mapped reads.

*Assumptions/Limitations*:

- Assumes all reads are in the same direction as the reference sequence (no reverse complements)

- Only maps reads that are exact matches to the reference sequence (no tolerance for mis-matches)

- Maps reads to the first location found using algorithm (does not check for multiple matches)


### Installation

Linux

```
git clone https://github.com/jmattick/BasicReadMapperCpp.git; cd BasicReadMapperCpp; cmake .; make;
```

### Usage

```
BasicReadMapper <reference.fa> <reads.fa> <output.fa>
```

*Arguments*: 

- `<reference.fa>` is the fasta file for thereference sequence that reads will be mapped to.

- `<reads.fa>` is the fasta file of the reads to be mapped to the reference sequence.

- `<output.fa>` is the output fasta file that will contain the mapped reads and reference sequence. 

### Run Example

Example data is provided in the `ExampleData` folder. An example output file `ExampleOutput.fasta` is provided.

To run the BasicReadMapper on the example data use the following command:

```
src/BasicReadMapper ExampleData/reference.fasta ExampleData/reads.fasta ExampleData/out.fasta
```




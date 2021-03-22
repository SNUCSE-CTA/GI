# Graph Isomorphism

## Introduction
The graph isomorphism problem is to determine whether there exists an isomorphism between two input graphs. This project is a C++ software that solves graph isomorphism. Current version assumes that the input graphs are simple, undirected, connected, and vertex-labeled (single label is permitted for each vertex).

Graph isomorphism is a core problem in graph analyses of various domains including social networks, bioinformatics, chemistry, mechanics, and so on. As the real-world graphs are getting bigger and bigger, applications demand practically fast algorithms that can run on large graphs.

## Installation
To download and compile the project, use the following commands.
```console
git clone https://github.com/SNUCSE-CTA/GI.git
cd GI
make
```

## Usage
To run the proram:
``` console
./GI [file 1] [file 2]
```
In case that the two graphs are isomorphic, 
you can print an isomorphism between them into a file 
by specifying the file name as the third argument.
```console
./GI [file 1] [file 2] [output file]
```

## Running Example
``` console
./GI input/lcc_yeast.igraph input/sfl_lcc_yeast.igraph

./GI input/lcc_yeast.igraph input/sfl_lcc_yeast.igraph isomorphism.txt
```

## Input File Format
The file format is a text format to store an undirected graph. 
- The first line of the file should be "t ID #vertices"
- Following lines of "v [vertex ID] [vertex label]" indicate the vertices in the graph.
- The vertices should be written in the file in ascending order of their IDs, and a vertex ID should be in range [0, #vertices - 1].
- Following lines of "e [vertex ID] [vertex ID] [edge label]" after the vertices indicate the undirected edges in the graph.

For example:
```
Line "t 1 3112" means that the start of a graph with ID=1 and #vertices=3112.
Line "v 0 1" means that there is a vertex with ID=0 and vertex-label=1 in the graph.
Line "e 1 133 0" means that there is an undirected edge between vertices with IDs 1 and 133, where edge label is 0.
```

## Bug Reporting
If you have any trouble with this project, please let us know via [GitHub issue tracking system](https://github.com/SNUCSE-CTA/GI/issues) of the project.

## Authors

The main contributors to this project are:
- [Geonmo Gu](https://github.com/gmgu)
- [Yehyun Nam](https://github.com/NamYehyun)
- [Kunsoo Park](http://theory.snu.ac.kr/?page_id=427) (mentor)

## Licensing
This project is an open source software provided under the Apache License 2.0.
- We use googletest library, which is covered by BSD 3-Clause License.
- We use a revised source code of Nauty and Traces, which is covered by Apache License 2.0.

## Contribute

### Decision Making Procedure
1. raise an issue that you want to make a contribution via [GitHub issue tracking system](https://github.com/SNUCSE-CTA/GI/issues).
2. communicate with the authors.
3. fork this project.
4. create a branch.
5. work on the issue.
6. create a pull request with a clear explanation of the changes.

### Coding Convension
Please see [Our Coding Convention](https://github.com/SNUCSE-CTA/GI/issues/6).

# Exhaustive Table of Contents 
## Algorithm analysis
* Master theorem :heavy_check_mark:
* Amortized time complexity :heavy_check_mark:
## Data Structures

### Fundamental
* Minimum Stack :heavy_check_mark:
* Minimum Queue :heavy_check_mark:
* Sparse Table :heavy_check_mark:

### Trees
* Union-Find Disjoint Sets :heavy_check_mark:
* Binary Tree :heavy_check_mark:
* Binary Search Tree :heavy_check_mark:
* AVL Trees
* Red-Black Trees
* Segment Tree 
* Fenwick Tree (Binary Indexed Tree)
* Trie
* Treap
* Heap
* N-ary Tree
* Suffix Tree
* Sqrt Tree
* Huffman Tree
* B+, B- Tree
* Merkle Tree
* Splay Tree
### Graph theory
* Traversals
	* Depth first search :heavy_check_mark:
	* Breadth first search :heavy_check_mark:
* Topological Sort
	* Using modified DFS/BSF :heavy_check_mark:
	* Kahn algorithm :heavy_check_mark:
* Connected components, bridges, articulations points
	* Articulation points and bridges (Undiredted graphs) :heavy_check_mark:
	* Strongly connected components (Directed graphs)
* Minimum spanning tree
	* Kruskal algorithm :heavy_check_mark:
	* Prim algorithm :heavy_check_mark:
	* Boruvka algorithm :red_circle:
	* Steiner Tree :red_circle:
* Shortest paths
	* Bellman Ford algorithm :heavy_check_mark:
	* SPFA (Shortest Path Faster Algorithm) :red_circle:
	* Dijkstra  algorithm :heavy_check_mark:
	* A* algorithm :red_circle:
	* Floyd-Warshall algorithm :heavy_check_mark:
	* Johnson algorithm :red_circle:
* Cycles
	* Checking a graph for acyclicity and finding a cycle in O(M) :heavy_check_mark:
	* Finding a Negative Cycle in the Graph :heavy_check_mark:
	* Eulerian Path :heavy_check_mark:
* Flow networks
	* Ford-Fulkerson and Edmonds-Karp :heavy_check_mark:
	* Push-relabel algorithm
	* Dinic's algorithm
	* MPM algorithm
	* Flows with demands
	* Minimum-cost flow
	* Assignment problem. Solution using min-cost-flow in O (N^5)
* Flood-Fill
	* Using DFS :heavy_check_mark:
	* Forest-Fire using BFS 
	* Using Scan-Line algorithm
* Lowest common ancestor
	* Lowest Common Ancestor - Euler Path (O(n) + O(q*logn)) :heavy_check_mark:
	* Lowest Common Ancestor - Binary Lifting :red_circle:
	* Lowest Common Ancestor - Farach-Colton and Bender algorithm :red_circle:
	* Solve RMQ by finding LCA :red_circle:
	* Lowest Common Ancestor - Tarjan's off-line algorithm :red_circle:
* Matchings and related problems
	* Bipartite Graph Check
* Vertex coloring
	* Bipartite graphs (=> trees)
	* 3^n (special case of set cover)
* Edge coloring
	* Trees
* Miscellaneous
	* Edge connectivity / Vertex connectivity
	* Tree painting
	* 2-SAT
	* Heavy-light decomposition
	* Euler cycles
	* Shortest cycle
	* Konig's theorem and vertex cover
	* Lovasz toggle
	* Matrix tree theorem
	* Maximal matching, general graphs
	* Hopcroft-Karp
	* Hall's marriage theorem
	* Graphical sequences
	* Min. path cover
	* Cut vertices, cut-edges and biconnected components
	* Diameter and centroid
	* K'th shortest path
	* Dynamic graphs (extra book-keeping)

## Searching and Sorting
* Binary Search :heavy_check_mark:
* Ternary Search :heavy_check_mark:
* Exponential Search :heavy_check_mark:
* Fibonacci Search :heavy_check_mark:
* Interpolation Search :heavy_check_mark:
* Jump Search :heavy_check_mark:
* Insertion Sort :heavy_check_mark:
* Selection Sort :heavy_check_mark:
* Bubble Sort :heavy_check_mark:
* Merge Sort :heavy_check_mark:
* Counting Sort :heavy_check_mark:
* Quick Sort :heavy_check_mark:
* Heap Sort :red_circle:
* Shell Sort :red_circle:
* Radix Sort :red_circle:
## Algorithmic Paradigms
### Greedy algorithm
* Scheduling
* Max contiguous subvector sum
* Invariants
* Huffman encoding
### Dynamic programming
* Knapsack
* Coin change
* Longest common subsequence
* Longest increasing subsequence
* Number of paths in a dag
* Shortest path in a dag
* Dynprog over intervals
* Dynprog over subsets
* Dynprog over probabilities
* Dynprog over trees
* 3^n set cover
* Divide and conquer
* Knuth optimization
* Convex hull optimizations
* RMQ (sparse table a.k.a 2^k-jumps)
* Bitonic cycle
* Log partitioning (loop over most restricted)
## Math
### Combinatorics
* Computation of binomial coefficients
* Pigeon-hole principle
* Inclusion/exclusion
* Catalan number
* Pick's theorem
### Number theory
* Integer parts
* Divisibility
* Euclidean algorithm
* Modular arithmetic
	* Modular multiplication
	* Modular inverses
	* Modular exponentiation by squaring
* Chinese remainder theorem
* Fermat's little theorem
* Euler's theorem
* Phi function
* Frobenius number
* Quadratic reciprocity
* Pollard-Rho
* Miller-Rabin
* Hensel lifting
* Vieta root jumping
### Game theory
* Combinatorial games
* Game trees
* Mini-max
* Nim
* Games on graphs
* Games on graphs with loops
* Grundy numbers
* Bipartite games without repetition
* General games without repetition
* Alpha-beta pruning
### Numerical methods
* Numeric integration
* Newton's method
* Root-finding with binary/ternary search
* Golden section search
### Matrices
* Gaussian elimination
* Exponentiation by squaring
## Geometry
* Coordinates and vectors
	* Cross product
	* Scalar product
* Convex hull
* Polygon cut
* Closest pair
* Coordinate-compression
* Quadtrees
* KD-trees
* All segment-segment intersection
## Strings
* Longest common substring
* Palindrome subsequences
* Knuth-Morris-Pratt
* Tries
* Rolling polynomial hashes
* Suffix array
* Suffix tree
* Aho-Corasick
* Manacher's algorithm
* Letter position lists
## Others
### Combinatorial search
* Meet in the middle
* Brute-force with pruning
* Best-first (A*)
* Bidirectional search
* Iterative deepening DFS / A*
* MiniMax
### Sweeping
* Discretization (convert to events and sweep)
* Angle sweeping
* Line sweeping
* Discrete second derivatives
### Data structures related
* LCA (2^k-jumps in trees in general)
* Pull/push-technique on trees
* Heavy-light decomposition
* Centroid decomposition
* Lazy propagation
* Self-balancing trees
* Convex hull trick (wcipeg.com/wiki/Convex_hull_trick)
* Monotone queues / monotone stacks / sliding queues
* Sliding queue using 2 stacks
* Persistent segment tree

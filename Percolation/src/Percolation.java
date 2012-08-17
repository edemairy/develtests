

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author edemairy
 */
public class Percolation {

    private static final int[][] DIRS = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    // indices go from up-left (1) to bottom-right (N*N). 
    // Index 0 is a virtual site linked to the uppest line.
    // Index N*N+1 is a virtual site linked to the bottom line.
    private int[] index;
    private int[] size;
    private boolean[] opened;
    private int N;
    private int gridSize;
    private int top;
    private int bottom;
    

    /**
     * Create N-by-N grid, with all sites blocked.
     *
     * @param N size of the square-grid.
     */
    public Percolation(int N) {
        this.N = N;
        this.gridSize = N * N + 2;
        top = 0;
        bottom = N * N + 1;
        index = new int[gridSize];
        size = new int[gridSize];
        opened = new boolean[gridSize];
        opened[top] = true;
        opened[bottom] = true;
        for (int i = 0; i <= N * N + 1; ++i) {
            index[i] = i;
            size[i] = 1;
            opened[i] = false;
        }
    }

    /**
     * open site (row i, column j) if it is not already opened.
     *
     * @param i row, 1-based.
     * @param j column, 1-based.
     */
    public void open(int i, int j) {
        if (!isOpen(i, j)) {
            opened[val(i, j)] = true;
            for (int[] d : DIRS) {
                if (isValid(i + d[0], j + d[1]) && isOpen(i + d[0], j + d[1])) {
                    union(val(i, j), val(i + d[0], j + d[1]));
                } else {
                    if (i + d[0] < 1) {
                        union(val(i, j), top);
                    }
                    if (i + d[0] > N) {
                        union(val(i, j), bottom);
                    }
                }
            }
        } else {
            return;
        }

    }

    public boolean isOpen(int i, int j) // is site (row i, column j) open?
    {
        return opened[val(i, j)];
    }

    public boolean isFull(int i, int j) // is site (row i, column j) full?
    {
        return root(val(i, j)) == root(0);
    }

    public boolean percolates() // does the system percolate?
    {
        return find(top, bottom);
    }

    private int val(int i, int j) {
        return (i - 1) * N + j;
    }

    private boolean isValid(int i, int j) {
        return (i >= 1 && i <= N && j >= 1 && j <= N);
    }

    private void union(int p, int q) {
        int idp = root(p);
        int idq = root(q);
        index[idp] = idq;

        assert (root(p) == root(q));
//        if (size[p] < size[q]) {
//            index[p] = idq;
//            size[q] += size[p];
//        } else {
//            index[q] = idp;
//            size[p] += size[q];
//        }
    }

    private boolean find(int p, int q) {
        int idp = root(p);
        int idq = root(q);
        return idp == idq;
    }

    private int root(int p) {
        int id = p;
        while (index[id] != id) {
            id = index[id];
        }
        return index[id];
    }
}
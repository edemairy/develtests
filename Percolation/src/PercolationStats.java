
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Locale;
import java.util.Random;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author edemairy
 */
public class PercolationStats {

    private final double[] x;
    private int N;
    private int T;
    private double mu;
    private double stddev;

    /**
     * perform T independent computational experiments on an N-by-N grid
     *
     * @param N size of the grid.
     * @param T number of iterations.
     */
    public PercolationStats(int N, int T) {
        this.N = N;
        this.T = T;
        x = new double[T];
        Arrays.fill(x, 0);
        Random r = new Random();

        for (int nbIter = 0; nbIter < T; ++nbIter) {
            int stepNumber = 0;
            Percolation percolation = new Percolation(N);
            while (!percolation.percolates()) {
                stepNumber++;
                int i;
                int j;
                do {
                    i = r.nextInt(N) + 1;
                    j = r.nextInt(N) + 1;
                } while (percolation.isOpen(i, j));
                percolation.open(i, j);
            }
            x[nbIter] = 1.0 * stepNumber / (N * N);
            mu += x[nbIter] / T;

        }
        double stddev2 = 0;
        for (int nbIter = 0; nbIter < T; ++nbIter) {
            stddev2 += (x[nbIter] - mu)*(x[nbIter] - mu);
        }
        stddev2 /= (T - 1);
        stddev = Math.sqrt(stddev2);
    }

    public double mean() // sample mean of percolation threshold
    {
        return mu;
    }

    public double stddev() // sample standard deviation of percolation threshold
    {
        return stddev;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        assert (args.length == 2);
        int N = Integer.parseInt(args[0]);
        assert (N > 0);
        int T = Integer.parseInt(args[1]);
        assert (T > 0);
        PercolationStats stats = new PercolationStats(N, T);
        Formatter formatter = new Formatter(Locale.ENGLISH);
        double dev = (1.96 * stats.stddev()) / Math.sqrt(T);
        double minInt95 = stats.mean() - dev;
        double maxInt95 = stats.mean() + dev;
        formatter.format(
                "mean                    = %f%n"
                + "stddev                  = %f%n"
                + "95%% confidence interval = %f, %f", 
                stats.mean(), stats.stddev(), minInt95, maxInt95);
        System.out.println(formatter);
    }
}

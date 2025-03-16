import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Interactive Mode: no arguments => use standard I/O.
        if (args.length == 0) {
            UserCode.solve(new Scanner(System.in), new PrintWriter(System.out));
        }
        // Test Mode: if three arguments are provided.
        else if (args.length == 3) {
            // args[0] -> input file, args[1] -> expected output file, args[2] -> actual output file.
            Scanner sc = new Scanner(new File(args[0]));
            PrintWriter out = new PrintWriter(new File(args[2]));
            UserCode.solve(sc, out);
            out.flush();
            
            // Compare expected and actual outputs.
            BufferedReader brActual = new BufferedReader(new FileReader(args[2]));
            BufferedReader brExpected = new BufferedReader(new FileReader(args[1]));
            String lineA, lineE;
            boolean passed = true;
            while ((lineE = brExpected.readLine()) != null) {
                lineA = brActual.readLine();
                if (lineA == null || !lineA.trim().equals(lineE.trim())) {
                    passed = false;
                    break;
                }
            }
            if (brActual.readLine() != null) {
                passed = false;
            }
            brActual.close();
            brExpected.close();
            
            System.out.println(args[0] + (passed ? " PASSED" : " FAILED"));
        }
        // Fallback: run in interactive mode.
        else {
            UserCode.solve(new Scanner(System.in), new PrintWriter(System.out));
        }
    }
}

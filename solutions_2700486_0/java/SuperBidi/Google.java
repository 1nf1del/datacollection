import java.io.*;
import java.math.BigInteger;
import java.util.Vector;

public class Google
{
    public static boolean executeOnStringTab(String[][] input, PrintWriter output)
    {
        long diamonds = Long.valueOf(input[0][0]);
        long x = Math.abs(Long.valueOf(input[0][1]));
        long y = Long.valueOf(input[0][2]);
        long c = x + y + 1;
        long square = c * (c + 1) / 2;
        if (diamonds >= square)
            return outputCase(output, "1.0");
        if (x == 0)
            return outputCase(output, "0.0");
        c -= 2;
        square = c * (c + 1) / 2;
        if (diamonds <= square)
            return outputCase(output, "0.0");
        diamonds -= square;

        long numberOfHeads = y + 1;
        if (diamonds >= x + y + numberOfHeads)
            return outputCase(output, "1.0");
        long proba = probability(0, diamonds, 0, numberOfHeads, 0);

        return outputCase(output, String.valueOf((double) proba / Math.pow(2, diamonds)));
    }

    public static long probability(long currentPlace, long diamonds, long numberOfHeads, long goal, long result)
    {
        if (currentPlace == diamonds)
        {
            if (numberOfHeads >= goal)
                return result + 1;
            return result;
        }
        currentPlace ++;

        return probability(currentPlace, diamonds, numberOfHeads + 1, goal, result) + probability(currentPlace, diamonds, numberOfHeads, goal, result);
    }

    public static boolean executeOnDataTab(Data input, PrintWriter output)
    {
        return outputCase(output, "IMPOSSIBLE");
    }



    public static void parseStringTab(PrintWriter output, BufferedReader br, int size, String str[], boolean excludeFirstLine) throws Exception
    {
        String input[][] = new String[size][];
        if (!excludeFirstLine)
            input[0] = str;

        for (int i = 1 - (excludeFirstLine ? 1 : 0); i < size; i ++)
        {
            String line = br.readLine();
            str = line.split(" ");
            input[i] = str;
        }

        executeOnStringTab(input, output);
    }

    public static void parseCharTab(PrintWriter output, BufferedReader br, int size, String str[], boolean excludeFirstLine) throws Exception
    {
        String input[][] = new String[size][];
        String line;

        for (int i = 0; i < size; i ++)
        {
            if (i == 0 && !excludeFirstLine)
                line = str[0];
            else line = br.readLine();
            str = new String[line.length()];

            for (int j = 0; j < line.length(); j ++)
            {
                str[j] = Character.toString(line.charAt(j));
            }
            input[i] = str;
        }

        executeOnStringTab(input, output);
    }

    public static void parseDataTab(PrintWriter output, BufferedReader br, int size, String str[]) throws Exception
    {
        Data data = new Data(str);
        for (int i = 1; i < size; i ++)
        {
            String line = br.readLine();
            str = line.split(" ");
            data.addLine(str);
        }

        executeOnDataTab(data, output);
    }

    public static BigInteger sqrt(BigInteger n)
    {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0)
        {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0)
                b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    public static int caseNumber = 0;
    public static boolean outputCase(PrintWriter output, String s)
    {
        caseNumber ++;
        output.println("Case #"+String.valueOf(caseNumber)+": "+s);

        return true;
    }

    public static boolean outputVector(PrintWriter output, Vector<Integer> chests)
    {
        String s = "";
        for (int i = 0; i < chests.size(); i ++)
        {
            s = s + chests.get(i) + " ";
        }

        return outputCase(output, s);
    }

    public static void trace(long l)
    {
        System.out.println(l);
    }

    public static void trace(double l)
    {
        System.out.println(l);
    }

    public static void trace(String s)
    {
        System.out.println(s);
    }

    public static class Line
    {
        int key;

        public Line(String str[])
        {
            key = Integer.parseInt(str[0]);
        }
    }

    public static class Data
    {
        int currentLine;
        Line lines[];
        Line begin;

        public Data(String str[])
        {
            currentLine = 0;
            lines = new Line[Integer.parseInt(str[1])];
        }

        public void addLine(String str[])
        {
            if (currentLine == 0)
                begin = new Line(str);
            else
            {
                Line line = new Line(str);
                lines[currentLine - 1] = line;
            }
            currentLine ++;
        }
    }

    public static void main (String[] args)
    {
        int sizeOfElement = 1;
        int lineToJump = 0;

        String file ="input.in";
        String output = "output.out";
        long timeInMillis = System.currentTimeMillis();

        try
        {
            FileWriter fw = new FileWriter (output);
            BufferedWriter bw = new BufferedWriter (fw);
            PrintWriter outputFile = new PrintWriter (bw);
            InputStream ips=new FileInputStream(file);
            InputStreamReader ipsr=new InputStreamReader(ips);
            BufferedReader br=new BufferedReader(ipsr);
            int numberOfExercices = Integer.parseInt(br.readLine());

            for (int i = 0; i < numberOfExercices; i ++)
            {
                String line = br.readLine();
                String str[] = line.split(" ");
                int size = sizeOfElement;

                //Tableau de String
                parseStringTab(outputFile, br, size, str, false);

                //Tableau de characters
                //parseCharTab(outputFile, br, size, str, false);

                //Data
                //parseDataTab(outputFile, br, size, str);

                for (int j = 0; j < lineToJump; j ++)
                    br.readLine();
            }
            br.close();
            outputFile.close();
        }
        catch (Exception e)
        {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            e.printStackTrace(pw);
            trace(sw.toString());
        }
        trace("time "+(String.valueOf(System.currentTimeMillis() - timeInMillis)));
    }
}
